#include "gtest/gtest.h"
#include "Circle.h"
#include "Square.h"
#include "exception"
#include "math.h"

TEST(AreaCalculatorUnitTest, Square_konstruktor){
    EXPECT_THROW(Square(0), std::invalid_argument);
}

TEST(AreaCalculatorUnitTest, Square_konstruktor2){
    Square x;
    ASSERT_EQ(x.getSide(), 1);
}

TEST(AreaCalculatorUnitTest, Square_getSize){
    Square x(1);
    ASSERT_EQ(x.getSide(), 1);
}

TEST(AreaCalculatorUnitTest, Square_getArea){
    Square x(5);
    ASSERT_EQ(x.getArea(), 25);
}

TEST(AreaCalculatorUnitTest, Square_setSide){
    Square x(5);
    x.setSide(25.3);
    ASSERT_EQ(x.getSide(), 25.3);
}

TEST(AreaCalculatorUnitTest, Square_Operator_plus_Square){
    Square x(4);
    Square y(7);
    ASSERT_EQ(x.operator+(y).getSide(), sqrt(16+49));
}

TEST(AreaCalculatorUnitTest, Square_Operator_plus_Circle){
    Square x(4);
    Circle y(7);
    ASSERT_EQ(x.operator+(y).getSide(), sqrt(16+49*M_PI));
}

TEST(AreaCalculatorUnitTest, Square_Operator_minus_Square1){
    Square x(7);
    Square y(4);
    ASSERT_EQ(x.operator-(y).getSide(), sqrt(49-16));
}

TEST(AreaCalculatorUnitTest, Square_Operator_minus_Square2){
    Square x(4);
    Square y(7);
    ASSERT_EQ(x.operator-(y).getSide(), sqrt(49-16));
}

TEST(AreaCalculatorUnitTest, Square_Operator_minus_Circle1){
    Square x(7);
    Circle y(4);
    ASSERT_EQ(x.operator-(y).getSide(), sqrt(16 * M_PI - 49));
}

TEST(AreaCalculatorUnitTest, Square_Operator_minus_Circle2){
    Square x(4);
    Circle y(7);
    ASSERT_EQ(x.operator-(y).getSide(), sqrt(49*M_PI-16));
}

TEST(AreaCalculatorUnitTest, Square_Operator_plus_eqal1){
    Square x(4);
    Square y(7);
    x.operator+=(y);
    ASSERT_EQ(x.getSide(), sqrt(49+16));
}

TEST(AreaCalculatorUnitTest, Square_Operator_plus_eqal2){
    Square x(4);
    Circle y(7);
    x.operator+=(y);
    ASSERT_EQ(x.getSide(), sqrt(49*M_PI+16));
}

TEST(AreaCalculatorUnitTest, Square_Operator_minus_eqal1){
    Square x(4);
    Square y(7);
    x.operator-=(y);
    ASSERT_EQ(x.getSide(), sqrt(49-16));
}

TEST(AreaCalculatorUnitTest, Square_Operator_minus_eqal2){
    Square x(4);
    Circle y(7);
    x.operator-=(y);
    ASSERT_EQ(x.getSide(), sqrt(49*M_PI-16));
}

TEST(AreaCalculatorUnitTest, Square_Operator_difrent){
    Square x(4);
    Circle y(sqrt(16/M_PI));
    ASSERT_EQ(x.operator!(), y);
}

TEST(AreaCalculatorUnitTest, Square_Operator_eqal1){
    Square x(7);
    Square y(7);
    ASSERT_EQ(x.operator==(y), true);
}

TEST(AreaCalculatorUnitTest, Square_Operator_eqal2){
    Square x(7);
    Square y(4);
    ASSERT_EQ(x.operator==(y), false);
}





TEST(AreaCalculatorUnitTest, Circle_konstruktor){
    EXPECT_THROW(Circle(0), std::invalid_argument);
}

TEST(AreaCalculatorUnitTest, Circle_konstruktor2){
    Circle x;
    ASSERT_EQ(x.getRadius(), 1);
}

TEST(AreaCalculatorUnitTest, Circle_getRadius){
    Circle x(1);
    ASSERT_EQ(x.getRadius(), 1);
}

TEST(AreaCalculatorUnitTest, Circle_getArea){
    Circle x(5);
    ASSERT_EQ(x.getArea(), 25*M_PI);
}

TEST(AreaCalculatorUnitTest, Circle_setRadius){
    Circle x(5);
    x.setRadius(25.3);
    ASSERT_EQ(x.getRadius(), 25.3);
}

TEST(AreaCalculatorUnitTest, Circle_Operator_plus_Circle){
    Circle x(4);
    Circle y(7);
    ASSERT_EQ(x.operator+(y).getRadius(), sqrt(16+49));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_plus_Squere){
    Circle x(4);
    Square y(7);
    ASSERT_EQ(x.operator+(y).getRadius(), sqrt(16+49/M_PI));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_minus_Circle1){
    Circle x(7);
    Circle y(4);
    ASSERT_EQ(x.operator-(y).getRadius(), sqrt(49-16));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_minus_Circle2){
    Circle x(4);
    Circle y(7);
    ASSERT_EQ(x.operator-(y).getRadius(), sqrt(49-16));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_minus_Squere1){
    Circle x(4);
    Square y(7);
    ASSERT_EQ(x.operator-(y).getRadius(), sqrt(16-49/M_PI));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_minus_Sqere2){
    Circle x(4);
    Square y(7);
    ASSERT_EQ(x.operator-(y).getRadius(), sqrt(16-49/M_PI));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_plus_eqal1){
    Circle x(4);
    Circle y(7);
    x.operator+=(y);
    ASSERT_EQ(x.getRadius(), sqrt(49+16));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_plus_eqal2){
    Circle x(4);
    Square y(7);
    x.operator+=(y);
    ASSERT_EQ(x.getRadius(), sqrt(49/M_PI+16));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_minus_eqal1){
    Circle x(4);
    Circle y(7);
    x.operator-=(y);
    ASSERT_EQ(x.getRadius(), sqrt(49-16));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_minus_eqal2){
    Circle x(4);
    Square y(7);
    x.operator-=(y);
    ASSERT_EQ(x.getRadius(), sqrt(16-49/M_PI));
}

TEST(AreaCalculatorUnitTest, Circle_Operator_difrent){
    Circle x(4);
    Square y(4*sqrt(M_PI));
    ASSERT_EQ(x.operator!(), y);
}

TEST(AreaCalculatorUnitTest, Circle_Operator_eqal1){
    Circle x(7);
    Circle y(7);
    ASSERT_EQ(x.operator==(y), true);
}

TEST(AreaCalculatorUnitTest, Circle_Operator_eqal2){
    Circle x(7);
    Circle y(4);
    ASSERT_EQ(x.operator==(y), false);
}
