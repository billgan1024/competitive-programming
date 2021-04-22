#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E{int u, v, l, f; } e[200002];
int N, M, D, cnt, pos, ans, p[100002], rk[100002];
bool cmp(E x, E y){ return x.l < y.l || (x.l==y.l && x.f < y.f); }
int Find(int x){
    if(x!=p[x]) p[x] = Find(p[x]);
    return p[x];
}
void Merge(int x, int y){
    if(rk[x] < rk[y]) p[x] = y;
    else{ p[y]=x; rk[x] += (rk[x]==rk[y]); }
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d %d %d", &N, &M, &D);
    for(int i=0; i<N-1; i++){
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].l);
        e[i].f =0; p[i+1]=i+1;
    }
    for(int i=N-1; i<M; i++){
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].l);
        e[i].f =1;
    }
    sort(e, e+M, cmp);
    for(int i=0; i<M; i++){
        int fu = Find(e[i].u), fv = Find(e[i].v);
        if(fu != fv){
            Merge(fu, fv);
            cnt++; pos=i; ans += e[i].f;
            if(cnt == N-1) break;
        }
    }
    if(e[pos].f){
        int maxCost = e[pos].l;
        for(int i=1; i<=N; i++){
            p[i] = i; rk[i] = 0;
        }
        for(int i=0; i<M; i++){
            int fu = Find(e[i].u), fv = Find(e[i].v);
            if(fu != fv){
                if(e[i].l < maxCost || (e[i].l==maxCost && !e[i].f)) Merge(fu, fv);
                else if(e[i].l <= D && !e[i].f) { ans--; break; }
            }
        }
    }
    printf("%d\n", ans);
}