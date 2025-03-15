
namespace line
{

    template <nsp_concepts::is_numeric T>
    DVec<T>::DVec() : data_v{}
    {
    }

    // functions
    template <nsp_concepts::is_numeric T>
    void DVec<T>::fill(T fill_value)
    {
        std::fill(data_v.begin(), data_v.end(), fill_value);
    }

    template <nsp_concepts::is_numeric T>
    std::size_t DVec<T>::size()
    {
        return data_v.size();
    }

    template <nsp_concepts::is_numeric T>
    std::size_t DVec<T>::capacity()
    {
        return data_v.capacity();
    }

    template <nsp_concepts::is_numeric T>
    void DVec<T>::reserve(std::size_t new_capacity)
    {
        data_v.reserve(new_capacity);
    }

}