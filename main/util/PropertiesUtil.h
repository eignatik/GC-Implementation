//
// Created by Evgeny Ignatik on 9/18/17.
//

#ifndef GARBAGECOLLECTOR_UTIL_H
#define GARBAGECOLLECTOR_UTIL_H

#include <string>
#include <map>
#include <fstream>
#include <vector>
#include "Logger.h"

using namespace std;

/**
 * Class provides util methods to operate with properties
 */
class PropertiesUtil {
public:
    PropertiesUtil() {
        properties = map<string, string>();
    }

    ~PropertiesUtil() {
    }

    /**
     * Set properties map from file
     * @param filePath related path to file
     */
    void setPropertiesFromFile(string filePath) {
        ifstream propertiesFile(filePath);
        if (!propertiesFile.is_open()) {
            Logger::error("The file with path " + filePath + " doesn't exist or wasn't opened\n", __FILE__, __LINE__);
            return;
        }
        string props = string((istreambuf_iterator<char>(propertiesFile)), istreambuf_iterator<char>());
        Logger::info("The following properties have been received\n", props, __FILE__, __LINE__);
        vector<string> propertiesKeys = getPropertiesVector(props);
        putProperties(propertiesKeys, props);
    }

    /**
     * get string property from garbage collector local properties
     * @param propertyName property you want to get
     * @return string property
     */
    string getProperty(string propertyName) {
        if (properties.empty()) {
            setPropertiesFromFile("../conf/gc.properties");
        }
        return properties[propertyName];
    }

    const map<string, string> &getProperties() const {
        return properties;
    }

    void setProperties(const map<string, string> &properties) {
        this->properties = properties;
    }

private:
    map<string, string> properties;

    /**
     * Provide all properties keys vector
     * @param props string of parsed properties
     * @return vector with properties keys
     */
    vector<string> getPropertiesVector(string &props) {
        vector<string> propKeys = vector<string>();
        string key;
        bool isProperty = true;
        for (int i = 0; i < props.length(); i++) {
            if (props[i] == '=') {
                isProperty = false;
            }
            if (props[i] == '\n') {
                isProperty = true;
                continue;
            }

            if (isProperty) {
                key = key + props[i];
            } else if (!key.empty()) {
                propKeys.push_back(key);
                key = "";
            }
        }
        return propKeys;
    }

    /**
     * Iterate all properties keys to put suitable value to properties map
     * @param propKeys list of properties keys
     * @param props string of parsed properties file
     */
    void putProperties(vector<string> &propKeys, string &props) {
        for (string prop : propKeys) {
            putProperty(props, prop);
        }
    }

    /**
     * put property to map of properties
     * @param props parsed properties file
     * @param propKey property key
     */
    void putProperty(string &props, string &propKey) {
        unsigned long startPosition = props.find(propKey);
        string size = string();
        for (unsigned long i = startPosition + propKey.length() + 1; props[i] != '\n'; i++) {
            size = size + props[i];
        }
        properties[propKey] = size;
    }
};

#endif //GARBAGECOLLECTOR_UTIL_H
