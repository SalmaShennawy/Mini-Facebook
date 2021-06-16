#include "User.h"
#include<string>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <dos.h>
#include <direct.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <stack>
#include "Groups.h"
#include "logInLogic.h"
using namespace std;
int POST_ORDER = 0;
std::deque<std::pair<int, Post>>User::NewsPosts;
int User::numofposts=0;
std::vector<Groups> allGroups;
User::User(std::string x) {

	name = x;
	NumOfFriends = 0;
	numofposts = 0;
}

User::User() {

	name = "";
	NumOfFriends = 0;
	numofposts = 0;
}

void User::UPost(string paragraph,User u) {
	Post p;
	p.content = paragraph;
	p.writer = u.name;

	++POST_ORDER;
	Posts.push_back({ POST_ORDER,p });
	PostInNews(p);
	cout << "Posted!\n";
}
void User::PostInNews(Post p) {

	NewsPosts.push_back({ numofposts,p });
	numofposts++;
}


void User::timeline(string user) {

	displayPersonalInfo();
	cout << "TimeLine : " << endl;
	for (int i = Posts.size()-1 ; i >= 0; i--)
	{
		cout << "Post Number : " << i +1 << endl;
		Posts[i].second.DisplayPost();
	}

	while (true) {
		cout << "Press 1 to choose a post to like or comment on it.\n";
		cout << "Press 2 to go back to menu.\n";
		int n; cin >> n;
		if (n == 1) {

			cout << "Enter post number : "; int Pnum; cin >> Pnum;

			cout << "\n\nPress 1 to like the post.\n";
			cout << "Press 2 to  comment the post.\n";
			cout << "Press 3 to go back to menu.\n\n";
			int nn; cin >> nn;
			if (nn == 1) {
				Posts[Pnum - 1].second.Like_Dislike(user);
				for (int i = 0; i < NewsPosts.size(); i++) {
					if (NewsPosts[i].second.content == Posts[Pnum - 1].second.content) {
						NewsPosts[i].second.Like_Dislike(user);
						break;
					}

				}


			}
			else if (nn == 2) {
				cout << "Write the comment.\n";
				string s; cin >> s;
				Posts[Pnum -1].second.AddComment(user, s);
				for (int i = 0; i < NewsPosts.size(); i++) {
					if (NewsPosts[i].second.content == Posts[Pnum - 1].second.content) {
						NewsPosts[i].second.AddComment(user, s);
						break;
					}
					
				}
				//++POST_ORDER;
				//Posts.push_back({ POST_ORDER,p });
			}
			else if (nn == 3) {
				return;
			}
		}
		else if (n == 2)
			return;
	}


}

