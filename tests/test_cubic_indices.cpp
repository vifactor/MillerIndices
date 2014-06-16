#include "MillerIndexCub.h"
#include <gtest/gtest.h>

namespace {

class MillerIndexCubTest : public ::testing::Test {
protected:
    virtual void SetUp()
    {
        double a = 2.0;
        transformator = new MillerCubIndicesTransformator(a);
    }

    virtual void TearDown()
    {
        if(transformator)
        {
            delete transformator;
            transformator = NULL;
        }
    }

    MillerCubIndicesTransformator * transformator;
};

// Tests wij methods
/*
TEST_F(AnalyticalMisfitInterfaceCubBxTest, wxx)
{
	EXPECT_NEAR(interface->wxx(), wxx, 1e-2);
}*/

}
