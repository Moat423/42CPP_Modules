#include "Harl.hpp"
#include <stdlib.h>

int main(int argc, char **argv)
{
	Harl harling;

	if (argc != 2)
		return (EXIT_FAILURE);
	harling.filteredComplain(argv[1]);
	return EXIT_SUCCESS;
}
