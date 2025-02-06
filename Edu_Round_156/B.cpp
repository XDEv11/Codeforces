//#pragma GCC optimize ("O3")

#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>

using namespace std;

void solve() {
	int px, py, ax, ay, bx, by;
	cin >> px >> py >> ax >> ay >> bx >> by;

	px *= 2, py *= 2, ax *= 2, ay *= 2, bx *= 2, by *= 2;
	auto sq{[](int x) { return x * x; }};
	int ao{sq(ax) + sq(ay)}, bo{sq(bx) + sq(by)};
	int ap{sq(ax - px) + sq(ay - py)}, bp{sq(bx - px) + sq(by - py)};
	int ab{sq(ax - bx) + sq(ay - by)};

	int ans{min({max(ao, ap), max(bo, bp), max({ab / 4, min(ao, bo), min(ap, bp)})})};
	cout << (sqrt(ans) / 2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(7);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
