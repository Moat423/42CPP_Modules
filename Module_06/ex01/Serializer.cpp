#include "Serializer.hpp"

// Default Constructor
Serializer::Serializer( void ) {}

// Destructor
Serializer::~Serializer() {}

// Copy Constructor
Serializer::Serializer(const Serializer &copy) { static_cast<void>(copy); }

// Copy Assignment Operator
Serializer& Serializer::operator=( const Serializer &assign )
{
	static_cast<void>(assign);
	return *this;
}


uintptr_t serialize(Data* ptr)
{
	return (std::static_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (std::static_cast<Data*>(raw));
}
