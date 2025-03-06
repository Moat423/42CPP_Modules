#include <iostream>

int	makenum( void);
void	changeNum( int *zahlPointer );

int	main( void ) 
{
	int zahl = 9;
	int* zahlPointer = &zahl;

	std::cout << "zahl: " << zahl << std::endl;
	std::cout << "zahlpointer: " << zahlPointer << std::endl;
	changeNum(&zahl);
	std::cout << "zahl: " << zahl << std::endl;
	return (0);
}

void	changeNum( int *zahlPointer )
{
	*zahlPointer = 0;
}
