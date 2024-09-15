// ĐỀ BÀI : 
// Cho đồ thị có hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. 
// Hãy kiểm tra xem đồ thị có liên thông mạnh hay không?

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
const int maxn = 1000007; 
int V = 0, E, used[maxn];  
vector<int> adj[maxn], r_adj[maxn]; 
stack<int> topo; 
void input() {
    for (int i = 1; i <= V; i++) { 
        adj[i].clear();
        r_adj[i].clear();
    }
    cin >> V >> E; 
    for (int i = 0; i < E; i++) { 
        int x, y; cin >> x >> y; 
        adj[x].push_back(y); 
        r_adj[y].push_back(x); 
    }
}

void dfs(int i){ 
    used[i] = 1;  
    for (int it : adj[i]) if (!used[it])  dfs(it); 
    topo.push(i); 
}


void r_dfs(int i){ 
    used[i] = 1;  
    for (int it : r_adj[i]) if (!used[it]) r_dfs(it); 
}

void kosaraju(){ 
    memset(used, 0, sizeof(used));  
    for (int i = 1; i <= V; i++) if (!used[i]) dfs(i);  
    memset(used, 0, sizeof(used));  
    int cnt = 0;  
    while (!topo.empty()) {
        int u = topo.top(); topo.pop();  
        if (!used[u]) {  
            r_dfs(u); 
            cnt++;  
        }
    }
    if (cnt == 1) cout << "YES\n";  
    else cout << "NO\n";  
}

int main(){
    fast; 
    int t; cin >> t;  
    while (t--) {
        input();  
        kosaraju(); 
    }
}
