#include <iostream>
#include <cmath>
#include "Number.h"
#include "Vector.h";

int main()
{
    Number a(1);
    Number b(2);
    std::cout << "Created 2 objects of class Number, they are:" << std::endl;
    std::cout << a.to_string() << std::endl << b.to_string() << std::endl;
    Number c( a+ b);
    std::cout<< "Added 2 Numbers, result is: " << c.to_string() <<std::endl;
    a._sqrt();
    b._atan(a);
    Vector v(a, b);
    std::cout << "Created a Vector object, this is: "<< std::endl;
    std::cout <<"("  <<v.to_string_x()<< ", " << v.to_string_y()<< ")" << std::endl;
    Vector v1 = v.polar_coordinates_in_one_method();
    std::cout << "Created a Vector object in polar coordinates, this is: " << std::endl;
    std::cout << "(" << v1.to_string_x() << ", " << v1.to_string_y() << ")" << std::endl;
    return 0;
}
