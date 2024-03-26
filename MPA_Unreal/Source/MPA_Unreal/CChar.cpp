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
void CChar::processKwargs(kwargs body)
{
	for (pair<string, float> s : body) {
		if (s.first == "boobs") boobs = s.second;
		if (s.first == "butt") butt = s.second;
		if (s.first == "fit") fit = s.second;
		if (s.first == "fat") fat = s.second;
	}
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

	float digestionAmount = time * digestionRate;
	float absorptionAmount = time * absorptionRate;
	float absorbedMass = 0;
	for (Prey prey : stomach) {
		if (!prey.liquified) {
			stomachFillLevel -= digestionAmount;
			prey.digest(digestionAmount);

		}
			

	}



	return false;
}


// Constructors
CChar::CChar(string n, bool s, Quirk q, wg_func wg, wl_func wl, kwargs body)
{
	processName(n);
	sex = s;
	quirks = { q };
	processKwargs(body);
	gain = wg;
	burn = wl;
} 
CChar::CChar(string n, bool s, Quirks qs, wg_func wg, wl_func wl, kwargs body)
{
	processName(n);
	sex = s;
	quirks = qs;
	for (pair<string, int> s : body) {
		if (s.first == "boobs") boobs = s.second;
		if (s.first == "butt") butt = s.second;
		if (s.first == "fit") fit = s.second;
		if (s.first == "fat") fat = s.second;
	}
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


// Weight Manipulation Operators
void CChar::operator+=(int i)
{
	gain(i);
}
void CChar::operator-=(int i)
{
	burn(i);
}
void CChar::operator++()
{
	gain(1);
}
void CChar::operator--()
{
	burn(1);
}




// Standard Weight Gain Function Generators
wg_func TopHeavy::wg(CChar& c, int scalar)
{
	return [&](int i) -> void {
		kwargs vals;
		vals["boobs"] = scalar * i;
		c.processKwargs(vals);
	};
}
wl_func TopHeavy::wl(CChar& c, int scalar)
{
	return [&](int i) -> void {
		kwargs vals;
		vals["boobs"] = scalar * i * -1;
		c.processKwargs(vals);
	};
}

wg_func Distributed::wg(CChar& c, int scalar)
{
	return [&](int i) -> void {
		kwargs vals;
		vals["boobs"] = scalar * i;
		vals["fat"] = scalar * i;
		vals["butt"] = scalar * i;
		c.processKwargs(vals);
	};
}
wg_func Distributed::wl(CChar& c, int scalar)
{
	return [&](int i) -> void {
		kwargs vals;
		vals["boobs"] = scalar * i * -1;
		vals["fat"] = scalar * i * -1;
		vals["butt"] = scalar * i * -1;
		c.processKwargs(vals);
	};
}

wg_func BottomHeavy::wg(CChar& c, int scalar)
{
	return [&](int i) -> void {
		kwargs vals;
		vals["butt"] = scalar * i;
		c.processKwargs(vals);
	};
}
wg_func BottomHeavy::wl(CChar& c, int scalar)
{
	return [&](int i) -> void {
		kwargs vals;
		vals["butt"] = scalar * i * -1;
		c.processKwargs(vals);
	};
}

Prey::Prey(CChar* c)
{
	prey = c;
	size = c->size;
}

bool Prey::digest(float& digAmt)
{
	digLevel += digAmt;

	if (digPercent() >= preyDeath) alive = false;

	if (digLevel > size) {
		digAmt = digLevel - size;
		digLevel = size;
	}

	if (digLevel == size) liquified = true; 

	return liquified;
}

bool Prey::absorb(float&)
{
	return false;
}
