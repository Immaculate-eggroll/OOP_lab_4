#include <iostream>
#include <memory>
#include "array.h"
#include "trapezoid.h"
#include "rhombus.h"
#include "pentagon.h"

int main() {
    Array<std::shared_ptr<Figure<int>>> figures;

    std::cout << "Enter trapezoid coordinates (x1 y1 x2 y2 x3 y3 x4 y4): ";
    int x1, y1, x2, y2, x3, y3, x4, y4;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    figures.push_back(std::make_shared<Trapezoid<int>>(x1, y1, x2, y2, x3, y3, x4, y4));

    std::cout << "Enter rhombus coordinates (x1 y1 x2 y2 x3 y3 x4 y4): ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    figures.push_back(std::make_shared<Rhombus<int>>(x1, y1, x2, y2, x3, y3, x4, y4));

    std::cout << "Enter pentagon coordinates (x1 y1 x2 y2 x3 y3 x4 y4 x5 y5): ";
    int x5, y5;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;
    figures.push_back(std::make_shared<Pentagon<int>>(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5));

    std::cout << "\nAll figures:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << *figures[i] << "\n";
    }

    std::cout << "\nTotal area: " << figures.total_area() << "\n";

    std::cout << "\nRemoving figure at index 1...\n";
    figures.erase(1);

    std::cout << "\nRemaining figures:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << *figures[i] << "\n";
    }

    std::cout << "\nTotal area after removal: " << figures.total_area() << "\n";

    return 0;
}
