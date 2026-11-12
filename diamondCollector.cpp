#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
   
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    
    sort(a.begin(), a.end());

    
    vector<int> canTake(n);
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && a[r] - a[l] <= k) {
            r++;
        }
        canTake[l] = r - l;
    }

    
    vector<int> maxAfter(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        maxAfter[i] = max(maxAfter[i + 1], canTake[i]);
    }

   
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, canTake[i] + maxAfter[i + canTake[i]]);
    }

    cout << ans << "\n";

    return 0;
}