//
// Created by nourb on 16/03/2026.
//

#ifndef NOAM_RAYTRACER_RAY_H
#define NOAM_RAYTRACER_RAY_H
#include "Vec3.h"
using Point3 = Vec3;

class Ray {
public:
    Ray();
    Ray(Point3 p_origin, Vec3 p_direction );

    Point3 m_origin;
    Vec3 m_direction;

    Point3 position(double t) const;

};


#endif //NOAM_RAYTRACER_RAY_H