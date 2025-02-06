//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	template<typename T>
	using matrix = vector<vector<T>>;
	void solve() {
		int n;
		cin >> n;
		matrix<char> g(n, vector<char>(n));
		for (auto& v : g)
			for (auto& x : v) cin >> x;

		vector<array<int, 2>> t{};
		for (int i{0}; i < n; ++i)
			for (int j{0}; j < n; ++j) {
				if (g[i][j] == '#') t.push_back({i, j});;
			}

		if (t.empty()) return cout << "YES\n", []{}();

		bool f;
		if (t.size() == 4) {
			f = true;
			for (int i{1}; i < t.size(); ++i) {
				auto di{t[i][0] - t[0][0]}, dj{t[i][1] - t[0][1]};
				if (clamp(di, 0, 1) == di && clamp(dj, 0, 1) == dj) continue;
				f = false;
				break;
			}
			if (f) return cout << "YES\n", []{}();
		}

		f = true;
		for (int i{1}; i < t.size(); ++i) {
			auto di{t[i][0] - t[0][0]}, dj{t[i][1] - t[0][1]};
			if (di == dj || di - 1 == dj) continue;
			f = false;
			break;
		}
		if (f) return cout << "YES\n", []{}();

		f = true;
		for (int i{1}; i < t.size(); ++i) {
			auto di{t[i][0] - t[0][0]}, dj{t[i][1] - t[0][1]};
			if (di == dj || di == dj - 1) continue;
			f = false;
			break;
		}
		if (f) return cout << "YES\n", []{}();
		
		f = true;
		for (int i{1}; i < t.size(); ++i) {
			auto di{t[i][0] - t[0][0]}, dj{-(t[i][1] - t[0][1])};
			if (di == dj || di - 1 == dj) continue;
			f = false;
			break;
		}
		if (f) return cout << "YES\n", []{}();

		f = true;
		for (int i{1}; i < t.size(); ++i) {
			auto di{t[i][0] - t[0][0]}, dj{-(t[i][1] - t[0][1])};
			if (di == dj || di == dj - 1) continue;
			f = false;
			break;
		}
		if (f) return cout << "YES\n", []{}();

		cout << "NO\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
