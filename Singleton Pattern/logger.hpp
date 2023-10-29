#ifndef logger_h
#define logger_h
#endif
#include<string>
#include<mutex>

using namespace std;

class Logger{
    static int ctr;
    static Logger *loggerIstance;
    static mutex mtx;
    Logger();
    
    // this is a copy constructor
    Logger(const Logger&);

    //this is operator overloading
    Logger operator=(const Logger&);

    public:
        static Logger *getLogger();
        void Log(string msg);
};