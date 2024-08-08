#pragma once

#include <optional>
#include <array>
#include "../../iterator/include/iterator_vec.hpp"
#include "../../iterator/include/iterator_cvec.hpp"
#include "../../detail/setup_vec.hpp"


namespace line{
    template<length_t L, IsNumber T> 
    struct vec{
        
        using value_type = T;
        using type = vec<L, T>;
        using length = std::integral_constant<length_t, L>;
        using optional_type = std::optional<T>;
        using array_type = std::array<optional_type, L>;
        using iterator = line::iterator<optional_type>;
        using const_iterator = line::const_iterator<optional_type>;


        //constructors
        vec();
        vec(const std::initializer_list<T>& l);

        template<length_t M>
        vec(const vec<M, T>& v);
        vec(const vec<L, T>& v);
        vec(vec<L, T>&& v) noexcept;
        vec<L, T>& operator = (const vec<L, T>& v);
        vec<L, T>& operator = (vec<L, T>&& v) noexcept;

        // index operator
        const optional_type& operator [] (const std::size_t& i) const;
        optional_type& operator [] (const std::size_t& i);

        // functions
        std::size_t size() const;
        optional_type* data();
        const optional_type& at(const std::size_t& i) const;
        optional_type& at(const std::size_t& i);


        // iterators
        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;
       
       ~vec(); 
       
        private:
        array_type data_v;   
    };
};

#include "../src/vec.inl"