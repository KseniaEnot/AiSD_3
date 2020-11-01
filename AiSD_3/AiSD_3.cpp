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
	std::cout <<"BFT:"<< std::endl;
	Iterator* h_bft_iterator = h.create_bft_iterator();
	while (h_bft_iterator->has_next())
	{
		std::cout << h_bft_iterator->next() << " ";
	}
	std::cout << std::endl;
	std::cout << "DFT:" << std::endl;
	Iterator* h_dft_iterator = h.create_dft_iterator();
	while (h_dft_iterator->has_next())
	{
		std::cout << h_dft_iterator->next() << " ";
	}
}

