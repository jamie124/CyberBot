#include "cyber_logger.h"

CyberLogger::CyberLogger(void){
	messageLog = new std::vector<std::string>;
}

CyberLogger::~CyberLogger(void){
	delete messageLog;
}

void CyberLogger::addMessage(std::string newMessage){
	messageLog->push_back(newMessage);
}

