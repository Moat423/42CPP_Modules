
#include "Debug.hpp"
#include "Data.hpp"
#include "Serializer.hpp"
#include <cstdint>
#include <iostream>

int main (int argc, char *argv[])
{
	Data *mizi = new Data("cat", 4);
	Data ralf("T-Rex", 2);

	std::cout << "Testing serialization and deserialization" << std::endl;
	std::cout << BLUE << "Original Data:" << RESET << std::endl;
	std::cout << "Data at: " << mizi << " :" << std::endl
		<< mizi->getAnimal() << " has " << mizi->getNumberOfFeet() << " feet." << std::endl;
	std::cout << "Data at: " << &ralf << " :"<< std::endl
		<< ralf.getAnimal() << " has " << ralf.getNumberOfFeet() << " feet." << std::endl;

	std::cout << BLUE << "Serializing Data..." << RESET << std::endl;
	uintptr_t addressOfMizi = Serializer::serialize(mizi);
	uintptr_t addressOfRalf = Serializer::serialize(&ralf);
	std::cout << "Serialized address of mizi: " << addressOfMizi << std::endl;
	std::cout << "Serialized address of ralf: " << addressOfRalf << std::endl;

	std::cout << BLUE << "Deserializing Data..." << RESET << std::endl;
	Data *deserializedMizi = Serializer::deserialize(addressOfMizi);
	Data *deserializedRalf = Serializer::deserialize(addressOfRalf);
	std::cout << BLUE << "Data after Deserialization:" << RESET << std::endl;
	std::cout << "Data at: " << deserializedMizi << " :" << std::endl
		<< deserializedMizi->getAnimal() << " has " << deserializedMizi->getNumberOfFeet() << " feet." << std::endl;
	std::cout << "Data at: " << deserializedRalf << " :"<< std::endl
		<< deserializedRalf->getAnimal() << " has " << deserializedRalf->getNumberOfFeet() << " feet." << std::endl;
	delete mizi;
	return (0);
}
