#include <iostream>
#include <string>
#define interface struct

using namespace std;

interface DBAPI {
    virtual string getDBName() = 0;
};

class DatabaseAPI : public DBAPI
{
public:
    string getDBName()
    {
        return "HIHI";
    }
};

class LogSystem
{
public:
	string getLogMessage(string content)
    {
        return std::string("[") + DB->getDBName() + string("]");
    }
private :
    DatabaseAPI *DB;
};

class Cal {
public:
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }
};