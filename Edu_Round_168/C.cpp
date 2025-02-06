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

		long long ans{};
		vector<int> t{};
		for (int i{0}; i < n; i += 2) {
			if (t.empty() || (t.size() == 1 && t[i + 1] == ')')) {
				t.push_back(i);
			} else {
				int j{t.back()}; t.pop_back();
				ans += i - j;
			}
			if (v[i + 1] == ')') {
				int j{t.back()}; t.pop_back();
				ans += i + 1 - j;
			} else {
				t.push_back(i + 1);
			}
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
