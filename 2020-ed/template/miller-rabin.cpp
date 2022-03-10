#include<bits/stdc++.h>
using namespace std;

long long exp(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    res += m;
    return res%m;
}

bool check_composite(long long n, long long a, long long d, int s) {
    long long x = exp(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (long long)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}

bool MillerRabin(long long n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    long long d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}

bool MillerRabinDeterministic(long long n) {
    if(n < 2) return false;
    int r = 0;
    long long d = n-1;
    while(d%2 == 0) {
        d /= 2;
        r++;
    }
    for(int a: {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if(n == a) return true;
        if(check_composite(n,a,d,r)) return false;
    }
    return true;
}

int main(){
    
}