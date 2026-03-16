#include <iostream>
#include <fstream>

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
        for (int j = 0; j<width; j++) {
            auto r = double(j)/(width-1);
            auto b = double(i)/(height-1);

            int ir = r*255.9999;
            int ig = 0;
            int ib = b*255.9999;

            ofs<< ir <<' '<< ig << ' ' << ib << "\n";
        }
    }
    ofs.close();

}