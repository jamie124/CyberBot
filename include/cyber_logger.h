#pragma once

#include <iostream>
#include <vector>

class CyberLogger
{
private:
	typedef std::vector<std::string> *MessageLog;

	MessageLog messageLog;

public:
	CyberLogger(void);
	~CyberLogger(void);

	void addMessage(std::string newMessage);
};
