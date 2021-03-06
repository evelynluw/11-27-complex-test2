#include "complexnumber.h"
#include <sstream>

complexNumber::complexNumber() {
    real = img = 0;
}
complexNumber::~complexNumber() {
    real = img = 0;
}
complexNumber::complexNumber(mixedNumber _real, mixedNumber _img) {
    setValue(_real, _img);
}
complexNumber::complexNumber(const complexNumber &other) {
    setValue(other);
}

complexNumber::complexNumber(const std::string str) {
    std::stringstream ss;
    ss<<str;
    ss>>*this;
}

//accessors
void complexNumber::getValue(mixedNumber& _real, mixedNumber& _img) {
    _real = real;
    _img = img;
}
mixedNumber complexNumber::getRealPart() const {
    return real;
}
mixedNumber complexNumber::getImgPart() const {
    return img;
}

bool complexNumber::isReal() const {
    return img == 0;
}

mixedNumber complexNumber::dotProduct(const complexNumber& other) {
    return (real * other.getRealPart() + img * other.getImgPart());
}

//mutators
void complexNumber::setValue(mixedNumber _real, mixedNumber _img) {
    real = _real;
    img = _img;
}

void complexNumber::setValue(const complexNumber &other) {
    setValue(other.getRealPart(), other.getImgPart());
}

void complexNumber::setRealPart(mixedNumber _real) {
    real = _real;
}
void complexNumber::setImgPart(mixedNumber _img) {
    img = _img;
}

//operators
complexNumber& complexNumber::operator = (const complexNumber &other) {
    if(this != &other)
        this->setValue(other);
    return *this;
}

complexNumber& complexNumber::operator += (const complexNumber &other) {
    *this = *this + other;
    return *this;
}
complexNumber& complexNumber::operator -= (const complexNumber &other) {
    *this = *this - other;
    return *this;
}
complexNumber& complexNumber::operator *= (const complexNumber &other) {
    *this = *this * other;
    return *this;
}
complexNumber& complexNumber::operator /= (const complexNumber &other) {
    *this = *this / other;
    return *this;
}

complexNumber complexNumber::operator ~ () const { //TESTED
    return complexNumber(getRealPart(), 0 - getImgPart());
}



//PRIVATE

void complexNumber::copy(const complexNumber& other) {
    setValue(other);
}


