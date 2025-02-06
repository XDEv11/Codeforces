//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const int C{1024}, E{1 << (32 - __builtin_clz(C))};
	void solve() {

		int n, q;
		cin >> n >> q;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;
		vector<pair<pair<int, int>, ll>> a(q);
		for (auto& [_, b] : a) {
			auto& [x, y]{_};
			cin >> x >> y >> b, --x;
		}

		vector<ll> ps(n + 1);
		for (int i{0}; i < n; ++i) ps[i + 1] = ps[i] + v[i];

		vector<int> od(q);
		vector<vector<int>> tb(q, vector<int>(C + 1)); {
			vector<pair<ll, int>> t(q);
			for (int j{0}; j < q; ++j) t[j] = {a[j].se, j};
			sort(t.begin(), t.end());

			for (int j{0}; j < q; ++j) od[t[j].se] = j;

			for (int j{0}; j < q; ++j)
				for (int k{1}; k <= C; ++k) {
					int i{!j ? n : tb[j - 1][k]};
					while (i - k >= 0 && ps[i] - ps[i - k] < t[j].fi) --i;
					tb[j][k] = i;
				}
		}

		for (int j{0}; j < q; ++j) {
			auto& [_, b]{a[j]};
			auto& [x, y]{_};
			int ans{};

			for (int k{1}; k <= min(C, y - x); ++k) {
				int t{(min(y, tb[od[j]][k]) - x) / k};
				if (t < 0) continue;
				x += k * t, ans += t;
			}

			int e{E};
			while (true) {
				while (e <= y - x && ps[x + e] - ps[x] < b) e <<= 1;

				int l{x + (e >> 1)}, r{min(y + 1, x + e)};
				while (r - l > 1) {
					int m{(l + r) / 2};
					(ps[m] - ps[x] < b ? l : r) = m;
				}
				if (r == y + 1) break;
				x = r, ++ans;
			}

			cout << ans << ' ' << ps[y] - ps[x] << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cerr << "C=" << C << ", E=" << E << endl; //
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
