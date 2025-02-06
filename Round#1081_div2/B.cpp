//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		vector<int> a{};
		for (int i{0}; i < n; ++i) {
			if (v[i] != '1') continue;
			a.push_back(i);
		}

		if (a.size() % 2) {
			if ((n - a.size()) % 2) {
				a.clear();
				for (int i{0}; i < n; ++i) {
					if (v[i] != '0') continue;
					a.push_back(i);
				}
			} else return void(cout << "-1\n");
		}

		cout << a.size() << '\n';
		for (auto& x : a) cout << (x + 1) << ' ';
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a{1};
	cin >> a;
	while (a--) solve();
}
