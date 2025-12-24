#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"
#include <memory>
#include <vector>
#include <iostream>

template<Scalar T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual double area() const = 0;
    virtual Point<T> center() const = 0;
    virtual void print(std::ostream& os) const = 0;

    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure& operator=(const Figure& other) = 0;
    virtual operator double() const { return area(); }

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.print(os);
        return os;
    }
};

#endif
