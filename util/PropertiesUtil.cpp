//
// Created by Evgeny Ignatik on 9/18/17.
//

#include "PropertiesUtil.h"
#include "Logger.h"
#include <fstream>
#include <vector>

using namespace std;

PropertiesUtil::PropertiesUtil() {
    properties = map<string, string>();
}

PropertiesUtil::~PropertiesUtil() {
}

/**
 * get string property from garbage collector local properties
 * @param propertyName property you want to get
 * @return string property
 */
string PropertiesUtil::getProperty(string &propertyName) {
    if (properties.empty()) {
        setPropertiesFromFile("../conf/gc.properties");
    }
    return properties[propertyName];
}

/**
 * Set properties map from file
 * @param filePath related path to file
 */
void PropertiesUtil::setPropertiesFromFile(string filePath) {
    ifstream propertiesFile(filePath);
    string props = string((istreambuf_iterator<char>(propertiesFile)), istreambuf_iterator<char>());
    Logger::info("The following properties have been received\n", props, __FILE__, __LINE__);
    vector<string> propertiesKeys = getPropertiesVector(props);
    putProperties(propertiesKeys, props);
}

/**
 * Provide all properties keys vector
 * @param props string of parsed properties
 * @return vector with properties keys
 */
vector<string> PropertiesUtil::getPropertiesVector(string &props) {
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
void PropertiesUtil::putProperties(vector<string> &propKeys, string &props) {
    for (string prop : propKeys) {
        putProperty(props, prop);
    }
}

/**
 * put property to map of properties
 * @param props parsed properties file
 * @param propKey property key
 */
void PropertiesUtil::putProperty(string &props, string &propKey) {
    unsigned long startPosition = props.find(propKey);
    string size = string();
    for (int i = startPosition + propKey.length() + 1; props[i] != '\n'; i++) {
        size = size + props[i];
    }
    properties[propKey] = size;
}

const map<string, string> &PropertiesUtil::getProperties() const {
    return properties;
}

void PropertiesUtil::setProperties(const map<string, string> &properties) {
    PropertiesUtil::properties = properties;
}
