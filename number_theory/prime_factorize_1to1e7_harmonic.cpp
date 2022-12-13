const int mx = 5e6;
vi primefactors[mx+5];

genPrime(mx);

for(auto u : prime) {
    for(int i = p; i <= mx; i += p) {
        int tmp = i;
        while(tmp % p == 0) { // don't do this loop if you want only unique primes
            primefactors[i].pb(p);
            tmp /= p;
        }
    }
}
