#include <"point.h">
#include <cmath>

Point::Point(double x, double y, double z){
    _x = x; _y = y; _z = z;
}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

double Point::getZ() const {
    return _z;
}

void Point::negate(){
    _x *= -1;
    _y *= -1;
    _z *= -1;
}

double Point::norm() const {
    return std::sqrt(_x*_x + _y*_y + _z*_z);
}

std::ostream& operator<<(std::ostream& os, const Point& p){
   return os << "X:" << p.getX() << " Y:" << p.getY() << " Z:" << p.getZ();
}

Point Point::operator+(const Point& p){
    return Point(getX()+p.getX(), getY()+p.getY(), getZ()+p.getZ());
}