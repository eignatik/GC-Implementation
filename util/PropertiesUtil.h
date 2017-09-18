//
// Created by Evgeny Ignatik on 9/18/17.
//

#ifndef GARBAGECOLLECTOR_UTIL_H
#define GARBAGECOLLECTOR_UTIL_H

#include <string>
#include <map>
using namespace std;

/**
 * Class provides util methods to operate with properties
 */
class PropertiesUtil {
private:
    map<string, string> properties;
    void setPropertiesFromFile(string filePath);
    vector<string> getPropertiesVector(string &props);
    void putProperties(vector<string> &propKeys, string &props);
    void putProperty(string &props, string &propKey);

public:
    string getProperty(string &propertyName);
    PropertiesUtil();
    ~PropertiesUtil();

    const map<string, string> &getProperties() const;
    void setProperties(const map<string, string> &properties);
};


#endif //GARBAGECOLLECTOR_UTIL_H
