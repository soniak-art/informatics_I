#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
   
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> intervals(m);
    for (int i = 0; i < m; ++i) {
        cin >> intervals[i].first >> intervals[i].second;
    }

   
    sort(intervals.begin(), intervals.end());

    auto can_place = [&](long long d) {
        int cows_placed = 1;
        long long last_pos = intervals[0].first;

        for (int i = 0; i < m; ++i) {
            long long a = intervals[i].first;
            long long b = intervals[i].second;

           
            while (max(a, last_pos + d) <= b) {
                last_pos = max(a, last_pos + d);
                cows_placed++;
                if (cows_placed == n) return true;
            }
        }
        return false;
    };

    long long low = 1;
    long long high = 1e18;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (can_place(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}