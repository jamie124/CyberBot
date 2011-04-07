#include "cyber_logger.h"

CyberLogger::CyberLogger(void){
	filePath = "main_log.log";

	messageLog = new std::vector<std::string>;

	fileOut.open(filePath, std::ios_base::app);

	if(!fileOut.is_open()){
		std::cout << "Error: could not open file for appending, creating a new one." << std::endl;
		fileOut.open(filePath);
	}
}

CyberLogger::~CyberLogger(void){
	delete messageLog;

	fileOut.close();
}

void CyberLogger::addMessage(std::string newMessage){
	messageLog->push_back(newMessage);
}