int NewsCnt = 0;
int first = 1;
void User::Newsfeed(string user, User u) {

	cout << "NewsFeed : " << endl;

	bool postedBefore[1000];
	memset(postedBefore, 0, sizeof(postedBefore));
	for (int i = NewsPosts.size() - 1; i >= 0; i--) {
		if (NewsPosts[i].second.writer == name) {
			cout << "Post number : " << i + 1 << endl;
			NewsPosts[i].second.DisplayPost();
			postedBefore[i] = 1;
		}
		for (int j = 0; j < friends.size(); j++) {
			if (!postedBefore[i] && NewsPosts[i].second.writer == friends[j].name) {
				cout << "Post number  : " << i + 1 << endl;
				NewsPosts[i].second.DisplayPost();
				postedBefore[i] = 1;
			}

		}
		if (NewsPosts[i].second.postGroupName.size())
		{
			for (auto e : userGroups)
				if (!postedBefore[i] && e.groupName == NewsPosts[i].second.postGroupName)
				{

					NewsPosts[i].second.DisplayPost();
					postedBefore[i] = 1;

				}
		}

	}


	while (true) {
		cout << "Press 1 to choose a post to like or comment on it.\n";
		cout << "Press 2 to go back to menu.\n";
		int n; cin >> n;

		if (n == 1) {

			cout << "Enter post number : "; int Pnum; cin >> Pnum;

			cout << "\n\nPress 1 to like the post.\n";
			cout << "Press 2 to  comment the post.\n";

			cout << "Press 3 to tag a friend in the post.\n";
			cout << "Press 4 to share a post on your timeline.\n";
			cout << "Press 5 to go back to menu.\n\n";
			int nn; cin >> nn;
			if (nn == 1) {
				NewsPosts[Pnum - 1].second.Like_Dislike(user);
				for (int i = 0; i < Posts.size(); i++) {
					if (Posts[i].second.content == NewsPosts[Pnum - 1].second.content) {
						Posts[i].second.Like_Dislike(user);
						break;
					}

				}
			}
			else if (nn == 2) {
				cout << "Write the comment.\n";
				string s; cin >> s;
				NewsPosts[Pnum - 1].second.AddComment(user, s);
				for (int i = 0; i < Posts.size(); i++) {
					if (Posts[i].second.content == NewsPosts[Pnum - 1].second.content) {
						Posts[i].second.AddComment(user, s);
						break;
					}

				}
				NewsPosts.push_back(NewsPosts[Pnum - 1]);
				NewsPosts.erase(NewsPosts.begin() + (Pnum - 1));


				//++POST_ORDER;
				//Posts.push_back({ POST_ORDER,p });
			}

			else if (nn == 4) {
				++POST_ORDER;
				Posts.push_back({ POST_ORDER, NewsPosts[Pnum - 1].second });
				cout << "Post Shared successfully.\n";
			}
			else if (nn == 5) {
				return;
			}
		}
		else if (n == 2)
			return;
	}

}


void User::DisplayFriends() {
	for (auto e : friends)
		cout << e.name << endl;
}


void User::displayPersonalInfo() {
	cout << "Name : " << name << " " << lastName << endl;
	cout << "Gender : " << gender << endl;
	cout << "Birthday : " << birthday << "/" << birthmonth << "/" << birthyear << endl;
	cout << "Work : " << work << " " << endl;
	cout << "Education : " << education << " " << endl;
	cout << "Residential address  : " << place << " " << endl;

}


void User::AddFriend(User Friend) {

	//cout << "add fun " << Friend.name << endl;
	int found = 0;
	for (int i = 0; i < 100; i++) {
		if (users[i].email.empty()) return;
		if (users[i].email == Friend.email) {
			found = 1;
			users[i].friends.push_back(users[getUserIdx(email)]);
			break;
	}
	
	}
	if(!found){
		cout << "Doesn't exist!\n";
		return;
	}
	for (int i = 0; i < friends.size(); i++) {
		if (friends[i].email == Friend.email) {
			cout << "Already exists\n";
			return;
		}
	}
	friends.push_back(Friend);

	cout << "Successfully added!\n";
}

void User::tagging(std::string user, std::string taged, Post p) {
	int flag = 0;

	int index;
	for (int i = 0; i < friends.size(); i++) {
		if (friends[i].name == taged) {

			string msg = user + " has tagged you in a post";
			friends[i].notifications.push({ msg, p });
			//cout << friends[i].notifications.size()<<endl;
			flag = 1;
		}
	}

	if (flag)
		cout << taged << " was taged successfully.\n";
	else
		cout << "This friend was not found.\n";
	return;
}

