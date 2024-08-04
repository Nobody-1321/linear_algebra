

namespace line {

    //constructors

    template<IsNumberV T>
    vec<2, T>::vec(T x, T y) : x(x), y(y) {}

    template<IsNumberV T>
    vec<2, T>::vec(const vec<2, T>& v) : x(v.x), y(v.y) {}

    template<IsNumberV T>
    vec<2, T>& vec<2, T>::operator=(const vec<2, T>& v) {
        
        if (this != &v) {
            x = v.x;
            y = v.y;
        }

        return *this;
    }

    // arithmetic operators
    template<IsNumberV T>
    vec<2, T> vec<2, T>::operator + (const vec<2, T>& v) const {
        return vec<2, T>(x + v.x, y + v.y);
    }

    template<IsNumberV T>
    vec<2, T> vec<2, T>::operator - (const vec<2, T>& v) const{
       return vec<2, T>(x - v.x, y - v.y);
    }

    template<IsNumberV T>
    vec<2, T> vec<2, T>::operator * (const vec<2, T>& v) const{
        return vec<2, T>(x * v.x, y * v.y);
    }

    template<IsNumberV T>
    vec<2, T> vec<2, T>::operator * (const T& t) const{
        return vec<2, T>(x * t, y * t);
    }

    template<IsNumberV T>
    vec<2, T> vec<2, T>::operator / (const T& t) const {
        if (t == 0) throw std::invalid_argument("In vec2 division by zero");

        return vec<2, T>(x / t,y / t);
    }

    // comparison operators
    template<IsNumberV T>
    bool vec<2, T>::operator==(const vec<2, T>& v) const {
        return this->x == v.x && this->y == v.y;
    }

    // index operator
    template<IsNumberV T>
    const T & vec<2, T>::operator [] (const int& i) const {
        if (i == 0) return this->x;
        if (i == 1) return this->y;
        throw std::out_of_range("In vec2 __index ("+ std::to_string(i) + ") is out of range");
    }

    template<IsNumberV T>
    T & vec<2, T>::operator [] (const int& i)  {
        if (i == 0) return this->x;
        if (i == 1) return this->y;
        throw std::out_of_range("In vec2 __index ("+ std::to_string(i) + ") is out of range");
    }

    template<IsNumberV T>
    int vec<2, T>::size() const {
        return 2;
    }

    template<IsNumberV U>
    vec<2, U> operator / (const U& t, const vec<2, U>& v) {
        if (t == 0) throw std::invalid_argument("In vec2 division by zero");
        
        return vec<2, U>(v.x / t, v.y / t);
    }

    template<IsNumberV U>
    vec<2, U> operator * (const U& t, const vec<2, U>& v) {
        return vec<2, U>(v.x * t, v.y * t);
    }

}