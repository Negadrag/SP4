#ifndef CHARACTER_H
#define CHARACTER_H

#include "Weapon.h"
#include "Armor.h"
#include "MyMath.h"
#include "Mesh.h"
#include "Vector2.h"
#include <string>
#include <vector>

using std::string;

class Character
{
public:
	Character(); // Hp always default to 100
	virtual ~Character();
	void takeDamage(int dmg);
	virtual bool attack(Character* opponent) = 0; // returns true if the attack was successful
	virtual void equipWeapon(Weapon* newWeapon);
	virtual void equipArmor(Armor* newArmor);
	virtual void calculateStats();

	int getSTR();
	int getDEX();
	int getLUK();
	int getDamage();
	int getHP();
	Mesh* get3DMesh();
	Mesh* get2DMesh();
	Mesh* getPortrait();
	Vector2 getPos();
	Weapon* getWeapon();
	Armor* getArmor();
	string getName();

	void setSTR(int newSTR);
	void setDEX(int newDEX);
	void setLUK(int newLUK);
	void setDamage(int newDamage);
	void setHP(int newHP);
	void set3DMesh(Mesh* newMesh);
	void set2DMesh(Mesh* newMesh);
	void setPortrait(Mesh* newMesh);
	void setPos(Vector2 newPos);

	int i_movementCost;
	int i_stepsTaken;
	int i_idInParty;
	bool b_inParty; // If this unit is in the party
	int i_attackRange; // Range of attack of this character
	bool b_tookAction; // If the unit has already moved/attacked this turn
protected:
	Weapon* weapon;
	Armor* armor;
	int i_HP; // max HP
	int i_currentHP;
	int i_Damage;
	Vector2 pos;
	// Stats
	int i_STR; // Determines the unit's attack power
	int i_DEX; // Determines the accuracy of the attacks of this unit
	int i_LUK; // Determines the avoidability of this unit
	string s_Name; // Name of this unit
	Mesh* character3DMesh; // For battle uses
	Mesh* character2DMesh; // For rendering on the tilemap
	Mesh* characterPortrait; // For rendering on the status screen
};

typedef std::vector<Character*> CharactersList;

#endif CHARACTER_H
