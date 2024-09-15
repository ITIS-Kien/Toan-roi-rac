// ĐỀ BÀI:
// Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số âm. 
// Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)  // Tăng tốc độ nhập/xuất
const int maxn = 100001;
const ll INF = 1e18; 
int V, E, s;  // V là số đỉnh, E là số cạnh, s là đỉnh bắt đầu
struct Edge {
    int u, v; // u là đỉnh bắt đầu, v là đỉnh kết thúc
    int weight; // trọng số của cạnh
};
vector<Edge> edges;  // Danh sách cạnh
void input() {
    edges.clear();  // Xóa danh sách cạnh trước khi nhập dữ liệu mới
    cin >> V >> E >> s;  // Nhập số đỉnh, số cạnh và đỉnh bắt đầu
    for (int i = 0; i < E; i++) {
        int x, y, z; cin >> x >> y >> z;  // Nhập hai đỉnh x, y và trọng số z của cạnh
        edges.push_back({x, y, z});  // Thêm cạnh vào danh sách
    }
}

void bellmanFord(int s) {
    vector <ll> d(V + 1, INF);  // d[] lưu khoảng cách ngắn nhất từ đỉnh s đến các đỉnh khác, khởi tạo tất cả là vô cực
    d[s] = 0;  // Khoảng cách từ s đến chính nó bằng 0
    // Bước 1: Cập nhật khoảng cách V-1 lần
    for (int i = 1; i <= V - 1; i++) {
        for (Edge edge : edges) { // Duyệt qua từng cạnh
            int u = edge.u;
            int v = edge.v;
            int w = edge.weight;
            if (d[u] != INF && d[u] + w < d[v]) { // Nếu tìm thấy đường đi ngắn hơn
                d[v] = d[u] + w;  // Cập nhật khoảng cách ngắn nhất
            }
        }
    }
    // Bước 2: Kiểm tra chu trình âm
    for (Edge edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int w = edge.weight;
        if (d[u] != INF && d[u] + w < d[v]) {  
            // Nếu vẫn có thể cập nhật khoảng cách sau V-1 lần lặp
            cout << "-1";
            return;
        }
    }
    for (int i = 1; i <= V; i++) { //In kết quả
        if (d[i] == INF) cout << "INFI ";  // Nếu đỉnh i không thể tới được
        else cout << d[i] << " ";  // In khoảng cách ngắn nhất đến đỉnh i
    }
}

int main() {
    fast; 
    int t; cin >> t; 
    while (t--) {
        input();  
        bellmanFord(s);  
        cout << "\n";  
    }
}
