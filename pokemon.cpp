#include "pokemon.h"

Fire::Fire(int index) : Pokemon(index){
	maxHP+=1; speed+=2;
	attack+=2; defense-=2;
	specialAttack+=4; specialDefense+=1;
	weaknesses.push_back(element::water);
}

Water::Water(int index) : Pokemon(index){
	maxHP+=2; speed-=1;
	attack-=2; defense+=2;
	specialAttack-=4; specialDefense-=1;
	weaknesses.push_back(element::grass);
}

Grass::Grass(int index) : Pokemon(index){
	maxHP-=3; speed-=2;
	attack-=2; defense+=0;
	specialAttack-=3; specialDefense+=0;
	weaknesses.push_back(element::fire);
}

int Pokemon::take_damage(int damageAmount, std::list<element> damageTypes) {
	int weaknessCount = 0;
	for(auto wIt = weaknesses.begin(); wIt != weaknesses.end(); wIt++)
		for(auto dIt = damageTypes.begin(); dIt != damageTypes.end(); dIt++)
			if(*dIt == *wIt) weaknessCount++;

	damageAmount = damageAmount * (log(5 * weaknessCount + 5) / log(5));
	currentHP -= damageAmount;
	return damageAmount;
};

//Constructors for water species classes
Squirtle::Squirtle(std::string n, int index) : Water(index){
	this->get_name() = n;
}

Wartortle::Wartortle(std::string n, int index) : Water(index) {
	this->get_name() = n;
}

Blastoise::Blastoise(std::string n, int index) : Water(index){
	this->get_name() = n;
}

//Functions attack1 and attack2
int Water::attack1(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::water);

	int damage = pokePtr->take_damage(2, ele);

	std::cout << pokePtr->get_name() << " used Bubble. ";
	std::cout << pokePtr->get_species() << " took " << damage << " damage!\n";

	return damage;
}

int Blastoise::attack1(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::water);
	ele.push_back(element::dragon);

	int damage = pokePtr->take_damage(8, ele);

	std::cout << pokePtr->get_name() << " used Water Pledge. ";
	std::cout << pokePtr->get_species() << " took " << damage << " damage!\n";

	return damage;
}

int Squirtle::attack2(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::normal);

	int damage = pokePtr->take_damage(2, ele);

	std::cout << pokePtr->get_name() << " used Tackle. ";
	std::cout << pokePtr->get_species() << " took " << damage << " damage!\n";

	return damage;
}

int Wartortle::attack2(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::water);

	int damage = pokePtr->take_damage(4, ele);

	std::cout << pokePtr->get_name() << " used Surf. ";
	std::cout << pokePtr->get_species() << " took " << damage << " damage!\n";

	return damage;
}

int Blastoise::attack2(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::water);

	int damage = pokePtr->take_damage(6, ele);

	std::cout << pokePtr->get_name() << " used Hydro Cannon. ";
	std::cout << pokePtr->get_species() << " took " << damage << " damage!\n";

	return damage;
}

Pokemon *make_pokemon(element e, std::string n) {

	Pokemon *newPokemon;
	if(e == element::fire) {
		newPokemon = new Fire(1);
		newPokemon->name = n;
	} else if(e == element::grass) {
		newPokemon = new Grass(1);
		newPokemon->name = n;
	} else if(e == element::water) {
		newPokemon = new Water(1);
		newPokemon->name = n;
	}
	return newPokemon;

}

std::ostream &operator << (std::ostream &output, Pokemon &poke){

	output << "<pokemon>\n";
	output << "  <id> " << poke.id << " </id>\n";
	output << "  <name> " << poke.name << " </id>\n";
	output << "  <attack> " << poke.attack << " </attack>\n";
	output << "  <defense> " << poke.defense << " </defense>\n";
	output << "  <entry>\n";
	output << "    <number> " << poke.pEntry.number << " </number>\n";
	output << "    <name> " << poke.pEntry.name << " </name>\n";
	output << "  </entry>\n";
	output << "</pokemon>";

	return output;
}

void Pokemon::write(){

	std::ofstream saveFile;
	saveFile.open(this->id + ".dat");

	saveFile << this;

	saveFile.close();

}
