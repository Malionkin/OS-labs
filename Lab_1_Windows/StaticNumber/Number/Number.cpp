#include "Number.h";
#include <cmath>;
Number::Number(double value) :value(value) {}
Number  Number::operator+(Number num) {
	return (this->value + num.value);
}
Number  Number::operator-(Number num) {
	return (this->value - num.value);
}
Number  Number::operator*(Number num) {
	return (this->value * num.value);
}
Number  Number::operator/(Number num) {
	return (this->value / num.value);
}
Number Number::_one = Number(1);
Number Number::_zero = Number(0);
std::string Number::to_string() {
	return std::to_string(this->value);
}
Number Number::_sqrt() {
	return sqrt(this->value);
}
Number Number::_atan(Number num) {
	return atan(num.value / this->value);
}