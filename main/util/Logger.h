//
// Created by Evgeny Ignatik on 9/18/17.
//

#ifndef GARBAGECOLLECTOR_LOGGER_H
#define GARBAGECOLLECTOR_LOGGER_H

#include <string>
#include <iostream>

using namespace std;

static class Logger {
private:
    static string basicInfo(string type, string message, string file, int line) {
        return type + ": " + file + ", line: " + to_string(line) + message;
    }

public:
    static void info(string message, string file, int line) {
        cout << basicInfo("INFO", message, file, line) << endl;
    }

    static void info(string message, string &objectToDisplay, string file, int line) {
        cout << basicInfo("INFO", message, file, line)  << objectToDisplay << endl;
    }

    static void info(string message, int &objectToDisplay, string file, int line) {
        cout << basicInfo("INFO", message, file, line) << objectToDisplay << endl;
    }

    static void error(string message, string file, int line) {
        cout << basicInfo("ERROR", message, file, line) << endl;
    }
};


#endif //GARBAGECOLLECTOR_LOGGER_H
