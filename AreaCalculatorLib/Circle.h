#ifndef INC_22L_PROI_AREACALCULATOR_BARTOSZ_PAWLAKK_CIRCLE_H
#define INC_22L_PROI_AREACALCULATOR_BARTOSZ_PAWLAKK_CIRCLE_H
class Square;
#include "Square.h"
#include "math.h"
#include "iostream"

class Circle {
private:
    double r = 1.0;

public:
    Circle() noexcept;
    Circle(double radius);
    double getRadius() const noexcept;
    double getArea() const noexcept;
    double setRadius(double radius);

    Circle operator+(Circle const& c) const noexcept;
    Circle operator+(Square const& c) const noexcept;
    Circle operator-(Circle const& c) const noexcept;
    Circle operator-(Square const& c) const noexcept;

    void operator+=(Circle const& c) noexcept;
    void operator+=(Square const& c) noexcept;
    void operator-=(Circle const& c) noexcept;
    void operator-=(Square const& c) noexcept;

    Square operator!() const noexcept;
    bool operator==(Circle const& c) const noexcept;
};

std::ostream& operator<<(std::ostream& os, const Circle& dt);

std::istream & operator>>(std::istream& input, Circle& dt);

#endif //INC_22L_PROI_AREACALCULATOR_BARTOSZ_PAWLAKK_CIRCLE_H
