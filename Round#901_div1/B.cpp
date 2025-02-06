//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <queue>

using namespace std;

int atoi(const array<int, 8>& a) {
	int i{};
	for (int k{0}; k < 8; ++k) i = i * 5 + a[k];
	return i;
}

array<int, 8> itoa(int i) {
	array<int, 8> a;
	for (int k{7}; k >= 0; --k) a[k] = i % 5, i /= 5;
	return a;
}

const vector<int> ans{[] {
	vector<int> v(390625, -1);
	queue<int> qu{};
	array<int, 8> sa{0, 1, 2, 3, 0, 1, 2, 3};
	auto si{atoi(sa)};
	v[si] = 0, qu.push(si);
	for (int c{0}; !qu.empty(); ++c) {
		queue<int> nq{};
		while (!qu.empty()) {
			auto i{qu.front()}; qu.pop();
			auto a{itoa(i)};
			for (int j{0}; j < (1 << 8); ++j) {
				auto ta{a};
				for (int k{0}; k < 8; ++k) {
					if ((j >> k) & 1) continue;
					ta[k] = 4;
				}
				auto ti{atoi(ta)};
				if (v[ti] == -1) v[ti] = c;
			}
			{
				auto ta{a};
				for (int k{0}; k < 8; ++k) ta[k] &= ((ta[k] & 1) << 1) | 1;
				auto ti{atoi(ta)};
				if (v[ti] == -1) v[ti] = c + 1, nq.push(ti);
			}
			{
				auto ta{a};
				for (int k{0}; k < 8; ++k) ta[k] |= ((ta[k] & 1) << 1);
				auto ti{atoi(ta)};
				if (v[ti] == -1) v[ti] = c + 1, nq.push(ti);
			}
			{
				auto ta{a};
				for (int k{0}; k < 8; ++k) ta[k] ^= ((ta[k] & 2) >> 1);
				auto ti{atoi(ta)};
				if (v[ti] == -1) v[ti] = c + 1, nq.push(ti);
			}
			{
				auto ta{a};
				for (int k{4}; k < 8; ++k) ta[k] ^= 1;
				auto ti{atoi(ta)};
				if (v[ti] == -1) v[ti] = c + 1, nq.push(ti);
			}
		}
		qu.swap(nq);
	}
	return v;
}()};

void solve() {
	int a, b, c, d, m;
	cin >> a >> b >> c >> d >> m;

	array<int, 8> x; x.fill(4);
	for (int j{0}; j < 30; ++j) {
		int aj{(a >> j) & 1}, bj{(b >> j) & 1}, cj{(c >> j) & 1}, dj{(d >> j) & 1}, mj{(m >> j) & 1};
		int k{(mj << 2) | (aj << 1) | bj}, r{(cj << 1) | dj};
		if (x[k] != 4) {
			if (x[k] != r) return cout << "-1\n", []{}();
		} else x[k] = (cj << 1) | dj;
	}
	cout << ans[atoi(x)] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
