//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int c0{}, c1{};
		for (int i{0}; i < n; ++i) {
			if (v[i] == '0') c0 += (!i || v[i - 1] != '0');
			else ++c1;
		}

		cout << (c1 > c0 ? "Yes\n" : "No\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
