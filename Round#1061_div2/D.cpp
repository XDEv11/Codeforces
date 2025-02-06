//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	int ask(int i, int x) {
		cout << "? " << i << ' ' << x << endl;
		return cin >> x, x;
	}
	void solve() {
		int n;
		cin >> n;

		vector<int> a(n), v(n - 1);
		iota(a.begin(), a.end(), 1), iota(v.begin(), v.end(), 1);
		for (int k{0}; !v.empty(); ++k) {
			vector<int> c(v.size());
			for (int i{0}; i < v.size(); ++i) c[i] = ask(v[i], (1 << k));

			vector<int> b{}, w{};
			int t{count_if(a.begin(), a.end(), [&](int x) { return x & (1 << k); })};
			if (count(c.begin(), c.end(), 1) == t) {
				for (auto& x : a) {
					if (!(x & (1 << k))) b.push_back(x);
				}
				for (int i{0}; i < v.size(); ++i) {
					if (!c[i]) w.push_back(v[i]);
				}
			} else {
				for (auto& x : a) {
					if (x & (1 << k)) b.push_back(x);
				}
				for (int i{0}; i < v.size(); ++i) {
					if (c[i]) w.push_back(v[i]);
				}
			}
			a = b, v = w;
		}

		cout << "! " << a[0] << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
