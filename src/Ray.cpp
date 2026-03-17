//
// Created by nourb on 16/03/2026.
//

#include "../include/Ray.h"
Ray::Ray():m_origin(0,0,0),m_direction(0,0,0){}
Ray::Ray(const Point3& p_origin, const Vec3& p_direction ):m_origin(p_origin), m_direction(p_direction){}

const Point3&
    Ray::getOrigin() const {
    return m_origin;
}
const Vec3&
    Ray::getDirection() const {
    return m_direction;
}

Point3
    Ray::position(double t) const {
    return m_origin+t*m_direction;
}
