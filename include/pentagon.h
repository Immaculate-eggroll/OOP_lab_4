#ifndef PENTAGON_H
#define PENTAGON_H

#include "figure.h"
#include <array>
#include <cmath>

template<Scalar T>
class Pentagon : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 5> vertices;

public:
    Pentagon(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4, T x5, T y5) {
        vertices[0] = std::make_unique<Point<T>>(x1, y1);
        vertices[1] = std::make_unique<Point<T>>(x2, y2);
        vertices[2] = std::make_unique<Point<T>>(x3, y3);
        vertices[3] = std::make_unique<Point<T>>(x4, y4);
        vertices[4] = std::make_unique<Point<T>>(x5, y5);
    }

    double area() const override {
        double area = 0;
        for (int i = 0; i < 5; ++i) {
            const auto& p1 = *vertices[i];
            const auto& p2 = *vertices[(i + 1) % 5];
            area += p1.getX() * p2.getY() - p2.getX() * p1.getY();
        }
        return std::abs(area) / 2.0;
    }

    Point<T> center() const override {
        T sumX = 0, sumY = 0;
        for (const auto& v : vertices) {
            sumX += v->getX();
            sumY += v->getY();
        }
        return Point<T>(sumX / 5, sumY / 5);
    }

    void print(std::ostream& os) const override {
        os << "Pentagon vertices: ";
        for (const auto& v : vertices) os << *v << " ";
        os << ", center: " << center() << ", area: " << area();
    }

    bool operator==(const Figure<T>& other) const override {
        const auto* o = dynamic_cast<const Pentagon*>(&other);
        if (!o) return false;
        for (size_t i = 0; i < 5; ++i)
            if (vertices[i]->getX() != o->vertices[i]->getX() ||
                vertices[i]->getY() != o->vertices[i]->getY())
                return false;
        return true;
    }

    Pentagon& operator=(const Figure<T>& other) override {
        const auto* o = dynamic_cast<const Pentagon*>(&other);
        if (o) {
            for (size_t i = 0; i < 5; ++i) {
                vertices[i] = std::make_unique<Point<T>>(o->vertices[i]->getX(), o->vertices[i]->getY());
            }
        }
        return *this;
    }
};

#endif
