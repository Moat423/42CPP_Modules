#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#ifndef DEBUG_HPP
# define DEBUG_HPP

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YEL "\033[33m"
# define BLUE "\033[34m"
# define MAG "\033[35m"    // Magenta
# define CYN "\033[36m"    // Cyan
# define WHT "\033[37m"    // White
# define BRED "\033[1;31m" // Bold Red
# define RESET "\033[0m"
# define BOLD "\033[1m"

# ifdef DEBUG
# include <iostream>
# include <sstream>

# define debug(msg) \
	std::cerr << YEL << __FILE__ << ":" << __LINE__ << " " << msg << RESET << std::endl;
# else
# define debug(msg) (void(0))
# endif

#endif // !DEBUG_HPP

#include <deque>
#include <stack>

template < class Type, class Container = std::deque<Type> >
class MutantStack: public std::stack<Type, Container>
{
	public:
		//Typedefs
		typedef typename Container::size_type size_type;
		typedef typename Container::value_type value_type;
		typedef Container container_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;

		explicit MutantStack(const container_type& rhs = container_type());
		virtual ~MutantStack();
		MutantStack(const MutantStack& rhs);
		MutantStack& operator=( const MutantStack& rhs );
	
		//iterators
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		container_type &getContainer();
};

template < class Type, class Container >
MutantStack<Type, Container>::~MutantStack()
{
	this->c.clear();
}

template < class Type, class Container >
MutantStack<Type, Container>::MutantStack(const container_type& rhs)
	: std::stack<Type, Container>(rhs) {}

template < class Type, class Container >
MutantStack<Type, Container> &MutantStack<Type, Container>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
	{
		this->c = rhs->c;
	}
	return (*this);
}

template < class Type, class Container >
typename MutantStack<Type, Container>::container_type &MutantStack<Type, Container>::getContainer()
{
	return (this->c);
}


/*==============================Member Functions==============================*/
/*==============================iterators==============================*/

template < class Type, class Container >
typename MutantStack<Type, Container>::iterator	MutantStack<Type, Container>::begin()
{
	return (this->c.begin());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::const_iterator MutantStack<Type, Container>::begin() const
{
	return (this->c.begin());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::iterator MutantStack<Type, Container>::end()
{
	return (this->c.end());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::const_iterator MutantStack<Type, Container>::end() const
{
	return (this->c.end());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::reverse_iterator MutantStack<Type, Container>::rbegin()
{
	return (this->c.rbegin());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::const_reverse_iterator MutantStack<Type, Container>::rbegin() const
{
	return (this->c.rbegin());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::reverse_iterator MutantStack<Type, Container>::rend()
{
	return (this->c.rend());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::const_reverse_iterator MutantStack<Type, Container>::rend() const
{
	return (this->c.rend());
}

/*==============================Non-Member Functions belonging to the MutantStack class==============================*/

template < class Type, class Container >
bool operator==( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (lhs.getContainer() == rhs.getContainer());
}

template < class Type, class Container >
bool operator!=( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (!(lhs == rhs));
}

template< class Type, class Container >
bool operator< ( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (lhs.getContainer() < rhs.getContainer());
}

template< class Type, class Container >
bool operator<=( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (lhs.getContainer() <= rhs.getContainer());
}

template< class Type, class Container >
bool operator> ( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (lhs.getContainer() > rhs.getContainer());
}

template< class Type, class Container >
bool operator>=( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (lhs.getContainer() >= rhs.getContainer());
}

#endif // !MUTANTSTACK_HPP
