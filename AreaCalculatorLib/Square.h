#ifndef INC_22L_PROI_AREACALCULATOR_BARTOSZ_PAWLAKK_SQUARE_H
#define INC_22L_PROI_AREACALCULATOR_BARTOSZ_PAWLAKK_SQUARE_H
class Circle;
#include "../AreaCalculatorLib/Circle.h"
#include "math.h"
#include "iostream"

class Square {
private:
    double a = 1.0;

public:
    Square() noexcept;
    Square(double side);
    double getSide() const noexcept;
    double getArea() const noexcept;
    double setSide(double side);

    Square operator+(Square const& c) const noexcept;
    Square operator+(Circle const& c) const noexcept;
    Square operator-(Square const& c) const noexcept;
    Square operator-(Circle const& c) const noexcept;

    void operator+=(Square const& c) noexcept;
    void operator+=(Circle const& c) noexcept;
    void operator-=(Square const& c) noexcept;
    void operator-=(Circle const& c) noexcept;

    Circle operator!() const noexcept;
    bool operator==(Square const& c) const noexcept;
};

std::ostream& operator<<(std::ostream& os, const Square& dt);
std::istream& operator>>(std::istream& input, Square& dt);

#endif //INC_22L_PROI_AREACALCULATOR_BARTOSZ_PAWLAKK_SQUARE_H
