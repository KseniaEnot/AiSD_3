#include "BinaryHeap.h"
#include <stdlib.h>

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
    count++;
    if (count == Maxcount)
        realloc(Heap, sizeof(int) * count * 2);
    Maxcount = count * 2;
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
        return; //error!!!!!
    ToSwap = Heap[count-1];
    Heap[count - 1] = Heap[i];
    Heap[i] = ToSwap;
    siftDown(i);
    count--;
}