#include <iostream>
#include "complexnumber.h"
#include "calculator.h"

using namespace std;

map<string, fptr> funcMap;

void execCommand(string command, memories &mem);
void fillFunction();
void load(string arg, memories &mem);

int main(int argc, char *argv[])
{
//    test();
    memories mem;
    fillFunction();
    bool record = false;
    switch (argc) {
    case 1:
        break;
    case 2: { //TESTED
        if(string(argv[1]) == "/h" ||
                string(argv[1]) == "/?") {
            help();
        } else {
            string filename(argv[1]);
            load(filename, mem);
        }
        break;
    }
    case 3: {
        if(toUpper(string(argv[1]))=="EXECUTE") { //TESTED
//            execute(string(argv[2]));
        }
        if(toUpper(string(argv[1]))=="RECORD") {
            record = true;
            cout<<"recording to "<<argv[2]<<endl;
        }
        break;
    }
    default:
        cout<<"argument error"<<endl;
        exit(1);
        //throw error
        break;
    }
    while(1) {
        prompt();
        string line = getCommand(cin);
        execCommand(line, mem);
        if(record)
            recordToFile(argv[2], line);
    }
}

void execCommand(string command, memories &mem) {
    //TESTED:
    ////execCommand("LET F = 2 2/3 + 4i");
    /* sample argm:
     * LET F = 2 + 4i
     * LOAD filename.complex
     * SAVE filename.complex
     * PRINT F
     * EXIT
     * WEXIT
     */
    command = toUpper(command);
    stringstream ss;
    string action, arg;
    ss<<command;
    ss>>action;
    getline(ss, arg);

    if(funcMap.find(action)==funcMap.end()) {
        size_t pos = 0;
        if((pos = action.find("TRIG")) != string::npos) {
            arg = formatString(action);
            arg = arg.substr(4,3);
            funcMap["TRIG"](arg, mem);
        }
        arg = action + arg;
        arg = formatString(arg);
        algebra(arg, mem);
    }
    else {
        arg = formatString(arg);
        funcMap[action](arg, mem);
    }

}

void fillFunction() {
    funcMap["LET"] = let;
    funcMap["LOAD"] = load;
    funcMap["SAVE"] = save;
    funcMap["PRINT"] = print;
    funcMap["EXIT"] = exit;
    funcMap["WEXIT"] = wexit;
    funcMap["TRIG"] = trig;
}

void load(string arg, memories &mem) {
    //arg="filename.complex"
    ifstream ifs;
    string filename = arg,
            line;
    if(filename.empty()) {
        cout<<"invalid filename"<<endl;
        return;
        //throw error
    }
    if(filename.find(".exp")>filename.size())
        filename+=".exp";
    ifs.open(filename);
    if(ifs.fail()) {
        cout<<"file does not exist"<<endl;
        return;
        //throw error
    }
    cout<<"loaded "<<filename<<endl;
    while(!ifs.eof())
    {
        stringstream ss;
        getline(ifs, line);
        if(!line.empty()){
            ss<<"LET "<<line;
            getline(ss, line);
//            cout<<"##line: "<<line<<endl;
            execCommand(line, mem);
        }
    }
}
