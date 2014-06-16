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
    MillerReciprocalCubIndices dindex(1, 1, 1);
    Vector3d vec = transformator->toVector3d(dindex);
    double val = 2 * M_PI * 0.5;
    
    EXPECT_EQ(vec, Vector3d(val, val, val));
}

TEST_F(MillerIndexCubTest, rindex_dindex_multiply)
{
    MillerDirectCubIndices dindex(1, 1, 1);
    MillerReciprocalCubIndices rindex(1, 1, 1);
    Vector3d dvec = transformator->toVector3d(dindex);
    Vector3d rvec = transformator->toVector3d(rindex);
    
    double val = 2 * M_PI * (dindex.X * rindex.H 
                + dindex.Y * rindex.K
                + dindex.Z * rindex.L);
    
    EXPECT_EQ(inner_prod(rvec, dvec), val);
}

TEST_F(MillerIndexCubTest, burgers_estimate)
{
    MillerDirectCubIndices burgers(1, 1, 0);
    MillerDirectCubIndices line(1, -1, 0);
    
    Vector3d burg_vec = transformator->toVector3d(burgers);
    Vector3d line_vec = transformator->toVector3d(line);
    Vector3d norm_vec = Vector3d(0, 0, 1);
    Vector3d misf_vec;
    
    line_vec = normalize(line_vec);
    misf_vec = cross(norm_vec, line_vec);
    
    /*misfit, screw and bz-edge components of the dislocation*/
    double bx = inner_prod(burg_vec, misf_vec);
    double by = inner_prod(burg_vec, line_vec);
    double bz = inner_prod(burg_vec, norm_vec);
    
    EXPECT_NEAR(bx, 2 * sqrt(2), 1e-4);
    EXPECT_EQ(by, 0);
    EXPECT_EQ(bz, 0);
}

}//namespace
