/* ĐỀ BÀI : Cho đồ thị vô hướng có trọng số G=<V, E, W>. 
Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của đồ thị bằng thuật toán Kruskal.*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

struct edge { // Cấu trúc dữ liệu cho cạnh của đồ thị
    int u, v, w;  // u và v là hai đỉnh, w là trọng số của cạnh
    edge (int x, int y, int z) {  // Constructor để khởi tạo cạnh
        u = x;
        v = y;
        w = z;
    }
};

int n, m, par[1000007], sz[1000007];  // n là số đỉnh, m là số cạnh; par[] và sz[] dùng cho thuật toán Union-Find
vector <edge> E;  // Danh sách các cạnh

// Hàm nhập dữ liệu
void input(){
    E.clear();  // Xóa danh sách cạnh trước mỗi lần chạy
    cin >> n >> m;  // Nhập số đỉnh và số cạnh
    for (int i = 0; i < m; i++) {
        int x, y, z; 
        cin >> x >> y >> z;  // Nhập cạnh có hai đỉnh x, y và trọng số z
        edge e(x, y, z);  // Tạo một cạnh mới
        E.push_back(e);  // Thêm cạnh vào danh sách
    }
}

// Khởi tạo các tập hợp ban đầu cho thuật toán Union-Find
void makeset(){
    for (int i = 1; i <= n; i++) {
        par[i] = i;  // Ban đầu mỗi đỉnh là một tập hợp riêng biệt
        sz[i] = 1;   // Kích thước mỗi tập hợp là 1
    }
}

// Tìm đại diện của tập chứa đỉnh i
int find(int i){
    if(i == par[i]) return i;  // Nếu i là đại diện của chính nó, trả về i
    return par[i] = find(par[i]);  // Tìm đại diện của i và áp dụng nén đường đi
}

// Hợp nhất hai tập hợp chứa a và b
int Union (int a, int b){
    a = find(a);  // Tìm đại diện của tập hợp chứa a
    b = find(b);  // Tìm đại diện của tập hợp chứa b
    if(a == b) return 0;  // Nếu hai đỉnh đã thuộc cùng một tập hợp, không hợp nhất
    if(sz[a] < sz[b]) swap(a, b);  // Đảm bảo rằng tập hợp chứa a có kích thước lớn hơn
    par[b] = a;  // Đặt đại diện của tập b là a
    sz[a] += sz[b];  // Cập nhật kích thước tập hợp mới
    return 1;  // Hợp nhất thành công
}

// Hàm so sánh để sắp xếp các cạnh theo trọng số
bool cmp(edge a, edge b) {
    return a.w < b.w;  // Trả về true nếu cạnh a có trọng số nhỏ hơn cạnh b
}

// Giải thuật Kruskal để tìm cây khung nhỏ nhất (MST)
void solve(){
    vector <edge> mst;  // Danh sách các cạnh trong cây khung nhỏ nhất (MST)
    int d = 0;  // Tổng trọng số của cây khung nhỏ nhất
    sort(E.begin(), E.end(), cmp);  // Sắp xếp các cạnh theo trọng số tăng dần
    for (int i = 0; i < m; i++) {
        if(mst.size() == n - 1) break;  // Dừng khi đã tìm đủ n-1 cạnh cho cây khung
        edge e = E[i];  // Lấy cạnh tiếp theo trong danh sách
        if(Union(e.u, e.v)) {  // Nếu hai đỉnh của cạnh này thuộc hai tập khác nhau
            d += e.w;  // Thêm trọng số của cạnh vào tổng trọng số của MST
            mst.push_back(e);  // Thêm cạnh vào cây khung nhỏ nhất
        }
    }
    cout << d << "\n";  // In ra tổng trọng số của cây khung nhỏ nhất
}

int main() {
    fast;  // Tăng tốc độ đọc/ghi dữ liệu
    int t; cin >> t;  // Nhập số lượng test case
    while (t--) {  // Xử lý từng test case
        input();  // Nhập dữ liệu cho test case
        makeset();  // Khởi tạo các tập hợp ban đầu cho thuật toán Union-Find
        solve();  // Tìm cây khung nhỏ nhất
    }
}
