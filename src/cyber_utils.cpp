#include "cyber_utils.h"

CyberUtils::CyberUtils(){
}

CyberUtils::~CyberUtils(){
}

std::string CyberUtils::intToString(int value){
	std::string s;
	std::stringstream out;
	out << value;
	return out.str();
}