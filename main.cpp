#include <iostream>
#include "complexnumber.h"

using namespace std;

int main()
{
    complexNumber cplx1(5,4), cplx2(3,-2),
            cplx3 = cplx1 ^ cplx2;
    cout<<cplx1<<" ^ "<<cplx2<<" = "<<cplx3<<endl;
    return 0;
}
