#include <iostream>
#include <algorithm>
using namespace std;

bool check(int mid, int location[], int N, int K) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int chazhi = location[i] - location[i - 1];
        count += (chazhi - 1) / mid;
    }
    return count <= K;
}

int main() {
    int L, N, K;
    cin >> L >> N >> K; // L为公路长度N原有路标K可增设的路标
    int location[1000002] = {0}; // 增加数组大小以防止越界
    for (int i = 1; i <= N; i++) {
        cin >> location[i];
    }
    location[0] = 0;
    location[N + 1] = L;
    sort(location + 1, location + 1 + N);

    int left = 1, right = L, min = L;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, location, N + 1, K)) {
            min = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << min << endl;
    return 0;
}
