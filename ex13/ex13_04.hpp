template<typename MV1, typename MV2,
         typename tag1, typename tag2>
struct return_type_of {
    typedef typename if_call<is_same<tag1, vector_tag>::result,
                             if_call<is_same<tag2, matrix_tag>::result,
                                     pipe_<MV2>,
                                     pipe_<MV1> >,
                             pipe_<MV1> >::return_type return_type;
};
