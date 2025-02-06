//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	// previous/next one
	class PvNx {
		vector<int> pa, sz, mn, mx;
		int find(int x) { // collapsing find
			return pa[x] == -1 ? x : pa[x] = find(pa[x]);
		}
		void unionn(int x, int y) { // weighted union
			auto rx{find(x)}, ry{find(y)};
			if (rx == ry) return ;
			if (sz[rx] < sz[ry]) swap(rx, ry);
			pa[ry] = rx, sz[rx] += sz[ry], mn[rx] = min(mn[rx], mn[ry]), mx[rx] = max(mx[rx], mx[ry]);
		}
	public:
		explicit PvNx(int n) : pa(n + 1, -1), sz(n + 1, 1), mn(n + 1) { iota(mn.begin(), mn.end(), 0), mx = mn; }
		void remove(int i) { unionn(i, i + 1); }
		int prev(int i) { return mn[find(i)] - 1; }
		int next(int i) {
			int j{mx[find(i)]};
			if (i == j) j = mx[find(j + 1)];
			return j;
		}
		bool exist(int i) { return i == mx[find(i)]; }
	};
	void solve() {
		int n, _;
		cin >> n >> _;
		vector<int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		PvNx pa{n}, pb{n};
		auto cn{[&n](PvNx& p, int i) {
			int t{p.next(i)};
			if (t == n) {
				if (p.exist(0)) return 0;
				return p.next(0);
			} else return t;
		}};
		int ca{n};
		for (int k{0}; ; ++k) {
			int i{pa.exist(0) ? 0 : pa.next(0)};
			while (i < n) {
				int j{cn(pb, (i + k - 1 + n) % n)};
				int t{((j - k) % n + n) % n};
				if (t < i) break;
				i = t;
				if (pa.exist(i)) {
					if (a[i] == b[j]) {
						a[i] = 0, pa.remove(i), --ca;
						b[j] = 0, pb.remove(j);
					} else if (a[i] < b[j]) {
						b[j] -= a[i];
						a[i] = 0, pa.remove(i), --ca;
					} else {
						a[i] -= b[j];
						b[j] = 0, pb.remove(j);
					}
				}
				i = pa.next(i);
			}
			if (ca == 0) return cout << (k + 1) << '\n', []{}();
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
