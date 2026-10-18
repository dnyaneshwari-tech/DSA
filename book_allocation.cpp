
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isvalid(vector<int> &arr, int m, int n, int mid) {
    int studentcount = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            return false;
        }

        if (pages + arr[i] <= mid) {
            pages += arr[i];
        } else {
            studentcount++;
            pages = arr[i];
        }
    }

    return studentcount <= m;
}

int bookallocation(vector<int> &arr, int n, int m) {
    if (m > n) {
        return -1;
    }

    int str = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        str = max(str, arr[i]);
    }

    int end = sum;
    int ans = -1;

    while (str <= end) {
        int mid = str + (end - str) / 2;

        if (isvalid(arr, m, n, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            str = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {10, 20, 30, 40};

    int n = arr.size();
    int m = 2;

    cout << "The minimum number of pages allocated to a student is "
         << bookallocation(arr, n, m) << endl;

    return 0;
}
