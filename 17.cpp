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

// Best Time to Buy and Sell Stock

/*
Type I: At most one transaction is allowed

Given an array prices[] of length N, representing the prices of the stocks on different days, the task is to find the maximum profit possible for buying and selling the stocks on different days using transactions where at most one transaction is allowed.

Note: Stock must be bought before being sold.

Examples:

Input: prices[] = {7, 1, 5, 3, 6, 4]
Output: 5
Explanation:
The lowest price of the stock is on the 2nd day, i.e. price = 1. Starting from the 2nd day, the highest price of the stock is witnessed on the 5th day, i.e. price = 6. 
Therefore, maximum possible profit = 6 – 1 = 5. 

Input: prices[] = {7, 6, 4, 3, 1} 
Output: 0
Explanation: Since the array is in decreasing order, no possible way exists to solve the problem.
*/
ll type_1(vll &a, ll n){
    ll maxProfit = 0, maxPriceTillNow = a[n-1];
    flr(i,n-2,0,1){
        if(a[i] > maxPriceTillNow) maxPriceTillNow = a[i];
        else{
            maxProfit = max(maxProfit, maxPriceTillNow - a[i]);
        }
    }
    return maxProfit;
}

/*
Type II: Infinite transactions are allowed

Given an array price[] of length N, representing the prices of the stocks on different days, the task is to find the maximum profit possible for buying and selling the stocks on different days using transactions where any number of transactions are allowed.

Examples: 

Input: prices[] = {7, 1, 5, 3, 6, 4} 
Output: 7
Explanation:
Purchase on 2nd day. Price = 1.
Sell on 3rd day. Price = 5.
Therefore, profit = 5 – 1 = 4.
Purchase on 4th day. Price = 3.
Sell on 5th day. Price = 6.
Therefore, profit = 4 + (6 – 3) = 7.

Input: prices = {1, 2, 3, 4, 5} 
Output: 4
Explanation: 
Purchase on 1st day. Price = 1.
Sell on 5th day. Price = 5. 
Therefore, profit = 5 – 1 = 4.
*/
ll type_2(vll &a, ll n){
    ll maxProfit = 0, localMinimaIndex = 0, i = localMinimaIndex+1;
    while(i < n){
        while(i < n && a[i] > a[i-1]){
            i++;
        }
        maxProfit += a[i-1] - a[localMinimaIndex];
        localMinimaIndex = i;
        i++;
    }
    return maxProfit;
}

/*
Type III: At most two transactions are allowed

Problem: Given an array price[] of length N which denotes the prices of the stocks on different days. The task is to find the maximum profit possible for buying and selling the stocks on different days using transactions where at most two transactions are allowed.

Note: Stock must be bought before being sold. 

Input: prices[] = {3, 3, 5, 0, 0, 3, 1, 4} 
Output: 6 
Explanation: 
Buy on Day 4 and Sell at Day 6 => Profit = 3 0 = 3 
Buy on Day 7 and Sell at Day 8 => Profit = 4 1 = 3 
Therefore, Total Profit = 3 + 3 = 6

Input: prices[] = {1, 2, 3, 4, 5} 
Output: 4 
Explanation: 
Buy on Day 1 and sell at Day 6 => Profit = 5 1 = 4 
Therefore, Total Profit = 4 
*/
ll type_3(vll &a, ll n){
    ll maxProfit = 0, localMinimaIndex = 0, i = localMinimaIndex+1;
    priority_queue<ll> maxHeap;
    while(i < n){
        while(i < n && a[i] > a[i-1]){
            i++;
        }
        maxHeap.push(a[i-1] - a[localMinimaIndex]);
        localMinimaIndex = i;
        i++;
    }

    if(maxHeap.size() == 0) return 0;
    
    
    else if(maxHeap.size() == 1) 
    {
        maxProfit += maxHeap.top();
        maxHeap.pop();
        return maxProfit;
    }

    maxProfit += maxHeap.top();
    maxHeap.pop();
    maxProfit += maxHeap.top();
    maxHeap.pop();
    return maxProfit;
}

/*
Type IV: At most K transactions are allowed

Problem: Given an array price[] of length N which denotes the prices of the stocks on different days. The task is to find the maximum profit possible for buying and selling the stocks on different days using transactions where at most K transactions are allowed.

Note: Stock must be bought before being sold.

Examples: 

Input: K = 2, prices[] = {2, 4, 1} 
Output: 2
Explanation: Buy on day 1 when price is 2 and sell on day 2 when price is 4. Therefore, profit = 4-2 = 2.

Input: K = 2, prices[] = {3, 2, 6, 5, 0, 3} 
Output: 7
Explanation: 
Buy on day 2 when price is 2 and sell on day 3 when price is 6. Therefore, profit = 6-2 = 4.
Buy on day 5 when price is 0 and sell on day 6 when price is 3. Therefore, profit = 3-0 = 3.
Therefore, the total profit = 4+3 = 7
*/
ll type_4(vll &a, ll n, ll k){
    ll maxProfit = 0, localMinimaIndex = 0, i = localMinimaIndex+1;
    priority_queue<ll> maxHeap;
    while(i < n){
        while(i < n && a[i] > a[i-1]){
            i++;
        }
        maxHeap.push(a[i-1] - a[localMinimaIndex]);
        localMinimaIndex = i;
        i++;
    }
    
    ll count = 0;
    while(count++<k && maxHeap.size() > 0) 
    {
        maxProfit += maxHeap.top();
        maxHeap.pop();
    }

    return maxProfit;
}

/*
Type V: Infinite transaction with Cooldown
 
Problem : Given an array price[] of length N which denotes the prices of the stocks on different days. The task is to find the maximum profit possible by buying and selling stock with the restriction of after you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note : Stock must be bought before being sold, and overlapping of transactions is not allowed.

Examples : 

Input : arr[] = 1 2 3 0 2
Output : 3
Explanation :
You first buy on day 1 and sell on the day 2 then cooldown, then buy on day 4 and sell on day 5.
Total profit earned is (2-1) + (2-0) = 3, which is the maximum achievable profit.

Input : arr[] = 3 1 6 1 2 4
Output : 7
Explanation :
You first buy at day 2 and sell on the day 3 then cooldown, then again you buy on day 5 and then sell 
on day 6. Clearly, total profit earned is (6-1) + (4-2) = 7, which is the maximum achievable profit.
*/
ll type_5_util(vll &a, ll n, ll i, ll profit = 0){
    ll j = i+1;
    priority_queue<ll> maxHeap;
    while(j < n){
        while(j < n && a[j] > a[j-1]){
            maxHeap.push(type_5_util(a,n,j+2, profit+(a[j] - a[i])));
            j++;
        }
        i = j;
        j++;
    }

    return maxHeap.size()>0 ? maxHeap.top() : profit;
}

ll type_5(vll &a, ll n){
    unordered_map<ll, ll> dp(n);
    
    return type_5_util(a,n,0);
}


int main(){
  test;
  while(T--){
    ll n;
    in(n);
    vll a(n);
    in_ds(a,n);
    // ll maxProfitType1 = type_1(a,n);
    // dbg(maxProfitType1);
    // ll maxProfitType2 = type_2(a,n);
    // dbg(maxProfitType2);
    // ll maxProfitType3 = type_3(a,n);
    // dbg(maxProfitType3);
    // ll k;
    // in(k);
    // ll maxProfitType4 = type_4(a,n,k);
    // dbg(maxProfitType4);
    ll maxProfitType5 = type_5(a,n);
    dbg(maxProfitType5);
  }
}