#pragma once
#include "Vector.h"
#include "iostream"
using namespace std;

struct Dot {
	float x, y, z;

	Dot(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Dot() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	};
};

class Cone
{
protected:
	const float pi = 3.14;
	Dot base_center;
	float r;
	float h;
	friend ostream& operator<<(ostream& stream, Cone obj);
public:
	Cone();
	Cone(float r, float h);
	Cone(Dot base_center, float r, float h);
	float Square();
	float Volume();
	float GetR();
	float GetH();
	Dot GetBase();
	void set(Dot base, float r, float h);
	void set(float r, float h);
};

