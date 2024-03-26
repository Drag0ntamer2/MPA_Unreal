// Fill out your copyright notice in the Description page of Project Settings.
#include "CChar.h"


// General Functions
bool CChar::learn(string fact)
{
	for (string thing : knowledge) {
		if (thing == fact) return true;
	}
	knowledge.push_back(fact);
	return false;
}
bool CChar::knows(string fact)
{
	for (string thing : knowledge) {
		if (thing == fact) return true;
	}
	return false;
}
bool CChar::hasPrec(string prec) 
{
	for (string p : precedents) {
		if (p == prec) return true;
	}
	return false;
}
bool CChar::setPrec(string prec)
{
	if (hasPrec(prec)) {
		return true;
	}
	precedents.push_back(prec);
	return false;
}
Quirk CChar::quirk()
{
	return quirks[0];
}
Quirk CChar::quirk(string s)
{
	for (Quirk q : quirks) {
		if (q.name == s)
			return q;
	}
	return Quirk();
}
void CChar::processName(string n)
{
	fname = n;
	istringstream iss(n);
	string part;
	while (getline(iss, part, ' ')) {
		nameParts.push_back(part);
	}
	name = nameParts[0];
}

// Vore Functions
bool CChar::release(string prey)
{
	for (int i = stomach.size(); 0 < i; --i)
	{
		if (prey == stomach[i] && stomach[i].alive) {
			stomach[i].prey->isPrey = false;
			stomach.erase(stomach.begin() + i);

		}
	}
	return false;
}
bool CChar::churn(int time)
{
	if (stomach.empty()) return true;

	float digAmt = time * acidStrength;
	float absAmt = time * absRate;
	float absMass = 0;
	for (Prey prey : stomach) {
		// step 1 > digest: 
		// if digest returns a non-zero value, that means the prey is fully liquified
		// dividing the number returned by the digest function by the acid strength
		// should return the remaining time not used to liquify this prey. 
		// multiplying that number by the character's absorbtion rate will result in
		// the how much of this prey is absorbed in this time block. 
		// this is then added to the overall absorbed mass for this time block as the 
		// next prey is processed.
		absMass += absorb(prey, digest(prey, digAmt) / acidStrength * absRate);
	}
	gain(absMass);

	if (stomach.empty()) return true;
	return false;
}

float CChar::digest(Prey& prey, float digAmt)
{
	stomachFillLevel -= digAmt;
	prey.digest(digAmt);
	return digAmt;
}
float CChar::absorb(Prey& prey, float absAmt) 
{
	stomachFillLevel -= absAmt;
	prey.absorb(absAmt);
	return absAmt;
}


// Constructors
CChar::CChar(string n, bool s, Quirk q, wg_func wg, wl_func wl, Body bdy)
{
	processName(n);
	sex = s;
	quirks = { q };
	body = bdy;
	gain = wg;
	burn = wl;
} 
CChar::CChar(string n, bool s, Quirks qs, wg_func wg, wl_func wl, Body bdy)
{
	processName(n);
	sex = s;
	quirks = qs;
	body = bdy;
	gain = wg;
	burn = wl;
} 


// Comparison Operators
bool CChar::operator==(string Name) 
{
	return Name == name || Name == fname;
}


// Quirk Manipulation Operators
CChar& CChar::operator+(Quirk q)
{
	quirks.push_back(q);
	return *this;
}



// Standard Weight Gain Function Generators
wg_func TopHeavy::wg(CChar& c)
{
	return [&](int mass) -> void {
		c.body["boobs"] += mass;
	};
}
wl_func TopHeavy::wl(CChar& c)
{
	return [&](int mass) -> void {
		c.body["boobs"] += mass * -1;
	};
}

wg_func Distributed::wg(CChar& c)
{
	return [&](int mass) -> void {
		mass /= 4;
		c.body["boobs"] += mass;
		c.body["belly"] += mass;
		c.body["thighs"] += mass;
		c.body["hips"]  += mass;
	};
}
wl_func Distributed::wl(CChar& c)
{
	return [&](int mass) -> void {
		mass /= 4;
		c.body["boobs"] -= mass;
		c.body["midsection"] -= mass;
		c.body["thighs"] -= mass;
		c.body["hips"] -= mass;
	};
}

wg_func BottomHeavy::wg(CChar& c)
{
	return [&](int mass) -> void {
		mass /= 2;
		c.body["hips"] += mass; 
		c.body["thighs"] += mass;
	};
}
wl_func BottomHeavy::wl(CChar& c)
{
	return [&](int mass) -> void {
		mass /= 2;
		c.body["hips"] -= mass; 
		c.body["thighs"] -= mass;
	};
}

wg_func CustomWeightChange::wg(CChar& c, Body distrib) {
	return [&](int mass) -> void {
		c.body["boobs"] += mass * distrib["boobs"];
		c.body["belly"] += mass * distrib["belly"];
		c.body["thighs"] += mass * distrib["thighs"];
		c.body["hips"] += mass * distrib["hips"];
	};
}
wl_func CustomWeightChange::wl(CChar& c, Body distrib) {
	return [&](int mass) -> void {
		c.body["boobs"] -= mass * distrib["boobs"];
		c.body["belly"] -= mass * distrib["belly"];
		c.body["thighs"] -= mass * distrib["thighs"];
		c.body["hips"] -= mass * distrib["hips"]; 
	};
}
