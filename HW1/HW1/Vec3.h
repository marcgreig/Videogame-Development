#pragma once
#include <cstdio>
#include <iostream>

template <class T>

class vec3 {
private:
	T x;
	T y;
	T z;

public:
	vec3() : x(0), y(0), z(0) { }
	vec3(T v) : x(v), y(v), z(v) { }
	vec3(T X, T Y, T Z) : x(X), y(Y), z(Z) { }

public: 

	template<typename T>
	void Vector3<T>::operator+(T sum) {
		x += sum;
		y += sum;
		z += sum;
	}

	template<typename T>
	void Vector3<T>::operator+=(const Vector3 &v) {
		x += v.x;
		y += v.y;
		z += v.z;
	}

	template<typename T>
	void Vector3<T>::operator-(T sum) {
		x -= sum;
		y -= sum;
		z -= sum;
	}

	template<typename T>
	void Vector3<T>::operator-=(const Vector3 &v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	template<typename T>
	void Vector3<T>::operator=(const Vector3 &v) {
		x = v.x;
		y = v.y;
		z = v.z;
	}

	template<typename T>
	bool Vector3<T>::operator==(const Vector 3 & v) {
		
	}


	void normalize();
	void zero();
	bool is_zero();
	void distance_to(T_vec);

};