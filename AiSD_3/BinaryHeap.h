#pragma once
#include <stdlib.h>
#include "Iterator.h"
#include "dualList.h"

class BinaryHeap
{
private:
	int count;
	int Maxcount;
	int* Heap; //array for heap
    
public:
	BinaryHeap(int* Heap=nullptr, int Maxcount = 1, int count = 0) {
		this->count = count;
		this->Maxcount = Maxcount;
		this->Heap = (int*)malloc(sizeof(int)*Maxcount);
    };

    void siftDown(int);
	void siftUp(int);
	bool contains(int); // search for an element in the heap by key
	void insert(int); // add an item to the heap by key
	void remove(int); // delete an item to the heap by key
	Iterator* create_dft_iterator(); // depth-first traverse iterator
	Iterator* create_bft_iterator(); // breadth-first traverse iterator

	class dft_Iterator : public Iterator // depth-first traverse
	{
	public:
		dft_Iterator(int* start, int max) {
			Stack = new dualList();
			size = max;
			current = start;
			Icurrent = 0;
			Stack->push_back(Icurrent);
			if ((Icurrent + 1) * 2 < size) //add right branch
				Stack->push_back((Icurrent + 1) * 2);
		};
		int next();
		bool has_next();
		~dft_Iterator() {
			delete Stack;
			delete current;
		}

	private:
		dualList* Stack;
		int* current;
		int Icurrent;
		int size;
	};

	
	class bft_Iterator : public Iterator //breadth-first traverse
	{
		public:
			bft_Iterator(int* start,int max) {
				current=start;
				size = max;
				Icurrent = 0;
			};
			int next();
			bool has_next();
			~bft_Iterator() {
				delete current;
			}

		private:
			int* current;
			int Icurrent;
			int size;
	};

	~BinaryHeap() {
		free(this->Heap);
	};
};

