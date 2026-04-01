//
// Created by nourb on 01/04/2026.
//

#ifndef NOAM_RAYTRACER_SPHERE_H
#define NOAM_RAYTRACER_SPHERE_H
#include "Vec3.h"

using Vec3 = Point;

class Sphere {
public:
        double m_rayon;
        Point m_centre;

        Sphere(double p_rayon, Point p_centre): m_rayon(p_rayon),m_centre(p_centre) {}

};


#endif //NOAM_RAYTRACER_SPHERE_H