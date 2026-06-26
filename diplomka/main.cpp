#include <iostream>
#include <Windows.h>
#include <ctime>
#include "tasks.h"
#include "birthday.h"

using namespace std;

void menu()
{
    

    loadTasks();
    loadBirthdays();

    int choice;

    time_t now = time(nullptr);
    tm local;

    localtime_s(&local, &now);
    int Day = local.tm_mday;
    int Month = local.tm_mon + 1;
    do
    {
        checkBirthdays();
        cout << "\nДата: " << Day << "." << Month << endl;
        cout << "========== СПИСОК ДЕЛ ==========\n";
        cout << "1. Добавить задачу\n";
        cout << "2. Показать задачи\n";
        cout << "3. Удалить задачу\n";
        cout << "4. Добавить день рождения\n";
        cout << "5. Показать дни рождения\n";
        cout << "6. Удалить день рождения\n";
        cout << "7. Сохранить в файл\n";
        cout << "0. Выход\n";
        
        cout << "Выберите: ";

        cin >> choice;
        cin.ignore(10000, '\n');

        switch (choice)
        {
        case 1:
            addTask();
            cout << "Задача добавлена!\n";
            break;

        case 2:
            showTasks();
            break;

        case 3:
            deleteTask();
            break;

        case 4:
            addBirthday();
            break;

        case 5:
            showBirthdays();
            break;
        case 6:
            deleteBirthday();
            break;
        case 7:
            saveTasks();
            saveBirthdays();
            break;
        case 0:
            saveBirthdays();
            saveTasks();
            system("cls");
            cout << "Сохранено. Выход из программы.\n";
            break;

        default:
            system("cls");
            cout << "Такого выбора нет!\n";
        }

    } while (choice != 0);
}