#include "pokemon.h"

Fire::Fire(int index) : Pokemon(index){
	maxHP+=1; speed+=2;
	attack+=2; defense-=2;
	specialAttack+=4; specialDefense+=1;
}

Water::Water(int index) : Pokemon(index){
	maxHP+=2; speed-=1;
	attack-=2; defense+=2;
	specialAttack-=4; specialDefense-=1;
}

Grass::Grass(int index) : Pokemon(index){
	maxHP-=3; speed-=2;
	attack-=2; defense+=0;
	specialAttack-=3; specialDefense+=0;
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

	PokeEntry &pEntry;

	output << "<pokemon>\n";
	output << "  <id> " << poke.id << " </id>\n";
	output << "  <name> " << poke.name << " </id>\n";
	output << "  <attack> " << poke.attack << " </attack>\n";
	output << "  <defense> " << poke.defense << " </defense>\n";
	output << "  <entry>\n";
	output << "    <number> " << pEntry.number << " </number>\n";
	output << "    <name> " << pEntry.name << " </name>\n";
	output << "  </entry>\n";
	output << "</pokemon>";

	return output;
}

void Pokemon::write(){

	Pokemon pokeData;

	std::ofstream saveFile;
	saveFile.open(this->id + ".dat");

	saveFile << pokeData;

	saveFile.close();

}
