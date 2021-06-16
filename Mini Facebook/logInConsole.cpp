#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include "logInLogic.h"
#include"User.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <direct.h>
#include <stdio.h>
#include "User.h"
#include"Post.h"
#include"logInConsole.h"
#include <stdlib.h>
using namespace std;


void Displaymenu(string s) {

	int m = 9;
	while (true) {
		cout << "Display main menu ?(Y/N)";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			cout << "press 1 to post on your timeline\n";
			cout << "press 2 to display your timeline\n";
			cout << "press 3 to add friend\n";
			cout << "press 4 to display newsfeed\n";
			cout << "press 5 to display your friends\n";
			cout << "press 6 to display notifictions.\n"; // new 
			cout << "press 7 to chat with friend. \n";
			cout << "press 8 to display your conversations \n";
			cout << "Press 9 to create a group\n";
			cout << "Press 10 to join group \n";
			cout << "Press 11 to display all groups\n";
			cout << "Press 12 to display your groups\n";
			cout << "press 13 to post in a group\n";
			cout << "Press 14 to display group feed\n";
			cout << "Press 15 to invite a friend to join  a group\n";
			cout << "press 16 for guess number game .\n"; 
			cout << "press 17 to play Tic Tac Toe.\n"; 
			cout << "press 18 to exit\n";
			cout << "Press 19 to logout\n";
			cin >> m;
			int currUser = getUserIdx(s);
			if (m == 18) exit(0);
			if (m == 1) {
				cout << " " << endl;
				cout << "Write something to Post on your Timeline....... : " << endl;
				string paragraph;
				cin.ignore();
				getline(cin, paragraph);

				users[currUser].UPost(paragraph, users[currUser]);
			}
			if (m == 2) users[currUser].timeline(users[currUser].name);
			if (m == 3) {
				cout << "Enter his/her email\n";
				string f;
				cin >> f;
				users[currUser].AddFriend(users[getUserIdx(f)]);
			}
			if (m == 4) users[currUser].Newsfeed(users[currUser].name, users[currUser]);
			if (m == 5) users[currUser].DisplayFriends();
			if (m == 6) users[currUser].displayNotifications();  
			
			if (m == 7) users[currUser].AddChattingFriend();
			if (m == 8) users[currUser].DisplayConversation();
			if (m == 9)
			{
				cout << "Please enter group name" << endl;
				string s;
				cin.ignore();
				getline(cin, s);
				users[currUser].createGroup(s);
			}
			if (m == 10)
			{
				cout << "Please enter group name  you would like to join" << endl;
				
				cin.ignore();
				getline(cin, s);
				
				users[currUser].joinGroup(s);
			}
			if (m == 11)
			{
				users[currUser].displayAllGroups();
			}
			if (m == 12)
			{
				users[currUser].displayUserGroups();
			}
			if (m == 13)
			{
				cout << "Please enter your group name\n";
				cin.ignore();
				getline(cin, s);
				users[currUser].UpostInGroup(s);
			}
			if (m == 14)
			{
				cout << "Please enter group name\n";
				cin.ignore();
				getline(cin, s);
				users[currUser].displayGroupPosts(s);
			}
			if (m == 15)
			{
				string s, ss;
				cout << "Please enter yout friend's email: ";
				cin >> s;
				cout << "Please enter group name: ";
				cin.ignore();
				getline(cin, ss);
				users[getUserIdx(s)].joinGroup(ss);

			}
			if (m == 16) RandomGame();
			if (m == 17) TicTacToe();
			if (m == 19) logout();

		}
		else {
			cout << "Are you sure you want to exit ?(Y/N)";
			cin >> choice;
			if (choice == 'Y' || choice == 'y') break;
			else continue;
		}
	}
}
	char square[10] = { '1','2','3','4','5','6','7','8','9' };
	void TicTacToe() {
		
		int i;
		char mark;
		int cnt = 0;
		do {
			DisplayBoard();

			if (cnt % 2 == 0) {
				cout << "Player  1 (X) , enter a number:  ";
				mark = 'X';

			}
			else {
				cout << "Player  2  (O), enter a number:  ";
				mark = 'O';
			}
			int choice;

			cin >> choice;
			if (choice == 1 && square[0] == '1')square[0] = mark;
			else if (choice == 2 && square[1] == '2')square[1] = mark;
			else if (choice == 3 && square[2] == '3')square[2] = mark;
			else if (choice == 4 && square[3] == '4')square[3] = mark;
			else if (choice == 5 && square[4] == '5')square[4] = mark;
			else if (choice == 6 && square[5] == '6')square[5] = mark;
			else if (choice == 7 && square[6] == '7')square[6] = mark;
			else if (choice == 8 && square[7] == '8')square[7] = mark;
			else if (choice == 9 && square[8] == '9')
				square[8] = mark;





			i = win();
			if (i == 1 && cnt % 2 == 0) {
				DisplayBoard();
				cout << " Player 1 wins !!!\n";
				cout << "**************************************\n";
				char c;

				cout << "Do You Want to Play Again ?(y/n)\n";
				cin >> c;
				if (c == 'y') TicTacToe();
				if (c == 'n') return;

			}
			else if (i == 1) {
				DisplayBoard();
				cout << " Player 2 wins !!!\n";
				cout << "**************************************\n";
				char c;

				cout << "Do You Want to Play Again ?(y/n)\n";
				cin >> c;
				if (c == 'y') TicTacToe();
				if (c == 'n') return;
			}

			cnt++;
		} while (i == -1);
	

}
int win() {
	if (square[0] == square[1] && square[1] == square[2]) return 1;
	if (square[3] == square[4] && square[4] == square[5]) return 1;
	if (square[6] == square[7] && square[7] == square[8]) return 1;
	if (square[0] == square[3] && square[3] == square[6]) return 1;
	if (square[1] == square[4] && square[4] == square[7]) return 1;
	if (square[2] == square[5] && square[5] == square[8]) return 1;
	if (square[0] == square[4] && square[4] == square[8]) return 1;
	if (square[2] == square[4] && square[4] == square[6]) return 1;
	return -1;

}
void DisplayBoard() {
	system("cls");
	cout << "*********  Tic Tac Toe  *********\n" ;
	cout << "Player 1 (X)  -  Player 2 (O)" ;

	cout << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[0] << "  |  " << square[1] << "  |  " << square[2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[3] << "  |  " << square[4] << "  |  " << square[5] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << square[6] << "  |  " << square[7] << "  |  " << square[8] << endl;
	cout << "     |     |     " << endl << endl;
	
}


void RandomGame() {
	system("cls");
	cout << "*********  Number Guess Game  *********" << endl;
	int number = rand() % 10;
	int guess;
	int Tries=0;
	cout << "Guess number between 1 and 9\n";
	cin >> guess;
	while (guess != number) {
		 if (abs(guess - number) == 1)cout << "SO CLOSE !!\n";
		 else cout << "Try next time \n";
		 cin >> guess;
		 Tries++;
	}
	 cout << "Good Job! You made it after " << Tries << "  times\n";

	cout << "Do you want to play again ? (y/n)\n";
	char choice;
	cin >> choice;
	if (choice == 'y') RandomGame();
	if (choice == 'n') return;

}

void menu()
{
	cout << "Do you want to:" << endl;
	cout << "1-Login" << endl;
	cout << "2-Register" << endl;
	int x;
	cin >> x;
	while (x != 1 && x != 2)
	{
		cout << "Please enter a valid choice" << endl;
		cin >> x;
	}

	if (x == 1)
	{
		login();
	}
	if (x == 2)
	{
		Register();
		menu();
	}

}
bool login()
{
	string s;
	cout << "Enter your mail " << endl;
	cin >> s;
	fillLoginData(s, 0);
	string mail = s;
	cout << "Enter your password " << endl;
	cin >> s;
	fillLoginData(s, 1);
	while (!checkLoginData())
	{
		cout << "Invalid username or password" << endl;
		cout << "Do you want to register ? (Y/N)";
		char choice;
		cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			Register();
		
		}
	
		cout << "Enter your mail " << endl;
		cin >> s;
		mail = s;
		fillLoginData(s, 0);
		cout << "Enter your password " << endl;
		cin >> s;
		fillLoginData(s, 1);
		
		//Displaymenu();
		/*
		cout << "Back to main menu? [Y/N] " << endl;
		cin >> s;
		if (s == "Y")
			menu();
			*/

	}
	Displaymenu(mail);
	return true;
}





