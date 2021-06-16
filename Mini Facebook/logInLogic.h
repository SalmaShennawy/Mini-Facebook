#pragma once
#include<string>
#include "User.h"
#define USERS_MAX_NUM 100

extern  User users[USERS_MAX_NUM];
void print();
void writeInfile();
void clearData();
void fillUserCredentials(std::string s, int index);
void fillLoginData(std::string s, int index);
bool checkLoginData();
int getUserIdx(std::string s);
