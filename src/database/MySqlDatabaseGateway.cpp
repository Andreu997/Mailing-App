#include "MySqlDatabaseGateway.h"
#include "DBConnection.h"
#include "../imgui/imgui.h"
#include <cstdarg>

// You can use this function to create the SQL statements easily, works like the printf function
std::string stringFormat(const char *fmt, ...)
{
	// Find out the final string length
	va_list ap;
	va_start(ap, fmt);
	int size = vsnprintf(nullptr, 0, fmt, ap);
	va_end(ap);

	// Format the actual resulting string
	std::string resultString;
	resultString.resize(size + 1, '\0');
	va_start(ap, fmt);
	vsnprintf(&resultString[0], resultString.size(), fmt, ap);
	va_end(ap);

	return resultString;
}


MySqlDatabaseGateway::MySqlDatabaseGateway()
{
}


MySqlDatabaseGateway::~MySqlDatabaseGateway()
{
}

void MySqlDatabaseGateway::insertProfile(const Profile &profile)
{
	DBConnection db(bufMySqlHost, bufMySqlPort, bufMySqlDatabase, bufMySqlUsername, bufMySqlPassword);

	if (db.isConnected())
	{
		DBResultSet res;

		std::string sqlStatement;

		// TODO: Create the SQL statement to insert the passed username into the DB (INSERT)
		sqlStatement = "INSERT INTO profile (username, password) VALUES ('"
			+ profile.username + "', '" + 
			(char) profile.password + "')";;

		printf(sqlStatement.c_str());

		// insert some messages
		db.sql(sqlStatement.c_str());
	}
}

size_t MySqlDatabaseGateway::getUserPassword(const std::string &username)
{
	Profile profile;

	DBConnection db(bufMySqlHost, bufMySqlPort, bufMySqlDatabase, bufMySqlUsername, bufMySqlPassword);
	
	if (db.isConnected())
	{
		std::string sqlStatement;
		sqlStatement = "SELECT * FROM messages WHERE username = '" + username + "';";

		// consult all messages
		DBResultSet res = db.sql(sqlStatement.c_str());

		// fill the array of messages
		profile.username = res.rows[0].columns[0];
		profile.password = (unsigned int)&res.rows[0].columns[1];
	}

	return profile.password;
}

void MySqlDatabaseGateway::insertMessage(const Message & message)
{
	DBConnection db(bufMySqlHost, bufMySqlPort, bufMySqlDatabase, bufMySqlUsername, bufMySqlPassword);
	
	if (db.isConnected())
	{
		DBResultSet res;

		std::string sqlStatement;
		// TODO: Create the SQL statement to insert the passed message into the DB (INSERT)
		sqlStatement = "INSERT INTO messages (sender, receiver, subject, body) VALUES ('"
			+ message.senderUsername + "', '" +
			message.receiverUsername + "', '" +
			message.subject + "', '" +
			message.body + "')";
		printf(sqlStatement.c_str());

		// insert some messages
		db.sql(sqlStatement.c_str());
	}
}

std::vector<Message> MySqlDatabaseGateway::getAllMessagesReceivedByUser(const std::string & username)
{
	std::vector<Message> messages;

	DBConnection db(bufMySqlHost, bufMySqlPort, bufMySqlDatabase, bufMySqlUsername, bufMySqlPassword);

	if (db.isConnected())
	{
		std::string sqlStatement;
		// TODO: Create the SQL statement to query all messages from the given user (SELECT)
		sqlStatement = "SELECT * FROM messages WHERE receiver = '" + username + "';";

		// consult all messages
		DBResultSet res = db.sql(sqlStatement.c_str());

		// fill the array of messages
		for (auto & messageRow : res.rows)
		{
			Message message;
			message.senderUsername = messageRow.columns[0];
			message.receiverUsername = messageRow.columns[1];
			message.subject = messageRow.columns[2];
			message.body = messageRow.columns[3];
			messages.push_back(message);
		}
	}


	return messages;
}

void MySqlDatabaseGateway::updateGUI()
{
	ImGui::Separator();

	ImGui::Text("MySQL Server info");
	ImGui::InputText("Host", bufMySqlHost, sizeof(bufMySqlHost));
	ImGui::InputText("Port", bufMySqlPort, sizeof(bufMySqlPort));
	ImGui::InputText("Database", bufMySqlDatabase, sizeof(bufMySqlDatabase));
	ImGui::InputText("Username", bufMySqlUsername, sizeof(bufMySqlUsername));
	ImGui::InputText("Password", bufMySqlPassword, sizeof(bufMySqlUsername), ImGuiInputTextFlags_Password);
}
