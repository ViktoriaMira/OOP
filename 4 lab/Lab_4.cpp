#include <iostream>
#include <string>
#include "Header.h"    //подключаем заголовочный файл со структурой класса
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	int LENGTH_TV; //объявляем переменную, в которой будем хранить значение количества элементов

	int LENGTH_Fridge;

	cout << "Enter array length for TV object " << endl;

	cin >> LENGTH_TV;

	TV *arr_TV = new TV[LENGTH_TV]; //создаем динамический массив

	int a, b, i;

	bool c, firm_1;

	for (i = 0; i<LENGTH_TV; i++) {

		cout << "Enter value of brightness, quantity of usb and firm (0 - Tefal, 1 - Supra) for " << i + 1 << " TV" << endl; //заполняем динамический массив

		cin >> a;

		cin >> b;

		cin >> c;

		arr_TV[i] = TV(a, b, c);

		continue;

	}
	cout << "Enter array length for Fridge object " << endl;

	cin >> LENGTH_Fridge;

	Fridge *arr_Fridge = new Fridge[LENGTH_Fridge];

	for (i = 0; i<LENGTH_Fridge; i++) {

		cout << "Enter value of height and volume and firm (0 - Tefal, 1 - Supra) for " << i + 1 << " fridge" << endl; //заполняем динамический массив

		cin >> a;

		cin >> b;

		cin >> c;

		arr_Fridge[i] = Fridge(a, b, c);

		continue;

	}

	//Найдем количество товаров по фирме 1 у холодильников erixon_x
	cout << "Enter firm, for what will be a sort (0 - Tefal, 1 - Supra) " << endl;

	cin >> firm_1;

	if (firm_1 == 1) {
		firm_1 = int(firm_1);
		Fridge object_Fridge;
		for (int i = 0; i < LENGTH_Fridge; i++) {
			object_Fridge = object_Fridge + arr_Fridge[i];   //реализация оператор-функции +
		}
		cout << "Количество холодильников по фирме " << firm_1 << ": " << object_Fridge.GetFirm() << endl;
	}
	else {
		for (int i = 0; i < LENGTH_Fridge; i++) {
			a = a + getGirm_forFridge(arr_Fridge[i], firm_1);
		}
		cout << "Количество холодильников по фирме " << firm_1 << ": " << a << endl;
	}

	if (firm_1 == 1) {
		firm_1 = int(firm_1);
		TV object_tv;
		for (int i = 0; i < LENGTH_TV; i++) {
			object_tv = object_tv + arr_TV[i];         //реализация оператор-функции +
		}
		cout << "Количество телевизоров по фирме " << firm_1 << ": " << object_tv.GetFirm() << endl;
	}
	else {
		for (int i = 0; i < LENGTH_TV; i++) {
			a = a + getGirm_forTV(arr_TV[i], firm_1);
		}
		cout << "Количество телевизоров по фирме " << firm_1 << ": " << a << endl;
	}

	Product product_1;
	TV tv_1;
	Fridge fridge_1;

	Product *prod = &tv_1;
	Product *prod_1 = &fridge_1;
	prod->Get();        //вывод виртуальной функции, переопределенной в производном классе TV
	prod_1->Get();     //вывод виртуальной функции, переопределенной в производном классе Fridge

	
	return 0;

}
