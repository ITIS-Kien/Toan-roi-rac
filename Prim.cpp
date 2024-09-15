// ĐỀ BÀI : 
// Cho đồ thị vô hướng có trọng số G=. 
// Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của đồ thị bằng thuật toán PRIM.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)  // Tăng tốc độ nhập/xuất
const int maxn = 1000007;  // Giá trị tối đa cho số đỉnh và cạnh

struct edge { // Cấu trúc dữ liệu cho cạnh của đồ thị
    int u, v, w;  // u và v là hai đỉnh, w là trọng số của cạnh
};
int n = 0, m, used[maxn], par[maxn], d[maxn];  // n: số đỉnh, m: số cạnh; used[]: đánh dấu đỉnh đã thuộc MST, par[]: lưu đỉnh cha, d[]: lưu trọng số ngắn nhất
vector <pair <int, int>> adj[maxn];  // adj[] là danh sách kề, mỗi phần tử là cặp {đỉnh kề, trọng số}

void input() { // Hàm nhập dữ liệu đồ thị
    for (int i = 1; i <= n; i++) adj[i].clear(); // Xóa danh sách kề trước khi nhập dữ liệu mới
    cin >> n >> m;  // Nhập số đỉnh và số cạnh
    for (int i = 0; i < m; i++) { // Nhập các cạnh của đồ thị
        int x, y, z; cin >> x >> y >> z;  // Nhập cạnh giữa hai đỉnh x và y với trọng số z
        adj[x].push_back({y, z});  // Thêm đỉnh y và trọng số z vào danh sách kề của đỉnh x
        adj[y].push_back({x, z});  // Thêm đỉnh x và trọng số z vào danh sách kề của đỉnh y (đồ thị vô hướng)
    }
    memset(used, 0, sizeof(used));  // Đặt tất cả các đỉnh chưa được sử dụng (chưa thuộc MST)
    for (int i = 1; i <= n; i++) d[i] = INT_MAX;  // Khởi tạo khoảng cách ngắn nhất đến các đỉnh là vô cùng
}

void prim(int u) { // Hàm Prim để tìm cây khung nhỏ nhất (MST)
    // Hàng đợi ưu tiên để chọn cạnh có trọng số nhỏ nhất (dùng để chọn cạnh tiếp theo vào MST)
    priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair <int, int>>> Q;
    vector <edge> mst;  // Danh sách các cạnh của cây khung nhỏ nhất
    int res = 0;  // Tổng trọng số của cây khung nhỏ nhất
    Q.push({0, u});  // Đưa đỉnh bắt đầu u vào hàng đợi với trọng số 0
    while (!Q.empty()) { // Thực hiện giải thuật Prim
        pair <int, int> top = Q.top(); Q.pop();  // Lấy cạnh có trọng số nhỏ nhất ra khỏi hàng đợi
        int x = top.second, z = top.first;  // x là đỉnh, z là trọng số cạnh
        if (used[x]) continue;  // Nếu đỉnh x đã thuộc MST, bỏ qua
        res += z;  // Cộng trọng số của cạnh vào tổng trọng số của cây khung nhỏ nhất
        used[x] = 1;  // Đánh dấu đỉnh x đã thuộc MST
        if (u != x) mst.push_back({x, par[x], z});  // Nếu x không phải là đỉnh bắt đầu, thêm cạnh vào cây khung nhỏ nhất
        for (auto it : adj[x]) { // Duyệt các đỉnh kề với x
            int y = it.first, w = it.second;  // y là đỉnh kề, w là trọng số cạnh từ x đến y
            if (!used[y] && w < d[y]) {  // Nếu đỉnh y chưa thuộc MST và trọng số cạnh từ x đến y nhỏ hơn trọng số hiện tại của y
                Q.push({w, y});  // Đưa đỉnh y vào hàng đợi với trọng số w
                d[y] = w;  // Cập nhật trọng số ngắn nhất của y
                par[y] = x;  // Cập nhật đỉnh cha của y là x
            }
        }
    }
    cout << res << "\n";  // In ra tổng trọng số của cây khung nhỏ nhất
}

int main() {
    fast; 
    int t; cin >> t;
    while (t--) {
        input();  
        prim(1); 
    }
}
