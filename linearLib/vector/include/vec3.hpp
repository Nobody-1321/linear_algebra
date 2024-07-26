#pragma once
#include "setup.hpp"
#include "types.hpp"
#include <stdexcept>
#include <stdint.h>

namespace line{
 
    template<IsNumber T> 
    struct vec<3, T>{
        union {
            struct { T x,  y, z;};
            struct { T r,  g, b;};
        };

        vec(T x, T y, T z);
        vec(const vec<3, T>& v);
        vec<3, T>& operator=(const vec<3, T>& v) ;
        vec<3, T> operator + (const vec<3, T>& v) const;
        vec<3, T> operator - (const vec<3, T>& v) const;
        vec<3, T> operator * (const vec<3, T>& v) const;
        vec<3, T> operator * (const T& v) const;
        T operator [] (const int& i) const;

        size_t size() const;
        
        private:
            size_t size_v = 3;

    };

};
