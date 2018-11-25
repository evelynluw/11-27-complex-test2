#include "complexnumber.h"

std::ostream& operator << (std::ostream& out, const complexNumber& cplx) {
    out<<cplx.getRealPart()<<'+'<<cplx.getImgPart()<<'i';
    return out;
}

std::istream& operator >> (std::istream& in, mixedNumber& cplx) {

}

complexNumber operator + (const complexNumber& x, const complexNumber& y) {
    complexNumber temp((x.getRealPart() + y.getRealPart()),
                       x.getImgPart() + y.getImgPart());
    return temp;
}

complexNumber operator - (const complexNumber& x, const complexNumber& y) {

}

complexNumber operator * (const complexNumber& x, const complexNumber& y) {

}

complexNumber operator / (const complexNumber& x, const complexNumber& y) {

}

complexNumber operator ^ (const complexNumber& x, const complexNumber& y) {

}


bool operator == (const complexNumber& x, const complexNumber& y) {

}

bool operator != (const complexNumber& x, const complexNumber& y) {

}

bool operator > (const complexNumber& x, const complexNumber& y) {

}

bool operator < (const complexNumber& x, const complexNumber& y) {

}

bool operator >= (const complexNumber& x, const complexNumber& y) {

}

bool operator <= (const complexNumber& x, const complexNumber& y) {

}

