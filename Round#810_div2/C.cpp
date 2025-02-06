//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	long long n, m, k;
	cin >> n >> m >> k;
	vector<long long> v(k);
	for (auto& x : v) cin >> x;

	long long cnt{0};
	bool f{false};
	for (auto& x : v)
		if (x / m >= 2) {
			cnt += x / m;
			if (x / m >= 3) f = true;
		}
	if (cnt >= n && ((cnt - n) % 2 == 0 || f)) return cout << "Yes\n", []{}();

	cnt = 0, f = false;
	for (auto& x : v)
		if (x / n >= 2) {
			cnt += x / n;
			if (x / n >= 3) f = true;
		}
	if (cnt >= m && ((cnt - m) % 2 == 0 || f)) return cout << "Yes\n", []{}();

	cout << "No\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
