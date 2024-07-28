
namespace line {

    // Constructors

    template<IsNumber T>
    vec<4, T>::vec(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

    template<IsNumber T>
    vec<4, T>::vec(const vec<4, T>& v) : x(v.x), y(v.y) , z(v.z) , w(v.w) {}

    template<IsNumber T>
    vec<4, T>::vec(const vec<2, T>& v, T z, T w) : x(v.x), y(v.y), z(z) , w(w) {}

    // assignment operators
    template<IsNumber T>
    vec<4, T>& vec<4, T>::operator=(const vec<4, T>& v) {
        
        if(this != &v){
            x = v.x;
            y = v.y;
            z = v.z;
            w = v.w;
        }

        return *this;
    }

    // arithmetic operators
    template<IsNumber T>
    vec<4, T> vec<4, T>::operator + (const vec<4, T>& v) const {
        return vec<4, T>(x + v.x, y + v.y, z + v.z, w + v.w);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator - (const vec<4, T>& v) const{
       return vec<4, T>(x - v.x, y - v.y, z - v.z, w - v.w);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator * (const vec<4, T>& v) const{
        return vec<4, T>(x * v.x, y * v.y, z * v.z, w * v.w);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator * (const T& v) const{
        return vec<4, T>(x * v, y * v, z * v, w * v);
    }

    template<IsNumber T>
    vec<4, T> vec<4, T>::operator / (const T& t) const{
        return vec<4, T>(x / t, y / t, z / t, w / t);
    }

    template<IsNumber T>
    bool vec<4, T>::operator == (const vec<4, T>& v) const {
        return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
    }

    template<IsNumber T>
    T vec<4, T>::operator [] (const int& i) const {
        if (i == 0) return this->x;
        if (i == 1) return this->y;
        if (i == 2) return this->z;
        if (i == 3) return this->w;
        throw std::out_of_range("In vec3 __index ("+ std::to_string(i) + ") is out of range");
    }

    template<IsNumber T>
    int vec<4, T>::size() const {
        return 4;
    }

    template<IsNumber U>
    vec<4, U> operator/(const U& t, const vec<4, U>& v){
        return vec<3, U>(v.x / t, v.y / t, v.z / t, v.w / t);
    }

    template<IsNumber U>
    vec<4, U> operator*(const U& t, const vec<4, U>& v){
        return vec<3, U>(t * v.x, t * v.y, t * v.z, t * v.w);
    }
}