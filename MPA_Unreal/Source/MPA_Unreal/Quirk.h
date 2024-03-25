// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::istringstream;
using std::ostringstream;


/**
 * 
 */
class MPA_UNREAL_API Quirk
{
	int stren; 
	int spd;
	
public:
	string name;

	Quirk(string n, int spdMultiplier, int strenMultiplier): name(n), spd(spdMultiplier), stren(strenMultiplier) {}



	Quirk() = default;
	~Quirk() = default;
};

