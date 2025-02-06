//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> t{};
		for (auto& x : v) {
			if (x % 2 == 0) t.push_back(x);
			if (t.size() == 2) return cout << t[0] << ' ' << t[1] << '\n', []{}();
		}

		for (int i{0}; i + 1 < n; ++i) {
			if (v[i + 1] % v[i] % 2 == 0) return cout << v[i] << ' ' << v[i + 1] << '\n', []{}();
		}

		for (int i{0}; i < n; ++i)
			for (int j{i + 1}; j < n; ++j) {
				if (v[j] % v[i] % 2 == 0) return cout << v[i] << ' ' << v[j] << '\n', []{}();
			}

		cout << "-1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
