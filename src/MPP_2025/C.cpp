#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define pll pair<ll, ll>
#define pii pair<int, int>

bool is_valid(int C, int L) {
    if(abs(C) >= 0 && abs(C) <= L) {
        return true;
    }
    return false;
}

class point {
    private:
        int x;
        int y;

    public:
        point(int x, int y) {
            this->x = x;
            this->y = y;
        };

        bool is_in_triangle(point A, point B, point C) {
            // AB x P
            int p1 = (B.x - A.x) * (this->y - A.y) - (B.y - A.y) * (this->x - A.x);
            // BC x P
            int p2 = (C.x - B.x) * (this->y - B.y) - (C.y - B.y) * (this->x - B.x);
            // CA x P
            int p3 = (A.x - C.x) * (this->y - C.y) - (A.y - C.y) * (this->x - C.x);

            bool has_neg = (p1 < 0) || (p2 < 0) || (p3 < 0);
            bool has_pos = (p1 > 0) || (p2 > 0) || (p3 > 0);
            return !(has_neg && has_pos);
        }
};

void solve() {
    int X, Y;
    cin >> X >> Y;
    if(X < -200 || X > 200) {
        cout << "N" << endl;
        return;
    }
    if(Y < -100 || Y > 100) {
        cout << "N" << endl;
        return;
    }

    // Está dentro dos quadrados?
    if(X >= -100 && X <= 0 && Y >= 0 && Y <= 100) {
        cout << "S" << endl;
        return;
    }
    if(X >= 0 && X <= 100 && Y <= 0 && Y >= -100) {
        cout << "S" << endl;
        return;
    }

    // Em relação aos triângulos
    point P = point(X, Y);

    if(X >= -200 && X <= -100) {
        point A = point(-100, 100);
        point B = point(-100, 0);
        point C = point(-200, 0);
        if(P.is_in_triangle(A, B, C)) {
            cout << "S" << endl;
            return;
        }
    }
    if(X >= -100 && X <= 0) {
        point A = point(0, 0);
        point B = point(0, -100);
        point C = point(-100, 0);
        if(P.is_in_triangle(A, B, C)) {
            cout << "S" << endl;
            return;
        }
    }
    if(X >= 0 && X <= 100) {
        point A = point(0, 100);
        point B = point(100, 0);
        point C = point(0, 0);
        if(P.is_in_triangle(A, B, C)) {
            cout << "S" << endl;
            return;
        }
    }
    if(X >= 100 && X <= 200) {
        point A = point(100, 0);
        point B = point(200, 0);
        point C = point(100, -100);
        if(P.is_in_triangle(A, B, C)) {
            cout << "S" << endl;
            return;
        }
    }
    cout << "N" << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    while(N--)
        solve();
}