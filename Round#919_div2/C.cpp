//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pn{[] {
	int maxval{200000};
	vector<int> v{};
	vector<bool> ck(maxval + 1, true);
	for (int i{2}; i <= maxval; ++i) {
		if (!ck[i]) continue;
		for (int j{i}; j <= maxval; j += i) ck[j] = false;
		v.push_back(i);
	}
	return v;
}()};

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{1};
	for (int d{1}; d < n; ++d) {
		if (n % d) continue;
		bool f{false};
		for (auto& m : pn) {
			if (m > n) break;
			for (int i{d}; i < n; i += d)
				for (int j{0}; j < d; ++j) {
					if (v[j] % m != v[i + j] % m) goto CONT;
				}
			f = true;
			break;
CONT:
			;
		}
		ans += f;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
