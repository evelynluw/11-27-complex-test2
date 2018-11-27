#include "memories.h"
#include <string>

using namespace std;


typedef void (*fptr)(string, memories&);

//memories &mem;
//map<string, fptr> funcMap;
void run(int argc, char *argv[]);
void test();

void prompt();
void help();
string getCommand(istream& in);

void algebra(string algebraExp, memories &mem);
string formatString(string unformatted);
string toUpper(string str);
void recordToFile(string filename, string line);
void saveStringToFile(string filename, string line, bool append);

void let(string arg, memories &mem);
void save(string arg, memories &mem);
void print(string arg, memories &mem);
void exit(string arg, memories &mem);
void wexit(string arg, memories &mem);
void trig(string arg, memories &mem);

void execute(string arg, memories &mem);
void record(string arg, memories &mem);

