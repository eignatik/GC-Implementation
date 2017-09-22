//
// Created by Evgeny Ignatik on 9/21/17.
//

#include "../cmake-build-debug/googletest-src/googletest/include/gtest/gtest.h"

TEST(IfWorks, WorksCorrectly) {
    ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}