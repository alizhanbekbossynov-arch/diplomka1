#pragma once
#include <string>
using namespace std;

struct Birthday
{
    string name;
    int day;
    int month;
};

extern Birthday birthdays[100];
extern int birthdayCount;

void addBirthday();
void showBirthdays();
void deleteBirthday();
void saveBirthdays();
void loadBirthdays();
void checkBirthdays();