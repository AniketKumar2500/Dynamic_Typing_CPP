#if !defined(CORE_H)
#define CORE_H

#include <vector>
#include <string>
#include <map>

using namespace std;

int FLOAT = 0;
int STR = 1;

struct Value{
    string vals;
    double valf;
    int type;
};

struct Cell{
    Value value;
    int type;
    //for memory management
    int used;    
};

//The memory will be represented as the vector of Cells[Tiny memory blocks]
vector<Cell> memory;

//Functions to work with memory.

void addCell(double value){
    Cell newcell;
    newcell.type = 0;
    newcell.value.valf = (value);
    newcell.value.type = 0;
    memory.push_back(newcell);
}

void addCell(string value){
    Cell newcell;
    newcell.type = 1;
    newcell.value.vals = (value);
    newcell.value.type = 1;
    memory.push_back(newcell);
}


Cell readCell(int addr){
    return memory[addr];    
}

//////////////////////////////////////////////////////////////
map<string, int> mem_objects;
//Functions to do actual dynamic typing
void createObject(string name, string value){
    addCell(value);
    mem_objects[name] = memory.size()-1;
}
void createObject(string name, double value){
    addCell(value);
    mem_objects[name] = memory.size()-1;
}
double readObjectAsFloat(string name){
    Value val = memory[mem_objects[name]].value;
    if(val.type != 0){
        printf("Error:{Invalid type reading} trying to read double value from '%s' containing string value.\n", name.c_str());
        exit(0);
    }
    else{
        return val.valf;
    }
}
string readObjectAsStr(string name){
    Value val = memory[mem_objects[name]].value;
    if(val.type != 1){
        printf("Error:{Invalid type reading} trying to read string value from '%s' containing double value instead.\n", name.c_str());
        exit(0);
    }
    else{
        return val.vals;
    }
}

#endif // CORE_H
