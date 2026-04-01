#include <iostream>
#include <fstream>
#include "Vec3.h"
#include "Color.h"
#include "Ray.h"
#include "Sphere.h"
#include <cmath>

using Color = Vec3;
bool hit_sphere(const Ray& ray, const Sphere& sphere) {
    Vec3 directionRay = ray.m_direction;
    Point originRay = ray.m_origin;

    Vec3 centre = sphere.m_centre;
    double r = sphere.m_rayon;

    Vec3 vectorOriginToCenter = centre-originRay;

    double a = dot(directionRay,directionRay);
    double b = dot(-2*directionRay, vectorOriginToCenter);
    double c = dot(vectorOriginToCenter,vectorOriginToCenter)-r*r;

    bool hit_sphere = (b*b-4*a*c>-1);
    if (hit_sphere){return true;}
    return false;
}
Color ray_color(const Ray& ray) {
    auto direction = ray.m_direction;

    double r = 15;
    Point centre(10,0,30);

    Sphere sphere(r,centre);

    Vec3 unit_direction = direction.unit_vector();
    double a;
    a = 0.5*(unit_direction.getY() + 1.0);

    if (hit_sphere(ray,sphere)) {
        return Color(1,0,0);
    }
    else {
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