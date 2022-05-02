#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N,D;
vector<vector<int> > adj;
vector<int> opt, optdist, sacrdist; //optimal # of nodes, optimal distance, sacrifice distance with respect to the subtree
// optdist = max distance from the root for marked nodes in any configuration with the optimal # of nodes
// sacrdist = min distance that other markers would have to obey for any configuration with the optimal # of nodes.

// dfs from 0: at the end, opt[0] represents the optimal # of nodes you can mark.
void DFS(int pos) {
	// Base case: pos is a leaf
	if(adj[pos].size() == 0) {
		opt[pos] = 1;
		optdist[pos] = 0;
		sacrdist[pos] = D;
		return;
	}
	
    // start dfs on the first node
	int v = adj[pos][0];
	DFS(v);
    // check if you can get 1 more marked node at the root
	if(optdist[v] + 1 >= D) {
		opt[pos] = opt[v] + 1;
		optdist[pos] = 0;

		sacrdist[pos] = optdist[v] + 1;
	} else {
		opt[pos] = opt[v];
		optdist[pos] = optdist[v] + 1;
		sacrdist[pos] = sacrdist[v] + 1;
	}
	
	for(int i = 1; i < adj[pos].size(); ++i) {
		int v = adj[pos][i];
		DFS(v);
		
		// distance between closest points and 
		// distance to root
		// in the 4 possible solution combinations. 
		int doo = optdist[pos] + optdist[v] + 1;
		int mdoo = min(optdist[pos], optdist[v] + 1);
		
		int dos = optdist[pos] + sacrdist[v] + 1;
		int mdos = min(optdist[pos], sacrdist[v] + 1);

		int dso = sacrdist[pos] + optdist[v] + 1;
		int mdso = min(sacrdist[pos], optdist[v] + 1);

		int dss = sacrdist[pos] + sacrdist[v] + 1;
		int mdss = min(sacrdist[pos], sacrdist[v] + 1);
		
		if(doo >= D) {
			opt[pos] += opt[v];
			optdist[pos] = mdoo;
			sacrdist[pos] = max(mdos, mdso);
		} else if (dos >= D || dso >= D) {
			opt[pos] += opt[v] - 1;
			if(dos >= D) optdist[pos] = mdos; else optdist[pos] = 0;
			if(dso >= D) optdist[pos] = max(optdist[pos], mdso);
			sacrdist[pos] = mdss;
		} else {
			cout << "error!" << endl;
			exit(0);
		}
	}
}

int main() {
	scanf("%d%d", &N, &D);
    // vector with a predefined size 
    // adj = adjlist
	adj = vector<vector<int>> (N);
	opt = vector<int> (N, 0);
	optdist = vector<int> (N, 0);
	sacrdist = vector<int> (N, 0);
	for(int i = 1; i < N; ++i) {
		int a;
		scanf("%d", &a);
		adj[a].push_back(i);
	}
    // the tree is from 0 to N-1, and we only add the edge (a, b) with a < b
    // this way you can track leaf nodes easily
	DFS(0);
	printf("%d\n", opt[0]);
	return 0;
}