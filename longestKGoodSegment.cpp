#include <iostream>
#include <vector>

using namespace std;

int freq[1000005];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int l = 0;
    int distinct = 0;
    int max_len = 0;
    int best_l = 1, best_r = 1;

    for (int r = 0; r < n; ++r) {
        if (freq[a[r]] == 0) {
            distinct++;
        }
        freq[a[r]]++;

        
        while (distinct > k) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) {
                distinct--;
            }
            l++;
        }

       
        if (r - l + 1 > max_len) {
            max_len = r - l + 1;
            best_l = l + 1;
            best_r = r + 1;
        }
    }

    cout << best_l << " " << best_r << "\n";

    return 0;
}