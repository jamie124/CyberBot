#include "cyber_logger.h"

CyberLogger::CyberLogger(void){
	filePath = "main_log.log";

	fileOut.open(filePath, std::ios_base::app);

	if(!fileOut.is_open()){
		std::cout << "Error: could not open file for appending, creating a new one." << std::endl;
		fileOut.open(filePath);
	}

	fileOut << "STARTED LOGGING\n";
}

CyberLogger::~CyberLogger(void){
	fileOut << "ENDED LOGGING\n\n";

	fileOut.close();
}

void CyberLogger::addMessage(std::string newMessage){
	fileOut << newMessage + "\n";

	std::cout << newMessage + "\n";
}

