#include <gtest/gtest.h>
#include "array.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"

TEST(PointTest, DefaultConstructor) {
    Point<int> p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
}

TEST(PointTest, ParameterizedConstructor) {
    Point<double> p(3.5, 4.2);
    EXPECT_DOUBLE_EQ(p.getX(), 3.5);
    EXPECT_DOUBLE_EQ(p.getY(), 4.2);
}

TEST(TrapezoidTest, Area) {
    Trapezoid<int> t(0, 0, 4, 0, 1, 3, 3, 3);
    EXPECT_NEAR(t.area(), 10.0, 1e-6);
}

TEST(TrapezoidTest, Center) {
    Trapezoid<int> t(0, 0, 4, 0, 1, 3, 3, 3);
    Point<int> c = t.center();
    EXPECT_EQ(c.getX(), 2);
    EXPECT_EQ(c.getY(), 1);
}

TEST(RhombusTest, Area) {
    Rhombus<int> r(0, 0, 3, 4, 8, 0, 5, -4);
    EXPECT_NEAR(r.area(), 24.0, 1e-6);
}

TEST(PentagonTest, Area) {
    Pentagon<int> p(0, 0, 1, 2, 3, 3, 4, 1, 2, -1);
    EXPECT_NEAR(p.area(), 8.5, 1e-6);
}

TEST(ArrayTest, PushBackAndAccess) {
    Array<std::shared_ptr<Figure<int>>> arr;
    arr.push_back(std::make_shared<Trapezoid<int>>(0, 0, 2, 0, 1, 1, 1, 1));
    EXPECT_EQ(arr.size(), 1);
    EXPECT_NEAR((*arr[0]).area(), 1.0, 1e-6);
}

TEST(ArrayTest, Erase) {
    Array<std::shared_ptr<Figure<int>>> arr;
    arr.push_back(std::make_shared<Trapezoid<int>>(0,0,2,0,1,1,1,1));
    arr.push_back(std::make_shared<Rhombus<int>>(0,0,1,1,2,0,1,-1));
    arr.erase(0);
    EXPECT_EQ(arr.size(), 1);
    EXPECT_NEAR((*arr[0]).area(), 1.0, 1e-6);
}

TEST(ArrayTest, TotalArea) {
    Array<std::shared_ptr<Figure<int>>> arr;
    arr.push_back(std::make_shared<Trapezoid<int>>(0,0,2,0,1,1,1,1));
    arr.push_back(std::make_shared<Rhombus<int>>(0,0,1,1,2,0,1,-1));
    EXPECT_NEAR(arr.total_area(), 2.0, 1e-6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
