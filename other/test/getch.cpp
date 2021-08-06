#include <iostream>
#include <vector>
#include <array>

using std::endl;

int main()
{
	double arr1[4] = { 2.4, 5.0, 8.45, 7.231 };
	//	1й способ инициализации
	
	
	std::vector<double> arr_temp{ 2.4, 5.0, 8.45, 7.231 };
	

	//	2й способ инициализации

	/*
		std::vector<double> arr2{ arr_temp.begin(), arr_temp.end() };
	*/

	//  3й способ инициализации

	/*
		std::vector<double>arr2;
		arr2.push_back(1.0);
		arr2.push_back(2.0);
		arr2.push_back(3.0);
		arr2.push_back(4.0);

		for (int i : arr2) std::cout << i << ' ';
		std::cout << endl;
	*/
	
	// 4й способ инициализации

	/*
		double arr[] = { 6.0, 8.0, 12.0, 16.0 };
		int n = sizeof(arr)/sizeof(*arr);

		std::vector<double> arr2 (arr, arr+n);
		for (int i : arr2) std::cout << i << ' ';
		std::cout << endl;
	*/
	std::array<double, 4> arr3 = { 5.1, -3.9, 7.0, 43.2 };
	std::array<double, 4> arr4;
	arr4 = arr3;

	//вывод массива статического массива arr1
	std::cout << "Arr 1: ";
	for (int i=0; i<4; i++) std::cout << arr1[i] << ' ';
	std::cout << " &Arr 1: " << arr1 << endl; // По адресу можно сказать, что этот массив находится в стеке
	
	std::cout << "Vector (arr_temp): ";
	std::vector<double>::iterator b = arr_temp.begin();
	std::vector<double>::iterator e = arr_temp.end();
	for (; b!=e; b++) 
	{ 
		std::cout << *b << ' ';
	}
	std::cout << " &Vector (arr_temp): " << &arr_temp[0] << ' ' << endl; //Адрес отличается от адресов стека. 
	// объект vector хранится в динамическом хранилище, в кучке) 

	std::cout << "Arr 3: ";
	for (int i=0; i<arr3.size(); i++) std::cout << arr3[i] << ' ';
	std::cout << " &Arr 3: " << &arr3 << endl; //По адресу видно, что объекты array находятся в стеке

	std::cout << "Arr 4: ";
	for (int i=0; i<arr4.size(); i++) std::cout << arr4[i] << ' ';
	std::cout << " &Arr 4: " << &arr4 << endl; //По адресу видно, что объекты array находятся в стеке

	return 0;
}