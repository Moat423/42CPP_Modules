calling a member function:
(this->*MembFunctions[i]) ();

Remember that one can always call a function from within another member function by using the this pointer.
That means, at no point should one create an instance of the class inside a member function of this class, if i ever see that, i should remember this.
