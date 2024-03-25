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


CChar::CChar()
{
}

CChar::CChar(string n, bool s, Quirk q, map<string, int> body)
{
	processName(n);
	sex = s;
	for (pair<string, int> s : body) {
		if (s.first == "boobs") boobs = s.second; 
		if (s.first == "butt") butt = s.second; 
		if (s.first == "fit") fit = s.second;
		if (s.first == "fat") fat = s.second;
	}
}

CChar::~CChar()
{
}

bool CChar::operator==(string Name) 
{
	return Name == name || Name == fname;
}
