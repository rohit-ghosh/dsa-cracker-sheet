#include <bits/stdc++.h>
using namespace std;
#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, NAME, ...) NAME
#define in(...)                                                             \
  GET_MACRO(__VA_ARGS__, in10, in9, in8, in7, in6, in5, in4, in3, in2, in1) \
  (__VA_ARGS__)
#define in1(a1) cin >> a1
#define in2(a1, a2) cin >> a1 >> a2
#define in3(a1, a2, a3) cin >> a1 >> a2 >> a3
#define in4(a1, a2, a3, a4) cin >> a1 >> a2 >> a3 >> a4
#define in5(a1, a2, a3, a4, a5) cin >> a1 >> a2 >> a3 >> a4 >> a5
#define in6(a1, a2, a3, a4, a5, a6) cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6
#define in7(a1, a2, a3, a4, a5, a6, a7) cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7
#define in8(a1, a2, a3, a4, a5, a6, a7, a8) cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8
#define in9(a1, a2, a3, a4, a5, a6, a7, a8, a9) cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9
#define in10(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10
#define line cout << "\n"
#define test \
  ll T;      \
  in(T)
#define dbg(a)         \
  cout << #a << ": " << a; \
  line
#define dbg_ds(a) \
  cout<<"Printing elements in "<<#a; \
  line; \
  for(auto e: a){ \
    cout<<e<<" "; \
  } \
  line
#define fl(i, a, b, c) for (ll i = a; i <= b; i += c)
#define flr(i, a, b, c) for (ll i = a; i >= b; i -= c)
#define in_ds(a, n) \
    fl(i,0,n-1,1) in(a[i])
#define F first
#define S second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpii;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
typedef pair<string,int> psi;
typedef unordered_map<ll,ll> umll;
typedef unordered_map<int,int> umii;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;

/*
Maximum Product Subarray | Set 3

Given an array A[] that contains both positive and negative integers, find the maximum product subarray.

Examples : 

Input: A[] = { 6, -3, -10, 0, 2 }
Output: 180  // The subarray is {6, -3, -10}

Input: A[] = {-1, -3, -10, 0, 60 }
Output: 60  // The subarray is {60}

Input: A[] = { -2, -3, 0, -2, -40 }
Output: 80  // The subarray is {-2, -40}
*/

int main(){
  test;
  while(T--){
    ll n;
    in(n);
    vll a(n);
    in_ds(a,n);
    ll i = 0;
    ll ans = a[i], max_product_of_subarray_ending_at_i = a[i], min_product_of_subarray_ending_at_i = a[i];
    while(++i < n){
        if(a[i]<0) swap(min_product_of_subarray_ending_at_i, max_product_of_subarray_ending_at_i);
        max_product_of_subarray_ending_at_i = max(max_product_of_subarray_ending_at_i * a[i], a[i]);
        min_product_of_subarray_ending_at_i = min(min_product_of_subarray_ending_at_i * a[i], a[i]);
        ans = max(ans, max_product_of_subarray_ending_at_i);
    }
    dbg(ans);
  }
}