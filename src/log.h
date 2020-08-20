/*
use file to log
*/
#ifndef LOG_H
#define LOG_H

#include <ctime>
#include <fstream>
extern std::ofstream logStream;
#define LOG(level,msg) logStream<<"level: "<<level<<", "<<msg<<"\n";
void initLog();
void closeLog();

#endif