#if GTEST_OS_MAC
# include <time.h>
#endif  // GTEST_OS_MAC

#include "gtest/gtest.h"
#include "gtest/gtest-spi.h"

#define GTEST_IMPLEMENTATION_ 1
#include "src/gtest-internal-inl.h"
#undef GTEST_IMPLEMENTATION_

namespace testing {
    namespace internal {
        TEST() {
            ASSERT_TRUE(true);
        }
    }
}