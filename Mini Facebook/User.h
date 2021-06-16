#pragma once
#include<string>
#include<stack>
#include<vector>
#include<deque>
#include"Post.h"
#include <utility>
#include <list>
#include<map>
#include <stack>
#include "Groups.h"
extern std::vector<Groups> allGroups;
class User
{
public:
	static int numofposts;
	
	static std::deque<std::pair<int, Post>>NewsPosts;

	std::string name;
	std::string lastName;
	std::string password;
	std::string birthday;
	std::string birthmonth;
	std::string birthyear;
	std::string email;
	std::string gender;
	std::string work;
	std::string education;
	std::string place;
	User(std::string x);
	User();
	void UPost(std::string paragraph,User u);
	 void PostInNews(Post p);
	void timeline(std::string user);
	void AddFriend(User Friend);
	void Newsfeed(std::string user, User u);
	void DisplayFriends();
	void displayPersonalInfo();
	void displayNotifications();
	void tagging(std::string user, std::string taged, Post p);
	std::vector<User> friends;
	std::stack<std::pair<std::string, Post>>notifications;
	std::vector<Groups> userGroups;
	void createGroup(std::string gpName);
	void joinGroup(std::string groupName);
	void displayAllGroups();
	void UpostInGroup(std::string gpName);
	void displayUserGroups();
	void displayGroupPosts(std::string gpName);
	void AddChattingFriend();
	void DisplayConversation();
	std::deque<std::pair<int, Post>>Posts;

	int NumOfFriends;
};

