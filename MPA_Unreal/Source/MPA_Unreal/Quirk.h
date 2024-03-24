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
public:
	string name;


	Quirk();
	~Quirk();
};
