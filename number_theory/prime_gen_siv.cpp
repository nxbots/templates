#include<bits/stdc++.h>
using namespace std;

static const int mx = 1e6+20;
bool isPrime[mx];
vector<int> prime;

void genPrime(int n) {
    for(int i = 3; i <= n; i += 2) isPrime[i] = 1;

    int sq = sqrt(n);

    for(int i = 3; i <= sq; i += 2) {
        if(isPrime[i] == 1) {
            for(int j = i*i; j <= n; j += i*2) {
                isPrime[j] = 0;
            }
        }
    }
    prime.push_back(2);
    for(int i = 3; i <= n; i += 2) {
        if(isPrime[i] == 1) prime.push_back(i);
    }
}

int main() {
    int n = mx - 10;
    genPrime(n);

    for(auto u : prime) cout << u << " ";
    cout << endl;
}
