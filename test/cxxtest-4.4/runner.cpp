/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_MyTest_init = false;
#include "/Users/eignatik/CLionProjects/garbagecollector/test/testSample.h"

static MyTest suite_MyTest;

static CxxTest::List Tests_MyTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTest( "../../testSample.h", 10, "MyTest", suite_MyTest, Tests_MyTest );

static class TestDescription_suite_MyTest_testMethod : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTest_testMethod() : CxxTest::RealTestDescription( Tests_MyTest, suiteDescription_MyTest, 12, "testMethod" ) {}
 void runTest() { suite_MyTest.testMethod(); }
} testDescription_suite_MyTest_testMethod;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
