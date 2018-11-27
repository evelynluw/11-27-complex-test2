#include "calculator.h"
#include <regex>

void run(int argc, char *argv[]) {

}

void test() {
    cout <<"unformatted: "<< "F = 1 2/3 + 4i" <<endl;
    cout <<"formatted: "<<formatString("F = 2 2/3 + 4i")<<endl;
}

void prompt() {
    cout<<"INPUT: ";
}

void help() {

}

string getCommand(istream& in) {
    if(in.peek()=='\n')
        exit(0);
    string temp;
    getline(in, temp);
    return temp;
}


void algebra(string algebraExp, memories &mem) {
/* sample argm:
     * F=G+H
     * F=G-H
     * F=G*H
     * F=G/H
     * F=G^H
     * F=~G
     */
    size_t pos;
    if((pos = algebraExp.find_first_of("+-*/^"))!= string::npos) {
        char fn1 = algebraExp[0], //funcName
                fn2 = algebraExp[2],
                fn3 =  algebraExp[4];
        switch (algebraExp[pos]) {
        case '+': //TESTED
            mem[fn1] = mem[fn2] + mem[fn3];
            break;
        case '-': //TESTED
            mem[fn1] = mem[fn2] - mem[fn3];
            break;
        case '*': //TESTED
            mem[fn1] = mem[fn2] * mem[fn3];
            break;
        case '/':
            mem[fn1] = mem[fn2] / mem[fn3];
            break;
        case '^':
            mem[fn1] = mem[fn2] ^ mem[fn3];
            break;
        default:
            break;
        }
        print(string(1,fn1), mem);
        return;
    }
    if((pos = algebraExp.find('~'))!= string::npos) { //TESTED
        char fn1 = algebraExp[0],
                fn2 = algebraExp[3];
        mem[fn1] = ~mem[fn2];
        print(string(1,fn1), mem);
        return;
    }
}

string formatString(string unformatted) {
//    TESTED:
////    cout <<"unformatted: "<< "F = 1 2/3 + 4i" <<endl;
////    cout <<"formatted: "<<formatString("F = 2 2/3 + 4i")<<endl;
    regex excessiveSpace("(?!\\s\\d+\\/)\\s");
    string formatted = regex_replace(unformatted, excessiveSpace, "");
    formatted = toUpper(formatted);
    return formatted;
}

string toUpper(string str) {
    string temp;
    for(string::iterator it=str.begin(); it!=str.end(); ++it){
        temp.push_back(toupper(*it));
    }
    return temp;
}

void recordToFile(string filename, string line) {
    if(filename.find(".spt")>filename.size())
        filename+=".spt";
    saveStringToFile(filename, line, true);
}

void saveStringToFile(string filename, string line, bool append) {
    ofstream ofs;
    if(append)
        ofs.open(filename, ios_base::app);
    else
        ofs.open(filename);
    ofs<<line<<endl;
    //check if there is line endings
}

//

void let(string arg, memories &mem) {
    //arg="F=2 1/2+4i"
    char funcName = arg[0];
    arg.erase(0,2); //"2 1/2+4i"
    mem[funcName]=arg;
    string funcNameStr;
    funcNameStr+=funcName;
    print(funcNameStr, mem);
}

void save(string arg, memories &mem) {
    ifstream ifs;
    ofstream ofs;
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
    if(!ifs.fail()) {
       cout<<"file already exists, overwrite?"<<endl;
       getline(cin, line);
       if(toupper(line[0])!='Y')
           return;
    }
    ofs.open(filename);
    for(char i = 'A'; i <= 'Z'; ++i) {
       ofs<<i<<" = "<<mem[i]<<endl;
    }
    cout<<"saved to "<<filename<<endl;
}

void print(string arg, memories &mem) {
    //arg="F" (from PRINT F)
    cout<<arg<<" = "<<mem[arg[0]]<<endl;
}

void exit(string arg, memories &mem) {
    exit(0);
}

void wexit(string arg, memories &mem) {

}

void trig(string arg, memories &mem) {    //arg="F=2 1/2+4i"
    //arg="(F)"
    complexNumber var = mem[arg[1]];
    std::complex<double> _var(var.getRealPart().evaluate(), var.getImgPart().evaluate());
    cout<<abs(_var)<<", "<<std::arg(_var)<<endl;
}
//

void execute(string arg, memories &mem) {

}

void record(string arg, memories &mem) {

}

//


