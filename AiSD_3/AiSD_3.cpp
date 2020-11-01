#include <iostream>
#include "BinaryHeap.h"

int main()
{
    int in;
	BinaryHeap h=BinaryHeap();
	std::cin >> in;
	while (in != -1)
	{
		h.insert(in);
		std::cin >> in;
	}
	std::cout << std::endl;
	h.printHeap();
	std::cout << std::endl;
	std::cin >> in;
	h.remove(in);
	h.printHeap();
	std::cout << std::endl;
	std::cin >> in;
	h.insert(in);
	h.printHeap();
	std::cout << std::endl;
}

