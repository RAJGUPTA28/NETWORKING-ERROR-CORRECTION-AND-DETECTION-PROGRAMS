#include <bits/stdc++.h>
using namespace std;
 

int hammingDistance(int n1, int n2)
{
    int x = n1 ^ n2;
    int intBits = 0;
 
    while (x > 0) {
        intBits += x & 1;
        x >>= 1;
    }
 
    return intBits;
}
 

int main()
{
    cout << "\nHAMMING DISTANCE BETWEEN 12 AND 6 IS : "<<hammingDistance(12, 6) << endl;
 
    return 0;
}