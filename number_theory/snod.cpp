int SNOD ( int n ) {
    int sq = sqrt ( n );
    int ret = 0;
    for ( int i = 1; i <= sq; i++ ) {
        ret += ( n / i ) - i;
    }
    ret *= 2;
    ret += sq;
    return ret;
}
