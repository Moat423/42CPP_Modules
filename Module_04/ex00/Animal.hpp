#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
  public:
    void makeSound( void );
  protected:
    std::string   name;
};

class Cat : public Animal
{
  
}

#endif //ANIMAL_HPP
