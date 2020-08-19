/*
use file to log
*/
#ifndef LOG_H
#define LOG_H

#include <ctime>
#include <fstream>
#define LOG(level,msg) ofstream<<"level: "<<(level)<<", "<<(msg)<<"\n";
extern std::ofstream logStream;
void initLog();
void closeLog();

#endif