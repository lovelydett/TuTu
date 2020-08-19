#include "log.h"
std::ofstream logStream;
void initLog(){
    logStream.open("./logFile.txt",std::ios_base::out);
    logStream<<"log:\nprogram begins\n-----------------------\n";
}

void closeLog(){
    logStream.close();
}