void PassWord()
{
	bool correctPassword = false;
	string password;
	int number=0;
	while (correctPassword == false)
	{
		cout << "Please enter a password: \n";
		cin >> password;
		correctPassword = true;

		if (password.length() < 8)
		{
			correctPassword = false;
			cout << "Your password  must be at least 8 characters\n";
			continue;
		}
		for (int i = 0; i < password.length(); i++)
		{
			if ((!(isdigit(password[i]))) && (!(isalpha(password[i]))))
			{
				correctPassword = false;
				cout << "You have entered an invalid character.\n";
			}
			else if (isdigit(password[i]))
				number++;

		}
		if (number < 2)
		{
			correctPassword = false;
			cout << " You must have at least two digits in the password." << endl;
		}

	}
	fillUserCredentials(password, 3);
}
string email;

void Email()
{
	cout << "Please enter your E-mail " << endl;
	cin >> email;
	while (email.find('@') == -1 && email.find(".com") == -1)
	{
		cout << "Your mail must be in the form of example@gmai.com" << endl;
		cin >> email;
	}
	fillUserCredentials(email, 2);
}

int y;
string str;
void birthYear()
{
	cout << "Please enter your birth year " << endl;
	cin >> y;
	while (y > 2009 || y < 1901)
	{
		cout << "Sorry, you can't sign up! Min age is 12+";
		cout << "Please enter your birth year " << endl;
		cin >> y;
	}
	str = to_string(y);
	fillUserCredentials(str, 6);
}




void Register()
{
	string s;
	cout << "Please enter your first name " << endl;
	cin >> s;
	fillUserCredentials(s, 0);
	cout << "Please enter your surname " << endl;
	cin >> s;
	fillUserCredentials(s, 1);
	
	Email();

	PassWord();

	cout << "Please enter your birth day " << endl;
	cin >> s;
	while (!(stoi(s) >= 1 && stoi(s) <= 31))
	{
		cout << "Please enter a day in range [1-31]\n";
		cin >> s;
	}
	fillUserCredentials(s, 4);
	cout << "Please enter your birth month " << endl;
	cin >> s;
	while (!(stoi(s) >= 1 && stoi(s) <= 12))
	{
		cout << "Please enter a day in range [1-12]\n";
		cin >> s;
	}
	fillUserCredentials(s, 5);
	birthYear();
	cout << "Please enter you gender [Female/Male]" << endl;
	cin >> s;
	fillUserCredentials(s, 7);
	cout << "Please enter your work :" << endl;
	cin >> s;
	fillUserCredentials(s, 8);
	cout << "Please enter your education :" << endl;
	cin >> s;
	fillUserCredentials(s, 9);
	cout << "Where do you live ?" << endl;
	cin >> s;
	fillUserCredentials(s, 10);
	writeInfile();
	

}