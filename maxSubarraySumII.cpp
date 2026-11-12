#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {

    int n, a, b;
    cin >> n >> a >> b;

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        long long x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }

    long long max_sum = -4e18; 
    deque<int> dq;

    for (int i = a; i <= n; ++i) {
        
        while (!dq.empty() && dq.front() < i - b) {
            dq.pop_front();
        }

      
        int new_idx = i - a;
        while (!dq.empty() && pref[dq.back()] >= pref[new_idx]) {
            dq.pop_back();
        }
        dq.push_back(new_idx);

        
        max_sum = max(max_sum, pref[i] - pref[dq.front()]);
    }

    cout << max_sum << "\n";

    return 0;
}