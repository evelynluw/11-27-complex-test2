#include "memories.h"

memories::memories() {
    complexNumber zero(0,0);
    for(char c = 'A'; c < 'Z'; c++)
        cplxMap[c] = zero;
}

memories::~memories() {
    complexNumber zero(0,0);
    for(char c = 'A'; c < 'Z'; c++)
        cplxMap[c] = zero;
}
