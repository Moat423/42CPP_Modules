#include "Debug.hpp"
#include "Serializer.hpp"
#include <ios>
#include <iostream>

int main ( void )
{
	Data *mizi = new Data;
	mizi->animal = "Mizi";
	mizi->numberOfFeet = 4;
	Data ralf;
	ralf.animal = "T-Rect";
	ralf.numberOfFeet = 2;

	std::cout << "Testing serialization and deserialization" << std::endl;
	std::cout << BLUE << "Original Data:" << RESET << std::endl;
	std::cout << "Data at: " << mizi << " :" << std::endl
		<< mizi->animal << " has " << mizi->numberOfFeet << " feet." << std::endl;
	std::cout << "Data at: " << &ralf << " :"<< std::endl
		<< ralf.animal << " has " << ralf.numberOfFeet << " feet." << std::endl;

	std::cout << BLUE << "Serializing Data..." << RESET << std::endl;
	uintptr_t addressOfMizi = Serializer::serialize(mizi);
	uintptr_t addressOfRalf = Serializer::serialize(&ralf);
	std::cout << "Serialized address of mizi: " << addressOfMizi << std::endl;
	std::cout << "same in Hex: " << std::showbase << std::hex << addressOfMizi << std::dec << std::endl;
	std::cout << "Serialized address of ralf: " << addressOfRalf << std::endl;
	std::cout << "same in Hex: " << std::showbase << std::hex << addressOfRalf << std::dec << std::endl;

	std::cout << BLUE << "Deserializing Data..." << RESET << std::endl;
	Data *deserializedMizi = Serializer::deserialize(addressOfMizi);
	Data *deserializedRalf = Serializer::deserialize(addressOfRalf);
	std::cout << BLUE << "Data after Deserialization:" << RESET << std::endl;
	std::cout << "Data at: " << deserializedMizi << " :" << std::endl
		<< deserializedMizi->animal << " has " << deserializedMizi->numberOfFeet << " feet." << std::endl;
	std::cout << "Data at: " << deserializedRalf << " :"<< std::endl
		<< deserializedRalf->animal << " has " << deserializedRalf->numberOfFeet << " feet." << std::endl;
	if (deserializedMizi == mizi && deserializedRalf == &ralf)
		std::cout << GREEN << "Deserialization successful, pointers match!" << RESET << std::endl;
	else
		std::cout << RED << "Deserialization failed, pointers do not match!" << RESET << std::endl;
	delete mizi;
	return (0);
}
