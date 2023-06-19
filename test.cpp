#include "VM/core.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    //To do the dynamic typing first create an object with createObject function 
    //params : (name of the object, value of the object)
    createObject("a", 1000);
    //After the creating you can do anything with the object like updating the object with a new type value.
    updateObject("a", "hello world");
    //And to read there are two different functions to read the objects value as string or double
    //readObjectAsStr and readObjectAsFloat
    cout << readObjectAsStr("a") << "\n";

    return 0;
}
