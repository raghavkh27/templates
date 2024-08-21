#include<bits/stdc++.h>
using namespace std;

#define int long long int 

struct unionFind {
    int n, set_size, *parent, *rank;

    // Constructor
    unionFind() {}

    // Parameterized constructor
    unionFind(int a) {
        n = set_size = a;    
        parent = new int[n + 1];
        rank = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // Find function with path compression
    int find(int x) {
        if (x != parent[x]) return parent[x] = find(parent[x]);
        return x;
    }

    // Union by rank
    void merge(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);
        if (xroot != yroot) {
            if (rank[xroot] >= rank[yroot]) {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            } else {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            set_size -= 1;
        }
    }

    // Function to get the number of disjoint sets
    int size() {
        return set_size;
    }

    // Function to print the parent array
    void print() {
        for (int i = 1; i <= n; i++) cout << i << " -> " << parent[i] << endl;
    }
};

void solve() {
    // Problem-solving logic
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
