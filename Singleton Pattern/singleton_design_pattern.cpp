#include<bits/stdc++.h>
#include "logger.hpp"
#include<mutex>
using namespace std;
int Logger:: ctr =0;
Logger* Logger::loggerInstance =nullptr;


Logger::Logger(){
    ctr++;
    cout<<"new instance create. #of instances is"<<ctr<<endl;
}
void Logger::Log(string msg){
    cout<<msg<<endl;
}

Logger* Logger::getLogger(){
    if(loggerInstance==nullptr){
        Logger::mtx.lock();
        if(loggerInstance==nullptr)
            loggerInstance = new Logger();
        Logger::mtx.unlock();
    }
    return loggerInstance;
}