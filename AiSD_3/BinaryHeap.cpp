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
    while (Heap[i]<Heap[(i-1)/2])
    {
        ToSwap = Heap[(i - 1) / 2];
        Heap[(i - 1) / 2] = Heap[i];
        Heap[i] = ToSwap;
        i = (i - 1) / 2;
    }
}

void BinaryHeap::insert(int add)
{
    if (count+1 >= Maxcount) //проверка возможности добавления
    {
        throw std::out_of_range("Array overflow");
    }
    count++;
    Heap[count - 1] = add;
    siftUp(count - 1);
}

bool BinaryHeap::contains(int find) {
    int i = 0, ToSwap;;
    while ((i < count) && (Heap[i] != find))
        i++;
    if (Heap[i] != find)
        return false; //if not found
    else
        return true;  //if found
}

void BinaryHeap::remove(int del) {
    int ToSwap,i = 0;
    while ((i < count) && (Heap[i] != del))// if contains
        i++;
    if (Heap[i] != del)
        throw std::out_of_range("Element doesn't exist"); //error
    ToSwap = Heap[count-1];
    Heap[count - 1] = Heap[i];
    Heap[i] = ToSwap;
    siftDown(i);
    count--;
}

void BinaryHeap::printHeap() {
    int maxinrow = 1;
    for (size_t i = 0; i < count; i++)
    {
        std::cout << Heap[i] << " ";
        if (i+1 == maxinrow)
        {
            std::cout << std::endl;
            maxinrow = maxinrow*2+1;
        }
    }
}

Iterator BinaryHeap::create_bft_iterator() {
    return bft_Iterator(0, Heap, count);
}

bool BinaryHeap::bft_Iterator::has_next() {
    return current >= size;
}

int BinaryHeap::bft_Iterator::next() {
    if (!has_next()) {
        throw std::out_of_range("No more elements");
    }
    int temp =Heapitr[current];
    current = current+1;
    return temp;
}

Iterator BinaryHeap::create_dft_iterator() {
    return dft_Iterator(0, Heap, count);
}

bool BinaryHeap::dft_Iterator::has_next() {
    return Stack->at(Stack->get_size()-1)==0;
}

int BinaryHeap::dft_Iterator::next() {
    if (!has_next()) {
        throw std::out_of_range("No more elements");
    }
    int temp = Heapitr[current];
    if (current*2+1 < size)
    {
        current = current * 2 + 1;
    }else{
        current = Stack->at(Stack->get_size() - 1);
        Stack->pop_back();
    }
    if ((current + 1) * 2 < size)
        Stack->push_back((current + 1) * 2);
    return temp;
}