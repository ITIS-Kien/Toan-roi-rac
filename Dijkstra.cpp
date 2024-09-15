// ĐỀ BÀI:
// Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số không âm. 
// Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)  // Tăng tốc độ nhập/xuất
const int maxn = 100001;

int V = 0, E, s;  // V là số đỉnh, E là số cạnh, s là đỉnh bắt đầu
vector <pair<int, int>> adj[maxn];  // adj[] là danh sách kề, mỗi phần tử lưu một cặp {đỉnh kề, trọng số}

void input() {
    // Xóa danh sách kề của các đỉnh trước khi nhập dữ liệu mới
    for (int i = 1; i <= V; i++) adj[i].clear();
    cin >> V >> E >> s;  // Nhập số đỉnh, số cạnh và đỉnh bắt đầu
    for (int i = 0; i < E; i++) { // Nhập các cạnh của đồ thị
        int x, y, z; cin >> x >> y >> z;  // Nhập hai đỉnh x, y và trọng số z của cạnh
        adj[x].push_back({y, z});  // Thêm đỉnh y và trọng số z vào danh sách kề của đỉnh x
        adj[y].push_back({x, z});  // Thêm đỉnh x và trọng số z vào danh sách kề của đỉnh y (đồ thị vô hướng)
    }
}

void dijkstra(int s) {
    vector <ll> d(V + 1, INFINITY);  // d[] lưu khoảng cách ngắn nhất từ đỉnh s đến các đỉnh khác, khởi tạo tất cả là vô cực
    d[s] = 0;  // Khoảng cách từ s đến chính nó bằng 0
    // Hàng đợi ưu tiên để chọn đỉnh có khoảng cách ngắn nhất (độ ưu tiên nhỏ nhất)
    priority_queue <pair<int, int>, vector <pair<int ,int>>, greater <pair<int, int>>> Q;
    Q.push({0, s});  // Đưa đỉnh s vào hàng đợi với khoảng cách 0
    while (!Q.empty()) { // Dijkstra's algorithm: tìm đường đi ngắn nhất từ s đến các đỉnh khác
        auto top = Q.top(); Q.pop();  // Lấy đỉnh u có khoảng cách nhỏ nhất từ hàng đợi
        int u = top.second;  // Lấy đỉnh hiện tại
        int kc = top.first;  // Lấy khoảng cách hiện tại từ s đến u
        if (kc > d[u]) continue; // Nếu khoảng cách này lớn hơn khoảng cách đã lưu, bỏ qua đỉnh này
        for (auto it : adj[u]) { // Duyệt các đỉnh kề với u
            int v = it.first;  // Đỉnh kề v
            int w = it.second;  // Trọng số cạnh từ u đến v
            if (d[v] > d[u] + w) { // Nếu khoảng cách mới đến v ngắn hơn khoảng cách đã biết
                d[v] = d[u] + w;  // Cập nhật khoảng cách mới
                Q.push({d[v], v});  // Đưa đỉnh v vào hàng đợi với khoảng cách mới
            }
        }
    }
    for (int i = 1; i <= V; i++)  cout << d[i] << " ";  // In khoảng cách từ s đến đỉnh i
}

int main() {
    fast; 
    int t; cin >> t; 
    while (t--) {
        input();  
        dijkstra(s);  
        cout << "\n";  
    }
}
