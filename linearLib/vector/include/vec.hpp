#pragma once
#include "setup_vec.hpp"
#include "types_vec.hpp"
#include <stdexcept>
#include <array>
#include <stdint.h>
#include <iostream>
#include "../../iterator/include/iterator_vec.hpp"
#include "../../iterator/include/iterator_cvec.hpp"
#include <type_traits>
#include <optional>

namespace line{
    template<length_t L, IsNumberV T> 
    struct vec{
        using value_type = T;
        using type = vec<L, T>;
        using length = std::integral_constant<length_t, L>;
        using optional_type = std::optional<T>;
        using array_type = std::array<optional_type, L>;

        //constructors
        vec();
        
        template<length_t M>
        vec(const vec<M, T>& v);
        vec(const vec<L, T>& v);
        vec<L, T>& operator = (const vec<L, T>& v);

        // index operator
        const optional_type& operator [] (const int& i) const;
        optional_type& operator [] (const int& i);

        int size() const;

        // iterators
        using iterator = line::iterator<optional_type>;
        using const_iterator = line::const_iterator<optional_type>;

        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;
        
        private:
        array_type data_v;   
    };
};

#include "../src/vec.inl"