#pragma once
#include <cmath>;
#include "Number.h"
#include <string>

#ifdef VECTOR_EXPORTS
#define VECTOR_API __declspec(dllexport)
#else
#define VECTOR_API __declspec(dllimport)
#endif



	extern "C" class VECTOR_API Vector {
	private:
		Number x, y;
	public:
		Vector(Number x, Number y);
		Vector _add(Vector vec);
		Vector polar_coordinates_x();
		Vector polar_coordinates_y();
		Vector polar_coordinates_in_one_method();
		static Vector __one_vec;
		static Vector __zero_vec;
		std::string to_string_x();
		std::string to_string_y();
	};



