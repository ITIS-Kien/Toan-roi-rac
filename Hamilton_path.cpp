// Cho đồ thị có hướng, có trọng số có thể  âm hoặc không âm G= được biểu diễn dưới dạng danh sách cạnh. 
// Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int maxn = 100001;

int V, E, visited[maxn];
vector<int> adj[maxn];  // adj là danh sách kề
vector<int> path;       // Lưu đường đi hiện tại
void input() {
    for (int i = 1; i <= V; i++) adj[i].clear(); 
    cin >> V >> E;  
    for (int i = 0; i < E; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);  
        adj[y].push_back(x); 
    }
    memset(visited, 0, sizeof(visited));  
    path.clear();  
}
int hamilton(int u) {
    path.push_back(u);  // Đưa đỉnh u vào đường đi hiện tại
    if (path.size() == V) {  // Nếu đường đi đã bao gồm tất cả các đỉnh
        return 1;  // Tìm thấy đường đi Hamilton
    }

    visited[u] = 1;  // Đánh dấu đỉnh u đã được duyệt
    // Duyệt các đỉnh kề với u
    for (int v : adj[u]) {
        if (!visited[v]) {  // Nếu đỉnh v chưa được duyệt
            if (hamilton(v)) {  // Gọi đệ quy để tiếp tục tìm đường đi từ v
                return 1;  // Nếu tìm thấy đường đi, trả về true
            }
        }
    }

    // Quay lui
    visited[u] = 0;  // Bỏ đánh dấu đỉnh u để thử các đường đi khác
    path.pop_back();  // Loại đỉnh u khỏi đường đi hiện tại
    return 0;  // Không tìm thấy đường đi
}

int main() {
    fast;
    int t; cin >> t;
    while (t--) {
        input();  // Nhập dữ liệu cho mỗi test case
        int res = 0;
        // Thử bắt đầu từ tất cả các đỉnh
        for (int i = 1; i <= V; i++) {
            if (hamilton(i)) {
                res = 1;
                break;  // Nếu tìm thấy đường đi Hamilton, thoát khỏi vòng lặp
            }
        }
        cout << res << "\n";  // In ra kết quả
    }
}