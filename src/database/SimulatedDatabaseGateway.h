#pragma once

#include "IDatabaseGateway.h"
#include <vector>

class SimulatedDatabaseGateway :
	public IDatabaseGateway
{
public:

	// Constructor and destructor

	SimulatedDatabaseGateway();

	~SimulatedDatabaseGateway();


	// Virtual methods from IDatabaseGateway

	void insertMessage(const Message &message) override;

	std::vector<Message> getAllMessagesReceivedByUser(const std::string &username) override;

	void insertProfile(const Profile &profile) override;

	unsigned int getUserPassword(const std::string &username) override;

private:

	std::vector<Message> allMessages;
	std::vector<Profile> allProfiles;
};
