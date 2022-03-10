int lk[N];
int sz[N];
void pre(){
    fo(i,n) lk[i] = i;
    fo(i,n) sz[i] = 1;
}
int find(int l) {
    while(l!=lk[l])l=lk[l];
    return l;
}
void uni(int l, int r) {
    l = find(l);
    r = find(r);
    if(l==r)return;
    if(sz[l] < sz[r]) swap(l,r);
    sz[l] += sz[r];
    lk[r] = l;
}