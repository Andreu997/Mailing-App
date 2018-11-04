#pragma once

#include "DatabaseTypes.h"
#include <vector>

class IDatabaseGateway
{
public:

	// Constructor and destructor

	IDatabaseGateway() { }
	
	virtual ~IDatabaseGateway() { }


	// Virtual methods

	virtual void insertMessage(const Message &message) = 0;

	virtual std::vector<Message> getAllMessagesReceivedByUser(const std::string &username) = 0;

	virtual void insertProfile(const Profile &profile) = 0;

	virtual size_t getUserPassword(const std::string &username) = 0;

	virtual void updateGUI() { }
};

