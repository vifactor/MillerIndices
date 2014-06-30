#ifndef MILLERINDEXHEX_H
#define MILLERINDEXHEX_H

#include "Vector3d.hpp"

enum {MillerHexIndicesDimension = 4};

struct MillerReciprocalHexIndices
{
    MillerReciprocalHexIndices(double h, double k, double i, double l) : 
                                                        H(h), K(k), I(i), L(l){}
    MillerReciprocalHexIndices(double h, double k, double l) : 
                                                        H(h), K(k), I(-(h + k)), L(l){}
    double H, K, I, L;

    bool isCorrect()
    {
        /**property of hexagonal Miller indices**/
        if((H + K + I) != 0)
            return false;
        else
            return true;
    }
    friend std::ostream& operator<<(std::ostream& os, 
            const MillerReciprocalHexIndices& idx)
    {
        os << "[" << idx.H << ", " << idx.K << ", " << idx.I << ", " << idx.L << "]";
        return os;
    }
};

struct MillerDirectHexIndices
{
    MillerDirectHexIndices(double x, double y, double t, double z) : 
                                                        X(x), Y(y), T(t), Z(z){}
    MillerDirectHexIndices(double x, double y, double z) : 
                                                        X(x), Y(y), T(-(x + y)), Z(z){}
    double X, Y, T, Z;
    bool isCorrect()
    {
        /**property of hexagonal Miller indices**/
        if((X + Y + T) != 0)
            return false;
        else
            return true;
    }
    friend std::ostream& operator<<(std::ostream& os, 
            const MillerDirectHexIndices& idx)
    {
        os << "[" << idx.X << ", " << idx.Y << ", " << idx.T << ", " << idx.Z << "]";
        return os;
    }
};

class MillerHexIndicesTransformator
{
public:
    MillerHexIndicesTransformator(double a, double c);
    virtual ~MillerHexIndicesTransformator() {}
    Geometry::Vector3d toVector3d(const MillerReciprocalHexIndices& rec_index);
    Geometry::Vector3d toVector3d(const MillerDirectHexIndices& dir_index);
protected:
    Geometry::Vector3d m_a1, m_a2, m_a3, m_cc;
    Geometry::Vector3d m_A1, m_A2, m_A3, m_CC;
};

#endif // MILLERINDEXHEX_H
