//  Cho đồ thị có hướng, có trọng số có thể  âm hoặc không âm G= được biểu diễn dưới dạng danh sách cạnh.
//  Hãy viết chương trình tìm đường đi đến tất cả các cạnh còn lại trên đồ thị.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const int maxn = 100001;
// Khai báo các biến toàn cục
int V = 0, E, s, degree[maxn];  // V là số đỉnh, E là số cạnh, s là đỉnh bắt đầu
set <int> adj[maxn];  // adj là danh sách kề, sử dụng set để lưu các cạnh

void input(){ // Hàm nhập dữ liệu đầu vào
    for (int i = 1; i <= V; i++) adj[i].clear(); // Xóa danh sách kề của các đỉnh từ lần chạy trước (nếu có)
    // Nhập số đỉnh, số cạnh và đỉnh bắt đầu
    cin >> V >> E >> s;
    // Duyệt qua các cạnh để xây dựng danh sách kề và tăng bậc của các đỉnh
    for (int i = 0; i < E; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].insert(y);  // Thêm đỉnh y vào danh sách kề của đỉnh x
        adj[y].insert(x);  // Thêm đỉnh x vào danh sách kề của đỉnh y (đồ thị vô hướng)
    }
}
void euler(int u){ // Hàm tìm chu trình Euler bắt đầu từ đỉnh u
    stack <int> st;  // Sử dụng ngăn xếp để duyệt các đỉnh
    vector <int> EC;  // Lưu trữ chu trình Euler
    st.push(u);  // Đẩy đỉnh bắt đầu vào ngăn xếp
    while (!st.empty()) // Tiếp tục duyệt cho đến khi ngăn xếp rỗng
    {
        int x = st.top();  // Lấy đỉnh trên cùng của ngăn xếp
        if (adj[x].size()) { // Nếu đỉnh x vẫn còn cạnh chưa duyệt
            int y = *adj[x].begin();  // Lấy đỉnh đầu tiên kề với x
            st.push(y);  // Đẩy đỉnh y vào ngăn xếp
            adj[x].erase(y);  // Xóa cạnh giữa x và y (vì đã duyệt)
            adj[y].erase(x);  // Xóa cạnh giữa y và x (vì đồ thị vô hướng)
        }
        else { // Nếu không còn cạnh nào kề với x
            st.pop();  // Loại bỏ đỉnh x khỏi ngăn xếp
            EC.push_back(x);  // Thêm đỉnh x vào chu trình Euler
        }
    }
    reverse(begin(EC), end(EC)); // Đảo ngược chu trình Euler để có thứ tự chính xác
    for (int it : EC) cout << it << " ";    // In chu trình Euler
}
int main() {
    fast;  
    int t; cin >> t; 
    while (t--) 
    {
        input();  // Nhập dữ liệu cho mỗi test case
        euler(s);  // Tìm chu trình Euler bắt đầu từ đỉnh s
        cout << "\n";  
    }
}
