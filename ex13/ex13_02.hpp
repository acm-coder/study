template<typename MV1, typename MV2,
         typename tag1, typename tag2>
struct return_type_of {
    typedef typename if_<is_same<tag1, matrix_tag>::result &&
                         is_same<tag2, vector_tag>::result,
                         MV2, MV1>::return_type return_type;
};
