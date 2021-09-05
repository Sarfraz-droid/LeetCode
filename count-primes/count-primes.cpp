class Solution {
public:
int countPrimes(int n) {
    vector prime(n, true);
    if(n==0 || n==1)
        return 0;
    prime[0] = false, prime[1] = false;
    for (int i = 2; i < sqrt(n); ++i) {
        if (prime[i]) {
            for (int j = 2*i; j < n; j += i) {
                prime[j] = false;
            }   
        }
    }
    return count(prime.begin(), prime.end(), true);
    }
};

