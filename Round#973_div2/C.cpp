//#pragma GCC optimize ("O3")

#include <iostream>
#include <deque>

#include <cstdlib>

using namespace std;

namespace {
	ostream& operator<<(ostream& os, const deque<char>& dq) {
		for (auto& x : dq) os << x;
		return os;
	}
	bool ask(const deque<char>& t) {
		cout << "? " << t << endl;
		int r; cin >> r;
		if (r == -1) exit(EXIT_SUCCESS);
		return r;
	}
	void ans(const deque<char>& s) {
		cout << "! " << s << endl;
	}
	void solve() {
		int n;
		cin >> n;

		bool f{false};
		deque<char> s{'0'};
		if (!ask(s)) return ans(deque(n, '1'));
		for (int i{1}; i < n; ++i) {
			if (!f) {
				s.push_front('0');
				if (!ask(s)) {
					s.front() = '1';
					if (!ask(s)) s.pop_front(), f = true;
				}
			}
			if (f) {
				s.push_back('0');
				if (!ask(s)) s.back() = '1';
			}
		}

		ans(s);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
