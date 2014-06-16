#include "MillerIndexHex.h"

using namespace Geometry;

MillerHexIndicesTransformator::MillerHexIndicesTransformator(double a, double c)
{
        /**Initialization**/
        /**direct space hexagonal base vectors**/
        m_a1 = Vector3d(a, 0.0, 0.0);
        m_a2 = Vector3d(-a / 2.0, sqrt(3.0)*a / 2.0, 0.0);
        m_a3 = Vector3d(-a / 2.0, -sqrt(3.0)*a / 2.0, 0.0);
        m_cc = Vector3d(0.0, 0.0, c);
        /**reciprocal space hexagonal base vectors**/
        m_A1 = Vector3d(2.0 * M_PI * 2.0 / (3.0 * a), 0.0, 0.0);
        m_A2 = Vector3d(2.0 * M_PI * (-1.0) / (3.0 * a),
                 2.0 * M_PI * 1.0 / (sqrt(3.0) * a),
                 0.0);
        m_A3 = Vector3d(2.0 * M_PI * (-1.0) / (3.0 * a),
                 2.0 * M_PI * (-1.0) / (sqrt(3.0) * a),
                 0.0);
        m_CC = Vector3d(0.0, 0.0, 2.0 * M_PI / c);
}

Vector3d 
MillerHexIndicesTransformator::toVector3d(const MillerReciprocalHexIndices& rec_index)
{
    return m_A1 * rec_index.H + m_A2 * rec_index.K
            + m_A3 * rec_index.I +  m_CC * rec_index.L;
}

Vector3d
MillerHexIndicesTransformator::toVector3d(const MillerDirectHexIndices& dir_index)
{
    return  m_a1 * dir_index.X + m_a2 * dir_index.Y
            + m_a3 * dir_index.T + m_cc * dir_index.Z;
}
