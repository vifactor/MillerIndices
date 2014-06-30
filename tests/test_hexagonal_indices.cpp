#include "MillerIndexHex.h"
#include <gtest/gtest.h>

namespace {

using namespace Geometry;

class MillerIndexHexTest : public ::testing::Test {
protected:
    virtual void SetUp()
    {
        a0 = 2.0;
        c0 = 2.3;
        transformator = new MillerHexIndicesTransformator(a0, c0);
    }

    virtual void TearDown()
    {
        if(transformator)
        {
            delete transformator;
            transformator = NULL;
        }
    }
    
    double a0, c0;
    MillerHexIndicesTransformator * transformator;
};

// Tests
TEST_F(MillerIndexHexTest, dindex_create)
{
    //MillerReciprocalCubIndices rindex;
    MillerDirectHexIndices dindex1(1, 1, -2, 0);
    Vector3d vec1 = transformator->toVector3d(dindex1);
    EXPECT_NEAR(norm_2(vec1)/3, a0, 1e-4);
    
    MillerDirectHexIndices dindex2(0, 0, 0, 1);
    Vector3d vec2 = transformator->toVector3d(dindex2);
    EXPECT_EQ(vec2, Vector3d(0, 0, c0));
}

TEST_F(MillerIndexHexTest, rindex_create)
{
    MillerReciprocalHexIndices rindex1(1, 1, -2, 0);
    Vector3d vec1 = transformator->toVector3d(rindex1);
    EXPECT_NEAR(norm_2(vec1) / 2, 2 * M_PI / a0, 1e-4);
}

TEST_F(MillerIndexHexTest, dindex_create_second_way)
{
    //MillerReciprocalCubIndices rindex;
    MillerDirectHexIndices dindex1(1, 1, -2, 1);
    MillerDirectHexIndices dindex2(1, 1, 1);
    
    Vector3d vec1 = transformator->toVector3d(dindex1);
    Vector3d vec2 = transformator->toVector3d(dindex2);
    
    EXPECT_EQ(vec1, vec2);
}

TEST_F(MillerIndexHexTest, rindex_create_second_way)
{
    //MillerReciprocalCubIndices rindex;
    MillerReciprocalHexIndices rindex1(1, 1, -2, 1);
    MillerReciprocalHexIndices rindex2(1, 1, 1);
    
    Vector3d vec1 = transformator->toVector3d(rindex1);
    Vector3d vec2 = transformator->toVector3d(rindex2);
    
    EXPECT_EQ(vec1, vec2);
}

TEST_F(MillerIndexHexTest, dindex_correct_nocorrect)
{
    //MillerReciprocalCubIndices rindex;
    MillerDirectHexIndices dindex_correct(1, 1, -2, 1);
    MillerDirectHexIndices dindex_incorrect(1, 1, 1, 1);
    
    EXPECT_TRUE(dindex_correct.isCorrect());
    EXPECT_FALSE(dindex_incorrect.isCorrect());
}

TEST_F(MillerIndexHexTest, rindex_correct_nocorrect)
{
    //MillerReciprocalCubIndices rindex;
    MillerReciprocalHexIndices rindex_correct(1, 1, -2, 1);
    MillerReciprocalHexIndices rindex_incorrect(1, 1, 1, 1);
    
    EXPECT_TRUE(rindex_correct.isCorrect());
    EXPECT_FALSE(rindex_incorrect.isCorrect());
}

TEST_F(MillerIndexHexTest, rindex_dindex_multiply)
{
    MillerDirectHexIndices dindex(1, 1, -2, 1);
    MillerReciprocalHexIndices rindex(1, 2, -3, 2);
    Vector3d dvec = transformator->toVector3d(dindex);
    Vector3d rvec = transformator->toVector3d(rindex);
    double val = 2 * M_PI * (1 * 1 + 1 * 2 + (-2) * (-3) + 1 * 2);
    
    EXPECT_NEAR(inner_prod(rvec, dvec), val, 1e-4);
}

}//namespace
