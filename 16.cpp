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
Inversion count in Array using Merge Sort

Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in reverse order, the inversion count is the maximum. 

Given an array arr[]. The task is to find the inversion count of arr[]. Where two elements arr[i] and arr[j] form an inversion if a[i] > a[j] and i < j.

Examples: 

Input: arr[] = {8, 4, 2, 1}
Output: 6
Explanation: Given array has six inversions: (8, 4), (4, 2), (8, 2), (8, 1), (4, 1), (2, 1).

Input: arr[] = {1, 20, 6, 4, 5}
Output: 5
Explanation: Given array has five inversions: (20, 6), (20, 4), (20, 5), (6, 4), (6, 5).  
*/

ll inversions = 0;

void merge(vll &left, vll &right, vll &sorted_array){
    ll i = 0, j = 0;
    while(i<left.size() && j<right.size()){
        if(left[i]<=right[j]){
            sorted_array.push_back(left[i]);
            i++;
        }
        else{
            sorted_array.push_back(right[j]);
            inversions += (left.size() - i);
            j++;
        }
    }
    while(i<left.size()){
        sorted_array.push_back(left[i]);
        i++;
    }
    while(j<right.size()){
        sorted_array.push_back(right[j]);
        j++;
    }
}

void merge_sort(vll &a, ll s, ll e){
  if(e>s){
    ll m = s + (e-s)/2;
    merge_sort(a, s, m);
    merge_sort(a, m+1, e);
    vll left(m-s+1), right(e-m);
    fl(i,s,m,1){
      left[i-s] = a[i];
    }
    fl(i,m+1,e,1){
      right[i-(m+1)] = a[i];
    }
    vll sorted_array;
    merge(left,right,sorted_array);
    fl(i,s,e,1) a[i] = sorted_array[i-s];
  }

}

int main(){
  test;
  while(T--){
    ll n;
    in(n);
    vll a(n);
    in_ds(a,n);
    merge_sort(a, 0, n-1);
    dbg_ds(a);
    dbg(inversions);
    inversions = 0;
  }
}