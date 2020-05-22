#include"Function.h"

int state_menu;

void menu() {
	cout << "Выберите действие: " << endl
		<< "(0) Выход из файла " << endl
		<< "(1) Ввод данных" << endl
		<< "(2) Вывод данных" << endl
		<< "(3) Редактировать данные" << endl
		<< "(4) Добавить заявку" << endl
		<< "(5) Удалить заявку" << endl
		<< "(6) Отсортировать заявки в алфавитном порядке" << endl
		<< "(7) Сохранить данные в файл" << endl
		<< "(8) Посчитать  заказов для гостя" << endl
		<< "Ваш выбор: ";
	cin >> state_menu;
}

int main()
{
	
	setlocale(LC_CTYPE, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	menu();
	int _actions;
	string filename;

	int _size = 0;
	Request* d = new Request[_size];
	
	

	while (state_menu != 0)
	{
		switch (state_menu)
		{
		case 1:
			system("cls");
			cout << "Вывести данные в консоль или в файл (1/2)? ";
			cin >> _actions;

			system("cls");
			
			if (_actions == 1)
			{
				DataCin(d, _size);
			}
			else {
				DataReadFromFile(d, _size, "Input.txt");
			}
			system("pause");
			system("cls");
			menu();
			break;

		case 2:
			system("cls");

			if (_size != 0)
				Print(d, _size);
			else
				cout << "Data is empty" << endl;
			system("pause");
			system("cls");
			menu();
			break;

		case 3:
			system("cls");

			if (_size != 0)
				DataChange(d, _size);
			else cout << "Data is empty" << endl;
			system("pause");
			system("cls");
			menu();
			break;

		case 4:
			system("cls");

			if (_size != 0)
				AddData(d, _size);
			else cout << "Data is empty" << endl;
			system("pause");
			system("cls");
			menu();
			break;

		case 5:
			system("cls");
			if (_size != 0)
				DeleteData(d, _size);
			else cout << "Data is empty" << endl;
			system("pause");
			system("cls");
			menu();
			break;

		case 6:
			system("cls");
			if (_size != 0)
				SortingData(d, _size);
			else cout << "Data is empty" << endl;
			system("pause");
			system("cls");
			menu();
			break;

		case 7:
			system("cls");
			if (_size != 0)
				SaveData(d, _size, "Output.txt");
			else cout << "Data is empty" << endl;
			system("pause");
			system("cls");
			menu();
			break;

		case 8:
			
			system("cls");
			SumRequest(d, _size, "Output.txt");
			system("pause");
			system("cls");
			menu();
			break;
			

		default:
			cout << "Wrong" << endl;
			system("cls");
			menu();
			break;

		}
	}
	system("cls");
	cout << "Finish" << endl;
	system("pause");
}
