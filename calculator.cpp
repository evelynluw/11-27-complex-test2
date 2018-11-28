#include "calculator.h"
#include <regex>


void test() {
    cout <<"unformatted: "<< "F = 1 2/3 + 4i" <<endl;
    cout <<"formatted: "<<formatString("F = 2 2/3 + 4i")<<endl;
}

void prompt() {
    cout<<"INPUT: ";
}

void help(string arg, memories &mem) {
    cout<<"SAMPLE COMMANDS: \nLET F = 2 + 4i\nLOAD filename.complex\nSAVE filename.complex\n"
        <<"PRINT F\nEXIT\nWEXIT\nF=G+H\nF=G-H\nF=G*H\nF=G/H\nF=G^H\nF=~G"<<endl;
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
    regex excessiveSpace("((?!\\s\\d+\\/)\\s)");
    string formatted = regex_replace(unformatted, excessiveSpace, "");
//    regex excessiveSpace2("=\\s");
//    string formatted2 =C:\Users\Evelyn\Google Drive (ylu40@go.pasadena.edu)\CS 3A\9\11-27-complex-test2\build-complexCalculate-Desktop_Qt_5_11_2_MinGW_32bit-Debug\debug regex_replace(formatted, excessiveSpace, "=");
    size_t pos;
    if((pos=formatted.find('='))!=string::npos)
        if(formatted[pos+1]==' ')
            formatted.erase(pos+1,1);
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
//    cout<<"##arg = "<<arg<<endl;
    regex complexNum("^((\\d+\\s)?\\d+([\\/.]\\d+)?[+-]?)?(((\\d+\\s)?\\d+([\\/.]\\d+)?)?I?)$");
    if(!regex_match(arg, complexNum))
        throw e_wrong_input_format;
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
    if(filename.find(".complex")>filename.size())
       filename+=".complex";
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
    //arg = "filename.complex"
    save(arg, mem);
    exit(0);
}

void trig(string arg, memories &mem) {    //arg="F=2 1/2+4i"
    //arg="(F)"
    complexNumber var = mem[arg[1]];
    std::complex<double> _var(var.getRealPart().evaluate(), var.getImgPart().evaluate());
    cout<<abs(_var)<<", "<<std::arg(_var)<<endl;
}
//
void ortho(string arg, memories &mem) {
    //arg = "FG"
    mixedNumber crossproduct = mem[arg[0]].dotProduct(mem[arg[1]]);
    cout<<arg[0] << " and "<<arg[1];
    if(crossproduct == mixedNumber(0))
        cout<<" are orthogonal"<<endl;
    else
        cout<<" are not orthogonal"<<endl;
}


