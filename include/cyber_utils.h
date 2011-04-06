#ifndef CYBER_UTILS_H_
#define CYBER_UTILS_H_

#include <string>
#include <sstream>

class CyberUtils
{
private:

public:
	CyberUtils(void);
	~CyberUtils(void);

	static std::string intToString(int value);
};

#endif /* CYBER_UTILS_H_ */