
#include <iostream>

int main()
{
	setlocale(LC_ALL, "RUS");
	std::cout << "Введите стороны паралллелепипеда: "<<std::endl;

	int a, b, c;
	std::cin >> a >> b >> c;
	int V=a*b*c;
	std::cout << "Объем паралллелепипеда равен: " << V;
}


