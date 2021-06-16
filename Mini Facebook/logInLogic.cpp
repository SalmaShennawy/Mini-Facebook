#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <map>
//#include "logInLogic.h"
#include "logInConsole.h"

#define INFO_NUM 11
#define USERS_MAX_NUM 100

using namespace std;

ofstream credentials("textFile.txt");
vector < string > userCredentials(INFO_NUM);
string loginData[3];
User users[USERS_MAX_NUM];
map <string, int > userIdx;
int currUserIdx = 0;
int loggedInUserIdx = -1;

void print()
{
	for (auto e : userCredentials)
		cout << e << endl;
}
void clearData()
{
	userCredentials.resize(INFO_NUM);
}
void fillUserCredentials(string s, int index)
{
	userCredentials[index] = s;
	if (!index)
		users[currUserIdx].name = s;
	if (index == 1)
		users[currUserIdx].lastName = s;
	if (index == 2)
	{
		users[currUserIdx].email = s;
		userIdx[s] = currUserIdx;

	}
	if (index == 3)
		users[currUserIdx].password = s;
	if (index == 4)
		users[currUserIdx].birthday = s;
	if (index == 5)
		users[currUserIdx].birthmonth = s;
	if (index == 6)
	{
		users[currUserIdx].birthyear = s;
		
	}
	if (index == 7)
	{
		users[currUserIdx].gender = s;
		
	}
	if (index == 8)
	{
		users[currUserIdx].work = s;
		
	}
	if (index == 9)
	{
		users[currUserIdx].education = s;
		
	}
	if (index == 10)
	{
		users[currUserIdx].place = s;
		currUserIdx++;
	}

}

void writeInfile()
{
	for (auto e : userCredentials)
		credentials << e << endl;
}
void fillLoginData(string s, int index)
{
	loginData[index] = s;

}
string Names[100];
bool checkLoginData()
{
	int line = 1;
	ifstream MyReadFile("textFile.txt");
	string s;
	bool email = false, pass = false;

	while (getline(MyReadFile, s))
	{
		if (line == 3)
		{
			email = (s == loginData[0]);
		}
		if (line == 4)
		{
			pass = (s == loginData[1]);
		}
		if (line == 4 && email && pass)
		{


			return true;
		}
		else if (line >= 4)
			email = 0, pass = 0;

		line++;
		line %= 11;


	}
	return false;

}
int getUserIdx(string s)
{
	//cout << s << " " << userIdx[s] << endl;
	return userIdx[s];
}
void logout()
{
	system("CLS");
	menu();

}