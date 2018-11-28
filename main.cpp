#include <iostream>
#include "complexnumber.h"
#include "calculator.h"

using namespace std;

map<string, fptr> funcMap;

void run(int argc, char *argv[]);
void execCommand(string command, memories &mem);
void fillFunction();
void load(string arg, memories &mem);
void execute(string arg, memories &mem);

int main(int argc, char *argv[])
{
    try {
        run(argc, argv);
    }
    catch (E &e) {
        cout << "error: " << e.what() <<endl;
    }
    return 0;
}

void run(int argc, char *argv[]) {
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
            help(argv[1], mem);
        } else {
            string filename(argv[1]);
            load(filename, mem);
        }
        break;
    }
    case 3: {
        if(toUpper(string(argv[1]))=="EXECUTE") { //TESTED
            execute(string(argv[2]), mem);
        }
        if(toUpper(string(argv[1]))=="RECORD") {
            record = true;
            cout<<"recording to "<<argv[2]<<endl;
        }
        break;
    }
    default:
        throw e_argm_error;
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
        if(action.find("TRIG") != string::npos) {
            arg = formatString(action);
            arg = arg.substr(4,3);
            funcMap["TRIG"](arg, mem);
        }
        if(action.find_first_of("!@#$%&,:;'\"[]{}`") != string::npos) {
            throw e_wrong_input_format;
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
    funcMap["ORTHO"] = ortho;
    funcMap["HELP"] = help;
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
    if(filename.find(".complex")>filename.size())
        filename+=".complex";
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

void execute(string arg, memories &mem) {
    ifstream ifs;
    string filename = arg,
            line;
    if(filename.empty()) {
        cout<<"invalid filename"<<endl;
        return;
        //throw error
    }
    if(filename.find(".spt")>filename.size())
        filename+=".spt";
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
            ss<<line;
            getline(ss, line);
            cout<<": "<<line<<endl;
            execCommand(line, mem);
        }
    }
}
