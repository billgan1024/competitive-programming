#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("Ofast")
#define INF 0x3f
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
const int MN = 5e5, LG = bit_width((unsigned int)(2*MN));

// disRoot = distance from 0; disT = shortest distance from a centroid to a T-node
int N, t, s[MN], vis[MN], pre[MN], fst[MN]; pii st[LG][2*MN]; ll disRoot[MN], disT[MN]; 
vector<pii> adj[MN];
// get sizes of the local component
void dfs(int cur, int pre) {
    //s[cur] = 1 + sum s[child]
    s[cur] = 1;
    for(auto [nxt, w] : adj[cur]) {
        if(nxt != pre && !vis[nxt]) {
            dfs(nxt, cur); s[cur] += s[nxt];
        }
    }
}

// fill up first row in sparse table and construct distance from root array
void euler(int cur, int pre, int dep, ll d) {
    // pr("current node ", cur, sp, dep, nl);
// fst[i] = first time u encounter i
    disRoot[cur] = d; st[0][t] = {dep, cur}; fst[cur] = t++; 
    for(auto [nxt, w] : adj[cur]) {
        if(nxt != pre) {
            euler(nxt, cur, dep+1, d+w);
            st[0][t++] = {dep, cur}; 
        }
    }
}

// get centroid of the local component
int find_cent(int cur, int pre, int size) {
    for(auto [nxt, w] : adj[cur]) {
        if(nxt != pre && !vis[nxt] && s[nxt] > size/2) return find_cent(nxt, cur, size);
    }
    return cur;
}

//dfs on centroids to link them together
void decomp(int cur) {
    vis[cur] = true;
    for(auto [nxt, w] : adj[cur]) {
        if(!vis[nxt]) {
            // search into the new centroid
            dfs(nxt, -1);
            int cent = find_cent(nxt, -1, s[nxt]);
            pre[cent] = cur;
            decomp(cent);
        }
    }
    // invariant: at the end of this, the subtree for cur (which is a centroid in the centroid tree) 
    // is updated properly (can prove by induction)
}

inline int argmin(pii x, pii y) { return x.first < y.first ? x.second : y.second; }
int lca(int u, int v) {
    int tu = fst[u], tv = fst[v]; if(tu > tv) swap(tu, tv);
    int k = bit_width((unsigned int)(tv-tu+1))-1;
    return argmin(st[k][tu], st[k][tv-(1<<k)+1]);
}

inline ll dis(int u, int v) {
    // pr(u, sp, v, sp, lca(u, v), nl);
    return disRoot[u] + disRoot[v] - 2*disRoot[lca(u, v)];
}
// centroid tree only needs to be a parent array (equivalent representation of a tree)
void Init(int _N, int _A[], int _B[], int _D[]) {
    N = _N;
    for(int i = 0; i < N-1; i++) {
        int a = _A[i], b = _B[i], d = _D[i];
        adj[a].pb({b, d}); adj[b].pb({a, d});
    } 
    //construct centroid tree and lca data structure
    euler(0, -1, 0, 0); 
    for(int j = 1; j < LG; j++) {
        for(int i = 0; i+(1<<j)-1 < 2*N; i++) {
            pii p = st[j-1][i], q = st[j-1][i+(1<<(j-1))];
            st[j][i] = {min(p.first, q.first), argmin(p, q)};
        }
    }
    dfs(0, -1); 
    int cent = find_cent(0, -1, s[0]); 
    pre[cent] = -1;
    decomp(cent);
    fill(disT, disT+N, 1e18); //remember that sizeof returned the size of a pointer, so it's better to use fill

}

ll Query(int S, int X[], int T, int Y[]) {
    for(int i = 0; i < T; i++) {
        // only need to update these nodes (since we maintain the distance from each node to a node in 
        // T in its centroid component)
        for(int cur = Y[i]; cur != -1; cur = pre[cur]) {
            disT[cur] = min(disT[cur], dis(cur, Y[i]));
            // pr("centroid dis ", cur, sp, Y[i], sp, dis(cur, Y[i]), nl);
        } 
    }
    ll ans = 1e18;
    for(int i = 0; i < S; i++) {
        for(int cent = X[i]; cent != -1; cent = pre[cent]) {
            ans = min(ans, dis(X[i], cent) + disT[cent]);
            // pr("candidate dis ", cent, sp, dis(X[i], cent), sp, disT[cent], nl);

        }
    }
    // reset the centroid tree; u only updated up to these nodes
    for(int i = 0; i < T; i++) {
        for(int cent = Y[i]; cent != -1; cent = pre[cent]) {
            disT[cent] = 1e18;
        } 
    }
    return ans;
}
// int main(){
//     int N, Q;
//     sc(N, Q);
//     int *A = (int*)malloc(sizeof(int) * (N - 1));
//     int *B = (int*)malloc(sizeof(int) * (N - 1));
//     int *D = (int*)malloc(sizeof(int) * (N - 1));
//     for(int i = 0; i < N - 1; i++){
//         sc(A[i], B[i], D[i]);
//     }
//     Init(N, A, B, D);
//     // for(int i = 0; i < 2*N; i++) pr(st[0][i].first, sp, st[0][i].second, nl);
//     // for(int i = 0; i < N; i++) pr(pre[i], sp);

//     for(int a = 0; a < Q; a++){
//         int S, T; sc(S, T);
//         int *X = (int*)malloc(sizeof(int) * S);
//         int *Y = (int*)malloc(sizeof(int) * T);
//         for(int b = 0; b < S; b++){
//             sc(X[b]);
//         }
//         for(int b = 0; b < T; b++){
//             sc(Y[b]);
//         }
//         pr(Query(S, X, T, Y));
//         std::free(X);
//         std::free(Y);
//     }
//     std::free(A);
//     std::free(B);
//     std::free(D);
// }