//
// Created by Evgeny Ignatik on 9/20/17.
//

#ifndef GARBAGECOLLECTOR_GCAPI_H
#define GARBAGECOLLECTOR_GCAPI_H


#include "core/GCProperties.h"
#include "../util/PropertiesUtil.h"
#include "core/mappers/PropertiesMapper.h"

class GC {
public:
    GC() {}
    ~GC() {}

    void init() {
        gcProperties = PropertiesMapper().mappingToProperties("../conf/gc.properties");
    }

    bool run() {
        return true;
    }

private:
    GCProperties gcProperties;
};


#endif //GARBAGECOLLECTOR_GCAPI_H
