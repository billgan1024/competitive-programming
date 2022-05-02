#!/usr/bin/env python3
import sys, math
INF = 100000000

def catinatree():
    # Read input
    n, d = map(int, sys.stdin.readline().split())
    children = [[] for i in range(n)]
    for i in range(1, n):
        children[int(sys.stdin.readline().strip())].append(i) 
        
    # directed graph where we store edges (a, b) (a < b)
    
    # Keep state for each node in tree - traverse bottom up,
    # start at the leaves. For each node, remember:
    # - max # of marked nodes in subtree rooted at node
    # - maximum distance to any marked node in max size set of marked nodes     
    maxinsubtree = [-1]*n
    maxdistsubtr = [-1]*n
    
    # Stack-based DFS
    seen = [False] * n
    stack = [0]
    while len(stack) > 0:
        # get top node on the stack
        node = stack[-1] 
        if not seen[node]:
            # Pre-processing step of DFS
            seen[node] = True
            for child in children[node]:
                stack.append(child)
        else:
            # Post-processing step of DFS
            node = stack.pop()
            
            # Base case: a leaf
            if len(children[node]) == 0:
                maxinsubtree[node] = 1
                maxdistsubtr[node] = 0
            
            # Recursive case: internal node of tree
            else:
                # Merge first with first child, then with rest of children
                # furthest represents minimum distance that future subtrees need to consider, given 
                # the nodes that you've already taken.
                fchild = children[node][0]
                marked = maxinsubtree[fchild]
                furthest = maxdistsubtr[fchild] + 1
                if furthest == d:
                    marked += 1
                    furthest = 0
                    
                # Merge other children one by one
                # how the fuck do we prove this algorithm is correct?
                # it is greedy because it doesn't brute-force this calculation
                # apparently, the one fewer node corresponds to deleting the root.
                for i in range(1, len(children[node])):
                    child = children[node][i]
                    if furthest + maxdistsubtr[child] + 1 >= d:
                        marked += maxinsubtree[child]
                        furthest = min(furthest, maxdistsubtr[child] + 1)
                    else:
                        marked += maxinsubtree[child] - 1
                        furthest = max(furthest, maxdistsubtr[child] + 1)
                
                # prove
                maxinsubtree[node] = marked
                maxdistsubtr[node] = furthest


    return maxinsubtree[0]
    
print(catinatree())