// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CChar.h"


class CChar;

/******  Prey Class  ******
 * keeps track of a person who is inside of a stomach
 ***********  DATA  ***********
 *  - prey: -------------- a pointer to the CChar of the prey in question
 *  - digLevel: ---------- how much this prey has been digested
 *  - absLevel: ---------- how much this prey has been absorbed
 *  - alive: ------------- is this character still alive
 *  - size: -------------- how much space the prey currently takes up (defaults to the character's size)
 ***********  Methods  ***********
 *  - digPercent(): ------ returns the digestioin level divided by the prey's size
 *  - operator CChar&(): - typecast to return the prey's CChar object
 *  - Prey(CChar*): ------ construct a prey object from a CChar
 *  - digest(int): ------- increases digestion level by an ammount and returns whether digestion is complete
 *  - absorb(int): ------- increases absorption level by an ammount and returns whether absorption is complete
 */
class MPA_UNREAL_API Prey
{
public:
	CChar* prey;
	float digLevel = 0;
	float absLevel = 0;
	bool alive = true;
	bool liquified = false;
	float size;
	inline float digPercent() { return (digLevel / prey->size) * 100.0f; }
	inline operator CChar& () { return *prey; }
	Prey(CChar*);
	bool digest(float&);
	bool absorb(float&);
	inline operator string() {
		CChar p = *prey;
		return (string)p;
	}
	inline bool operator==(string s)
	{
		return *prey == s;
	}
	~Prey() = default;
};