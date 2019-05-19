#include <iostream>
using namespace std;


#ifndef hw3Header
#define hw3Header

class DataItem {
    
    public:
    
        int k; // Key
    	char d; // satellite datum, assume each datum is only a char.
    
    public:
    	DataItem() {}; // HINT: implement this...    
    	DataItem( int newKey, char newData ) { // HINT: implement this...
            k = newKey;
            d = newData;
    	    
    	}
    	~DataItem(); // HINT: implement this...
};

class ArrayQueue { // Please implement a queue using an array...
    // HINT: Add some fields here...

    // HINT: implement all of these...
    void enqueue( DataItem x ); // Insert a data item to front. If the array is full, double its size.
    DataItem dequeue(); // Return a DataItem from tail. If the array is less than half-full, half its size.
    bool isEmpty(); // Determine if the queue is empty
	bool isFull();  // Determine if the queue is full
	DataItem getBack(); // Get the last data item of the queue without removing it
	int getSize(); // Return the current number of data items in the queue
	int getCapacity(); // Return the size of the array that keeps the data items (must be at least as large as the number of data items in the queue)
};

class ArrayCircularQueue { // Please implement a circular queue using an array...
    // HINT: Add some fields here...

    // HINT: implement all of these...
    void enqueue( DataItem x ); // Insert a data item to front. If the array is full, double its size.
    DataItem dequeue(); // Return a DataItem from tail. If the array is less than half-full, half its size.
    bool isEmpty(); // Determine if the queue is empty
    bool isFull();  // Determine if the queue is full
	DataItem getBack(); // Get the last data item of the queue without removing it
    int getSize(); // Return the current number of data items in the queue
    int getCapacity(); // Return the size of the array that keeps the data items (must be at least as large as the number of data items in the queue)
};

class ArrayStack { // Please implement a stack using an array...
	// HINT: Add some fields here...

	// HINT: implement all of these...
	void push(int x) { // Insert a data item to top. If the array is full, double its size.
        if (top ==  n-1)
	}
	DataItem pop(); // Return a DataItem from top. If the array is less than half-full, half its size.
	bool isEmpty(); // Determine if the stack is empty
	DataItem getTop(); // Get the last data item of the stack without removing it
	int getSize(); // Return size of the array that keeps the data items (must be at least as large as the number of data items in the stack)
};

class TwoStackQueue { // Please implement a queue using two stacks (you CANNOT access array elements directly; instead, you can only call the methods of the previous ArrayStack class)
	// HINT: Add some fields here...

	// HINT: implement all of these...
	void enqueue();
	DataItem dequeue();
	bool isEmpty();
	bool isFull();
	DataItem getBack();
	int getSize();
};

#endif


int main()
{
    cout<<"Hello World";

    return 0;
}
