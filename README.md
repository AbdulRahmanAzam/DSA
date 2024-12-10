# DSA
[Guide to Competitive Programming_ Learning and Improving Algorithms Through Contests ( PDFDrive ).pdf](https://github.com/user-attachments/files/18078765/Guide.to.Competitive.Programming_.Learning.and.Improving.Algorithms.Through.Contests.PDFDrive.pdf)


## 📂 Table of Contents

1. [Basic Setup](#BASIC-SETUP-FOR-CP)  
2. [Loops](#LOOPS)  
3. [Common Functions](#COMMON-FUNCTIONS)  
4. [DATA STRUCTURES](#DATA-STRUCTURES)  
5. [INPUT MACROS](#INPUT-MACROS)  
6. [UTILITIES](#UTILITIES)
7. [TEMPLATES](#TEMPLATES-FOR-CP)
8. [Binary Search](#Binary-Search)
9. [DIJKSTRAS](#DIJKSTRAS)  


# BASIC SETUP FOR CP
```
#include <bits/stdc++.h>
using namespace std;
```
 - ### Macros for faster typing
```
#define int long long             // For using long long by default
#define pb push_back              // Shorter syntax for push_back
#define mp make_pair              // Shorter syntax for make_pair
#define all(x) x.begin(), x.end() // Shorter syntax for container traversal
#define rall(x) x.rbegin(), x.rend() // Reverse traversal
#define sz(x) (int)(x.size())     // Get size of a container
#define endl '\n'                 // Faster line breaks (avoids flush)
```
```
const int MOD = 1e9 + 7;          // Common modulo constant
const int INF = 1e18;             // Large number for infinity
```

 - ### Debugging
```
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
template <typename T> void _print(T x) { cerr << x; } // For single values
template <typename T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) cerr << i << " "; cerr << "]"; }
```
- ### Input/Output Optimization
```
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
```
# LOOPS
```
#define rep(i, a, b) for (int i = a; i < b; i++)         // Forward loop
#define repr(i, a, b) for (int i = a; i >= b; i--)       // Reverse loop
#define trav(a, x) for (auto &a : x)                    // Traversing a container
```

# COMMON FUNCTIONS
```
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); } // GCD
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }        // LCM
```
```
int mod_add(int a, int b) { return (a + b) % MOD; }          // Modulo addition
int mod_sub(int a, int b) { return ((a - b) % MOD + MOD) % MOD; } // Modulo subtraction
int mod_mul(int a, int b) { return (a * b) % MOD; }          // Modulo multiplication
```
```
int power(int a, int b, int m = MOD) {                       // Exponentiation
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
```

# DATA STRUCTURES
```
#define pii pair<int, int>              // Pair of integers
#define vi vector<int>                  // Vector of integers
#define vvi vector<vector<int>>         // 2D vector of integers
#define vvpi vector<vector<pair<int, int>>> // 2D vector of pairs
#define vpi vector<pair<int, int>>      // Vector of pairs
#define umap unordered_map              // Unordered map
#define uset unordered_set              // Unordered set
#define pqmin priority_queue<int, vector<int>, greater<int>> // Min-heap
#define pqmax priority_queue<int>       // Max-heap
```

# INPUT MACROS
```
#define read(x) for (auto &i : x) cin >> i; // Reading a container
#define print(x) for (auto &i : x) cout << i << " "; cout << endl; // Printing a container
```
- ### Read a matrix
```
#define read_matrix(mat, n, m) for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> mat[i][j];
```

# UTILITIES
```
#define yes cout << "YES" << endl      // Print YES
#define no cout << "NO" << endl        // Print NO
#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define prec(n) fixed << setprecision(n) // For printing with precision
#define unq(v) v.erase(unique(all(v)), v.end()) // Remove duplicates from sorted vector

template <typename T>                   // Template for finding min
T min_element_index(vector<T> &v) {
    return distance(v.begin(), min_element(all(v)));
}
template <typename T>                   // Template for finding max
T max_element_index(vector<T> &v) {
    return distance(v.begin(), max_element(all(v)));
}
```

# TEMPLATES FOR CP

### 1D GRID
```
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int &coin : coins) cin >> coin;

    // Add logic for solving the problem
}
```
```
int32_t main() {
    fast_io;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

```
### 2D GRID
```
int dx[] = {-1, 0, 1, 0};   // Movement in 4 directions (N, E, S, W)
int dy[] = {0, 1, 0, -1};

bool is_valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void grid_problem() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    read_matrix(grid, n, m);

    // Process the grid
}
```

## BINARY SEARCH
```
int binary_search(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Element not found
}

```
## DIJKSTRAS
```
vector<int> dijkstra(int src, int n, vector<vector<pii>> &adj) {
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
 ```
