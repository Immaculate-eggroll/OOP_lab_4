#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include <array>
#include <cmath>

template<Scalar T>
class Rhombus : public Figure<T> {
private:
    std::array<std::unique_ptr<Point<T>>, 4> vertices;

public:
    Rhombus(T x1, T y1, T x2, T y2, T x3, T y3, T x4, T y4) {
        vertices[0] = std::make_unique<Point<T>>(x1, y1);
        vertices[1] = std::make_unique<Point<T>>(x2, y2);
        vertices[2] = std::make_unique<Point<T>>(x3, y3);
        vertices[3] = std::make_unique<Point<T>>(x4, y4);
    }

    double area() const override {
        double d1 = distance(*vertices[0], *vertices[2]);
        double d2 = distance(*vertices[1], *vertices[3]);
        return d1 * d2 / 2.0;
    }

    Point<T> center() const override {
        T sumX = 0, sumY = 0;
        for (const auto& v : vertices) {
            sumX += v->getX();
            sumY += v->getY();
        }
        return Point<T>(sumX / 4, sumY / 4);
    }

    void print(std::ostream& os) const override {
        os << "Rhombus vertices: ";
        for (const auto& v : vertices) os << *v << " ";
        os << ", center: " << center() << ", area: " << area();
    }

    bool operator==(const Figure<T>& other) const override {
        const auto* o = dynamic_cast<const Rhombus*>(&other);
        if (!o) return false;
        for (size_t i = 0; i < 4; ++i)
            if (vertices[i]->getX() != o->vertices[i]->getX() ||
                vertices[i]->getY() != o->vertices[i]->getY())
                return false;
        return true;
    }

    Rhombus& operator=(const Figure<T>& other) override {
        const auto* o = dynamic_cast<const Rhombus*>(&other);
        if (o) {
            for (size_t i = 0; i < 4; ++i) {
                vertices[i] = std::make_unique<Point<T>>(o->vertices[i]->getX(), o->vertices[i]->getY());
            }
        }
        return *this;
    }

private:
    double distance(const Point<T>& a, const Point<T>& b) const {
        T dx = a.getX() - b.getX();
        T dy = a.getY() - b.getY();
        return std::sqrt(dx*dx + dy*dy);
    }
};

#endif
