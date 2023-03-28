#include "Cone.h"
#include <cmath>
#include <iostream>
using namespace std;

Cone::Cone() {};

Cone::Cone(float r, float h) {
	base_center = Dot();
	this->r = r;
	this->h = h;
}

Cone::Cone(Dot base_center, float r, float h) {
	this->base_center = base_center;
	this->r = r;
	this->h = h;
}

void Cone::set(float r, float h) {
	base_center = Dot();
	this->r = r;
	this->h = h;
}

void Cone::set(Dot base_center, float r, float h) {
	this->base_center = base_center;
	this->r = r;
	this->h = h;
}

float Cone::Volume() {
	return pi * r * r * h / 3;
}

float Cone::Square() {
	float l = sqrt(r * r + h * h);
	return pi * r * (r + l);
}

float Cone::GetH() { return h; }

float Cone::GetR() { return r; }

Dot Cone::GetBase() { return base_center; }

ostream& operator<<(ostream& stream, Cone obj) {
	stream << "Center :";
	stream << obj.base_center.x << " " << obj.base_center.y << " " << obj.base_center.z << "  ";
	stream << "h=" << obj.h << "  ";
	stream << "r=" << obj.r << "  ";
	return stream;
}