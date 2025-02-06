//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x, --x;

		vector<int> p(n);
		for (int i{0}; i < n; ++i) p[v[i]] = i;

		for (int i{0}, k{0}; k < n; ++i) {
			if (v[i] < k) continue;
			if ((v[i] - k) % 2) {
				int j{i + 1};
				for (int mn{v[i]}; ; ++j) {
					if (v[j] < k) continue;
					if ((v[j] - v[i]) % 2 && mn > v[j]) break;
					mn = min(mn, v[j]);
				}
				while (v[j] > k) {
					int p1{p[v[j] - 1]}, p2{p[v[j] - 2]};
					v[j] -= 2, v[p1] += 1, v[p2] += 1;
					p[v[j]] = j, p[v[p1]] = p1, p[v[p2]] = p2;
				}
				while (v[i] > k + 1) {
					int p1{p[v[i] - 1]}, p2{p[v[i] - 2]};
					v[i] -= 2, v[p1] += 1, v[p2] += 1;
					p[v[i]] = i, p[v[p1]] = p1, p[v[p2]] = p2;
				}
				k += 2;
			} else {
				while (v[i] > k) {
					int p1{p[v[i] - 1]}, p2{p[v[i] - 2]};
					v[i] -= 2, v[p1] += 1, v[p2] += 1;
					p[v[i]] = i, p[v[p1]] = p1, p[v[p2]] = p2;
				}
				k += 1;
			}
		}


		for (auto& x : v) cout << (x + 1) << ' ';
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
