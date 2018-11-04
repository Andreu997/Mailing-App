#pragma once

#include <string>

struct Message
{
	std::string senderUsername;
	std::string senderPassword;
	std::string receiverUsername;
	std::string subject;
	std::string body;
};

struct Profile
{
	std::string username;
	unsigned int password;
};
