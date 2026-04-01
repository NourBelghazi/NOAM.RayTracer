//
// Created by nourb on 16/03/2026.
//

#include "../include/Ray.h"
Ray::Ray():m_origin(0.0,0.0,0.0),m_direction(0.0,0.0,0.0){}
Ray::Ray(Point3 p_origin, Vec3 p_direction ):m_origin(p_origin), m_direction(p_direction){}


Point3
    Ray::position(double t) const {
    return m_origin+t*m_direction;
}
