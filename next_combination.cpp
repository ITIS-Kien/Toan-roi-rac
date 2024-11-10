#include <iostream>
#include <vector>
using namespace std;

// Hàm để tìm tổ hợp kế tiếp
bool next_combination(vector<int>& comb, int n) {
    int k = comb.size();  // k là số phần tử trong tổ hợp
    // Duyệt ngược từ phần tử cuối để tìm vị trí có thể tăng
    for (int i = k - 1; i >= 0; --i) {
        // Kiểm tra nếu phần tử hiện tại có thể tăng mà vẫn hợp lệ
        if (comb[i] < n - (k - 1) + i) {
            ++comb[i];  // Tăng phần tử tại vị trí i
            // Thiết lập lại các phần tử sau phần tử vừa tăng
            for (int j = i + 1; j < k; ++j) {
                comb[j] = comb[j - 1] + 1;  // Đảm bảo các phần tử sau luôn tăng dần
            }
            return true;  // Có tổ hợp kế tiếp
        }
    }
    return false;  // Không có tổ hợp kế tiếp
}

int main() {
    int k, n;
    cin >> k >> n;  // Nhập số phần tử trong tổ hợp và giá trị tối đa của n
    vector<int> comb(k);
    // Nhập tổ hợp ban đầu
    for (int i = 0; i < k; ++i) {
        cin >> comb[i];
    }
    // Hiển thị 5 tổ hợp kế tiếp
    for (int i = 0; i < 5; ++i) {
        if (next_combination(comb, n)) {  // Tìm tổ hợp kế tiếp nếu có
            // In tổ hợp hiện tại
            for (int j = 0; j < k; ++j) {
                cout << comb[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
