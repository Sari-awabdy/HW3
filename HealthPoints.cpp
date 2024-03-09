#include "healthpoints.h"

//implemntaion of constructor
HealthPoints::HealthPoints(int max) : max_points(max), current_points(max)
{
    if(max <= 0)
    {
        throw InvalidArgument();
    }
}
HealthPoints& HealthPoints::operator+=(const int value)
{
    current_points += value;
    if(current_points > max_points)
    {
        current_points  = max_points;
    }
    if(current_points < 0)
    {
        current_points = 0;
    }
    return *this;
}
HealthPoints& HealthPoints::operator-=(const int value)
{
    current_points -= value;
    if(current_points > max_points)
    {
        current_points  = max_points;
    }
    if(current_points < 0)
    {
        current_points = 0;
    }
    return *this;
}

HealthPoints HealthPoints::operator+(const int value) const 
{
    HealthPoints temp(*this);
    temp += value; //because we use += that we implemented we do not have to check if it is over the max
    return temp;
}
HealthPoints HealthPoints::operator-(const int value) const 
{
    HealthPoints temp(*this);
    temp -= value; 
    return temp;
}
// implemntation of comparison operators as non-member funsctions
bool operator==(const HealthPoints& hp1, const HealthPoints& hp2) {
    return hp1.current_points == hp2.current_points;
}
bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2) {
    return !(hp1 == hp2); // Reuse the equality operator
}
//
bool HealthPoints::operator<(const HealthPoints& other) const
{
    return current_points < other.current_points;
}

bool HealthPoints::operator<=(const HealthPoints& other) const
{
    return current_points <= other.current_points;
}

bool HealthPoints::operator>(const HealthPoints& other) const {
    return other < *this;
}

bool HealthPoints::operator>=(const HealthPoints& other) const {
    return other <= *this;
}
std::ostream& operator<<(std::ostream& os, const HealthPoints& hp)
{
    os << hp.current_points << "(" << hp.max_points << ")";
    return os;
}