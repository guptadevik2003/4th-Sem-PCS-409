#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> adjMatrix, int src, int vertices) {
  vector<bool> visited(vertices, false);
  vector<int> color(vertices, -1);
  queue<int> q;

  visited[src] = true;
  color[src] = 0;
  q.push(src);

  while(!q.empty()) {
    int current = q.front();
    q.pop();
    
    for(int neigh=0; neigh<vertices; neigh++) {
      if(adjMatrix[current][neigh]) {
        if(!visited[neigh]) {
          visited[neigh] = true;
          color[neigh] = !color[current];
          q.push(neigh);
        }
        else if(neigh != current && color[neigh] == color[current]) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  int vertices, temp, src;
  cout<<"Enter number of vertices: ";
  cin>>vertices;

  vector<vector<int>> adjMatrix(vertices, vector<int>(vertices, 0));

  cout<<"Enter edges:"<<endl;
  for(int i=0; i<vertices; i++){
    for(int j=0; j<vertices; j++){
      cin>>temp;
      adjMatrix[i][j] = temp;
    }
  }

  cout<<"Enter source vertex: ";
  cin>>src;

  if(isBipartite(adjMatrix, src, vertices)) {
    cout<<"Yes Bipartite"<<endl;
  } else {
    cout<<"Not Bipartite"<<endl;
  }
}

// DONE
