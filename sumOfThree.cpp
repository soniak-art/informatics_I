#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; ++i) {
        int left = i + 1;
        int right = n - 1;
        long long target = x - a[i].first;

        while (left < right) {
            long long current_sum = a[left].first + a[right].first;
            if (current_sum == target) {
                cout << a[i].second << " " << a[left].second << " " << a[right].second << "\n";
                return 0;
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}