#include <iostream>
using namespace std;


#ifndef hw3Header
#define hw3Header

class DatumItem
{
public:

    int key;		                      // Key
    char datum;			                    // satellite datum, assume each datum is only a char.

    DatumItem ()                         // constructor w/o input, using some default values 
    {				        
        key = 0;
        datum = '0';
    }
    DatumItem (int newKey, char newDatum)	// constructor w/ input
    {
        key = newKey;
        datum = newDatum;
    }
    ~DatumItem ()                        // destructor
    {
        // type 'int' argument given to 'delete', expected pointer 
        // ???
    }; 
};

class ArrayQueue
{   // Please implement a queue using an array...
    // HINT: Add some fields here...

    // HINT: implement all of these...
  void enqueue (DatumItem x);	// Insert a data item to front. If the array is full, double its size.
  DatumItem dequeue ();		    // Return a DataItem from tail. If the array is less than half-full, half its size.
  bool isEmpty ();		        // Determine if the queue is empty
  bool isFull ();		        // Determine if the queue is full
  DatumItem getBack ();		    // Get the last data item of the queue without removing it
  int getSize ();		        // Return the current number of data items in the queue
  int getCapacity ();		    // Return the size of the array that keeps the data items (must be at least as large as the number of data items in the queue)
};

class ArrayCircularQueue
{   // Please implement a circular queue using an array...
    // HINT: Add some fields here...

    // HINT: implement all of these...
    void enqueue (DatumItem x);	// Insert a data item to front. If the array is full, double its size.
    DatumItem dequeue ();		// Return a DataItem from tail. If the array is less than half-full, half its size.
    bool isEmpty ();		    // Determine if the queue is empty
    bool isFull ();		        // Determine if the queue is full
    DatumItem getBack ();		// Get the last data item of the queue without removing it
    int getSize ();		        // Return the current number of data items in the queue
    int getCapacity ();		    // Return the size of the array that keeps the data items (must be at least as large as the number of data items in the queue)
};

class ArrayStack
{   // Please implement a stack using an array...
    // HINT: Add some fields here...
public:

    int top;
    int arrayLen;
    int stack[];
    
    ArrayStack () // constructor
    { 
        int top = 0;
        arrayLen = 4;  // default array length as 8
        int *stack = new int[arrayLen] ;
        
        /* test
        for (int i = 0; i < arrayLen; i++) {
            stack[i] = 3;
        }
        
        cout << stack << endl;
        
        for (int i = 0; i < arrayLen; i++) {
            cout << stack[i]  << endl;
        } */
    };



    // HINT: implement all of these...
    void push (DatumItem datumItem)	// Insert a data item to top. 
    {
        if (top == arrayLen - 1)  // If the array is full, double its size.
        {
            cout << "Stack is full. Create and use a double-size array!" << endl;
            
            int * doubleSizeStack = new int[arrayLen * 2];
            
            cout << stack << endl;
            cout << doubleSizeStack << endl;
            
            for (int i = 0; i < arrayLen; i++)
            {
                doubleSizeStack[i] = stack[i];
            }
            arrayLen = arrayLen * 2;  // update it
            delete [] stack;             // delete the old
            stack = doubleSizeStack;    // update it  //  https://stackoverflow.com/questions/2857917/c-pointer-to-different-array
            
            cout << stack << endl;
            cout << doubleSizeStack << endl;
        } 
        else
        {
	        cout << "old"  << endl;
	        for (int i = 0; i < arrayLen; i++) 
	        {
                cout << stack[i];
            }
	        cout << endl;
	        
	        stack[top] = datumItem.key; 
	        top++;
	        
	        cout << "new" << endl;
	        for (int i = 0; i < arrayLen; i++) 
	        {
                cout << stack[i];
            }
	        cout << endl;
        }
    }
    DatumItem pop ();		// Return a DataItem from top. If the array is less than half-full, half its size.
    bool isEmpty ();		// Determine if the stack is empty
    DatumItem getTop ();		// Get the last data item of the stack without removing it
    int getSize ();		    // Return size of the array that keeps the data items (must be at least as large as the number of data items in the stack)
};

class TwoStackQueue
{	    // Please implement a queue using two stacks (you CANNOT access array elements directly; instead, you can only call the methods of the previous ArrayStack class)
        // HINT: Add some fields here...

        // HINT: implement all of these...
    void enqueue ();
    DatumItem dequeue ();
    bool isEmpty ();
    bool isFull ();
    DatumItem getBack ();
    int getSize ();
};

#endif


int main ()
{
    cout << "Hello World" << endl;
    
    DatumItem *datumItem = new DatumItem(1, 'a');  // The asterisk is required.
    
    ArrayStack arrayStack;  // The asterisk is required.
    
    arrayStack.push(*datumItem);  // can't use arrayStack.push()
    arrayStack.push(*datumItem);
    arrayStack.push(*datumItem);
    arrayStack.push(*datumItem);
    arrayStack.push(*datumItem);
    arrayStack.push(*datumItem);
    
    cout << "Mom! I am here!" << endl;
    return 0;
}
