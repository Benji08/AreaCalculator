#include "Square.h"
#include "ostream"


Square::Square() noexcept {
    a = 1.0;
}

Square::Square(double side) {
    if(side <= 0)
        throw std::invalid_argument("Invalide Side value");
    else{
        a = side;
    }
}

double Square::getSide() const noexcept {
    return a;
}

double Square::getArea() const noexcept {
    return a * a;
}

double Square::setSide(double side) {
    if(side <= 0)
        throw std::invalid_argument("Invalide Side value");
    else{
        a = side;
    }
}

Square Square::operator+(const Square &c) const noexcept {
    Square a = *this;
    a+=c;
    return a;
}

Square Square::operator+(const Circle &c) const noexcept {
    Square a = *this;
    a+=c;
    return a;
}

Square Square::operator-(const Square &c) const noexcept {
    Square a = *this;
    a-=c;
    return a;
}

Square Square::operator-(const Circle &c) const noexcept {
    Square a = *this;
    a-=c;
    return a;
}

void Square::operator+=(const Square &c) noexcept {
    a = sqrt(a*a + c.getArea());
}

void Square::operator+=(const Circle &c) noexcept {
    a = sqrt(a*a + c.getArea());
}

void Square::operator-=(const Square &c) noexcept {
    a = sqrt(abs(a*a - c.getArea()));
}

void Square::operator-=(const Circle &c) noexcept {
    a = sqrt(abs(a*a - c.getArea()));
}

Circle Square::operator!() const noexcept {
    double new_radius = sqrt(a*a / M_PI);
    return Circle(new_radius);
}

bool Square::operator==(const Square &c) const noexcept {
    if (a==c.a)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& os, const Square& dt){
    os << "Bok:" <<dt.getSide();
    return os;
}

std::istream& operator>>(std::istream &input, Square& dt){
    double a = 1;
    std::cout << "Podaj bok kwadratu:";
    input >> a;
    dt.setSide(a);
    return input;
}
