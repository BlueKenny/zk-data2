#include <string>
using namespace std;

#include <sstream>

extern std::string IntToString(const int& ZAHL){// Int to String
	stringstream ss;
	ss << ZAHL;
	return ss.str();
}
