//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<int> bp(n + 1, false);
	bp[n] = true;
	for (int bt{29}; bt >= 0; --bt) {
		bool f{true};
		int i{0};
		while (i < n) {
			int c{0}, ca{0}, cb{0};
			do {
				ca += (a[i] >> bt) & 1;
				cb += (b[i] >> bt) & 1;
				c += 1;
				++i;
			} while (!bp[i]);
			if (ca + cb != c) {
				f = false;
				break;
			}
		}
		if (f) {
			i = 0;
			while (i < n) {
				int j{i};
				queue<int> a0{}, a1{}, b0{}, b1{};
				do {
					if ((a[j] >> bt) & 1) a1.push(a[j]);
					else a0.push(a[j]);
					if ((b[j] >> bt) & 1) b1.push(b[j]);
					else b0.push(b[j]);
					++j;
				} while (!bp[j]);
				while (!a0.empty()) {
					a[i] = a0.front(), a0.pop();
					b[i] = b1.front(), b1.pop();
					++i;
				}
				bp[i] = true;
				while (!a1.empty()) {
					a[i] = a1.front(), a1.pop();
					b[i] = b0.front(), b0.pop();
					++i;
				};
			}
		}
	}

	vector<int> c(n);
	for (int i{0}; i < n; ++i) c[i] = a[i] ^ b[i];
	int ans{~0};
	for (auto& x : c) ans &= x;
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
