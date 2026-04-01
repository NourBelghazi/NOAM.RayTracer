
#ifndef NOAM_RAYTRACER_COLOR_H
#define NOAM_RAYTRACER_COLOR_H
#include "Vec3.h"
#include "Color.h"
#include <iostream>

using Color = Vec3;

void write_color(std::ostream& os,const Color& color) {
     int rbyte = int(color.getX()*255.999);
     int gbyte = int(color.getY()*255.999);
     int bbyte = int(color.getZ()*255.999);

     os<<rbyte<<' '<<gbyte<<' '<<bbyte<<"\n";
}


#endif //NOAM_RAYTRACER_COLOR_H