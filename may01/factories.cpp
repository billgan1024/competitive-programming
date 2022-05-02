#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("Ofast")
#define INF 0x3f
#define log2 31-__
#define nl '\n'
#define pb push_back
#define ms(x, y) memset(x, y, sizeof(x))
#define sp ' '
#define flush cout.setf(ios::unitbuf)
#define sz(x) (int)x.size()
#define scln(x) getline(cin, x)
void sc() {} template<class T, class...A> void sc(T &t, A &...a) { cin >> t, sc(a...); }
void pr() {} template<class T, class...A> void pr(T t, A...a) { cout << t, pr(a...); }
typedef long long ll;
typedef pair<int, int> pii;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X> using hash_map = gp_hash_table<T, X>;

// constraints on sum of S and T imply that our algorithm needs to process each query 
// in linear or nlogn time w.r.t. S or T
// u just need to find out for each of the nodes in S, the minimum distance to a node in T
// so you can just compute this answer for the centroids in their respective components i.e.
// dis[i] represents min dis to a node in T for i's centroid component
// this preprocessing requires Tlog(N) time (keep track of the Tlog(n) updates)
// then you can compute the desired result for any node in S; take the minimum
// and then remove the info about the current query (which takes Tlog(N) time due to u storing data about insertions)
// total complexity: O(nlogn) since sum of S and sum of T is linear
const int MN = 5e5, LG = bit_ceil;

int N, idx, s[MN], vis[MN], pre[MN], anc[MN][LG], fst[MN]; pii st[2*LG][MN]; ll dis[MN]; vector<pii> adj[MN];
// get sizes of the local component
void dfs(int cur, int pre) {
    s[cur] = 1;
    for(auto [nxt, w] : adj[cur]) {
        if(nxt != pre && !vis[nxt]) {
            dfs(nxt, cur); s[cur] += s[nxt];
        }
    }
}

void euler(int cur, int pre, int dep) {
// fst[i] = first time u encounter i
    st[0][idx] = {dep, cur}; fst[cur] = idx++; 
    for(auto [nxt, w] : adj[cur]) {
        if(nxt != pre) {
            euler(nxt, cur, dep+1);
        }
    }
    st[0][idx++] = {dep, cur}; 
}

// get centroid of the local component
int find_cent(int cur, int pre, int size) {
    for(auto [nxt, w] : adj[cur]) {
        if(nxt != pre && !vis[nxt] && s[nxt] > size/2) return find_cent(nxt, cur, size);
    }
    return cur;
}
    
// search and construct the centroid tree (basically dfsing on centroids all the time)
void decomp(int cur) {
    vis[cur] = true;
    for(auto [nxt, w] : adj[cur]) {
        if(!vis[nxt]) {
            dfs(nxt, -1);
            int cent = find_cent(nxt, -1, s[nxt]);
            pre[cent] = cur;
            decomp(cent);
        }
    }
}

int argmin(pii x, pii y) { return x.first < y.first ? x.second : y.second; }
int lca(int u, int v) {
    int tu = fst[u], tv = fst[v]; if(tu > tv) swap(tu, tv);
    int k = ;
    return argmin(st[k][tu], st[k][tv-(1<<k)+1]);
}
// centroid tree only needs to be a parent array (equivalent representation of a tree)
void Init(int _N, int _A[], int _B[], int _D[]) {
    N = _N;
    for(int i = 0; i < N-1; i++) {
        int a = _A[i], b = _B[i], d = _D[i];
        adj[a].pb({b, d}); adj[b].pb({b, a});
    } 
    //construct centroid tree and lca data structure
    euler(0, -1, 0); 
    for(int j = 1; j < LG; j++) {
        for(int i = 0; i+(1<<j)-1 < N; i++) {
            pii p = st[j-1][i], q = st[j-1][i+(1<<(j-1))];
            st[j][i] = {min(p.first, q.first), argmin(p, q)};
        }
    }
    
    dfs(0, -1); int cent = find_cent(0, -1, s[0]); 
    pre[cent] = -1;
    decomp(cent);
    fill(dis, dis+N, INT_MAX); //remember that sizeof returned the size of a pointer, so it's better to use fill
}

void upd(int v) {
    while(v != -1) {

    }
}

void reset(int v) {

}
ll Query(int S, int X[], int T, int Y[]) {
    for(int i = 0; i < T; i++) {

    }
}