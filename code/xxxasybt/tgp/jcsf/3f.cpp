
// 极值点与好点在坏点的同侧
// 极值点为区间最高点时，好点为大值
// 极值点为区间最低点时，好点为小值
double l = L, r = R;
while (r - l > exp) {
    double lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
    if (f(lmid) < f(rmid)) r = rmid; // 极值点为区间最低点时，好点为小值，即lmid
    else l = lmid;
}

double l = L, r = R;
while (r - l > exp) {
    double lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
    if (f(lmid) < f(rmid)) l = lmid; // 极值点为区间最高点时，好点为大值，即rmid
    else r = rmid;
}


