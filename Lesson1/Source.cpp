#include "stdafx.h"

using namespace std;

#include <cmath>
using namespace std;
inline void numCounter(long long& count, const long long& reiteration)
{
    for (int i = 1; i <= reiteration; i *= 10)
        count += (reiteration - i + 1);
}

long long myPow(long long  x, long long  y) {
    long long  ans = 1;
    long long  base = x;
    while (y) {
        if (y & 1) {
            ans *= base;
        }
        y >>= 1;
        base *= base;
    }
    return ans;
}

inline long long discharges(const long long& length)
{
    //return length * 9 * pow(10, length - 1);
    return length * 9 * myPow(10, length - 1);
}


int solve(long long n)
{
    int ans = 0;
    long long count = 0;
    long long lastBlock = 0;
    long long reiteration = 1;

    while (count < n)
    {
        numCounter(count, reiteration++);
    }

    numCounter(lastBlock, reiteration - 1);


    long long newN = n - (count - lastBlock);
    long long newN_Length = 1;

    while (newN > discharges(newN_Length))
    {
        newN -= discharges(newN_Length);
        ++newN_Length;
    }

    //long long num = pow(10, newN_Length - 1) + (newN - 1) / newN_Length;
    long long num = myPow(10, newN_Length - 1) + (newN - 1) / newN_Length;
    // ans = num / pow(10, (newN_Length - 1) - (newN - 1) % newN_Length);
    ans = num / myPow(10, (newN_Length - 1) - (newN - 1) % newN_Length);

    ans %= 10;

    return ans;
}


int main() {
	setlocale(LC_ALL, "ru");

    solve(999999999999999993); //equals 7     too slow

    system("pause");
}







