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
	h.printHeap();
	std::cout << std::endl;
	Iterator* h_iterator = h.create_bft_iterator();
	while (h_iterator->has_next())
	{
		std::cout << h_iterator->next() << " ";
	}
	std::cin >> in;
}

