#pragma once
#include <string>

	class Number {
		double value;
	public:
		Number(double value);
		Number operator+(Number num);
		Number operator-(Number num);
		Number operator*(Number num);
		Number operator/(Number num);
		Number _sqrt();
		Number _atan(Number num);
		static Number _one;
		static Number _zero;
		std::string to_string();
	};
