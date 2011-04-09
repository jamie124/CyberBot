#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class CyberLogger
{
private:
	const char* filePath;

	std::ofstream fileOut;

public:
	CyberLogger(void);
	~CyberLogger(void);

	void addMessage(std::string newMessage);
};
