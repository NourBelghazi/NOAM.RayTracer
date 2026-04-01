#ifndef NOAM_RAYTRACER_VEC3_H
#define NOAM_RAYTRACER_VEC3_H
#include <cmath>
#include <iostream>
class Vec3 {
public :
    double e[3];

    Vec3(): e{0,0,0}{}
    Vec3(double e0, double e1, double e2):e{e0,e1,e2}{}

    double getX() const {return e[0];}
    double getY() const {return e[1];}
    double getZ() const{return e[2];}

    Vec3& operator=(const Vec3& vector) {
        e[0]=vector.e[0];
        e[1]=vector.e[1];
        e[2]=vector.e[2];

        return *this;
    }

    Vec3& operator+=(const Vec3& vector) {
        e[0] += vector.getX();
        e[1] += vector.getY();
        e[2] += vector.getZ();
        return *this;
    }
    Vec3& operator-() {
        e[0] = -getX();
        e[1] = -getY();
        e[2] = -getZ();
        return *this;
    }
    Vec3& operator*=(const Vec3& vector) {
        e[0] = vector.getX()*getX();
        e[1] = vector.getY()*getY();
        e[2] = vector.getZ()*getZ();
        return *this;
    }
    Vec3& operator*=(double scalar) {
        e[0] *= scalar;
        e[1] *= scalar;
        e[2] *= scalar;
        return *this;
    }
    Vec3& operator/=(double denominator) {

        return *this*=1.0/denominator;
    }
    double getLengh() {
        double lenghSquared = getX()*getX()+getY()*getY()+getZ()*getZ();
        return std::sqrt(lenghSquared);
    }
    Vec3 unit_vector() {
        double len = getLengh();

        if (len < 1e-8) {
            return Vec3(0,0,0);
        }

        return *this/=len;
    }
    double operator[](int i) const {
        return e[i];
    }
    double& operator[](int i) {
        return e[i];
    }
};
using Point = Vec3;
inline std::ostream& operator<<(std::ostream& os, const Vec3& vector) {
    return os<<vector[0]<<' '<<vector[1]<<' '<<vector[2];
}
inline Vec3 operator*(const Vec3& vector, double scalar) {
    Vec3 vectorMultiplied = vector;
    vectorMultiplied*=scalar;
    return vectorMultiplied;
}
inline Vec3 operator*(double scalar,const Vec3& vector) {
    Vec3 vectorMultiplied = vector;
    vectorMultiplied*=scalar;
    return vectorMultiplied;
}
inline Vec3 operator+(const Vec3& vector1, const Vec3& vector2) {
    Vec3 vectorSomme = vector1;
    vectorSomme+=vector2;
    return vectorSomme;
}
inline Vec3 operator-(const Vec3& vector1, const Vec3& vector2) {
    Vec3 vectorInverseOfVector2 = vector2;
    vectorInverseOfVector2 = -vectorInverseOfVector2;
    return vector1+vectorInverseOfVector2;
}
inline Vec3 operator/(const Vec3& vector, double denominator) {
    Vec3 vectorDivided = vector;
    vectorDivided/=denominator;
    return vectorDivided;
}
inline Vec3 dot(const Vec3& vector1, const Vec3& vector2) {
    Vec3 vectorDot;
    vectorDot.e[0]= vector1.getX()*vector2.getX();
    vectorDot.e[1]= vector1.getY()*vector2.getY();
    vectorDot.e[2]= vector1.getZ()*vector2.getZ();

    return vectorDot;
}
inline Vec3 vectorial(const Vec3& vector1, const Vec3& vector2) {
    Vec3 vectorial;
    vectorial.e[0]= vector1.getY()*vector2.getZ()-vector1.getZ()*vector2.getY();
    vectorial.e[1]= vector1.getZ()*vector2.getX()-vector1.getX()*vector2.getZ();
    vectorial.e[2]= vector1.getX()*vector2.getY()-vector1.getY()*vector2.getX();
    return vectorial;
}



#endif