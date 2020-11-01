#include "BinaryHeap.h"
#include <iostream>

//parent=(i - 1) / 2
//left=2 * i + 1
//right=(i + 1) * 2

void BinaryHeap::siftDown(int i) {
    int j,left,right,ToSwap;
    while ((2 * i + 1) < count) //while we can go down
    {
        left = 2 * i + 1; //left child
        right = (i + 1) * 2;  //right child
        j = left;
        if ((right < count) && (Heap[right] < Heap[left])) //find min of child
            j = right;
        if (Heap[i] <= Heap[j]) //if the minimum child is equal to the element
            break;
        ToSwap = Heap[j];
        Heap[j] = Heap[i];
        Heap[i] = ToSwap;
        i = j;
    }
}
void BinaryHeap::siftUp(int i) {
    int ToSwap;
    while (Heap[i]<Heap[(i-1)/2]) //while the parent is more
    {
        ToSwap = Heap[(i - 1) / 2];
        Heap[(i - 1) / 2] = Heap[i];
        Heap[i] = ToSwap;
        i = (i - 1) / 2; //go to parent
    }
}

void BinaryHeap::insert(int add)
{
    if (count+1 >= Maxcount) //if cann't add
    {
        throw std::out_of_range("Array overflow");
        return;
    }
    count++;
    Heap[count - 1] = add;
    siftUp(count - 1);
}

bool BinaryHeap::contains(int find) {
    int i = 0, ToSwap;;
    while ((i < count) && (Heap[i] != find)) {
        i++;
    }
    if (Heap[i] != find)
        return false; //if not found
    else
        return true;  //if found
}

void BinaryHeap::remove(int del) {
    int ToSwap,i = 0;
    while ((i < count) && (Heap[i] != del))// if contains
        i++;
    if (Heap[i] != del) {
        throw std::out_of_range("Element doesn't exist"); //error
        return;
    }
    ToSwap = Heap[count-1];
    Heap[count - 1] = Heap[i];
    Heap[i] = ToSwap;
    count--;
    siftDown(i);
}

Iterator* BinaryHeap::create_bft_iterator() {
    return new bft_Iterator(Heap,count);
}

bool BinaryHeap::bft_Iterator::has_next() {
    return Icurrent < size;
}

int BinaryHeap::bft_Iterator::next() {
    if (!has_next()) {
        throw std::out_of_range("No more elements");
    }
    int temp = current[Icurrent];
    Icurrent++;
    return temp;
}


Iterator* BinaryHeap::create_dft_iterator() {
    return new dft_Iterator(Heap, count);
}

bool BinaryHeap::dft_Iterator::has_next() {
    return (Stack->at(Stack->get_size() - 1) != 0)||((size<3)&&(Icurrent<size)&&(Icurrent>-1));
}

int BinaryHeap::dft_Iterator::next() {
    if (!has_next()) {
        throw std::out_of_range("No more elements");
    }
    int temp = current[Icurrent];
    if (size<3)
        Icurrent++;
    else{
        if ((Icurrent + 1) * 2 < size)  //add right branch
         Stack->push_back((Icurrent + 1) * 2);
        if (Icurrent*2+1 < size) //if haven't reached the end of the branch go down
     {
         Icurrent = Icurrent * 2 + 1;
        }else{  //if reach the end of the branch go right
          Icurrent = Stack->at(Stack->get_size() - 1);
         Stack->pop_back();
     }
    }
    return temp;
}