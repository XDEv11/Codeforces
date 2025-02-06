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

		vector<bool> ck(n);
		for (int k{0}; k <= 1; ++k) {
			char op, cl;
			switch (k) {
				break; case 0: op = '(', cl = ')';
				break; case 1: op = '[', cl = ']';
			}
			vector<int> t{};
			for (int i{0}; i < n; ++i) {
				if (v[i] == cl && !t.empty()) ck[t.back()] = ck[i] = true, t.pop_back();
				else if (v[i] == op) t.push_back(i);
			}
		}

		int co{}, cc{}, f{1};
		for (int i{0}; i < n; ++i) {
			if (ck[i]) continue;
			if (v[i] == ')' || v[i] == ']') {
				++cc;
				if (co) f = 0;
			} else ++co;
		}
		if (co % 2 == 0) f = 0;
		int ans{(co + cc) / 2 + f};

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
