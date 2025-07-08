/*takes 3 parameters and returns nothing.
• first parameter is the address of an array.
• second one is the length of the array.
• third one is a function that will be called on every element of the array.
*/
template <typename T, typename Func>
void	iter(T *array, unsigned int length, Func func)
{
	for (unsigned int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}
