//
// Created by Evgeny Ignatik on 9/20/17.
//

#ifndef GARBAGECOLLECTOR_GCPROPERTIES_H
#define GARBAGECOLLECTOR_GCPROPERTIES_H

#include <string>
#include <map>

using namespace std;

class GCProperties {
private:
    int heapSize;
    int edenSize;
    int survivorSize;
    int tenuredSize;
    map<string, string> properties;

public:

    GCProperties() {}
    ~GCProperties() {}

    GCProperties withHeapSize(int heapSize) {
        this->heapSize = heapSize;
        return *this;
    }

    GCProperties withEdenSize(int edenSize) {
        this -> edenSize = edenSize;
        return *this;
    }

    GCProperties withSurvivorSize(int survivorSize) {
        this -> survivorSize = survivorSize;
        return *this;
    }

    GCProperties withTenuredSize(int tenuredSize) {
        this -> tenuredSize = tenuredSize;
        return *this;
    }

    GCProperties withProperties(map<string, string> properties) {
        this -> properties = properties;
        return *this;
    }

    int getHeapSize() const {
        return heapSize;
    }

    void setHeapSize(int heapSize) {
        this->heapSize = heapSize;
    }

    int getEdenSize() const {
        return edenSize;
    }

    void setEdenSize(int edenSize) {
        this->edenSize = edenSize;
    }

    int getSurvivorSize() const {
        return survivorSize;
    }

    void setSurvivorSize(int survivorSize) {
        this->survivorSize = survivorSize;
    }

    int getTenuredSize() const {
        return tenuredSize;
    }

    void setTenuredSize(int tenuredSize) {
        this->tenuredSize = tenuredSize;
    }

    const map<string, string> &getProperties() const {
        return properties;
    }

    void setProperties(const map<string, string> &properties) {
        GCProperties::properties = properties;
    }

};


#endif //GARBAGECOLLECTOR_GCPROPERTIES_H
