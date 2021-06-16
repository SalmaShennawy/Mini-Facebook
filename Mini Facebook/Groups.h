#pragma once
#include<string>
#include <deque>
#include "Post.h"
#include <utility>
#include <map>
#include "Groups.h"
#include <vector>


#define USERS_MAX_NUM 100

class Groups
{

public:
	std::string groupName;
	std::string groupCreator;
	bool isMember[USERS_MAX_NUM];
	std::vector<std::pair<int, Post>>groupPosts;
	void displayPosts();
	void displayMembers();
	void postInGroup(std::string writerName, std::string postConten, std::string email);
	void displayGroupInfo(); 
};

