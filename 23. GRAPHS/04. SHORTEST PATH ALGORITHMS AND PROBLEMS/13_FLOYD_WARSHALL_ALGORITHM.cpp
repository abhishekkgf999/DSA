/*
====================================================
FLOYD WARSHALL ALGORITHM
====================================================

💡 PROBLEM SUMMARY
----------------------------------------------------
Floyd Warshall Algorithm is used for:

✔ Multi-source shortest path

Meaning:
✔ Find shortest distance between
  EVERY pair of nodes

----------------------------------------------------
Unlike Dijkstra/Bellman Ford:

✔ Those solve:
      source → all nodes

✔ Floyd Warshall solves:
      every node → every node

====================================================
CORE IDEA: TRY EVERY NODE AS INTERMEDIATE ⭐
----------------------------------------------------
Main intuition:

Suppose we want shortest path:
    i → j

Question:
----------------------------------------------------
Can travelling through some node k
make the path shorter?

So check:

    i → k → j

----------------------------------------------------
If:

    dist[i][k] + dist[k][j]
        <
    dist[i][j]

Then:
✔ update shortest distance

====================================================
DYNAMIC PROGRAMMING INTERPRETATION
----------------------------------------------------
At every iteration:

✔ We allow one more node
  to act as intermediate node

----------------------------------------------------
Initially:
✔ direct edges only

Then:
✔ allow node 0
✔ allow node 1
✔ allow node 2
...

Eventually:
✔ all nodes become allowed
  intermediate nodes

====================================================
WHY THREE LOOPS ?
----------------------------------------------------
Outer loop:
    k

✔ Intermediate node

----------------------------------------------------
Middle loop:
    i

✔ Source node

----------------------------------------------------
Inner loop:
    j

✔ Destination node

----------------------------------------------------
Meaning:
✔ Try travelling from i to j via k

====================================================
WHY TIME COMPLEXITY IS O(N³)
----------------------------------------------------
Because:

✔ For every k
✔ traverse every i
✔ traverse every j

So:
    N × N × N

➡ O(N³)

====================================================
NEGATIVE CYCLE DETECTION ⭐
----------------------------------------------------
Normally:

✔ distance from node to itself = 0

So:
    dist[i][i] = 0

----------------------------------------------------
But after algorithm:

If:
    dist[i][i] < 0

Then:
✔ node can reach itself with
  negative cost

Meaning:
✔ negative cycle exists

====================================================
IMPORTANT PREPROCESSING
----------------------------------------------------
Input contains:
    -1

Meaning:
✔ no direct edge exists

So convert:
    -1 → INF

Otherwise:
✔ minimum calculations become incorrect

----------------------------------------------------
Also:
✔ distance from node to itself = 0

====================================================
APPROACH
----------------------------------------------------

STEP 1: Prepare matrix
----------------------------------------------------
✔ Convert -1 → INF

✔ Set diagonal:
      matrix[i][i] = 0

----------------------------------------------------

STEP 2: Run Floyd Warshall
----------------------------------------------------
For every intermediate node k:

✔ Try improving:
      i → j
  using:
      i → k → j

----------------------------------------------------

STEP 3: Detect negative cycle
----------------------------------------------------
If:
    matrix[i][i] < 0

Then:
✔ negative cycle exists

----------------------------------------------------

STEP 4: Restore unreachable nodes
----------------------------------------------------
Convert:
    INF → -1

====================================================
IMPORTANT CONDITIONS
----------------------------------------------------
✔ Works for directed graphs
✔ Supports negative weights
✔ Detects negative cycles
✔ Cannot handle infinite negative cycles
✔ Uses adjacency matrix representation

====================================================
TIME & SPACE COMPLEXITY
----------------------------------------------------
TIME:
➡ O(N³)

SPACE:
➡ O(N²)

====================================================
KEY TAKEAWAY
----------------------------------------------------
Whenever problem asks:
✔ shortest distance between
  every pair of nodes

Think:
✔ Floyd Warshall

Core intuition:
✔ Try every node as intermediate

====================================================
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

        void shortest_distance(vector<vector<int>> &matrix){

            int n = matrix.size();

            for(int i = 0; i < n; i++){

                for(int j = 0; j < n; j++){

                    if(matrix[i][j] == -1){
                        matrix[i][j] = 1e9;
                    }

                    if(i == j){
                        matrix[i][j] = 0;
                    }
                }
            }

            for(int k = 0; k < n; k++){

                for(int i = 0; i < n; i++){

                    for(int j = 0; j < n; j++){

                        matrix[i][j] = min(
                            matrix[i][j],
                            matrix[i][k] + matrix[k][j]
                        );
                    }
                }
            }

            for(int i = 0; i < n; i++){

                if(matrix[i][i] < 0){
                    cout << "There is negative cycle in graph";
                }
            }

            for(int i = 0; i < n; i++){

                for(int j = 0; j < n; j++){

                    if(matrix[i][j] == 1e9){
                        matrix[i][j] = -1;
                    }
                }
            }
        }
};

int main(){
    
    return 0;
}