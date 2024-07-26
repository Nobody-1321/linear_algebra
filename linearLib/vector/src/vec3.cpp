#include "../include/vec3.hpp"

namespace line {

    template<IsNumber T>
    vec<3, T>::vec(T x, T y, T z) : x(x), y(y), z(z) {}

    template<IsNumber T>
    vec<3, T>::vec(const vec<3, T>& v) : x(v.x), y(v.y) , z(v.z) {}

    template<IsNumber T>
    vec<3, T>& vec<3, T>::operator=(const vec<3, T>& v) {
        
        if(this != &v){
            x = v.x;
            y = v.y;
            z = v.z;
        }

        return *this;
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator + (const vec<3, T>& v) const {
        return vec<3, T>(x + v.x, y + v.y, z + v.z);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator - (const vec<3, T>& v) const{
       return vec<3, T>(x - v.x, y - v.y, z - v.z);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator * (const vec<3, T>& v) const{
        return vec<3, T>(x * v.x, y * v.y, z * v.z);
    }

    template<IsNumber T>
    vec<3, T> vec<3, T>::operator * (const T& v) const{
        return vec<3, T>(x * v, y * v, z * v);
    }

    template<IsNumber T>
    T vec<3, T>::operator [] (const int& i) const {
        if (i == 0) return this->x;
        if (i == 1) return this->y;
        if (i == 2) return this->z;
        throw std::out_of_range("In vec2 __index ("+ std::to_string(i) + ") is out of range");
    }

    template<IsNumber T>
    size_t vec<3, T>::size() const {
        return size_v;
    }

    template struct vec<3, float>;
    template struct vec<3, int>;
    template struct vec<3, double>;
  
    /*
    template struct vec<2, long>;
    template struct vec<2, int8_t>;
    template struct vec<2, int16_t>;
    template struct vec<2, int32_t>;
    template struct vec<2, int64_t>;
    template struct vec<2, uint8_t>;
    template struct vec<2, uint16_t>;
    template struct vec<2, uint32_t>;
    template struct vec<2, uint64_t>;
    */


}