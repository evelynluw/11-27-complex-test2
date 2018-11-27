#include "calculator.h"

//PUBLIC

Calculator::Calculator() {

}

Calculator::~Calculator() {

}

void Calculator::run(int argc, char *argv[]) {

}

void Calculator::test() {

}


//PRIVATE

void Calculator::prompt() {

}

void Calculator::help() {

}

string Calculator::getCommand(istream& in) {
    if(in.peek()=='\n')
        exit(0);
    string temp;
    getline(in, temp);
    return temp;
}

void Calculator::execCommand(string command) {
    /* sample argm:
     * LET F = 2 + 4i
     * LOAD filename.complex
     * SAVE filename.complex
     * PRINT F
     * EXIT
     * WEXIT
     */
    stringstream ss;
    fptr action;
    ss<<command;
//    ss>>action;

}

void Calculator::callFunction(string funcName) {

}

void Calculator::fillFunction() {
    string test;
    funcMap["LET"] = let;
    funcMap["LOAD"] = load;
}


void Calculator::algebra(string algebraExp) {

}


//

void Calculator::let(string arg) {

}

void Calculator::load(string arg) {

}

void Calculator::save(string arg) {

}

void Calculator::print(string arg) {

}

void Calculator::exit(string arg) {

}

void Calculator::wexit(string arg) {

}

//

void Calculator::execute(string arg) {

}

void Calculator::record(string arg) {

}

//


