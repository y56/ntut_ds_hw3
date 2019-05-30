#include <iostream>
using namespace std;

class DatumItem
{
public:

    int key = -1;		 // Key, a positive int
    char datumChar = '\0';	 // satellite datum, assume each datum is only a char.

    DatumItem ()  // constructor w/o input, using some default values 
    {}
    DatumItem (int newKey, char newDatumChar)	// constructor with input
    {
        key = newKey;
        datumChar = newDatumChar;
    }
    ~DatumItem ()     // destructor  // not sure what to do
    {}; 
};

class ArrayStack
{
public:  // for convenience, set everything public

    int top;
    int arrayLen;
    DatumItem** stack;  // a pointer for basr address
    
    ArrayStack () // constructor
    { 
        top = -1;       // -1 means nothing is in the stack  
                        // the array index position to where we add an next element will be top+1
        arrayLen = 8;   // default array length as 8
        stack = new DatumItem*[arrayLen] ;  // an array of addresses of `DatumItem` objects
    }
    void push (DatumItem datumItem)	// Insert a data item to top.
                                    // Anyway, I will use the address of each `DatumItem` object as an element in an array.
    {
	        stack[top+1] = &datumItem; 
	        top++;
	        
	        for (int i = 0; i < arrayLen; i++) 
	        {
                cout << stack[i] << " | ";
            }
	        cout << endl;
    }
};


int main ()
{
    // test DatumItem destructor
    
    cout << "***** Use constructor" << endl<<endl;
    
    DatumItem* datumItemPtr2 = new DatumItem(2, 'b');  // The asterisk is required. // Create a datumItem and get its address
    
    cout << "content of datumItemPtr2:    " << datumItemPtr2 << endl;
    
    DatumItem datumItem2 = *datumItemPtr2;  // get the content to whcih datumItemPtr2 points
    
    cout << "address of datumItem2:       " << &datumItem2 << endl;
    
    datumItem2.~DatumItem();  // try to destruct
    
    cout << endl << "***** Use destructor" << endl<<endl;

    cout << "content of datumItemPtr2:    " << datumItemPtr2 << endl;

    cout << "address of datumItem2:       " << &datumItem2 << endl;

    
    // test ArrayStack
    ArrayStack* arrayStackPtr = new ArrayStack();  // The asterisk is required.
    
    // creat multiple datumItems for testing `push`
    DatumItem datumItem3 = DatumItem(3, 'c'); 
    DatumItem datumItem4 = DatumItem(4, 'd'); 
    DatumItem datumItem5 = DatumItem(5, 'e'); 
    DatumItem datumItem6 = DatumItem(6, 'f'); 

    // print their address
    
    cout << endl << "***** print the addresses of datumItems:" << endl<<endl;
    
    cout << datumItem3.key <<"  "<< datumItem3.datumChar <<"  "<< &datumItem3 << endl;
    cout << datumItem4.key <<"  "<< datumItem4.datumChar <<"  "<< &datumItem4 << endl;
    cout << datumItem5.key <<"  "<< datumItem5.datumChar <<"  "<< &datumItem5 << endl;
    cout << datumItem6.key <<"  "<< datumItem6.datumChar <<"  "<< &datumItem6 << endl;


    
    // test push on ArrayStack 
    
    cout << endl << "***** start pushing and printing my stack:" << endl<<endl;

    arrayStackPtr->push(  datumItem3  );  // can't use arrayStackPtr.push()
    arrayStackPtr->push(  datumItem4  );  // can't use arrayStackPtr.push()
    arrayStackPtr->push(  datumItem5  );  // can't use arrayStackPtr.push()
    arrayStackPtr->push(  datumItem6  );  // can't use arrayStackPtr.push()


    return 0;
} 
