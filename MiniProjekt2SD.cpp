#include <iostream>
#include "ArrayPriorityQueue.h"

int main()
{
	ArrayPriorityQueue a;
	a.insert(1, 1);
	a.insert(12, 2);
	a.insert(13, 2);
	a.insert(15, 4);
	a.show();
	a.changePriority(15, 1);
	std::cout << std::endl;
	a.show();
	
}