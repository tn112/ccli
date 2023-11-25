#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstring>

#define VERSION "0.0.1"


std::string usage() {
    std::string message;
    message += "Usage: ccli [instruction] [arg1] [arg2]\n";
    message += "  echo <message>  Display the given message.\n";
    message += "  file <name>     Creates a file <name>.\n";
    message += "  delete <name>   Deletes a file <name>.\n";     
    message += "  -v              Display the ccli version.\n";
    message += "  -help           Displays this help message.\n";
    return message;
}

void eval(std::string instruction, std::string arg1, std::string arg2) {
    if (instruction == "echo") {
        std::cout << arg1 << std::endl;
    } else if (instruction == "-v") {
        std::cout << "ccli version: " << VERSION << std::endl;
    } else if (instruction == "-help") {
        std::cout << usage();
    } else if (instruction == "file") {
        std::ofstream file(arg1);
    } else if (instruction == "delete") {
        const int length = arg1.length();
        char* arg1CharArray = new char[length + 1];
        strcpy(arg1CharArray, arg1.c_str());
        std::remove(arg1CharArray);
    } 
}


int main(int argc, char* argv[]) {
    std::string instruction;
    std::string arg1;
    std::string arg2;

    if (argc > 1) {
        instruction = argv[1];
    } else {
        instruction = "";
    }
    if (argc > 2) {
        arg1 = argv[2];
    } else {
        arg1 = "";
    }
    if (argc > 3) {
        arg2 = argv[3];
    } else {
        arg2 = "";
    }

    eval(instruction, arg1, arg2);

    return 0;
}