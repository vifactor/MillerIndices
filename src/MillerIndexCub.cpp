#include "MillerIndexCub.h"

using namespace Geometry;

MillerCubIndicesTransformator::MillerCubIndicesTransformator(double a)
{
        /**Initialization**/
        /**direct space cubic base vectors**/
        m_a1 = Vector3d(a, 0.0, 0.0);
        m_a2 = Vector3d(0.0, a, 0.0);
        m_a3 = Vector3d(0.0, 0.0, a);
        /**reciprocal space cubic base vectors**/
        m_A1 = Vector3d(2.0 * M_PI / a, 0.0, 0.0);
        m_A2 = Vector3d(0.0, 2.0 * M_PI / a, 0.0);
        m_A3 = Vector3d(0.0, 0.0, 2.0 * M_PI / a);
}

Vector3d 
MillerCubIndicesTransformator::toVector3d(const MillerReciprocalCubIndices& rec_index)
{
    return m_A1 * rec_index.H + m_A2 * rec_index.K + m_A3 * rec_index.L;
}

Vector3d
MillerCubIndicesTransformator::toVector3d(const MillerDirectCubIndices& dir_index)
{
    return  m_a1 * dir_index.X + m_a2 * dir_index.Y + m_a3 * dir_index.Z;
}
