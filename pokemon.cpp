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
Squirtle::Squirtle(std::string name = "Squirtle") : Water(7){
	this->name = name;
}

Wartortle::Wartortle(std::string name = "Wartortle") : Water(8) {
	this->name = name;
}

Blastoise::Blastoise(std::string name = "Blastoise") : Water(9){
	this->name = name;
}

//Functions attack1 and attack2
int Water::attack1(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::water);

	int damageAmt = pokePtr->take_damage(2, ele);

	std::cout << pokePtr->get_name() << " used Bubble. ";
	std::cout << pokePtr->get_species() << " took " << damageAmt << " damage!\n";

	return 0;
}

int Blastoise::attack1(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::water);
	ele.push_back(element::dragon);

	int damageAmt = pokePtr->take_damage(8, ele);

	std::cout << pokePtr->get_name() << " used Water Pledge. ";
	std::cout << pokePtr->get_species() << " took " << damageAmt << " damage!\n";

	return 0;
}

int Squirtle::attack2(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::normal);

	int damageAmt = pokePtr->take_damage(2, ele);

	std::cout << pokePtr->get_name() << " used Tackle. ";
	std::cout << pokePtr->get_species() << " took " << damageAmt << " damage!\n";

	return 0;
}

int Wartortle::attack2(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::water);

	int damageAmt = pokePtr->take_damage(4, ele);

	std::cout << pokePtr->get_name() << " used Surf. ";
	std::cout << pokePtr->get_species() << " took " << damageAmt << " damage!\n";

	return 0;
}

int Blastoise::attack2(Pokemon *pokePtr){

	std::list<element> ele;
	ele.push_back(element::water);

	int damageAmt = pokePtr->take_damage(6, ele);

	std::cout << pokePtr->get_name() << " used Hydro Cannon. ";
	std::cout << pokePtr->get_species() << " took " << damageAmt << " damage!\n";

	return 0;
}

Pokemon *make_pokemon(int index) {

	Pokemon *newPokemon;

	switch (index){
	case 7: newPokemon = new Squirtle;
			break;
	case 8: newPokemon = new Wartortle;
			break;
	case 9: newPokemon = new Blastoise;
			break;
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
	output << "    <number> " << poke.pEntry->number << " </number>\n";
	output << "    <name> " << poke.pEntry->name << " </name>\n";
	output << "  </entry>\n";
	output << "</pokemon>";

	return output;
}

void Pokemon::write(){

	std::ofstream saveFile;
	saveFile.open(std::to_string(this->id) + ".dat");

	saveFile << this;

	saveFile.close();

}
