

vector<int> factorize(int n) {
    vector<int> ret;
    for(auto p : prime) {
        if(p*p > n) break; //be careful about long long
        if(n%p == 0) {
            while(n%p == 0) {
                ret.pb(p);
                n/=p;
            }
        }
    }
    if(n > 1) ret.pb(n); //root n er boro prime
    return ret;
}
