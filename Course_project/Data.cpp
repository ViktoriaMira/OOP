#include"Data.h"

Guest::Guest()
{
	surname = " ";
	name = " ";
	second_name = " ";
	corpus = 0;
	floor = 0;
	room_number = 0;
}

Guest::Guest(string Surname, string Name, string Second_name, int Corpus, int Floor, int Room_number)
{
	surname = Surname;
	name = Name;
	second_name = Second_name;
	corpus = Corpus;
	floor = Floor;
	room_number = Room_number;
}

Guest::~Guest()
{

}

void Guest::ShowGuest()
{
	cout << "ФИО " << surname << " " << name << " " << second_name << endl;
	cout << "Корпус " << corpus << " " << "Этаж " << floor << " " << "Номер комнаты " << room_number << endl;
}

void Guest::ChangeParameters(string Surname, string Name, string Second_name, int Corpus, int Floor, int Room_number)
{
	surname = Surname;
	name = Name;
	second_name = Second_name;
	corpus = Corpus;
	floor = Floor;
	room_number = Room_number;
}

Request::Request()
{
	type = " ";
	data.day = 0;
	data.month = 0;
	data.year = 0;
	price = 0;
}

Request::Request(string Type, Date Data, int Price, string Surname, string Name, string Second_name, 
	int Corpus, int Floor, int Room)
{
	type = Type;
	data.day = Data.day;
	data.month = Data.month;
	data.year = Data.year;
	price = Price;
	SetSurname(Surname);
	SetName(Name);
	SetSecond_name(Second_name);
	SetCorpus(Corpus);
	SetFloor(Floor);
	SetRoom(Room);
}

Request::~Request()
{

}

void Request::Show()
{
	ShowGuest();
	cout << "Тип заявки " << type << endl;
	cout << "Сумма заказа " << price << endl;
	cout << "Дата заказа " << data.day << " " << data.month << " " << data.year << endl;
}

Request& Request::operator=(Request d_o)
{
	this->type = d_o.type;
	this->data.day = d_o.data.day;
	this->data.month = d_o.data.month;
	this->data.year = d_o.data.year;
	this->price = d_o.price;
	return *this;
}

void Request::ChangeParameters(string Type, Date Data, int Price, string Surname, 
	string Name, string Second_name, int Corpus, int Floor, int Room)
{
	type = Type;
	data.day = Data.day;
	data.month = Data.month;
	data.year = Data.year;
	price = Price;
	SetSurname(Surname);
	SetName(Name);
	SetSecond_name(Second_name);
	SetCorpus(Corpus);
	SetFloor(Floor);
	SetRoom(Room);
}

bool operator ==(string another, Request &other)
{
	if (another == other.GetSurname())
	{
		return true;
	}
	else
		return false;
}

