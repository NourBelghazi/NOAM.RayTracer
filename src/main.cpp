#include <iostream>
#include <fstream>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"
#include "Sphere.h"
#include <cmath>

using Color = Vec3;
double hit_sphere(const Ray& ray, const Sphere& sphere) {
    Vec3 directionRay = ray.m_direction;
    Point originRay = ray.m_origin;

    Vec3 centre = sphere.m_centre;
    double r = sphere.m_rayon;


    Vec3 vectorOriginToCenter = centre-originRay;

    double a = dot(directionRay,directionRay);
    double b = dot(-2*directionRay, vectorOriginToCenter);
    double c = dot(vectorOriginToCenter,vectorOriginToCenter)-r*r;
    double h = b/2;

    double discriminant = h*h-a*c;
    if (discriminant < 0) {
        return -1.0;
    }
    else {
        return (-h - std::sqrt(discriminant) ) / a;
    }

}
Color ray_color(const Ray& ray) {

    Vec3 centre(0,0,-1);
    auto t = hit_sphere(ray, Sphere(0.5,centre));
    if (t >=0.0) {
        Vec3 norme = ray.position(t) - Vec3(0,0,-1);
        Vec3 N = norme.unit_vector();

        return 0.5*Color(N.getX()+1, N.getY()+1, N.getZ()+1);
    }
    else {
        auto direction = ray.m_direction;
        Vec3 unit_direction = direction.unit_vector();
        auto a = 0.5*(unit_direction.getY() + 1.0);

        return (1.0-a)*Color(1.0, 1.0, 1.0) + a*Color(0.5, 0.7, 1.0);
    }

}
int main() {
    double focalLengh = 1.0;
    int imageWidth = 400;
    double ratio = 16.0/10.0;
    int imageHeight = static_cast<int>(imageWidth/ratio);

    imageHeight =(imageHeight<1)? 1 : imageHeight;
    double viewport_height = 2.0;
    double viewport_width = viewport_height*(static_cast<double>(imageWidth)/imageHeight);
    Point centreCamera(0,0,0);

    Vec3 viewport_u(viewport_width,0,0);
    Vec3 viewport_v(0,-viewport_height,0);
    Vec3 viewportZcoordonates(0,0,-focalLengh);

    Vec3 pixelDeltaWidth = viewport_u/imageWidth;
    Vec3 pixelDeltaHeight = viewport_v/imageHeight;

    Point viewportUpperLeft = centreCamera  +viewportZcoordonates- viewport_u/2 - viewport_v/2;
    Point pixelOrigin = viewportUpperLeft + (pixelDeltaWidth + pixelDeltaHeight)/2;

    std::ofstream ofs("../image/image.ppm");
    if (!ofs) {
        std::cout<<"Ne trouve pas";
    }

    ofs << "P3\n" << imageWidth << ' ' <<imageHeight;
    ofs <<"\n255\n";

    for (int i = 0; i<imageHeight; i++) {
        for (int j = 0; j<imageWidth; j++) {
            Point pixelCenter = pixelOrigin + j*pixelDeltaWidth + i*pixelDeltaHeight;
            Vec3 ray_direction = pixelCenter-centreCamera;

            Ray r(centreCamera, ray_direction);

            Color pixel_color = ray_color(r);
            write_color(ofs, pixel_color);
        }
    }



}