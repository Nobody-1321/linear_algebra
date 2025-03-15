namespace line
{
    namespace math
    {

        // transpose
        template <nsp_types::length_t R, nsp_types::length_t C, nsp_concepts::is_numeric T>
        SMat<C, R, T> transpose(const SMat<R, C, T> &mat_)
        {
            SMat<C, R, T> transposed;
            for (size_t i = 0; i < R; ++i)
            {
                for (size_t j = 0; j < C; ++j)
                {
                    transposed[j][i] = mat_[i][j];
                }
            }
            return transposed;
        }

    }
}
