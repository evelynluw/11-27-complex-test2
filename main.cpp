#include <iostream>
#include "complexnumber.h"

using namespace std;

int main()
{
    complexNumber cplx1(-1,0), cplx2(0.5,0),
            cplx3 = cplx1 ^ cplx2;
    while (1) {
        cout<<cplx1<<" ^ "<<cplx2<<" = "<<(cplx1^cplx2)<<endl;
        cout<<": ";
        cin>>cplx1;
        cout<<": ";
        cin>>cplx2;
    }
    return 0;
}
