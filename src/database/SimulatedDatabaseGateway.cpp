#include "SimulatedDatabaseGateway.h"



SimulatedDatabaseGateway::SimulatedDatabaseGateway()
{
}


SimulatedDatabaseGateway::~SimulatedDatabaseGateway()
{
}

void SimulatedDatabaseGateway::insertMessage(const Message & message)
{
	allMessages.push_back(message);
}

std::vector<Message> SimulatedDatabaseGateway::getAllMessagesReceivedByUser(const std::string & username)
{
	std::vector<Message> messages;
	for (const auto & message : allMessages)
	{
		if (message.receiverUsername == username)
		{
			messages.push_back(message);
		}
	}
	return messages;
}

void SimulatedDatabaseGateway::insertProfile(const Profile &profile)
{
	allProfiles.push_back(profile);
}

unsigned int SimulatedDatabaseGateway::getUserPassword(const std::string &username)
{
	std::vector<Profile> profiles;
	for (const auto & profile : allProfiles)
	{
		if (profile.username == username)
		{
			return profile.password;
		}
	}

}
