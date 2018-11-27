#include "complexnumber.h"
#include <string>

std::ostream& operator << (std::ostream& out, const complexNumber& cplx) {
    if(cplx.getRealPart() == 0 && cplx.getImgPart() == 0) {
        out<<0;
        return out;
    }
    if(cplx.getImgPart() == 0) {
        out<<cplx.getRealPart();
        return out;
    }
    if(cplx.getRealPart() == 0) {
        out<<cplx.getImgPart()<<'i';
        return out;
    }
//    char sign = (cplx.getImgPart()>=0) ? '+' : char(0);
    if(cplx.getImgPart()>=0)
        out<<cplx.getRealPart()<<'+'<<cplx.getImgPart()<<'i';
    else
        out<<cplx.getRealPart()<<cplx.getImgPart()<<'i';
    return out;
}

std::istream& operator >> (std::istream& in, complexNumber& cplx) {
    mixedNumber x, y;
    char junk, sign = '+';
    if(in.peek() == 'i') {
        in>>junk;
        cplx.setValue(0,1);
        return in;
    }

    in>>x;
//    while(in.peek()==' ')
//        in.get();
    if(toupper(in.peek()) == 'I') {
        in>>junk;
        cplx.setValue(0,x);
        return in;
    }

    if(in.peek() == '-' || in.peek() == '+')
        in>>sign;
    else {
        cplx.setValue(x,0);
        return in;
    }
//    while(in.peek()==' ')
//        in.get();
    in>>y;
    std::stringstream ss;
    ss<<sign<<y;
    ss>>y;
    cplx.setValue(x,y);
    return in;
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
    // TESTED, need to set prescision
    std::complex<double> _x(x.getRealPart().evaluate(),x.getImgPart().evaluate()),
            _y(y.getRealPart().evaluate(), y.getImgPart().evaluate()),
            _result;
    _result = std::pow(_x, _y);
    return complexNumber(_result.real(), _result.imag());
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

