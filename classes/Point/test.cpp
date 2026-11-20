#include "point.h"
#include <iostream>

int main(void){
    Point p(3, 4, 5);
    std::cout << p << "\n";

    p.negate();
    std::cout << p << "\n";

    double width = p.norm();
    std::cout << "Total width of: " << p << " " << width << "\n"; 

    return 0;
}