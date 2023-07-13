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
Count pairs with given sum
Given an array of N integers, and a number sum, the task is to find the number of pairs of integers in the array whose sum is equal to sum.

Examples:  

Input:  arr[] = {1, 5, 7, -1}, sum = 6
Output:  2
Explanation: Pairs with sum 6 are (1, 5) and (7, -1).

Input:  arr[] = {1, 5, 7, -1, 5}, sum = 6
Output:  3
Explanation: Pairs with sum 6 are (1, 5), (7, -1) & (1, 5).         
Input:  arr[] = {1, 1, 1, 1}, sum = 2
Output:  6
Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).

Input:  arr[] = {10, 12, 10, 15, -1, 7, 6, 5, 4, 2, 1, 1, 1}, sum = 11
Output:  9
Explanation: Pairs with sum 11 are (10, 1), (10, 1), (10, 1), (12, -1), (10, 1), (10, 1), (10, 1), (7, 4), (6, 5).
*/

int main(){
  test;
  while(T--){
    ll n;
    in(n);
    vll a(n);
    in_ds(a,n);
    ll sum;
    in(sum);
    unordered_map<ll, ll> freq;
    fl(i,0,n-1,1){
        freq[a[i]]++;
    }
    ll pairs_count = 0;
    fl(i,0,n-1,1){
        freq[a[i]]--;
        if(freq.find(sum - a[i]) != freq.end()){
            pairs_count += freq[sum-a[i]];
        }
    }
    dbg(pairs_count);
  }
}