#include<bits/stdc++.h>
using namespace std;
#define ll long long


#define mod 2419

//Function to calculate exponent taking care of the MOD
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}


signed main(){
    
    cout<<mpow(243, 11);
        return 0;
}