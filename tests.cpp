#include "point.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"
#include "array.h"
#include <gtest/gtest.h>
#include <memory>
#include <cmath>

TEST(PointTest, CreationAndAccess) {
    Point<int> p(3, 4);
    EXPECT_EQ(p.getX(), 3);
    EXPECT_EQ(p.getY(), 4);
}

TEST(PointTest, DoublePrecision) {
    Point<double> p(3.14, 2.71);
    EXPECT_DOUBLE_EQ(p.getX(), 3.14);
    EXPECT_DOUBLE_EQ(p.getY(), 2.71);
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid<int> t(0, 0, 4, 0, 1, 3, 3, 3);
    EXPECT_NEAR(t.area(), 9.0, 0.001);
}

TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid<int> t(0, 0, 4, 0, 1, 3, 3, 3);
    auto center = t.center();
    EXPECT_EQ(center.getX(), 2);
    EXPECT_EQ(center.getY(), 1);
}


TEST(RhombusTest, AreaCalculation) {
    Rhombus<int> r(0, 0, 2, 2, 4, 0, 2, -2);
    EXPECT_NEAR(r.area(), 8.0, 0.001);
}


TEST(PentagonTest, AreaCalculation) {
    Pentagon<int> p(0, 0, 2, 1, 3, 4, 1, 5, -1, 3);
    EXPECT_NEAR(p.area(), 12.0, 0.001);
}

TEST(ArrayTest, BasicOperations) {
    Array<std::shared_ptr<Figure<int>>> arr;
    
    auto fig1 = std::make_shared<Trapezoid<int>>(0, 0, 4, 0, 1, 3, 3, 3);
    arr.push_back(fig1);
    EXPECT_EQ(arr.size(), 1);
    
    auto fig2 = std::make_shared<Rhombus<int>>(0, 0, 2, 2, 4, 0, 2, -2);
    arr.push_back(fig2);
    EXPECT_EQ(arr.size(), 2);
    
    arr.erase(0);
    EXPECT_EQ(arr.size(), 1);
}

TEST(ArrayTest, TotalArea) {
    Array<std::shared_ptr<Figure<int>>> arr;
    
    auto fig1 = std::make_shared<Trapezoid<int>>(0, 0, 4, 0, 1, 3, 3, 3);
    auto fig2 = std::make_shared<Rhombus<int>>(0, 0, 2, 2, 4, 0, 2, -2);
    
    arr.push_back(fig1);
    arr.push_back(fig2);
    
    EXPECT_NEAR(arr.total_area(), 9.0 + 8.0, 0.001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
