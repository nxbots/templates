int NOD (long long n) {
    int ret = 1;
    for ( auto p : prime ) { 
        if ( 1LL * p * p > n ) break;
        if ( n % p == 0 ) { 
            int cnt = 1;
            while ( n % p == 0 ) { // n = 5
                n /= p; // n = 5;
                cnt++; // 2
            }
            ret *= cnt; // 1 * 3 * 2
        }
    }
    if ( n > 1 ) ret *= 2; // 1 * 3 * 2  * 2 = 12
    return ret;
}
