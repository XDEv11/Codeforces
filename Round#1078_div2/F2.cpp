//#pragma GCC optimize ("O3")
 
#include <iostream>
#include <array>
#include <vector>
#include <string> // SSO
 
#include <cstdint>
 
using namespace std;
 
namespace {
	using ll = int64_t;
	const int PM{1000000007};
 
	constexpr array<int, 11> ipm{[] {
		array<int, 11> t;
		t[0] = 1;
		for (int i{1}; i <= 10; ++i) t[i] = ll(t[i - 1]) * ((PM + 1) / 2) % PM;
		return t;
	}()};
	constexpr array<int8_t, 1 << 10> pty{[] {
		array<int8_t, 1 << 10> t;
		t[0] = 1;
		for (int i{1}; i < (1 << 10); ++i) t[i] = t[i >> 1] * ((i & 1) ? -1 : 1);
		return t;
	}()};
	basic_string<int> bs{};
	int mask(int x) {
		int t{};
		for (auto& b : bs) {
			t <<= 1;
			if ((x & b) > (b >> 1)) x ^= b, t |= 1;
		}
		if (x) return -1;
		return t;
	}
	array<int8_t, 1 << 10> fwht{};
	array<array<int, 1 << 10>, 16> dp{[] constexpr {
		array<array<int, 1 << 10>, 16> t;
		for (int i{0}; i < 16; ++i) t[i].fill(1);
		return t;
	}()};
	int dpc{};
	void solve(bool clear) {
		int n, m;
		cin >> n >> m;
		vector<basic_string<int>> adj(n);
		for (int _{0}; _ < n - 1; ++_) {
			int u, v;
			cin >> u >> v, --u, --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> c(n);
		for (int i{0}; i < n; ++i) cin >> c[i];
 
		{
			basic_string<int> s(m, 0);
			for (auto& x : s) cin >> x;

			bs.clear();
			auto t{s};
			while (!t.empty()) {
				int b{t.back()}; t.pop_back();
				if (!b) continue;
				for (auto& x : t) {
					if ((x & b) > (b >> 1)) x ^= b;
				}
				for (auto& x : bs) {
					if ((x & b) > (b >> 1)) x ^= b;
				}
				bs.push_back(b);
			}
			m = bs.size();

			for (int i{0}; i < s.size(); ++i) fwht[mask(s[i])] = 1;
			for (int l{1}; l < (1 << m); l <<= 1)
				for (int j{0}; j < (1 << m); j += (l << 1))
					for (int k{0}; k < l; ++k) {
						auto x{fwht[j + k]}, y{fwht[j + k + l]};
						fwht[j + k] = x + y;
						fwht[j + k + l] = x - y;
					}
		}

		
		vector<array<int, 3>> stk(n + 1);
		stk[0][0] = -1;
		adj[0].push_back(-1);
		int top{1};
		while (true) {
			auto& [u, ui, uh]{stk[top]};
			if (ui < adj[u].size() - 1) {
				auto& v{adj[u][ui]};
				if (v == stk[top - 1][0]) swap(v, adj[u].back());
				stk[++top] = {v, 0};
			} else {
				adj[u].pop_back();
				if (top == 1) break;

				auto& [w, wi, wh]{stk[--top]};
				if (uh >= wh) {
					wh = uh + 1;
					swap(adj[w][wi], adj[w][0]);
				}
				++wi;
			}
		}

		basic_string<int> usd{};
		auto AL{[&m, &usd]() {
			int p;
			if (!usd.empty()) {
				p = usd.back(), usd.pop_back();
				for (int j{0}; j < (1 << m); ++j) dp[p][j] = 1;
			} else p = dpc++;
			return p;
		}};
		auto DE{[&m, &usd](int p) {
			usd.push_back(p);
		}};

		int ans{};
		stk[1][1] = 0, stk[1][2] = -1, top = 1;
		while (true) {
			auto& [u, ui, up]{stk[top]};
			if (ui < adj[u].size()) {
				auto& v{adj[u][ui]};
				stk[++top] = {v, 0, -1};
			} else {
				if (up == -1) up = AL();
				int k{mask(c[u])};
				if (k != -1) {
					ll s{}; // fwht are small numbers
					int j{0};
					for (; j + 7 < (1 << m); j += 8) {
						array<ll, 15> t;
						t[0] = ll(dp[up][j    ]) * pty[j       & k] * fwht[j    ];
						t[1] = ll(dp[up][j + 1]) * pty[(j + 1) & k] * fwht[j + 1];
						t[2] = ll(dp[up][j + 2]) * pty[(j + 2) & k] * fwht[j + 2];
						t[3] = ll(dp[up][j + 3]) * pty[(j + 3) & k] * fwht[j + 3];
						t[4] = ll(dp[up][j + 4]) * pty[(j + 4) & k] * fwht[j + 4];
						t[5] = ll(dp[up][j + 5]) * pty[(j + 5) & k] * fwht[j + 5];
						t[6] = ll(dp[up][j + 6]) * pty[(j + 6) & k] * fwht[j + 6];
						t[7] = ll(dp[up][j + 7]) * pty[(j + 7) & k] * fwht[j + 7];
						t[8] = t[0] + t[1], t[9] = t[2] + t[3], t[10] = t[4] + t[5], t[11] = t[6] + t[7];
						t[12] = t[8] + t[9], t[13] = t[10] + t[11];
						t[14] = t[12] + t[13];
						s += t[14];
					}
					for (; j < (1 << m); ++j) s += ll(dp[up][j]) * pty[j & k] * fwht[j];
					s %= PM;
					s = (s * ipm[m]) % PM;
					if (u) {
						for (j = 0; j < (1 << m); ++j) {
							int t{dp[up][j]};
							t += s * pty[j & k];
							if (t <= -PM) t += PM;
							else if (t >= PM) t -= PM;
							dp[up][j] = t;
						}
					} else ans = s;
				}
				if (top == 1) break;

				auto& [w, wi, wp]{stk[--top]};
				c[w] ^= c[u];
				if (wi) {
					int j{0};
					for (; j + 7 < (1 << m); j += 8) {
						dp[wp][j    ] = (ll(dp[wp][j    ]) * dp[up][j    ]) % PM;
						dp[wp][j + 1] = (ll(dp[wp][j + 1]) * dp[up][j + 1]) % PM;
						dp[wp][j + 2] = (ll(dp[wp][j + 2]) * dp[up][j + 2]) % PM;
						dp[wp][j + 3] = (ll(dp[wp][j + 3]) * dp[up][j + 3]) % PM;
						dp[wp][j + 4] = (ll(dp[wp][j + 4]) * dp[up][j + 4]) % PM;
						dp[wp][j + 5] = (ll(dp[wp][j + 5]) * dp[up][j + 5]) % PM;
						dp[wp][j + 6] = (ll(dp[wp][j + 6]) * dp[up][j + 6]) % PM;
						dp[wp][j + 7] = (ll(dp[wp][j + 7]) * dp[up][j + 7]) % PM;
					}
					for (; j < (1 << m); ++j) dp[wp][j] = (ll(dp[wp][j]) * dp[up][j]) % PM;
					DE(up);
				} else wp = up;
				++wi;
			}
		}
		if (ans < 0) ans += PM;
 
		cout << ans << '\n'; 

		if (clear) {
			for (int j{0}; j < (1 << m); ++j) fwht[j] = 0;
			DE(stk[1][2]);
			for (auto& p : usd) 
				for (int j{0}; j < (1 << m); ++j) dp[p][j] = 1;
			dpc = 0;
		}
	}
};
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve(t);
}
