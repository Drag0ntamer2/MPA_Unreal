// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quirk.h"


using Mind = std::vector<string>;

/**
 * 
 */
class MPA_UNREAL_API CChar
{
	string fname;
	vector<string> nameParts;
	Mind knowledge;
	vector<Quirk> quirks;



public:
	// Public Data
	string name;



	// Public Methods
	bool Learn(string);
	bool Knows(string);


	// Getters
	Quirk quirk(string);

	// Constructors / Destructors
	CChar();
	~CChar();
};
