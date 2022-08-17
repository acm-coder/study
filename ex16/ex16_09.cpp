    using namespace std;
    list<huge_data> src = {0, 1, 2, 3};
    vector<huge_data> tgt;
    copy(make_move_iterator(src.begin()),
         make_move_iterator(src.end()),
         back_inserter(tgt));
