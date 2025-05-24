#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
class Brain
{
	public:
		Brain();
		~Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &assignment);
		void setIdea(const size_t index, const std::string idea);
		std::string getIdea(const size_t index) const;
		void printIdeas( void ) const;
	private:
		std::string _ideas[100];
};

#endif // !BRAIN_HPP
