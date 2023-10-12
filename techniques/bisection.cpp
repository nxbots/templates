If we use total 100 loops, we will be able to checking 10^18 + 12 precision points.
So we can easily run 100 loops & do binary search.
We can't do while(r <= l) because it may go indefinitely.
Precision error less than 10^9 acceptable.
So either we can loop for 100 times or do:
eps = 1e-12
while(abs(r-l) < eps) and do the bsearch works



-----------------------------------------------------------------------------
double l, w;
double L, R, mid, ans;
double dist() {
    double b = l-mid;
    double r = mid;
    double h = sqrt(r*r - b*b);
//    cout << b <<" "<<r<<" "<<w-h<<" "<<  2*mid + w-h << " ";
    return 2*mid + w-h;
}

void solve() {
    L = 0, R = l;
    mid = (L+R)/2.0;
//    cout << mid << endl;
    ans = l+w;
    L = mid; R = mid/2.0 + mid;
    for(int i = 0; i < 100; i++) {
        mid = (L+R)/2.0;
        double dis = dist();
//        cout <<L<<" "<<R<<" "<< dis << " ";
        if(dis <= ans) {
            L = mid;
            ans = dis;

        }
        else {
            R = mid;
        }
//        cout << ans << endl;
    }
     cout << fixed << setprecision(4)<< ans << endl;
}

int main() {
    fastio;


    while(true) {
        cin >> l >> w;
        if(l == 0 && w == 0)  break;
        solve();
    }
    return 0;
}
