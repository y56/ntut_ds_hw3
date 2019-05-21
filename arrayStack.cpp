#include <iostream>
using namespace std;

class DatumItem
{
public:

    int key = -1;		                        // Key, a positive int
    char datumChar = '\0';			            // satellite datum, assume each datum is only a char.

    DatumItem ()                                // constructor w/o input, using some default values 
    {}
    DatumItem (int newKey, char newDatumChar)	// constructor with input
    {
        key = newKey;
        datumChar = newDatumChar;
    }
    ~DatumItem ()                           // destructor  // not sure what to do
    {}; 
};

class ArrayStack
{   // Please implement a stack using an array...
    // HINT: Add some fields here...
public:  // for convenience, set everything public

    int top;
    int arrayLen;
    DatumItem** stack;  // a pointer for basr address
    
    ArrayStack () // constructor
    { 
        top = -1;       // -1 means nothing is in the stack  
                        // the array index position to where we add an next element will be top+1
        arrayLen = 4;   // default array length as 4
        stack = new DatumItem*[arrayLen] ;  // an array of addresses of `DatumItem` objects
    }
    // HINT: implement all of these...
    void push (DatumItem datumItem)	// Insert a data item to top.
                                    // The requirement says `void push(int x)` but I don't know how to link `int` to `DatumItem`. 
                                    // Perhaps a hash table?
                                    // Anyway, I will use the address of each `DatumItem` object as an element in an array.
    {
cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< &datumItem;
        if (top == arrayLen - 1)  // If the array is full, double its size.
        {
            cout << "old"  << endl;
	        for (int i = 0; i < arrayLen; i++) 
	        {
                cout << stack[i] << " | ";
            }
	        cout << endl;
	        
            cout<<"Stack (size="<<arrayLen<<") is full. Create and use a double-size array(size="<<arrayLen*2<<")!"<<endl;
            
            DatumItem ** doubleSizeStack = new DatumItem*[arrayLen * 2];
            
            cout << stack << endl;
            cout << doubleSizeStack << endl;
            
            for (int i = 0; i < arrayLen; i++)  // copy from the old
            {
                doubleSizeStack[i] = stack[i];
            }
            arrayLen = arrayLen * 2;     // update it
            delete [] stack;             // delete the old  // use delete [] instead of delete
            stack = doubleSizeStack;     // update it       //  https://stackoverflow.com/questions/2857917/c-pointer-to-different-array
            
            cout << stack << endl;
            cout << doubleSizeStack << endl;
            
            
	        
	        stack[top+1] = &datumItem; 
	        top++;
	        
	        cout << "new" << endl;
	        for (int i = 0; i < arrayLen; i++) 
	        {
                cout << stack[i] << " | ";
            }
	        cout << endl;
            
        } 
        else
        {
	        cout << "old"  << endl;
	        for (int i = 0; i < arrayLen; i++) 
	        {
                cout << stack[i] << " | ";
            }
	        cout << endl;
	        
	        stack[top+1] = &datumItem; 
	        top++;
	        
	        cout << "new" << endl;
	        for (int i = 0; i < arrayLen; i++) 
	        {
                cout << stack[i] << " | ";
            }
	        cout << endl;
        }
    }
    DatumItem pop (void)	        // Return a DataItem from top. If occupied space is less than half-full, halve array's size.
    {
        cout << "pop is trigered.\n";
        cout << "arrayLen=" << arrayLen << endl;
        cout << "top=" << top << endl;
        
        if (-1==top)          // if stack is empty, there is nothing to pop
        {
            cout << "The stack is empty. You got a default DatumItem object key=-1 datum=\\0" << endl;
            DatumItem n;
            return n;
        }
        else
        {
            cout << "old"  << endl;
	        for (int i = 0; i < arrayLen; i++) 
	        {
                cout << stack[i] << " | ";
            }
	        cout << endl;
	        
	        DatumItem* ptr = stack[top];
            DatumItem datumItem = *ptr;
            stack[top] = nullptr;
            
            top--;
            
            if (top < arrayLen/2 && arrayLen/2 >= 4)
            {    
                DatumItem ** halfSizeStack = new DatumItem*[arrayLen / 2];
                
                cout << stack << endl;
                cout << halfSizeStack << endl;
                
                for (int i = 0; i < top; i++)
                {
                    halfSizeStack[i] = stack[i];
                }
                
                arrayLen = arrayLen / 2;
                delete [] stack;             // delete the old  // use delete [] instead of delete
                stack = halfSizeStack;    // update it  //  https://stackoverflow.com/questions/2857917/c-pointer-to-different-array
            
                cout << stack << endl;
                cout << halfSizeStack << endl;
            }
	        
	        cout << "new" << endl;
	        for (int i = 0; i < arrayLen; i++) 
	        {
                cout << stack[i] << " | ";
            }
	        cout << endl;
	        
	        cout << "pop is trigered.\n";
            cout << "arrayLen=" << arrayLen << endl;
            cout << "top=" << top << endl;
            
            return datumItem;
        }
    }
    bool isEmpty ()		            // Determine if the stack is empty
    {
        if (-1 == top) {
            return true;
        }
        else {
            return false;
        }
    }
    DatumItem getTop ()		        // Get the last data item of the stack without removing it
    {
        DatumItem* ptr = stack[top];
        DatumItem datumItem = *ptr;
        return datumItem;
    }
    int getSize ()		            // Return size of the array that keeps the data items 
                                    // (must be at least as large as the number of data items in the stack)
    {
        return arrayLen;
    }
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

int main ()
{
    cout << "Hello World" << endl;
    
/***************************************** ArrayStack *************************/

    // test DatumItem constructor
    DatumItem* datumItemPtr1 = new DatumItem(1, 'a');  // The asterisk is required.
    
    // test DatumItem destructor
    DatumItem* datumItemPtr2 = new DatumItem(2, 'b');  // The asterisk is required.
    cout <<"                   "<< datumItemPtr2 << endl;
    DatumItem datumItem2 = *datumItemPtr2;
    cout <<"                   "<< &datumItem2 << endl;
    datumItem2.~DatumItem();
    cout <<"                   "<< datumItemPtr2 << endl;
    cout <<"                   "<< &datumItem2 << endl;

    
    // test ArrayStack
    ArrayStack* arrayStackPtr = new ArrayStack();  // The asterisk is required.
    
    // test pop on empty ArrayStack
    DatumItem catchedDataItem = arrayStackPtr->pop();
    
    // creat multiple datumItems for testing `push`

    DatumItem datumItem3 = DatumItem(3, 'c'); 
    DatumItem datumItem4 = DatumItem(4, 'd'); 
    DatumItem datumItem5 = DatumItem(5, 'e'); 
    DatumItem datumItem6 = DatumItem(6, 'f'); 
    DatumItem datumItem7 = DatumItem(7, 'g'); 
    DatumItem datumItem8 = DatumItem(8, 'h'); 
    DatumItem datumItem9 = DatumItem(9, 'i'); 
    DatumItem datumItem10 = DatumItem(10, 'j'); 
    DatumItem datumItem11 = DatumItem(11, 'k'); 
    cout << datumItem3.key << datumItem3.datumChar << &datumItem3 << endl;
    cout << datumItem4.key << datumItem4.datumChar << &datumItem4 << endl;
    cout << datumItem5.key << datumItem5.datumChar << &datumItem5 << endl;
    cout << datumItem6.key << datumItem6.datumChar << &datumItem6 << endl;
    cout << datumItem7.key << datumItem7.datumChar << &datumItem7 << endl;
    cout << datumItem8.key << datumItem8.datumChar << &datumItem8 << endl;
    cout << datumItem9.key << datumItem9.datumChar << &datumItem9 << endl;
    cout << datumItem10.key << datumItem10.datumChar << &datumItem10 << endl;
    cout << datumItem11.key << datumItem11.datumChar << &datumItem11 << endl;

    
    // test push on ArrayStack  // Test doubling size

    arrayStackPtr->push(  datumItem3  );  // can't use arrayStackPtr.push()
    cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;
    arrayStackPtr->push(  datumItem4  );  // can't use arrayStackPtr.push()
    cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;
    arrayStackPtr->push(  datumItem5  );  // can't use arrayStackPtr.push()
    cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;
    arrayStackPtr->push(  datumItem6  );  // can't use arrayStackPtr.push()
    cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;
    arrayStackPtr->push(  datumItem7  );  // can't use arrayStackPtr.push()
    cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;
    arrayStackPtr->push(  datumItem8  );  // can't use arrayStackPtr.push()
    cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;
    arrayStackPtr->push(  datumItem9  );  // can't use arrayStackPtr.push()
    cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;
    arrayStackPtr->push(  datumItem10  );  // can't use arrayStackPtr.push()
    cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;
    arrayStackPtr->push(  datumItem11  );  // can't use arrayStackPtr.push()
    cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;

    
    // test pop on  ArrayStack  // Test halving size
    for (int i = 0; i<9;i++)
    {
        cout << "i = " << i << endl;
        DatumItem catchedDataItem = arrayStackPtr->pop();  // can't use arrayStackPtr.pop()
        cout << "test getSize ==> "<< arrayStackPtr->getSize() << endl;
    }
    
    
    
    cout << "Mom! I am here!" << endl;
    return 0;
} 

