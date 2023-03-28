#include "Cone_Trunc.h"

Cone_Trunc::Cone_Trunc() {}

Cone_Trunc::Cone_Trunc(float r, float top_r, float h) {
	this->base_center = Dot(0, 0, 0);
	this->top_r = top_r;
	this->r = r;
	this->h = 0;
	this->h_slice = h;
}

Cone_Trunc::Cone_Trunc(Dot base_center, float r, float top_r, float h) : Cone_Trunc(r, top_r, h) {
	this->base_center = base_center;
}

Cone_Trunc::Cone_Trunc(Cone obj, float h_slice) {
	this->r = obj.GetR();
	this->h_slice = h_slice;
	this->h= obj.GetH();
	this->base_center = obj.GetBase();
	float base_l = sqrt(pow(obj.GetH(), 2) + r * r);
	float steepness = base_l / r;
	float this_l = base_l * (h_slice / obj.GetH());
	this->top_r = r - (this_l / steepness);
}

float Cone_Trunc::Volume() {  // Ужасно неудобно использовать метод простого конуса, НО ТЗ ТРЕБУЕТ!!
	if (h == 0) {
		return (1 / 3) * pi * h_slice * (r * r + r * top_r + top_r * top_r);
	}
	else {
		return Cone::Volume() - (1 / 3) * pi * top_r * top_r * (h - h_slice);
	}
}

float Cone_Trunc::Square() {  // Ужасно неудобно использовать метод простого конуса, НО ТЗ ТРЕБУЕТ!!
	if (h == 0) {
		return (1 / 3) * pi * h * (r * r + r * top_r + top_r * top_r);
	}
	else {
		float l_top_slice = sqrt(top_r * top_r + pow(h -h_slice, 2));
		return Cone::Square() - pi * top_r * l_top_slice + top_r * pi * pi;
	}
}

bool Cone_Trunc::operator<(Cone_Trunc obj) {
	return this->Volume() < obj.Volume();
}

bool Cone_Trunc::operator>(Cone_Trunc obj) {
	return this->Volume() > obj.Volume();
}

bool Cone_Trunc::operator==(Cone_Trunc obj) {
	if (Volume() == obj.Volume() && r == obj.r && top_r == obj.top_r) return true;
	else return false;
}

ostream& operator<<(ostream& stream, Cone_Trunc obj) {
	stream << "Center :";
	stream << obj.base_center.x << " " << obj.base_center.y << " " << obj.base_center.z << "  ";
	stream << "h=" << obj.h << "  ";
	stream << "r=" << obj.r << "  ";
	stream << "top_r=" << obj.top_r << "  ";
	return stream;
}

istream& operator>>(istream& stream, Cone_Trunc obj) {
	cout << "Enter elements in order: x, y, z, base_r, h, top_r: ";
	stream >> obj.base_center.x >> obj.base_center.y >> obj.base_center.z;
	stream >> obj.r >> obj.h >> obj.top_r;
	return stream;

}

