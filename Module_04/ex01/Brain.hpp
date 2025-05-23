#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &assignment);
};

#endif // !BRAIN_HPP
