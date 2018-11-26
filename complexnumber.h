#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "mixednumber.h"

class complexNumber
{
public:

    //constructors
    complexNumber();
    ~complexNumber();
    complexNumber(mixedNumber _real, mixedNumber _img);
    complexNumber(const complexNumber &other);

    //accessors
    void getValue(mixedNumber& _real, mixedNumber& _img);
    mixedNumber getRealPart() const;
    mixedNumber getImgPart() const;
    bool isReal() const;

    //mutators
    void setValue(mixedNumber _real, mixedNumber _img);
    void setValue(const complexNumber other);
    void setRealPart(mixedNumber _real);
    void setImgPart(mixedNumber _img);

    //operators
    complexNumber& operator = (const complexNumber &other);

    complexNumber& operator += (const complexNumber& other);
    complexNumber& operator -= (const complexNumber& other);
    complexNumber& operator *= (const complexNumber& other);
    complexNumber& operator /= (const complexNumber& other);

    complexNumber operator ~ () const;

    friend
    std::ostream& operator << (std::ostream& out, const complexNumber& cplx);
    friend
    std::istream& operator >> (std::istream& in, complexNumber& cplx);
    friend
    complexNumber operator + (const complexNumber& x, const complexNumber& y);
    friend
    complexNumber operator - (const complexNumber& x, const complexNumber& y);
    friend
    complexNumber operator * (const complexNumber& x, const complexNumber& y);
    friend
    complexNumber operator / (const complexNumber& x, const complexNumber& y);
    friend
    complexNumber operator ^ (const complexNumber& x, const complexNumber& y);
//    friend
//    complexNumber operator ~ (const complexNumber& other);

    friend
    bool operator == (const complexNumber& x, const complexNumber& y);
    friend
    bool operator != (const complexNumber& x, const complexNumber& y);
    friend
    bool operator > (const complexNumber& x, const complexNumber& y);
    friend
    bool operator < (const complexNumber& x, const complexNumber& y);
    friend
    bool operator >= (const complexNumber& x, const complexNumber& y);
    friend
    bool operator <= (const complexNumber& x, const complexNumber& y);

private:
    mixedNumber real, img;
    void copy(const complexNumber& other);




};

#endif // COMPLEXNUMBER_H
