#include <iostream>
#include <fstream>
#include "Vec3.h"
#include "Color.h"
using Color = Vec3;
int main() {
    int width = 256;
    int height = 256;

    std::ofstream ofs("../image/image.ppm");

    if (!ofs) {
        std::cout<<"Ne trouve pas";
    }

    ofs << "P3\n" << width << ' ' <<height;
    ofs <<"\n255\n";

    for (int i = 0; i<height; i++) {
        double normalisedI = i/(height-1);

        for (int j = 0; j<width; j++) {
            double normalisedJ = j/(width-1);
            Color color(normalisedI,0,normalisedJ);
            write_color(ofs, color);
        }
    }
    ofs.close();
    std::clog << "\rDone.                 \n";



}