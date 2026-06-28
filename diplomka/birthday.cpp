#include <iostream>
#include <fstream>
#include <ctime>
#include "birthday.h"
#include "acc.h"

using namespace std;

Birthday birthdays[100];
int birthdayCount = 0;

void showBirthdays()
{
    if (birthdayCount == 0)
    {
        system("cls");
        cout << "Список дней рождения пуст.\n";
        return;
    }
    system("cls");
    cout << "\n===== ДНИ РОЖДЕНИЯ =====\n";

    for (int i = 0; i < birthdayCount; i++)
    {
        cout << i + 1 << ". " << birthdays[i].name << " - " << birthdays[i].day << "." << birthdays[i].month << endl;
    }
}

void checkBirthdays()
{
    time_t now = time(nullptr);
    tm local;

    localtime_s(&local, &now);

    int todayDay = local.tm_mday;
    int todayMonth = local.tm_mon + 1;

    for (int i = 0; i < birthdayCount; i++)
    {
        if (birthdays[i].day == todayDay &&
            birthdays[i].month == todayMonth)
        {
            system("cls");
            cout << " Сегодня день рождения у " << birthdays[i].name << "!\n";
        }
    }
}

void saveBirthdays()
{
    ofstream file(currentUser + "_birthdays.txt");

    for (int i = 0; i < birthdayCount; i++)
    {
        file << birthdays[i].name << " " << birthdays[i].day << " " << birthdays[i].month << endl;
    }

    file.close();
}

void loadBirthdays()
{
    ifstream file(currentUser + "_birthdays.txt");
    birthdayCount = 0;

    while (file >> birthdays[birthdayCount].name >> birthdays[birthdayCount].day >> birthdays[birthdayCount].month)
    {
        birthdayCount++;
        if (birthdayCount >= 100)
        {
            break;
        }
    }

    file.close();
}

void deleteBirthday()
{
    if (birthdayCount == 0)
    {
        system("cls");
        cout << "Нет дней рождении для удаления!\n";
        return;
    }

    int Dindex;
    cout << "Введите номер дня рождения для удаления: ";
    cin >> Dindex;

    if (Dindex < 1 || Dindex > birthdayCount)
    {
        system("cls");
        cout << "Неверный номер!\n";
        cin.ignore();
        return;
    }

    for (int i = Dindex - 1; i < birthdayCount - 1; i++)
    {
        birthdays[i] = birthdays[i + 1];
    }

    birthdayCount--;
    cin.ignore(10000, '\n');

    system("cls");
    cout << "Удалено!\n";
}

void addBirthday()
{

        if (birthdayCount >= 100)
        {
            system("cls");
            cout << "Список заполнен!\n";
            return;
        }
        
        system("cls");
        cout << "Введите имя: ";
        getline(cin, birthdays[birthdayCount].name);

        cout << "Введите день рождения (день): ";
        cin >> birthdays[birthdayCount].day;

        while (birthdays[birthdayCount].day < 1 || birthdays[birthdayCount].day > 31)
        {
            cout << "Ошибка! День должен быть от 1 до 31.\n";
            cout << "Введите день: ";
            cin >> birthdays[birthdayCount].day;
        }

        cout << "Введите месяц рождения: ";
        cin >> birthdays[birthdayCount].month;

        while (birthdays[birthdayCount].month < 1 ||
       birthdays[birthdayCount].month > 12)
{
    cout << "Ошибка! Месяц должен быть от 1 до 12.\n";
    cout << "Введите месяц: ";
    cin >> birthdays[birthdayCount].month;
}

        birthdayCount++;

       cout << "День рождения добавлен!\n";
       cin.ignore(10000, '\n');
       saveBirthdays();
        
}
