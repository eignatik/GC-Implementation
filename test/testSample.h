//
// Created by Evgeny Ignatik on 9/22/17.
//

#ifndef GARBAGECOLLECTOR_TESTSAMPLE_H
#define GARBAGECOLLECTOR_TESTSAMPLE_H

#include "cxxtest-4.4/cxxtest/TestSuite.h"

class MyTest : public CxxTest::TestSuite {
public:
    void testMethod( void )
    {
        TS_ASSERT( 1 + 1 > 1 );
        TS_ASSERT_EQUALS( 1 + 1, 2 );
    }
};

#endif //GARBAGECOLLECTOR_TESTSAMPLE_H
