#ifndef HEALTHPOINTS_H
#define HEALTHPOINTS_H
#include <iostream>

class HealthPoints {
    int max_points;
    int current_points;

public:
    // Exception class for invalid arguments
    class InvalidArgument {};

    // Constructor
    HealthPoints(int max = 100);

    // Overloaded arithmetic operators
    HealthPoints operator+(int value);
    HealthPoints operator-(int value);
    HealthPoints& operator+=(const int value);
    HealthPoints& operator-=(const int value);

    // Comparison operators
    friend bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);
    friend bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);
    bool operator<(const HealthPoints& other) const;
    bool operator<=(const HealthPoints& other) const;
    bool operator>(const HealthPoints& other) const;
    bool operator>=(const HealthPoints& other) const;
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);
};

#endif