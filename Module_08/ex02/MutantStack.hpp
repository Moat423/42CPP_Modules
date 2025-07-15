#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

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
	
		bool					empty() const;
		void					pop();
		void					push(const Type &value);
		size_type				size() const;
		reference				top();
		const_reference			top() const;
		//iterators
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;
	private:
		Container _container;
};

template < class Type, class Container >
MutantStack<Type, Container>::~MutantStack()
{
	_container.clear();
}

template < class Type, class Container >
MutantStack<Type, Container>::MutantStack(const container_type& rhs)
	: _container(rhs) {}

template < class Type, class Container >
MutantStack<Type, Container> &MutantStack<Type, Container>::operator=(const MutantStack& rhs)
{
	if (this != &rhs)
	{
		_container = rhs._container;
	}
	return (*this);
}

/*==============================Member Functions==============================*/

template < class Type, class Container >
bool	MutantStack<Type, Container>::empty() const
{
	return (_container.empty());
}

template < class Type, class Container >
void	MutantStack<Type, Container>::pop()
{
	_container.pop_back();
}

template < class Type, class Container >
void MutantStack<Type, Container>::push(const Type& value)
{
	_container.push_back();
}

template < class Type, class Container >
typename Container::size_type MutantStack<Type, Container>::size() const
{
	return (_container.size());
}

template < class Type, class Container >
typename Container::const_reference MutantStack<Type, Container>::top() const
{
	return (_container.back());
}

template < class Type, class Container >
typename Container::reference MutantStack<Type, Container>::top()
{
	return (_container.back());
}

/*==============================iterators==============================*/

template < class Type, class Container >
typename MutantStack<Type, Container>::iterator	MutantStack<Type, Container>::begin()
{
	return (_container.begin());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::const_iterator MutantStack<Type, Container>::begin() const
{
	return (_container.begin());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::iterator MutantStack<Type, Container>::end()
{
	return (_container.end());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::const_iterator MutantStack<Type, Container>::end() const
{
	return (_container.end());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::reverse_iterator MutantStack<Type, Container>::rbegin()
{
	return (_container.rbegin());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::const_reverse_iterator MutantStack<Type, Container>::rbegin() const
{
	return (_container.rbegin());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::reverse_iterator MutantStack<Type, Container>::rend()
{
	return (_container.rend());
}

template < class Type, class Container >
typename MutantStack<Type, Container>::const_reverse_iterator MutantStack<Type, Container>::rend() const
{
	return (_container.rend());
}

/*==============================Non-Member Functions belonging to the MutantStack class==============================*/

template < class Type, class Container >
bool operator==( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (lhs._container == rhs._container);
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
	return (lhs._container < rhs._container);
}

template< class Type, class Container >
bool operator<=( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (lhs._container <= rhs._container);
}

template< class Type, class Container >
bool operator> ( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (lhs._container > rhs._container);
}

template< class Type, class Container >
bool operator>=( const MutantStack<Type, Container>& lhs,
                 const MutantStack<Type, Container>& rhs )
{
	return (lhs._container >= rhs._container);
}

#endif // !MUTANTSTACK_HPP
