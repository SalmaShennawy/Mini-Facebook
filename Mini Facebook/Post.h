#pragma once
#include<string>
#include<queue>
#include <vector>
#include <map>

struct comment {
	std::string commentContent;
	std::string  commentWriter;
};

class Post {
public:
	int numberOfLikes = 0;
	std::string writer;
	std::vector <comment> comments;
	std::map <std::string, int> likes;
	std::string content;
	std::string postGroupName;
	int order;
	void DisplayPost();
	void AddComment(std::string user, std::string commentt);
	void Like_Dislike(std::string user);
};