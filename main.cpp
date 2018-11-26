#include <iostream>
#include "complexnumber.h"

using namespace std;

int main()
{
    complexNumber a(5,4),
            b(3,-2),
            c = a/b;
    cout<<c<<endl;
    return 0;
}
