#include "Groups.h"
#include "Post.h"
#include <iostream>
#include "logInLogic.h"
#include "User.h"
#include <vector>
#include <utility>
#include <deque>
#define USERS_MAX_NUM 100

int  GROUP_POST_ORDER = 0;

using namespace std;

void Groups::displayPosts() {
	for(int i=groupPosts.size()-1;i>=0;i--)
	{
		groupPosts[i].second.DisplayPost();
	}
	
}

void Groups::displayMembers()
{
	stack < string > members;

	int cnt = 0;
	for (int i = 0; i < USERS_MAX_NUM; i++)
	{
		for (auto e : users[i].userGroups)
			if (e.groupName == this->groupName)
			{
				members.push(users[i].name);
			}
	}

	cout << members.size() << endl;
	while (members.size())
	{
		cout << members.top() << endl;
		members.pop();
	}
}

void Groups::postInGroup(string writerName,string postContent,string email)
{
	Post temp;
	temp.writer = writerName;
	temp.content = postContent;
	temp.postGroupName = groupName;
	++GROUP_POST_ORDER;
	pair < int, Post> p = { GROUP_POST_ORDER ,temp };
	this->groupPosts.emplace_back(p);
	users[getUserIdx(email)].PostInNews(temp);
	users[getUserIdx(email)].Posts.push_back(p);
}
void Groups::displayGroupInfo()
{
	cout << "*********** Group " << groupName << " info ***********\n";
	cout << "Group creator : " << groupCreator << endl;
	cout << "Group members: " << endl;
	int cnt = 0;
	for (int i = 0; i < USERS_MAX_NUM; i++)
	{
		for (auto e : users[i].userGroups)
			if (e.groupName == this->groupName)
			{
				cout << ++cnt << "- " << users[i].name << endl;
			}
	}

}
