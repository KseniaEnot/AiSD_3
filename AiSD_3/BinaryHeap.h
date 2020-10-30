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
	bool contains(int); // ����� �������� � ������ �� �����
	void insert(int); // ���������� �������� � ������ �� �����
	void remove(int); // �������� �������� ������ �� �����
	//Iterator create_dft_iterator(); // �������� ���������, ������������ ���� �� ������� ������ � ������� (depth-first traverse)
	//Iterator create_bft_iterator() // �������� ���������, ������������ ������ ������ � ������ (breadth-first traverse)
	//�������� ���� �����������!

	~BinaryHeap() {
		delete Heap;
	};
};

