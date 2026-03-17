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
    Ray(const Point3& p_origin, const Vec3& p_direction );

    const Point3& getOrigin() const;
    const Vec3& getDirection() const;

    Point3 position(double t) const;
private:
    Point3 m_origin;
    Vec3 m_direction;
};


#endif //NOAM_RAYTRACER_RAY_H