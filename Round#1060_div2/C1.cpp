//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> a(n), _(n);
		for (auto& x : a) cin >> x;
		for (auto& x : _) cin >> x;

		map<int, int> mp{};
		for (auto& x : a) {
			int t{x};
			for (int f{2}; f * f <= x; ++f) {
				if (t % f == 0) {
					if (++mp[f] > 1) return cout << "0\n", []{}();
					while (t % f == 0) t /= f;
				}
			}
			if (t > 1) {
				if (++mp[t] > 1) return cout << "0\n", []{}();
			}
		}

		for (auto& x : a) {
			x += 1;
			int t{x};
			for (int f{2}; f * f <= x; ++f) {
				if (t % f == 0) {
					if (mp[f] + 1 > 1) return cout << "1\n", []{}();
					while (t % f == 0) t /= f;
				}
			}
			if (t > 1) {
				if (mp[t] + 1 > 1) return cout << "1\n", []{}();
			}
		}

		cout << "2\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
