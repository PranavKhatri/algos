#include <bits/stdc++.h>
using namespace std;

class FenwickTree {

    int n;
    vector<long long> BIT;

    FenwickTree(int n){
        this->n = n;
        BIT.resize(n+1, 0);
    }

    // add val at position idx, a[idx] += val
    void add(int idx, long long val){
        for(int i = idx; i<=; i+=(i & -i)){
            BIT[i] += val;
        }
    }

    // prefix sum from 1 to idx
    long long sum(int idx){
        long long res = 0;
        for(int i = idx; i>=0; i-=(i & -i)){
            res += BIT[i];
        }
        return res;
    }

    // range sum from l to r
    long long rangeSum(int l, int r){
        return sum(r) - sum(l-1);
    }


};

int main(){
    return 0;

}