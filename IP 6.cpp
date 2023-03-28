#include "Cone.h"
#include "Cone_Trunc.h"
#include <iostream>
#include <vector>
//#include "Ocean.h"
//#include "Sea.h"
//#include "Bay.h"
using namespace std;


int main()
{
	// А

	//float r, h;
	//int basex, basey, basez;
	//int n;
	//cout << "Enter number of elements: ";
	//cin >> n;
	//vector<Cone> arr(n);
	//for (int i = 0; i < n; i++) {
	//	bool base_exist;
	//	cout << "Enter order: 1-  base_center, r, h   0 - r, h";
	//	cin >> base_exist;
	//	if (base_exist) {
	//		cin >> basex >> basey >> basez >> r >> h;
	//		Dot base = Dot(basex, basey, basez);
	//		arr[i].set(base, r, h);
	//	}

	//	else {
	//		cin >> r >> h;
	//		arr[i].set(r, h);
	//	}
	//	cout << arr[i];
	//	cout << "Volume " << arr[i].Volume() << endl;
	//	cout << "Square " << arr[i].Square() << endl;
	//}

	// Б

	Cone a = Cone(5, 6);
	Cone_Trunc b = Cone_Trunc(a, 3);
	Cone_Trunc c;
	cin >> c;
	cout << b << " " << b.Square() << " " << b.Volume() << endl;
	cout << c << " " << c.Square() << " " << c.Volume() << endl;


}


