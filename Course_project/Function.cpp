#include"Function.h"

void DataCin(Request* (&d), int& n)
{
	string Type;
	Date Data;
	int Price;
	string surname,
		name,
		second_name;
	int corpus,
		floor,
		room_number;

	cout << "Введите размер массива ";
	cin >> n;

	d = new Request[n];

	for (int i = 0; i < n; i++)
	{
		cout << "Введите ФИО ";
		cin >> surname >> name >> second_name;

		cout << "Введите адрес (корпус, этаж, комната) ";
		cin >> corpus >> floor >> room_number;

		cout << "Введите тип заявки ";
		cin >> Type;

		cout << "Введите дату ";
		cin >> Data.day >> Data.month >> Data.year;

		cout << "Введите цену ";
		cin >> Price;

		d[i].ChangeParameters(Type,  Data, Price, surname, name, second_name, corpus, floor, room_number);
		cout << "_______________________________________________" << endl;
	}
}

void DataReadFromFile(Request* (&d), int& n, string namefile)
{
	ifstream reading(namefile);

	if (reading)
	{
		string Type;
		Date Data;
		int Price;
		string surname,
			name,
			second_name;
		int corpus,
			floor,
			room_number;

		reading >> n;

		d = new Request[n];

		for (int i = 0; i < n; i++)
		{
			reading >> surname >> name >> second_name;

			reading >> corpus >> floor >> room_number;

			reading >> Type;

			reading >> Data.day >> Data.month >> Data.year;

			reading >> Price;

			d[i].ChangeParameters(Type, Data, Price, surname, name, second_name, corpus, floor, room_number);
		}
		cout << "Данные считаны" << endl;
	}
	else
		cout << "Ошибка открытия файла" << endl;

	reading.close();
}

void Print(Request * d, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Данные№ " << i + 1 << endl;

		d[i].Show();
		cout << "_____________________________________________________" << endl;
	}
}

void DataChange(Request* d, int n)
{
	string Type;
	Date Data;
	int Price;
	string surname,
		name,
		second_name;
	int corpus,
		floor,
		room_number;
	int _n;

	cout << "Введите номер нужного элемента (от 1 до " << n << ") ";
	cin >> _n;

	_n--;

	if (_n >= 0 && _n < n)
	{
		cout << "Введите новое ФИО ";
		cin >> surname >> name >> second_name;

		cout << "Введите новый адрес (корпус, этаж, комната) ";
		cin >> corpus >> floor >> room_number;

		cout << "Введите новый тип заявки: ";
		cin >> Type;

		cout << "Введите новую дату ";
		cin >> Data.day >> Data.month >> Data.year;

		cout << "Введите новую цену ";
		cin >> Price;

		

		d[_n].ChangeParameters(Type, Data, Price, surname, name, second_name, corpus, floor, room_number);

	}
	else
		cout << "Номер введен неверно" << endl;
}

void Copy(Request *d_n, Request *d_o, int n)
{
	for (int i = 0; i < n; i++)
	{
		d_n[i] = d_o[i];
	}
}

void AddData(Request* (&d), int& n)
{
	string Type;
	Date Data;
	int Price;
	string surname,
		name,
		second_name;
	int corpus,
		floor,
		room_number;
	Request* buf = new Request[n];
	int size = n, new_size = ++n;

	Copy(buf, d, size);

	d = new Request[new_size];

	Copy(d, buf, size);

	cout << "Введите новое ФИО ";
	cin >> surname >> name >> second_name;

	cout << "Введите новй адрес (корпус, этаж, комната) ";
	cin >> corpus >> floor >> room_number;

	cout << "Введите новый тип заявки: ";
	cin >> Type;


	cout << "Введите новую дату ";
	cin >> Data.day >> Data.month >> Data.year;

	cout << "Введите новую цену ";
	cin >> Price;

	d[size].ChangeParameters(Type,  Data, Price, surname, name, second_name, corpus, floor, room_number);

	cout << "Данные добавлены" << endl;

	delete[] buf;


}
void DeleteData(Request* (&d), int& n)
{
	int _n;
	Request* buf = new Request[n];

	cout << "Введите номер нужного элемента (от 1 до " << n << ") ";
	cin >> _n;

	_n--;

	if (_n >= 0 && _n < n) {
		Copy(buf, d, n);
		int q = 0;
		n--;

		d = new Request[n];

		for (int i = 0; i <= n; i++)
		{
			if (i != _n)
			{
				d[q] = buf[i];
				q++;
			}
		}
		cout << "Данные удалены" << endl;
	}
	else
		cout << "Номер введен неверно" << endl;

	delete[] buf;
}
void SortingData(Request* d, int& n)
{
	Request buf;
	int numsorted = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++)
		{
			if (d[i].GetSurname() > d[j].GetSurname())
			{
				buf = d[i];
				d[i] = d[j];
				d[j] = buf;

				numsorted++;
			}
		}
	}

	cout << "Данные отсортированы! Количество иттераций " << numsorted << endl;
}
void SaveData(Request* d, int& n, string namefile)
{
	ofstream record(namefile);

	if (record) {
		record << n << endl;

		for (int i = 0; i < n; i++) {
			record << d[i].GetSurname() << " " << d[i].GetName() << " " << d[i].GetSecond_Name() << endl;
			record << d[i].GetCoprus() << " " << d[i].GetFloor() << " " << d[i].GetRoom() << endl;
			record << d[i].GetType() << endl;
			record << d[i].GetDate().day << " " << d[i].GetDate().month << " " << d[i].GetDate().year << endl;
			record << d[i].GetPrice() << endl;
			

			if (i < n - 1)
			{
				record << endl;
			}
		}
	}
	else
		cout << "Ошибка открытия файла" << endl;

	cout << "Данные сохранены в файл " << namefile << endl;

	record.close();
}

void SumRequest(Request* &d, int &n, string namefile)
{
	string surname;
	int sum = 0;
	DataReadFromFile(d, n, namefile);
	cout << "Введите фамилию, по которой хотите посчитать сумму заявки " << endl;
	cin >> surname;

	for (int i = 0; i < n; i++)
	{
		if (surname == d[i]) 
		{
			sum = sum + d[i].GetPrice();
		}
		else
			cout << " nope";
	}

	cout << "Сумма всех заказов гостя составляет " << sum << " руб." << endl;
}
