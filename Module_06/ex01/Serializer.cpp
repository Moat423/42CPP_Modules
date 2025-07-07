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


uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
