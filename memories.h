#ifndef MEMORIES_H
#define MEMORIES_H

#include "complexnumber.h"
#include <map>
#include <vector>

using namespace std;

class memories
{
public:
    memories();
    ~memories();
private:
    map<char, complexNumber> cplxMap;
};

#endif // MEMORIES_H
