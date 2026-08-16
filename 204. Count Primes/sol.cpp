//Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        
        for(long i = 2; i < n; i++) {
            if(prime[i]) {
                for(long j = i * i; j < n; j += i)
                    prime[j] = false;
            }
        }
        
        int c = 0;
        for(long i = 2; i < n; i++)
            c += prime[i];
        
        return c;
    }
};
