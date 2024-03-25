// Fill out your copyright notice in the Description page of Project Settings.


#include "CChar.h"

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

CChar::CChar(string n, bool s, Quirk q, map<string, int> body, wg_func wg, wl_func wl)
{
	processName(n);
	sex = s;
	for (pair<string, int> s : body) {
		if (s.first == "boobs") boobs = s.second; 
		if (s.first == "butt") butt = s.second; 
		if (s.first == "fit") fit = s.second;
		if (s.first == "fat") fat = s.second;
	}
	gain = wg;
	burn = wl;
}

bool CChar::operator==(string Name) 
{
	return Name == name || Name == fname;
}

CChar& CChar::operator+(Quirk q)
{
	quirks.push_back(q);
	return *this;
}

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

wg_func TopHeavy::wg(CChar& c, int scalar)
{
	return [&](int i) -> void {
		map<string, int> vals;
		vals["boobs"] = scalar * i;
		c.bodyChange(vals);
	};
}
