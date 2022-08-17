template<typename T, typename N>
N* pop(hetero_node<T, N> *head) {
    N *next = head->next;
    delete head;
    return next;
}
