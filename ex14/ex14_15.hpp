struct throwing_data
{
    unsigned data;
    throwing_data() : data() {}
    throwing_data(unsigned data): data(data) {}
    throwing_data(throwing_data const &d)  : data(d.data) {}
    throwing_data(throwing_data &&rr) throw (int) : data() {
        static unsigned counter;
        if (++counter >= 3) throw -1;
        else std::swap(data, rr.data);
    }
};
