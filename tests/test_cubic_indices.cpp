#include "MillerIndexCub.h"
#include <gtest/gtest.h>

namespace {

using namespace Geometry;

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

// Tests
TEST_F(MillerIndexCubTest, dindex_create)
{
    //MillerReciprocalCubIndices rindex;
    MillerDirectCubIndices dindex(1, 1, 1);
    Vector3d vec = transformator->toVector3d(dindex);
    
    EXPECT_EQ(vec, Vector3d(2, 2, 2));
}

TEST_F(MillerIndexCubTest, rindex_create)
{
    //MillerReciprocalCubIndices rindex;
    MillerReciprocalCubIndices dindex(1, 1, 1);
    Vector3d vec = transformator->toVector3d(dindex);
    double val = 2 * M_PI * 0.5;
    
    EXPECT_EQ(vec, Vector3d(val, val, val));
}

TEST_F(MillerIndexCubTest, rindex_dindex_multiply)
{
    //MillerReciprocalCubIndices rindex;
    MillerDirectCubIndices dindex(1, 1, 1);
    MillerReciprocalCubIndices rindex(1, 1, 1);
    Vector3d dvec = transformator->toVector3d(dindex);
    Vector3d rvec = transformator->toVector3d(rindex);
    
    double val = 2 * M_PI * (dindex.X * rindex.H 
                + dindex.Y * rindex.K
                + dindex.Z * rindex.L);
    
    EXPECT_EQ(inner_prod(rvec, dvec), val);
}

}//namespace
