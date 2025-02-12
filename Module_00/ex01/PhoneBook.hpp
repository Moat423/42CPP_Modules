#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

/*#include "Contact.hpp"*/

class PhoneBook
{
	/*private:*/
		/*Contact	_contacts[8];*/
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact() const;
};

#endif // PHONEBOOK_HPP
