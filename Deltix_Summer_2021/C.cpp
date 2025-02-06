#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long ans{0};
	for (int i{0}; i + 1 < n; i += 2) {
		long long cnt{v[i] - v[i + 1]}, l{cnt};
		ans += min(v[i], v[i + 1]);
		for (int j{i + 3}; j < n && cnt >= 0; j += 2) {
			if (v[j] >= v[j - 1] + cnt - l) ans += min(l, v[j] - (v[j - 1] + cnt - l)) + 1;
			cnt += v[j - 1] - v[j];
			l = min(l, cnt);
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
