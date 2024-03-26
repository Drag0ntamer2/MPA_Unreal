// Fill out your copyright notice in the Description page of Project Settings.


#include "Prey.h"

Prey::Prey(CChar* c)
{
	prey = c;
	size = c->size;
}

bool Prey::digest(float& amt)
{
	digLevel += amt;
	amt = 0;

	if (digPercent() >= preyDeath) alive = false;

	if (digLevel > size) {
		amt = digLevel - size;
		digLevel = size;
		liquified = true;
	}

	return liquified;
}

bool Prey::absorb(float& amt)
{
	absLevel += amt;
	amt = 0;

	if (absLevel > size) {
		amt = absLevel - size;
		absLevel = size;
		return true;
	}

	return false;
}
