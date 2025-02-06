//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	int ask(int i, int j) {
		cout << "? " << i << ' ' << j << endl;
		int r;
		cin >> r;
		return r;
	}
	void ans(char a) {
		cout << "! " << a << endl;
	}
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n + 1);
		for (int i{1}; i <= n; ++i) cin >> v[i];

		vector<bool> f(n + 1);
		for (int i{1}; i <= n; ++i) f[v[i]] = true;
		for (int i{1}; i <= n; ++i) {
			if (!f[i]) {
				int r{ask(i, i == 1 ? 2 : 1)};
				return ans(r ? 'B' : 'A');
			}
		}

		int j, k;
		for (int i{1}; i <= n; ++i) {
			if (v[i] == 1) j = i;
			if (v[i] == n) k = i;
		}
		int r1{ask(j, k)}, r2{ask(k, j)};
		ans(r1 >= n - 1 && r1 == r2 ? 'B' : 'A');
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
