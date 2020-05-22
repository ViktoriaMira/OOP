#pragma once

#include <iostream>
#include<string>
#include<fstream>
#include<Windows.h>

using namespace std;

/*
Данные:
1. ФИО
2. Адрес (корпус, этаж, номер комнаты)
3. Дата
4. Количество заявок
5. Тип заявок
6. Конечная сумма
*/

struct Date
{
	int day,
		month,
		year;
};

class Guest
{
private:
	string surname,
		name,
		second_name;
	int corpus,
		floor,
		room_number;
public:
	Guest();
	Guest(string Surname, string Name, string Second_name, int Corpus, int Floor, int Room_number);
	~Guest();

	void ShowGuest();
	void ChangeParameters(string Surname, string Name, string Second_name, int Corpus, int Floor, int Room_number);

	string GetSurname() { return surname; }
	string GetName() { return name; }
	string GetSecond_Name() { return second_name; }
	int GetCoprus() { return corpus; }
	int GetFloor() { return floor; }
	int GetRoom() { return room_number; }

	void SetSurname(string Surname) { surname = Surname; }
	void SetName(string Name) { name = Name; }
	void SetSecond_name(string Second_name) { second_name = Second_name; }
	void SetCorpus(int Corpus) { corpus = Corpus; }
	void SetFloor(int Floor) { floor = Floor; }
	void SetRoom(int Room) { room_number = Room; }
};

class Request : public Guest
{
private:
	string type;
	Date data;
	int price;



public:
	Request();
	Request(string Type, Date Data, int Price, string Surname, string Name, 
		string Second_name, int Corpus, int Floor, int Room);
	~Request();

	void Show();
	void ChangeParameters(string Type, Date Data, int Price, string Surname, string Name, 
		string Second_name, int Corpus, int Floor, int Room);

	string GetType() { return type; }
	Date GetDate() {return data;}
	int GetPrice() { return price; }
	Request& operator=(Request d_o);
	
	


};

bool operator ==(string another, Request &other);
