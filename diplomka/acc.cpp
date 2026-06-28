#include <iostream>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include "tasks.h"
#include "birthday.h"
#include "main.h"
#include "acc.h"

using namespace std;
string currentUser;



void registerUser()
{
	string login, password;

	cout << "Придумайте логин: ";
	getline(cin, login);

	cout << "Придумайте пароль: ";
	getline(cin, password);

	ofstream file("users.txt", ios::app);

	file << login << " " << password << endl;

	file.close();

	system("cls");
	cout << "Регистрация завершена!\n";

}

bool loginUser()
{
	string login, password;

	cout << "Логин: ";
	getline(cin, login);

	cout << "Пароль: ";
	getline(cin, password);

	ifstream file("users.txt");

	string fileLogin;
	string filePassword;

	while (file >> fileLogin >> filePassword)
	{
		if (login == fileLogin && password == filePassword)
		{
			currentUser = login;
			file.close();
			system("cls");
			cout << "Авторизация прошла успешно!\n";
			return true;
		}
	}

	file.close();

	return false;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int choise1;
	SetConsoleTitleA("ToDo List");

	system("color 0A");
	system("mode con cols=100 lines=30");

	do
	{
		cout << "-=-=-=-=-=-=-=Авторизация=-=-=-=-=-=-=-=-\n";
		cout << "1.Авторизоватся\n";
		cout << "2.Регистрация\n";
		cout << "0.Выйти\n";
		cout << "Выберите действие: ";
		choise1 = inputInt();
		switch (choise1)
		{
		case 1:
			if (loginUser())
			{
				
				menu();
				
				return 0;
			}
			else
			{
				cout << "Неверный логин или пароль!\n";
			}
			break;
		case 2:
			registerUser();
			break;
		case 0:
			cout << "Выход из программы.\n";
			break;
		default:
			cout << "Такого выбора нет!\n";
			break;
		}

	} while (choise1 != 0);
}