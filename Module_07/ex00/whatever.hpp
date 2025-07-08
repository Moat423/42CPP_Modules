
//Swaps the values of two given parameters. Does not return anything.
template <typename T>
void	swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

//Compares the two values passed as parameters and returns the smallest one.
//If they are equal, it returns the second one.
template <typename T>
T	min(T x, T y)
{
	return (x < y ? x : y);
}

//Compares the two values passed as parameters and returns the greatest one.
//If they are equal, it returns the second one.
template <typename T>
T	max(T x, T y)
{
	return (x > y ? x : y);
}
