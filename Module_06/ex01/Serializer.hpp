#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include <string>

typedef struct Data
{
	std::string animal;
	unsigned int numberOfFeet;
} Data;


class Serializer {
	public:
		~Serializer();
		Serializer(const Serializer &copy);
		Serializer& operator=(const Serializer &assign);
		// takes a pointer and converts it to the unsigned integer type uintptr_t.
		static uintptr_t serialize(Data* ptr);
		// takes an unsigned integer parameter and converts it to a pointer to Data.
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
};

#endif // !SERIALIZER_HPP
