#pragma once
#include <string>
using namespace std;

extern string tasks[100];
extern int taskCount;

void addTask();
void showTasks();
void deleteTask();
void saveTasks();
void loadTasks();