
namespace line {

    // Constructors

    template<IsNumber T>
    vec<3, T>::vec(T x, T y, T z) : x(x), y(y), z(z) {}

    template<IsNumber T>
    vec<3, T>::vec(const vec<3, T>& v) : x(v.x), y(v.y) , z(v.z) {}

    template<IsNumber T>
    vec<3, T>::vec(const vec<2, T>& v, T z) : x(v.x), y(v.y), z(z) {}

    // assignment operators
    template<IsNumber T>
    vec<3, T>& vec<3, T>::operator=(const vec<3, T>& v) {
        
        if(this != &v){
            x = v.x;
            y = v.y;
            z = v.z;
        }

        return *this;
    }

    // arithmetic operators
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
    vec<3, T> vec<3, T>::operator / (const T& t) const{
        return vec<3, T>(x / t, y / t, z / t);
    }

    template<IsNumber T>
    bool vec<3, T>::operator == (const vec<3, T>& v) const {
        return (x == v.x) && (y == v.y) && (z == v.z);
    }

    template<IsNumber T>
    T vec<3, T>::operator [] (const int& i) const {
        if (i == 0) return this->x;
        if (i == 1) return this->y;
        if (i == 2) return this->z;
        throw std::out_of_range("In vec3 __index ("+ std::to_string(i) + ") is out of range");
    }

    template<IsNumber T>
    int vec<3, T>::size() const {
        return 3;
    }

    template<IsNumber U>
    vec<3, U> operator/(const U& t, const vec<3, U>& v){
        return vec<3, U>(v.x / t, v.y / t, v.z / t);
    }

    template<IsNumber U>
    vec<3, U> operator*(const U& t, const vec<3, U>& v){
        return vec<3, U>(t * v.x, t * v.y, t * v.z);
    }
}