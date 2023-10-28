class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void topoSort(int node,stack<int> &s, unordered_map<int,bool> &visited, vector<int> adj[]){
	    visited[node]=true;
	    
	    for(auto neighbour:adj[node]){
	        if(!visited[neighbour]){
	            topoSort(neighbour,s,visited,adj);
	        }
	    }
	            s.push(node);
	}
	
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int j : adj[i]) {
            indegree[j]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (int neighbour : adj[front]) {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    return ans;
}

};
