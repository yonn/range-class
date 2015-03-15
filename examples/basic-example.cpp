#include <iostream>

#include "Range.c"

int main()
{
	for (int i : Range(0, 10)) {
		std::cout << i << std::endl;
	}
	
	return 0;
	
}