#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "memories.h"
#include <string>

using namespace std;


class Calculator
{
typedef void (*fptr)(string arg);

public:
    Calculator();
    ~Calculator();
    void run(int argc, char *argv[]);
    void test();
private:
    memories mem;
    map<string, fptr> funcMap;

    void prompt();
    void help();
    string getCommand(istream& in);
    void execCommand(string command);
    void callFunction(string funcName);
    void fillFunction();
    void algebra(string algebraExp);

    void let(string arg);
    void load(string arg);
    void save(string arg);
    void print(string arg);
    void exit(string arg);
    void wexit(string arg);

    void execute(string arg);
    void record(string arg);



};

#endif // CALCULATOR_H
