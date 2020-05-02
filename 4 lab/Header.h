#include <iostream>

#include <string>

using namespace std;

void Menu() {

	cout << "What are you going to do?" << endl;

	cout << "If you want to see properties, press 1" << endl;

	cout << "If you want to chage properties, press 2" << endl;

	cout << "If you want to calculate quantity by firm, press 3" << endl;

	cout << "If you want exit programm, press 4" << endl;

}

struct Prod {

	string article;

	int quantity;

	string firm;

	int price;

	int TV_brightness;

	int TV_usb;

	int Fridge_height;

	int Fridge_volume;

};

class Product {

	int quantity_1;

	int price_1;

	int quantity_2;

	int price_2;

	string firm_0 = "Tefal";

	string firm_1 = "Supra";

public:

	Product() {

		quantity_1 = 20;

		quantity_2 = 2;

		price_1 = 400;

		price_2 = 38000;

	}

	int GetQuantity_1() {

		return quantity_1;

	}

	int GetQuantity_2() {

		return quantity_2;

	}

	int GetPrice_1() {

		return price_1;

	}

	int GetPrice_2() {

		return price_2;

	}

	string GetFirm_1() {

		return firm_0;

	}

	string GetFirm_2() {

		return firm_1;

	}

	virtual void Get() {                  //виртуальная функция для базового класса
		cout << "Виртуальная функция базового класса\t" << endl;
		cout << "Количество товара 1: " << quantity_1 << endl;
		cout << "Цена товара 1: " << price_1 << endl;
	}

};

class TV : public Product

{
	int brightness;

	int quantity_usb;

	int firm_TV;

	bool  firm0 = 0;

	bool firm1 = 1;

public:

	TV() {

		brightness = 500;

		quantity_usb = 6;

		firm_TV = 0;

	}

	TV(int b, int q_usb, int f_TV) {

		brightness = b;

		quantity_usb = q_usb;

		firm_TV = f_TV;

	}

	TV(int f_TV) {            //перегрузка конструктора производного класса TV
		firm_TV = f_TV;
	}

	int GetQuantity_usb() {

		return quantity_usb;

	}

	int GetBrightness() {

		return brightness;

	}

	int GetFirm() {

		return firm_TV;
	}

	friend int getGirm_forTV(TV a, int sorted_firm); //описание друж. функции

	void Get() {                          //виртуальная функция для производного класса TV
		cout << "Яркость: " << brightness << "\n" << "Фирма телевизора: " << firm_TV << endl;
	}

	TV operator+ (const TV &obj1) {
		TV temp;
		temp.firm_TV = firm_TV + obj1.firm_TV;
		return temp;
	}
};

class Fridge : public Product

{

	int height;

	int volume;

	int firm_Fridge=0;


public:

	Fridge() {

		height = 2001;

		volume = 433;

	}

	Fridge(int h, int v, int f_Fridge) {

		height = h;

		volume = v;

		firm_Fridge = f_Fridge;

	}

	Fridge(int f_Fridge) {
		firm_Fridge = f_Fridge;    //перегрузка конструктора производного класса Fridge
	}

	int GetHeight() {

		return height;

	}

	int Getvolume() {

		return volume;

	}

	int GetFirm() {

		return firm_Fridge;
	}

	friend int getGirm_forFridge(Fridge a, int sorted_firm); //описание друж. функции

	void Get() {                  //виртуальная функция для производного класса Fridge
		cout << "Фирма холодильника: " << firm_Fridge << endl;
	}

	int operator== (const Fridge &obj1) {
		if (obj1.firm_Fridge == 1) {
			return 1;
		}
		else return 0;
	}

	Fridge operator+ (const Fridge &obj1) {
		Fridge temp;
		temp.firm_Fridge = firm_Fridge + obj1.firm_Fridge;
		return temp;
	}
};

int getGirm_forTV(TV a, int sorted_firm) { //друж. функция для класса TV

	if (a.firm_TV == sorted_firm) {

		return 1;

	}

	else {

		return 0;

	}

}

int getGirm_forFridge(Fridge a, int sorted_firm) { //друж. функция для класса Fridge

	if (a.firm_Fridge == sorted_firm) {

		return 1;

	}

	else {

		return 0;

	}

}
