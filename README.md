# Development record and learning note


##  Creat an object
```C++
#include <iostream>
#include <string>
class DatumItem {
    int key;		                            // Key
    char datumChar;			                    // satellite datum, assume each datum is only a char.
    DatumItem () {                              // constructor w/o input, using some default values 
        key = -1;
        datumChar = '\0';
    }
    DatumItem (int newKey, char newDatum) {     // constructor with input
        key = newKey;
        datumChar = newDatum;
    }
    ~DatumItem () {}                            // destructor  // not sure what to do
};
int main() {
    DatumItem dataItem = DatumItem(1, 'a');
    DatumItem * dataItemPtr = new DatumItem(2, 'b');
    return 0;
};

```
