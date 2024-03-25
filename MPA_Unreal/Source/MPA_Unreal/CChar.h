// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Quirk.h"
#include <map>
#include <functional>

class CChar;
struct Prey;

using Mind = std::vector<string>;
using std::map;
using std::pair;
using std::function;
using wg_func = function<void(int)>;
using wl_func = function<void(int)>;
using ex_func = function<void(int)>;
using std::istringstream;
using std::getline;
using kwargs = map<string, float>;
using Quirks = vector<Quirk>;
using Stomach = vector<Prey>;


/******  Prey Struct  ******
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
 *  - absorb(int): ------- increases absorbtion level by an ammount and returns whether absorbtion is complete
 */
struct Prey {
	CChar* prey;
	float digLevel = 0;
	float abslevel = 0;
	bool alive = true;
	float size;
	inline float digPercent() { return (digLevel / prey->size) * 100.0f; }
	inline operator CChar&() { return *prey; }
	Prey(CChar*);
	bool digest(float);
	bool absorb(float); 
};



/******  CChar Class  ******
 * keeps track of character information
 * 
 ***********  DATA  ***********
 *				   Naming
 *  - name: ------------- the character's first name
 *  - fname: ------------ the character's full name
 *  - nameParts: -------- a vector containing all parts of the character's name 
 *				Information
 *  - knowledge: -------- a vector of strings describing all information the character has learned
 *  - precedents: ------- a vector of strings describing precedents that have been set for this character
 *  - knownQuirks: ------ a vector of quirks that the character knows about (including the quirk's owner)
 *  - inventory: -------- a vector of strings describing various items in the character's posession
 *				 Attributes
 *  - boobs ------------- the character's boob size
 *  - butt -------------- the character's butt size
 *  - fit --------------- the character's level of muscle mass
 *  - fat --------------- the amount of overall body fat the character has
 *  - sex --------------- male (true) or female (false)
 *				   Vore
 *  - preySwallowed ----- The number of people this character has swallowed						(default = 0)
 *  - preyDigested ------ The number of people this character has digested						(default = 0)
 *  - peopleUnbirthed --- the number of people this character has unbirthed						(default = 0)
 *  - stomachCapacity --- how much food can fit in the character's stomach						(average = 1)
 *  - stomachFillLevel -- how much space is currently being taken up in the character's stomach (default = 0)
 *  - digestionRate ----- how quickly space in the character's stomach is freed up by digestion	(average = 1)
 *  - absorbtionRate ---- how quickly dissolved food is absorbed by the character's body		(average = 1)
 *  - size -------------- how much space this character would take up in someone else's stomach	(average = 1)
 *  - stomach ----------- a list of the prey are currently in the character's stomach
 *  - isPrey ------------ is this character either currently in a stomach, or already digested
 *			   Relationships
 *  - rels -------------- the character's relationship levels with other characters
 *  - vergin ------------ is this character a vergin (default = true)
 * 
 ***********  Methods  ***********
 * 
 * 
 *				  Helpers 
 * 
 * 
 *  - processName: ---- takes a string containing the character's full name, and uses it to fill all
 *  					name-related fields
 *
 *  - kwargs: --------- >Under Construction<
 * 
 * 
 *				Information
 * 
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
 *  - setPrec: -------- returns a bool describing whether or not a givn precedent has been set for the 
 *						character
 * 
 *  - hasPrec: -------- sets a precedent about the character, and returns a bool describing whether or
 *						not it had already been set
 *
 *	
 *				Attributes
 * 
 * 
 *  - quirk: ----------- if a string parameter is provided, it will check if the character has a quirk 
 *						 matching said string, and return that quirk if found. Otherwise, it will return 
 *						 the character's primary quirk (quirks[0])
 * 
 *	- Char + Quirk: ---- adds a quirk to the character's list of quirks
 * 
 *	- Char += int: ----- increases the character's weight by the given value
 * 
 *	- Char -= int: ----- decreases the character's weight by the given value
 * 
 *	- Char++: ---------- increments the character's weight
 * 
 *	- Char--:	-------- decrements the character's weight
 * 
 *  - gain: ------------ the character's weight gain function
 * 
 *  - burn: ------------ the character's weight loss function
 *
 *  - musc: ------------ the character's exercise function (builds muscle)
 *
 *	
 *				    Vore
 * 
 * 
 *  - swallow: --------- adds a prey to the character's stomach
 *  
 *  - churn: ----------- updates digestion and absorbtion levels of current prey by the given 
 *						 value, multiplied by the character's digestion and absorbtion rates, 
 *						 and returns whether or not all prey have been fully absorbed by the 
 *						 process
 * 
 *  - livePrey: -------- returns true if any current prey are still alive, and false otherwise
 * 
 *  - Prey typecast: --- creates a Prey object using this CChar
 * 
 *	- empty: ----------- regurgitates all living prey, removing them from the prey list.
 * 
 *  - release: --------- releases a specific prey if they are both currently in the stomach, 
 *						 and alive
 *
 *	
 *				Constructors
 * 
 * 
 *  - default
 *  - name + sex + quirk + body info + weight gain function + weight loss function
 *  - name + sex + quirks + body info + weight gain function + weight loss function
 *  - file
 *
 *	
 *			   Misc Operators  
 * 
 * 
 *  - Char == string: ---- returns true if the string matches the character's name and false otherwise
 *	
 */
class MPA_UNREAL_API CChar
{
	// Private Helper Functions
	void processName(string);
	void processKwargs(kwargs);

public:
	//*********************** DATA ***********************\\
	// Naming
	string name;
	string fname;
	vector<string> nameParts;

	// Inforamation
	Mind knowledge;
	Mind precedents;
	vector<Quirk> knownQuirks;
	Mind inventory;

	// Attribute Data
	Quirks quirks;  
	float boobs = 0;
	float butt = 0;
	float fit = 0;
	float fat = 0;
	bool sex = true; // male
	
	// Vore Data
	int preySwallowed = 0;
	int preyDigested = 0;
	float stomachCapacity = 1;
	float stomachFillLevel = 0;
	float digestionRate = 1;
	float absorbtionRate = 1;
	float size = 1;
	Stomach stomach;
	bool isPrey;

	// Relationship Data
	map<string, vector<int>> rels;
	bool vergin = true;


	//*********************** METHODS ***********************\\
	// Information Methods
	bool learn(string);
	bool knows(string);
	bool setPrec(string);
	bool hasPrec(string);

	// Attribute Methods
	Quirk quirk();
	Quirk quirk(string);
	CChar& operator+(Quirk);
	wg_func gain; 
	wl_func burn; 
	ex_func musc; 
	void operator+=(int);
	void operator-=(int);
	void operator++();
	void operator--();

	// Vore Methods
	void swallow(const CChar&);
	bool churn(int);
	bool livePrey();
	inline operator Prey();
	void empty();
	bool release(string);

	// Constructors
	CChar() = default;
	CChar(string, bool,  Quirk, wg_func, wl_func, kwargs);
	CChar(string, bool, Quirks, wg_func, wl_func, kwargs); 
	CChar(string); // file input

	// Misc Operators
	bool operator==(string);
	inline operator string() { return fname; }

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

