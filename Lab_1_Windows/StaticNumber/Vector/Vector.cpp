#include "pch.h";
#include "Number.h";
#include "Vector.h";

#include <cmath>;
#include <string>;


Vector::Vector(Number x, Number y) : x(x), y(y) {};
Vector Vector::_add(Vector vec) {
	return Vector(this->x + vec.x, this->y + vec.y);
}
Vector Vector::polar_coordinates_x() {
	return Vector(((this->x) * (this->x)) + ((this->y) * (this->y))._sqrt(), this->y);
}
Vector Vector::polar_coordinates_y() {
	return Vector(this->x, this->x._atan(this->y));
}
Vector Vector::polar_coordinates_in_one_method() {
	return Vector((((this->x) * (this->x)) + ((this->y) * (this->y)))._sqrt(), this->x._atan(this->y));
}
Vector Vector::__one_vec = Vector(Number::_one, Number::_one);
Vector Vector::__zero_vec = Vector(Number::_zero, Number::_zero);
std::string Vector::to_string_x() {
	return this->x.to_string();
}
std::string Vector::to_string_y() {
	return this->y.to_string();
}
