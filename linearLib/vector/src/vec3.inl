
namespace line {

    // Constructors

    template<IsNumberV T>
    vec<3, T>::vec(T x, T y, T z) : x(x), y(y), z(z) {}

    template<IsNumberV T>
    vec<3, T>::vec(const vec<3, T>& v) : x(v.x), y(v.y) , z(v.z) {}

    template<IsNumberV T>
    vec<3, T>::vec(const vec<2, T>& v, T z) : x(v.x), y(v.y), z(z) {}

    template<IsNumberV T>
    vec<3, T>& vec<3, T>::operator=(const vec<3, T>& v) {
        
        if(this != &v){
            x = v.x;
            y = v.y;
            z = v.z;
        }

        return *this;
    }

    // arithmetic operators
    template<IsNumberV T>
    vec<3, T> vec<3, T>::operator + (const vec<3, T>& v) const {
        return vec<3, T>(x + v.x, y + v.y, z + v.z);
    }

    template<IsNumberV T>
    vec<3, T> vec<3, T>::operator - (const vec<3, T>& v) const{
       return vec<3, T>(x - v.x, y - v.y, z - v.z);
    }

    template<IsNumberV T>
    vec<3, T> vec<3, T>::operator * (const vec<3, T>& v) const{
        return vec<3, T>(x * v.x, y * v.y, z * v.z);
    }

    template<IsNumberV T>
    vec<3, T> vec<3, T>::operator * (const T& v) const{
        return vec<3, T>(x * v, y * v, z * v);
    }

    template<IsNumberV T>
    vec<3, T> vec<3, T>::operator / (const T& t) const{
        if (t == 0) throw std::invalid_argument("Division by zero not allowed");
        
        return vec<3, T>(x / t, y / t, z / t);
    }

    // comparison operators
    template<IsNumberV T>
    bool vec<3, T>::operator == (const vec<3, T>& v) const {
        return (x == v.x) && (y == v.y) && (z == v.z);
    }

    // index operator
    template<IsNumberV T>
    const T& vec<3, T>::operator [] (const std::size_t& i) const {
        return *(&x + i);
    }

    template<IsNumberV T>
    T& vec<3, T>::operator [] (const std::size_t& i) {
        return *(&x + i);
    }

    // functions
    template<IsNumberV T>
    std::size_t vec<3, T>::size() const {
        return 3;
    }

    template<IsNumberV T>
    T* vec<3, T>::data() {
        return &x;
    }

    template<IsNumberV T>
    const T& vec<3, T>::at(const std::size_t& i) const {
        if ( i < 3) {
            return *(&x + i);
        } 
        
        throw std::out_of_range("Index out of range");   
    }

    template<IsNumberV T>
    T& vec<3, T>::at(const std::size_t& i) {
        if ( i < 3) {
            return *(&x + i);
        } 
        
        throw std::out_of_range("Index out of range");   
    }

    template<IsNumberV T>
    typename vec<3, T>::iterator vec<3, T>::begin() {
        return iterator(&x);
    }

    template<IsNumberV T>
    typename vec<3, T>::iterator vec<3, T>::end() {
        return iterator(&z + 1);
    }

    template<IsNumberV T>
    typename vec<3, T>::const_iterator vec<3, T>::cbegin() const {
        return const_iterator(&x);
    }

    template<IsNumberV T>
    typename vec<3, T>::const_iterator vec<3, T>::cend() const {
        return const_iterator(&z + 1);
    }

    template<IsNumberV U>
    vec<3, U> operator / (const U& t, const vec<3, U>& v) {
        if (t == 0) throw std::invalid_argument("Division by zero not allowed");
        return vec<3, U>(v.x / t, v.y / t, v.z / t);
    }

    template<IsNumberV U>
    vec<3, U> operator * (const U& t, const vec<3, U>& v) {
        return vec<3, U>(t * v.x, t * v.y, t * v.z);
    }
}