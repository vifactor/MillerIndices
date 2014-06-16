#ifndef MILLERINDEXCUB_H
#define MILLERINDEXCUB_H

#include "Vector3d.hpp"

enum {MillerCubIndicesDimension = 3};

struct MillerReciprocalCubIndices
{
    MillerReciprocalCubIndices(double h = 0, double k = 0, double l = 0) : 
                                                        H(h), K(k), L(l){}
    double H, K, L;

    bool isCorrect()
    {
        /*any combination of integers gives correct cubic index*/
        return true;
    }
};

struct MillerDirectCubIndices
{
    MillerDirectCubIndices(double x = 0, double y = 0, double z = 0) : 
                                                        X(x), Y(y), Z(z){}
    double X, Y, Z;
    bool isCorrect()
    {
        /*any combination of integers gives correct cubic index*/
        return true;
    }
};

class MillerCubIndicesTransformator
{
public:
    MillerCubIndicesTransformator(double a);
    virtual ~MillerCubIndicesTransformator() {}
    Geometry::Vector3d toVector3d(const MillerReciprocalCubIndices& rec_index);
    Geometry::Vector3d toVector3d(const MillerDirectCubIndices& dir_index);
protected:
    Geometry::Vector3d m_a1, m_a2, m_a3;
    Geometry::Vector3d m_A1, m_A2, m_A3;
};

#endif // MILLERINDEXCUB_H
