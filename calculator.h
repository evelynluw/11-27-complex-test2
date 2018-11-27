#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "memories.h"
#include <string>

using namespace std;

class Calculator
{
public:
    Calculator();
    ~Calculator();
    void run(int argc, char *argv[]);
    void test();
private:
    memories mem;
//    map<string,
    void let(string arg);
    void load(string arg);
    void save(string arg);
    void print(string arg);
    void exit(string arg);
    void wexit(string arg);

    void execute(string arg);
    void record(string arg);

    void prompt();
    void help();
    string getCommand(istream& in);
    void execCommand(string command);
    void algebra(string algebraExp);

};

#endif // CALCULATOR_H
