void foo() {
    using namespace std;
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> il;
    // 将array[5]到array[9]插入到il末尾
    copy(array + 5, array + 10, back_inserter(il));
    
    // 将array[4]到array[0]插入到il前端，为保证数据顺序不变，需要用到
    // reverse_iterator
    typedef reverse_iterator<int*> array_reverse_iterator;
    copy(array_reverse_iterator(array + 5),
         array_reverse_iterator(array),
         front_inserter(il));
}
