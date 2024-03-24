// Fill out your copyright notice in the Description page of Project Settings.


#include "CChar.h"

bool CChar::Learn(string)
{
	return false;
}

bool CChar::Knows(string)
{
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

CChar::~CChar()
{
}
