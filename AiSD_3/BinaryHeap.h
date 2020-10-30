#pragma once
#include <iostream>
#include <stdlib.h>

class BinaryHeap
{
private:
	int count;
	int Maxcount;
	int* Heap; //array for heap
    
public:
	BinaryHeap(int* Heap, int Maxcount = 1, int count = 0) {
		this->count = count;
		this->Maxcount = Maxcount;
		this->Heap = (int*)malloc(sizeof(int)*Maxcount);
    };

    void siftDown(int);
	void siftUp(int);
	bool contains(int); // поиск элемента в дереве по ключу
	void insert(int); // добавление элемента в дерево по ключу
	void remove(int); // удаление элемента дерева по ключу
	//Iterator create_dft_iterator(); // создание итератора, реализующего один из методов обхода в глубину (depth-first traverse)
	//Iterator create_bft_iterator() // создание итератора, реализующего методы обхода в ширину (breadth-first traverse)
	//ВЫВОДИТЬ КУЧУ ПОЛОСОЧКАМИ!

	~BinaryHeap() {
		delete Heap;
	};
};

