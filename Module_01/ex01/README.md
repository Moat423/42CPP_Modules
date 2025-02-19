The new thing about this in comparison to ex00 is the file zombieHorde.cpp.
But because of one consideration, I also had to change the constructor:

I learned a lot about placement new in this chapter because we had the named constructor from the previous exercise.
But using a placement new like so:

``` 
#include "Zombie.hpp"
#include <new>

Zombie* zombieHorde(int N, std::string name)
{
    // Allocating raw memory as a C pointer to chars
    char* memory = new char[N * sizeof(Zombie)];
    Zombie* horde = reinterpret_cast<Zombie*>(memory);
    
    // Use placement new to construct each Zombie with the name
    for (int i = 0; i < N; i++) {
        new (&horde[i]) Zombie(name);
    }
    
    return horde;
}
```

would mean manual deletion:

    // Manually call the destructor for each Zombie
    for (int i = 0; i < N; i++) {
        horde[i].~Zombie();
    }
    
    // Clean up the raw memory
    delete[] reinterpret_cast<char*>(horde);

and because the task explicitly states that it should allocate memory in "a single allocation", I decided against this.
I went the the classic and easy approach of creating a constructor that doesn't require name to be set
and then set the name.
