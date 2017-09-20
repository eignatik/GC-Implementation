//
// Created by Evgeny Ignatik on 9/20/17.
//

#ifndef GARBAGECOLLECTOR_PROPERTIESMAPPER_H
#define GARBAGECOLLECTOR_PROPERTIESMAPPER_H


#include "../GCProperties.h"
#include "../../../util/PropertiesUtil.h"
#include <string>
#include <map>

using namespace std;

class PropertiesMapper {
public:
    GCProperties mappingToProperties(string pathToProperties) {
        propertiesUtil = PropertiesUtil();
        propertiesUtil.setPropertiesFromFile(pathToProperties);
        return mapping();
    }

    GCProperties mappingToProperties(map<string, string> &properties) {
        propertiesUtil = PropertiesUtil();
        propertiesUtil.setProperties(properties);
        return mapping();
    }
private:
    PropertiesUtil propertiesUtil;

    GCProperties mapping() {
        int heapSize = stoi(propertiesUtil.getProperty("heap.size"));
        return GCProperties()
                .withHeapSize(heapSize)
                .withEdenSize(heapSize / parseDecimalStringToInt(propertiesUtil.getProperty("eden")))
                .withSurvivorSize(heapSize / parseDecimalStringToInt(propertiesUtil.getProperty("survivor")))
                .withTenuredSize(heapSize / parseDecimalStringToInt(propertiesUtil.getProperty("tenured")))
                .withProperties(propertiesUtil.getProperties());

    }

    int parseDecimalStringToInt(string decimal) {
        unsigned long dividerPosition = decimal.find('/');
        string left, right;
        for (int i = 0; i < decimal.length(); i++) {
            if (i < dividerPosition) {
                left = left + decimal[i];
            }
            if (i > dividerPosition) {
                right = right + decimal[i];
            }
        }
        return stoi(right)/stoi(left);
    }
};


#endif //GARBAGECOLLECTOR_PROPERTIESMAPPER_H
