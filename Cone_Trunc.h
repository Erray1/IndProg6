#include "Cone.h"
#pragma once

class Cone_Trunc : public Cone
{
protected:
	float top_r;
	float h_slice;
	friend ostream& operator<<(ostream& stream, Cone_Trunc obj);
	friend istream& operator>>(istream& stream, Cone_Trunc obj);
public:
	Cone_Trunc();
	Cone_Trunc(float r, float top_r, float h);
	Cone_Trunc(Dot base_center, float r, float top_r, float h);
	Cone_Trunc(Cone obj, float h);
	float Square();
	float Volume();
	bool operator>(Cone_Trunc obj);
	bool operator<(Cone_Trunc obj);
	bool operator==(Cone_Trunc obj);
};

