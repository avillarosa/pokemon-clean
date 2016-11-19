#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
#include <list>

enum class element {
    fire = 0, water = 1, grass = 2, normal = 3, dragon = 4
};

struct PokeEntry {
	int number;
	std::string name;
	std::string description;
	std::string type;
	PokeEntry(){};
	PokeEntry(int n) {};
};


class Pokemon {
private:
	std::string name;
	int level = 1;
	int id;
	PokeEntry *pEntry;
protected:
	int maxHP = 20;
	int currentHP = maxHP;
	int speed = 10;
	int attack = 10;
	int defense = 10;
	int specialAttack = 10;
	int specialDefense = 10;
	std::list<element> weaknesses;

public:
	Pokemon(int i) { pEntry = new PokeEntry; pEntry->number = i; }
	~Pokemon() {}
	std::string get_name() {
		return name;
	}
	int get_level() {
		return level;
	}
	int get_maxHP() {
		return maxHP;
	}
	int get_currentHP() {
		return currentHP;
	}
	std::string get_species() {
		return pEntry->name;
	}

	int take_damage(int damageAmount, std::list<element> damageTypes);

	friend Pokemon* make_pokemon(int);

	friend std::ostream &operator << (std::ostream &output, Pokemon &poke);

	void write();

	// abstract functions attack1 and attack2
	virtual int attack1(Pokemon *pokePtr) = 0;
	virtual int attack2(Pokemon *pokePtr) = 0;

};

class Fire: public Pokemon {
public:
	Fire(int index);
};

class Water: public Pokemon {
public:
	Water(int index);
	int attack1(Pokemon *pokePtr);
};

class Grass: public Pokemon {
public:
	Grass(int index);
};


// species classes for water
class Squirtle: public Water {
public:
	Squirtle(std::string);
	int attack2(Pokemon *pokePtr);
};

class Wartortle: public Water {
public:
	Wartortle(std::string);
	int attack2(Pokemon *pokePtr);

};

class Blastoise: public Water {
public:
	Blastoise(std::string);
	int attack1(Pokemon *pokePtr);
	int attack2(Pokemon *pokePtr);
};


#endif // POKEMON_H
