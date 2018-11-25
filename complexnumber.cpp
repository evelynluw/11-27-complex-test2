#include "complexnumber.h"

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

//mutators
void complexNumber::setValue(mixedNumber _real, mixedNumber _img) {
    real = _real;
    img = _img;
}

void complexNumber::setValue(const complexNumber other) {
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


//PRIVATE

void complexNumber::copy(const complexNumber& other) {

}


