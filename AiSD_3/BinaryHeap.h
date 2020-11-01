#pragma once
#include "Iterator.h"
#include "dualList.h"

class BinaryHeap
{
private:
	int count;
	int Maxcount;
	int* Heap; //array for heap
    
public:
	BinaryHeap(int* Heap=nullptr, int Maxcount = 10000, int count = 0) {
		this->count = count;
		this->Maxcount = Maxcount;
		this->Heap = new int[Maxcount];
    };

    void siftDown(int);
	void siftUp(int);
	bool contains(int); // ����� �������� � ������ �� �����
	void insert(int); // ���������� �������� � ������ �� �����
	void remove(int); // �������� �������� ������ �� �����
	void printHeap();
	Iterator create_dft_iterator(); // �������� ���������, ������������ ���� �� ������� ������ � ������� (depth-first traverse)
	Iterator create_bft_iterator(); // �������� ���������, ������������ ������ ������ � ������ (breadth-first traverse)

	class dft_Iterator : public Iterator // depth-first traverse
	{
	public:
		dft_Iterator(int start, int max) {
			size = max;
			current = start;
			Stack->push_back(start);
			if ((current + 1) * 2 < size)
				Stack->push_back((current + 1) * 2);
		};
		int next();
		bool has_next();

	private:
		dualList* Stack = new dualList();\
		int current;
		int size;
	};


	class bft_Iterator : public Iterator //breadth-first traverse
	{
		public:
			bft_Iterator(int start,int max) {
				current = start;
				size = max;
			};
			int next();
			bool has_next();

		private:
			int current;
			int size;
	};

	~BinaryHeap() {
		delete Heap; //Error!
	};
};

