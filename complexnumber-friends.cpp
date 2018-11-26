#include "complexnumber.h"
#include <complex>

std::ostream& operator << (std::ostream& out, const complexNumber& cplx) {
    out<<cplx.getRealPart()<<'+'<<cplx.getImgPart()<<'i';
    return out;
}

std::istream& operator >> (std::istream& in, complexNumber& cplx) {

}

complexNumber operator + (const complexNumber& x, const complexNumber& y) {
    return complexNumber(x.getRealPart() + y.getRealPart(),
                         x.getImgPart() + y.getImgPart());
}

complexNumber operator - (const complexNumber& x, const complexNumber& y) {
    return complexNumber(x.getRealPart() - y.getRealPart(),
                         x.getImgPart() - y.getImgPart());
}

complexNumber operator * (const complexNumber& x, const complexNumber& y) { //TESTED
    mixedNumber a = x.getRealPart(),
            b = x.getImgPart(),
            c = y.getRealPart(),
            d = y.getImgPart();
    return complexNumber(a*c - b*d, a*d + b*c);
}

complexNumber operator / (const complexNumber& x, const complexNumber& y) { //TESTED
    mixedNumber a = x.getRealPart(),
            b = x.getImgPart(),
            c = y.getRealPart(),
            d = y.getImgPart();
    if(y.isReal())
        return complexNumber(a/c, b/c);
    complexNumber tempNum = x * ~y,
            tempDenom = y * ~y;
    return tempNum / tempDenom;
}

complexNumber operator ^ (const complexNumber& x, const complexNumber& y) {

}


bool operator == (const complexNumber& x, const complexNumber& y) {
    return x.getRealPart() == y.getRealPart() && x.getImgPart() == y.getImgPart();
}

bool operator != (const complexNumber& x, const complexNumber& y) {
    return !(x==y);
}

bool operator > (const complexNumber& x, const complexNumber& y) {
    return x.getRealPart() > y.getRealPart()
            ? true
            : x.getRealPart() == y.getRealPart()
              ? x.getImgPart() > y.getImgPart()
              : false;
}

bool operator < (const complexNumber& x, const complexNumber& y) {
    return x.getRealPart() < y.getRealPart()
            ? true
            : x.getRealPart() == y.getRealPart()
              ? x.getImgPart() < y.getImgPart()
              : false;
}

bool operator >= (const complexNumber& x, const complexNumber& y) {
    return !(x<y);
}

bool operator <= (const complexNumber& x, const complexNumber& y) {
    return !(x>y);
}