void User::displayNotifications() {

	while(!notifications.empty()){
		cout << "here"<<endl;
		cout << notifications.top().first << endl;
		cout << "Post:\n";
		notifications.top().second.DisplayPost();
		cout << endl;
		notifications.pop();
		cout << endl;
	}
	return;
}
void User::createGroup(string gpName) {
	// make sure group name wasn't taken before
	for (auto e : allGroups)
		if (e.groupName == gpName)
		{
			cout << "This group already exists! \n";
			return;
		}

	Groups group;
	group.groupName = gpName;
	group.groupCreator = name;
	group.isMember[getUserIdx(email)] = true;
	userGroups.push_back(group);
	allGroups.push_back(group);

}
void User::joinGroup(string gpName)
{

	for (auto& e : allGroups)
	{
		if (e.groupName == gpName)
		{
			if (e.isMember[getUserIdx(email)])
			{
				cout << "You are already a member of this group!\n";
				return;
			}
			userGroups.push_back(e);
			e.isMember[getUserIdx(email)] = 1; 

		}
		
	}
}
void User::displayAllGroups()
{

	for (auto& e : allGroups)
	{
		e.displayGroupInfo();
		cout << "Do you wanna join this group? [Y/N]" << endl;
		string s;
		cin >> s;
		if (s == "Y")
		{
			joinGroup(e.groupName);
		}
	}

}
void User::UpostInGroup(string gpName)
{


	for (auto& e : allGroups)
	{
		if (e.groupName == gpName && !e.isMember[getUserIdx(email)])
		{
			cout << "You aren't a member in this group " << endl;
		}
		else if (e.groupName == gpName && e.isMember[getUserIdx(email)])
		{
			cout << "Enter post content\n";
			string s;
			cin.ignore();
			getline(cin, s);
			e.postInGroup(name, s, email);
		}
	}

}

void User::displayUserGroups()
{
	for (auto e : userGroups)
		e.displayGroupInfo();
}
void User::displayGroupPosts(string gpName)
{
	// if the user is already a member
	for (auto e : allGroups)
	{
		if (e.groupName == gpName)
		{
			e.displayPosts();

		}
	}
}
void User::DisplayConversation()
{
	string infile;
	ifstream infileCurrentUser;
	infile = name + ".txt";
	infileCurrentUser.open(infile, ios_base::app);
	if (infileCurrentUser.is_open())
	{
		while (infileCurrentUser.peek() != -1)
		{
			string temp;
			getline(infileCurrentUser, temp);
			cout << temp << endl;
		}
	}
	else
	{
		cout << "Error in opening the file " << endl;
	}
	cout << endl;
	infileCurrentUser.close();


}
void User::AddChattingFriend()
{
	string s;
	queue<string>chat;
	int numOfFiles = 0;
	string message;
	char c;
	int n;
	string chatted;
	string fileFriend;
	string fileUser;
	ofstream outfileCurrentUser;
	ofstream outfileFriend;
	int flag = 0;
	int index;
	cout << "Your friends that you can chat with : " << endl;
	DisplayFriends();
	cout << "Enter the name of your friend that you want to chat with " << endl;
	cin >> chatted;
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends[i].name == chatted)
		{
			index = i;
			flag = 1;
			break;
		}
	}
	if (flag)
	{
		fileFriend = friends[index].name + ".txt";
		fileUser = name + ".txt";
		outfileCurrentUser.open(fileUser, ios_base::app);
		outfileFriend.open(fileFriend, ios_base::app);
		do {
			cout << "Enter your message.... " << endl;
			cin.ignore();
			getline(cin, message);
			chat.push(message);
			if (outfileCurrentUser.is_open() && outfileFriend.is_open())
			{
				outfileCurrentUser <<name <<" :" <<message << endl;
				outfileFriend <<name << " :" << message << endl;
			}
			else
			{
				cout << "Error in opening this file" << endl;
			}
			cout << "Please enter 0 to exit the chat and press 1 to continue" << endl;
			cin >> n;
		} while ((n != 0) && (n == 1));
	}
	if (flag)
		cout << endl << " Your message sent successfully to " << chatted << " ." << endl;
	else {
		cout << "This friend was not found.\n";
		return;
	}
	if (n == 0)
	{
		cout << "To show your messages please press 'Y' " << endl;
		cin >> c;
	}
	if ((c == 'y') || (c == 'Y'))
	{
		while (!chat.empty())
		{
			cout << "your message : " << chat.front() << endl << endl << endl;
			chat.pop();

		}
	}
	outfileCurrentUser.close();
	outfileFriend.close();
}