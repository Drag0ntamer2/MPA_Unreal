// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quirk.h"
#include <map>
#include <functional>

using Mind = std::vector<string>;
using std::map;
using std::pair;
using std::function;
using wg_func = function<void(int)>;
using wl_func = function<void(int)>;

/**
 * 
 */
class MPA_UNREAL_API CChar
{
	// Naming
	string name;
	string fname;
	vector<string> nameParts;
	
	// Inforamation
	Mind knowledge;
	Mind precedents;
	vector<Quirk> knownQuirks;
	Mind items;

	// Attributes
	vector<Quirk> quirks; 
	int boobs = 0;
	int butt = 0;
	int fit = 50;
	int fat = 50;
	bool sex = true; // male

	// relationship stats
	map<string, vector<int>> rels;

	// Private Helper Functions
	void processName(string);
	

public:
	// Setters
	void bodyChange(map<string, int>); 


	// Public Methods
	bool learn(string);
	bool knows(string); 
	wg_func gain;
	wl_func burn;
	 
	// Getters
	Quirk quirk(string);

	// Constructors
	CChar() = default;
	// name + sex + quirk + body info + weight gain function
	CChar(string, bool, Quirk, map<string, int>, wg_func, wl_func);
	// name + sex + quirks + body info + weight gain function
	CChar(string, bool, vector<Quirk>, map<string, int>, wg_func, wl_func);


	// Operator Overloads
	bool operator==(string);
	CChar& operator+(Quirk);
	void operator+=(int); // weight gain by num
	void operator-=(int); // weight loss by num
	void operator++(); // weight gain by 1
	void operator--(); // weight loss by 1

	// Destructor
	~CChar() = default;

};



// Standard Weight Function Generators
struct TopHeavy {
	wg_func wg(CChar&, int);
	wl_func wl(CChar&, int);
};
struct Distributed{
	wg_func wg(CChar&, int);
	wl_func wl(CChar&, int);
};
struct BottomHeavy{
	wg_func wg(CChar&, int);
	wl_func wl(CChar&, int);
};

