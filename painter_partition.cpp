
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isvalid(vector<int>& arr, int n, int k, int mid) {
    int time = 0;
    int painters = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            return false;
        }

        if (time + arr[i] <= mid) {
            time += arr[i];
        }
        else {
            painters++;
            time = arr[i];
        }

        if (painters > k) {
            return false;
        }
    }

    return true;
}

int painterpartition(vector<int>& arr, int n, int k) {
    if (n == 0 || k <= 0 || k > n) {
        return -1;
    }

    int str = 0;
    int sum = 0;
    int ans = -1;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        str = max(str, arr[i]);
    }

    int end = sum;

    while (str <= end) {
        int mid = str + (end - str) / 2;

        if (isvalid(arr, n, k, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            str = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    int n = arr.size();
    int k = 3;

    cout << "Minimum maximum workload: "
         << painterpartition(arr, n, k);

    return 0;
}
