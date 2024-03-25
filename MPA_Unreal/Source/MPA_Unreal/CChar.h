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
using ex_func = function<void(int)>;
using std::istringstream;
using std::getline;

/******  CChar Class  ******
 * keeps track of character information
 * 
 ***********  DATA  ***********
 *  - name: -------- the character's first name
 *  - fname: ------- the character's full name
 *  - nameParts: --- a vector containing all parts of the character's name 
 *  - knowledge: --- a vector of strings describing all information the character has learned
 *  - precedents: -- a vector of strings describing precedents that have been set for this character
 *  - knownQuirks: - a vector of quirks that the character knows about (including the quirk's owner)
 *  - inventory: --- a vector of strings describing various items in the character's posession
 *  - boobs -------- the character's boob size
 *  - butt --------- the character's butt size
 *  - fit ---------- the character's level of muscle mass
 *  - fat ---------- the amount of overall body fat the character has
 *  - sex ---------- male (true) or female (false)
 *  - rels --------- the character's relationship levels with other characters
 * 
 ***********  Methods  ***********
 *  - processName: ---- takes a string containing the character's full name, and uses it to fill all
 *  					name-related fields
 *
 *  - bodyChange: ----- takes a map of body change pairs (string describing body part + int describing 
 *						amount of change) and applies those changes
 *
 *  - learn: ---------- takes a string representing a piece of information, and checks if the character
 *						knows that information. If the character does not know it, it is added to the 
 *						knowledge vector. 
 *						Returns a bool describing whether the character already knew the thing.
 * 
 *  - knows: ---------- takes a string representing a piece of information, and checks if the character
 *						knows that information. Returns a bool describing whether the character already 
 *						knew the thing.
 * 
 *  - quirk: ---------- if a string parameter is provided, it will check if the character has a quirk 
 *						matching said string, and return that quirk if found. Otherwise, it will return 
 *						the character's primary quirk (quirks[0])
 * 
 * - gain: ------------ the character's weight gain function
 * 
 * - burn: ------------ the character's weight loss function
 * 
 * - musc: ------------ the character's exercise function (builds muscle)
 * 
 * 
 ***********  Constructors  ***********
 * - default
 * - name + sex + quirk + body info + weight gain function + weight loss function
 * - name + sex + quirks + body info + weight gain function + weight loss function
 * 
 ***********  Operators  ***********
 *	Char == string:		returns true if the string matches the character's name and false otherwise
 *	Char + Quirk:		adds a quirk to the character's list of quirks
 *	Char += int:		increases the character's weight by the given value
 *	Char -= int:		decreases the character's weight by the given value
 *	Char++:				increments the character's weight
 *	Char--:				decrements the character's weight
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
	Mind inventory;

	// Attributes
	vector<Quirk> quirks; 
	int boobs = 0;
	int butt = 0;
	int fit = 0;
	int fat = 0;
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
	Quirk quirk(string s = ""); 
	wg_func gain;
	wl_func burn;
	ex_func musc;

	// Constructors
	CChar() = default;
	CChar(string, bool, Quirk, map<string, int>, wg_func, wl_func);
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



/******  Standard Weight Function Generators  ******
 *
 */
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

