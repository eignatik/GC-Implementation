//
// Created by Evgeny Ignatik on 9/18/17.
//

#ifndef GARBAGECOLLECTOR_LOGGER_H
#define GARBAGECOLLECTOR_LOGGER_H

#include <string>
#include <iostream>

using namespace std;

static class Logger {
public:
    static void info(string &message, string file, int line) {
        cout << file << ", line: " << line << " " << message << endl;
    }

    static void info(string message, string &objectToDisplay, string file, int line) {
        cout << file << ", line: " << line << " " << message << " " << objectToDisplay << endl;
    }

    static void info(string message, int &objectToDisplay, string file, int line) {
        cout << file << ", line: " << line << " " << message << " " << objectToDisplay << endl;
    }
};


#endif //GARBAGECOLLECTOR_LOGGER_H
