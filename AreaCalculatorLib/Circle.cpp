#include "Circle.h"
#include "ostream"


Circle::Circle() noexcept {
    r = 1.0;
}

Circle::Circle(double radius) {
    if(radius <= 0)
        throw std::invalid_argument("Invalide Radious value");
    else{
        r = radius;
    }
}

double Circle::getRadius() const noexcept {
    return r;
}

double Circle::getArea() const noexcept {
    return M_PI * r * r;
}

double Circle::setRadius(double radius) {
    if(radius <= 0)
        throw std::invalid_argument("Invalide Radious value");
    else{
        r = radius;
    }
}

Circle Circle::operator+(const Circle &c) const noexcept {
    Circle a = *this;
    a+=c;
    return a;
}

Circle Circle::operator+(const Square &c) const noexcept {
    Circle a = *this;
    a+=c;
    return a;
}

Circle Circle::operator-(const Circle &c) const noexcept {
    Circle a = *this;
    a-=c;
    return a;
}

Circle Circle::operator-(const Square &c) const noexcept {
    Circle a = *this;
    a-=c;
    return a;
}

void Circle::operator+=(const Circle &c) noexcept {
    r = sqrt(r*r +c.r*c.r);
}

void Circle::operator+=(const Square &c) noexcept {
    r = sqrt(r*r + c.getArea() / M_PI);
}

void Circle::operator-=(const Circle &c) noexcept {
    r = sqrt(abs(r*r - c.r*c.r));
}

void Circle::operator-=(const Square &c) noexcept {
    r = sqrt(abs(r*r - c.getArea() / M_PI));
}

Square Circle::operator!() const noexcept {
    double new_side = sqrt(r * r * M_PI);
    return Square(new_side);
}

bool Circle::operator==(const Circle &c) const noexcept {
    if(r == c.r)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& os, const Circle& dt){
    os << "Promien:" <<dt.getRadius();
    return os;
}

std::istream & operator>>(std::istream &input, Circle& dt){
    double r;
    std::cout << "Podaj promien:";
    input >> r;
    dt.setRadius(r);
    return input;
}