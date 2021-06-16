#include "Post.h"
#include <iostream>
#include "User.h"

using namespace std;

void Post::DisplayPost() {

	if (postGroupName.size())
		cout << "Post in group " << postGroupName << endl;
	cout << "Post writer : " << writer << endl;
	cout << "Post : " << content << endl;
	cout << "Number of Likes : " << numberOfLikes << endl;
	cout << "Comments : \n";
	for (int i = comments.size() - 1; i >= 0; i--) {
		cout << "Comment writer : " << comments[i].commentWriter << endl;
		cout << "Comment : " << comments[i].commentContent << endl;
	}
	cout << endl << endl;
	return;
}

void Post::Like_Dislike(string user) {

	if (likes[user] == NULL) {
		numberOfLikes++;
		likes[user] = 1;
	}
	return;

}

void Post::AddComment(std::string user, std::string commentt) {

	comment c;
	c.commentWriter = user;
	c.commentContent = commentt;
	comments.push_back(c);

	return;
}