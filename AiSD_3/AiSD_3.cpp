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
	Iterator dftit = h.create_dft_iterator();
	while (!dftit.has_next())
	{
		dftit.next();
	}
}

