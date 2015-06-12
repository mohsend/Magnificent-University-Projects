//برنامه ای بنویسید تمام اعداد اول بین دو تا صد را چاپ کند

#include <iostream>

bool prime(int);

int main()
{
	for (int i = 2; i <= 100; i++)
		if (prime(i))
			std::cout << i << '\t';
		
	return 0;
}

bool prime(int x)
{
	for (int z = 2; z <= x/2; z++)
		if (x % z == 0)
			return false;
	return true;
}
