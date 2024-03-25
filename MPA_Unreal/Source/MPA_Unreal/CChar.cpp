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
Quirk CChar::quirk(string s = "")
{
	if (s == "")
		return quirks[0];
	else {
		for (Quirk q : quirks) {
			if (q.name == s)
				return q;
		}
		return Quirk();
	}
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
void CChar::bodyChange(map<string, int> body)
{
	for (pair<string, int> s : body) {
		if (s.first == "boobs") boobs = s.second;
		if (s.first == "butt") butt = s.second;
		if (s.first == "fit") fit = s.second;
		if (s.first == "fat") fat = s.second;
	}
}


// Constructors
CChar::CChar(string n, bool s, Quirk q, map<string, int> body, wg_func wg, wl_func wl)
{
	processName(n);
	sex = s;
	quirks = { q };
	for (pair<string, int> s : body) {
		if (s.first == "boobs") boobs = s.second; 
		if (s.first == "butt") butt = s.second; 
		if (s.first == "fit") fit = s.second;
		if (s.first == "fat") fat = s.second;
	}
	gain = wg;
	burn = wl;
}
CChar::CChar(string n, bool s, vector<Quirk> qs, map<string, int> body, wg_func wg, wl_func wl)
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
		map<string, int> vals;
		vals["boobs"] = scalar * i;
		c.bodyChange(vals);
	};
}
wl_func TopHeavy::wl(CChar& c, int scalar)
{
	return [&](int i) -> void {
		map<string, int> vals;
		vals["boobs"] = scalar * i * -1;
		c.bodyChange(vals);
	};
}

wg_func Distributed::wg(CChar& c, int scalar)
{
	return [&](int i) -> void {
		map<string, int> vals;
		vals["boobs"] = scalar * i;
		vals["fat"] = scalar * i;
		vals["butt"] = scalar * i;
		c.bodyChange(vals);
	};
}
wg_func Distributed::wl(CChar& c, int scalar)
{
	return [&](int i) -> void {
		map<string, int> vals;
		vals["boobs"] = scalar * i * -1;
		vals["fat"] = scalar * i * -1;
		vals["butt"] = scalar * i * -1;
		c.bodyChange(vals);
	};
}

wg_func BottomHeavy::wg(CChar& c, int scalar)
{
	return [&](int i) -> void {
		map<string, int> vals;
		vals["butt"] = scalar * i;
		c.bodyChange(vals);
	};
}
wg_func BottomHeavy::wl(CChar& c, int scalar)
{
	return [&](int i) -> void {
		map<string, int> vals;
		vals["butt"] = scalar * i * -1;
		c.bodyChange(vals);
	};
}
