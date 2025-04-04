#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>

class Animal
{
  public:
    void make_sound( void );
  protected:
    std::string   name;
};

#endif //ANIMAL_HPP
