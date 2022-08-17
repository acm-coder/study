template<typename Matrix1, typename Matrix2>
Matrix1 prod(Matrix1 const &m1, Matrix2 const &m2);

template<typename Matrix1, typename Vector1>
Vector1 prod(Matrix1 const &m, Vector1 const &v);

template<typename Vector2, typename Matrix2>
Vector2 prod(Vector2 const &v, Matrix2 const &m);
