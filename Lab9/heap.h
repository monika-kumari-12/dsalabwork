#ifndef HEAP_H_

#define HEAP_H_

template <class ItemType>

class Heap

{

private:
    ItemType *heapAry;

    int heapSize;

    int count;

    //function pointer compare : 0 means equal, 1 means left > right, -1 means left < right

    void _reHeapUp(int lastndx, int compare(ItemType &, ItemType &));

    void _reHeapDown(int rootndx, int compare(ItemType &, ItemType &));

    int _findParent(int index) { return (index <= 0) ? (-1) : (index - 1) / 2; }

    int _findLeftChild(int index) { return (2 * index + 1 > count) ? (-1) : (2 * index + 1); }

    int _findRightChild(int index) { return (2 * index + 2 > count) ? (-1) : (2 * index + 2); }

public:
    Heap()
    {
        count = 0;
        heapSize = 128;
        heapAry = new ItemType[heapSize];
    }

    Heap(int n)
    {
        count = 0;
        heapSize = n;
        heapAry = new ItemType[heapSize];
    }

    ~Heap() { delete[] heapAry; }

    int getCount() const { return count; }

    int getSize() const { return heapSize; }

    bool isEmpty() const { return count == 0; }

    bool isFull() const { return count == heapSize; }

    bool insertHeap(ItemType &itemIn, int compare(ItemType &, ItemType &));

    bool deleteHeap(ItemType &itemOut, int compare(ItemType &, ItemType &));
};

/**~*~*

 The private member function _reHeapUp rearranges the heap after insert by moving the 

 last item up to the correct location in the heap

 *~**/

template <class ItemType>

void Heap<ItemType>::_reHeapUp(int lastndx, int compare(ItemType &, ItemType &))

{

    if (lastndx)

    {

        int parent = findParent(lastndx);

        // finish writing this recursive function
    }
}

/**~*~*

 The private member function _reHeapDown rearranges the heap after delete by moving the

 data in the root down to the correct location in the heap

 *~**/

template <class ItemType>

void Heap<ItemType>::_reHeapDown(int rootdex, int compare(ItemType &, ItemType &))

{

    int left = findLeftChild(rootdex);

    // finish writing this recursive function
}

/**~*~*

 The public member function insertHeap inserts a new item into a heap. 

 It calls _reheapUp.

 *~**/

template <class ItemType>

bool Heap<ItemType>::insertHeap(ItemType &newItem, int compare(ItemType &, ItemType &))

{

    // finish writing this function

    return true;
}

/**~*~*

 The public member function deleteHeap deletes the root of the heap and

 passes back the root's data. It calls _reheapDown.

 *~**/

template <class ItemType>

bool Heap<ItemType>::deleteHeap(ItemType &returnItem, int compare(ItemType &, ItemType &))

{

    // finish writing this function

    return true;
}

#endif // HEAP_H_