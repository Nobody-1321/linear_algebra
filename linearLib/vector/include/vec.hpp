#pragma once

#include <optional>
#include <array>
#include <algorithm>
#include <memory>
#include "../../iterator/include/iterator_vec.hpp"
#include "../../iterator/include/iterator_cvec.hpp"
#include "../../detail/setup_vec.hpp"
#include "../../detail/setup_vec.hpp"

namespace line
{
  template <length_t L, IsNumber T>
  struct vec
  {

    using value_type = T;
    using type = vec<L, T>;
    using length = std::integral_constant<length_t, L>;
    using optional_type = std::optional<T>;
    using array_type = std::array<optional_type, L>;
    using iterator = line::iterator<optional_type>;
    using const_iterator = line::const_iterator<optional_type>;

    // constructors
    vec(const vec<L, T> &v);
    vec(const vec<L, T> &v, T fill_value);

    template <length_t L2>
    vec(const vec<L2, T> &v);

    template <length_t L2>
    vec(const vec<L2, T> &v, T fill_value);

    vec(vec<L, T> &&v) noexcept;
    
    template <typename... Args>
      requires detail::AreSameAndNumbers<T, Args...>
    vec(Args &&...args);

    vec(T fill_value);

    //functions
    constexpr std::size_t size() const noexcept;
    void fill(T fill_value);

    // index operator
    optional_type &operator[](const std::size_t &i) noexcept; // { return data_v->at(i); }
    const optional_type &operator[](const std::size_t &i) const noexcept; // { return data_v->at(i); }
    optional_type * data() noexcept;

    optional_type &at(const std::size_t &i) noexcept; // { return data_v->at(i); }
    const optional_type &at(const std::size_t &i) const noexcept; // { return data_v->at(i); }


    // iterator
    iterator begin()noexcept; //{ return iterator(data_v->begin()); }
    iterator end() noexcept;//{ return iterator(data_v->end()); }

    const_iterator begin() const noexcept;//{ return const_iterator(data_v->begin()); }
    const_iterator end() const noexcept;//{ return const_iterator(data_v->end()); }
    ~vec();

  private:
    std::unique_ptr<array_type> data_v = std::make_unique<array_type>();
  };

};

#include "../src/vec.inl"