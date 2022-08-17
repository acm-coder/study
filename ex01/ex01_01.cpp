int max_element(int const *l, unsigned sz)
{
  int max_value = l[0];
  for (unsigned i = 1; i < sz; ++i)
    if (l[i] > max_value) max_value = l[i];
  return max_value;
}
