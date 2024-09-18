#include<bits/stdc++.h>
using namespace std;
#define int long long int 
const int mod = (int)1e9+7;

class node {
public:
    node *child[2];
    int cnt = 0;
    node(){
        child[0] = nullptr;
        child[1] = nullptr;
        cnt = 0;
    }
};

class trie {
public: 
    node *root;
    trie(){
        root = new node();
    }

    // Insert a number into the Trie
    void insert(int num) {
        node* cur = root;
        for (int i = 31; i >= 0; i--) {
            cur->cnt++;
            int x = (num >> i) & 1;
            if (cur->child[x] == nullptr) {
                cur->child[x] = new node();
            }
            cur = cur->child[x];
        }
        cur->cnt++;
    }

    // Remove a number from the Trie
    void remove(int num) {
        node* cur = root;
        for (int i = 31; i >= 0; i--) {
            cur->cnt--;
            int x = (num >> i) & 1;
            cur = cur->child[x];
        }
        cur->cnt--;
    }

    // Find maximum XOR for a given number
    int findMax(int num) {
        node* cur = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (cur->child[!bit] && cur->child[!bit]->cnt > 0) {
                maxNum = maxNum | (1 << i);
                cur = cur->child[!bit];
            } else {
                cur = cur->child[bit];
            }
        }
        return maxNum;
    }
};
void solve(){}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;  // Number of test cases
    while(t--){
        solve();
    }
}
