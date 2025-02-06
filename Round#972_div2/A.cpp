//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>

using namespace std;

namespace {
	const array<char, 5> vc{'a', 'e', 'i', 'o', 'u'};
	void solve() {
		int n;
		cin >> n;

		vector<char> ans{};
		for (int i{0}; i < 5; ++i) {
			for (int j{0}; j < n / 5 + (i < n % 5); ++j) ans.push_back(vc[i]);
		}

		for (auto& x : ans) cout << x;
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
