#include <iostream>
#include <fstream>
#include <ctime>
#include "tasks.h"
#include "acc.h"

using namespace std;

string tasks[100];
int taskCount = 0;

void addTask()
{
    time_t now = time(nullptr);
    tm local;

    localtime_s(&local, &now);
    int Day = local.tm_mday;
    int Month = local.tm_mon + 1;
    string date = to_string(Day) + "." + to_string(Month);

    string temp;

    if (taskCount >= 100)
    {
        system("cls");
        cout << "Список заполнен!\n";
        return;
    }

    system("cls");
    cout << "Введите задачу: ";
    getline(cin, temp);

    while (temp.empty()|| temp.find_first_not_of(' '))
    {
        cout << "Ошибка! Введите задачу\n";
        cout << "Введите задачу: ";
        getline(cin, temp);
    }

    tasks[taskCount] = temp + " |дата добавления задачи: " + date;

    taskCount++;
}

void showTasks()
{
    if (taskCount == 0)
    {
        system("cls");
        cout << "Список пуст.\n";
        return;
    }
    system("cls");
    cout << "\n========== ЗАДАЧИ ==========\n";

    for (int i = 0; i < taskCount; i++)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void deleteTask()
{
    if (taskCount == 0)
    {
        system("cls");

        cout << "Нет задач для удаления!\n";
        return;
    }

    int Dindex;
    cout << "Введите номер задачи для удаления: ";
    cin >> Dindex;

    if (Dindex < 1 || Dindex > taskCount)
    {
        cout << "Неверный номер!\n";
        cin.ignore();
        return;
    }

    for (int i = Dindex - 1; i < taskCount - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }

    taskCount--;
    cin.ignore(10000, '\n');
    
    system("cls");
    cout << "Удалено!\n";
}
void saveTasks()
{
    ofstream file(currentUser + "_tasks.txt");

    for (int i = 0; i < taskCount; i++)
    {
        file << tasks[i] << endl;
    }

    file.close();
    system("cls");
    cout << "Сохранено в файл!\n";
}

void loadTasks()
{
    ifstream file(currentUser + "_tasks.txt");
    taskCount = 0;

    while (getline(file, tasks[taskCount]))
    {
        taskCount++;
        if (taskCount >= 100) break;
    }

    file.close();
}