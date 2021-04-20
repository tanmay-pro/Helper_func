// The best way is to use __gcd(a, b) function. LCM can be calculated using a*b/gcd(a, b) 
// On some compilers, __gcd(0, 0) gives exeption.

int gcd(int a, int b)
{
    if (a > b)
    {
        if (b == 0)
        {
            return a;
        }
        return gcd(a, a % b);
    }
    else if (b > a)
    {
        if (a == 0)
        {
            return b;
        }
        return gcd(b, b % a);
    }
    else
    {
        return a;
    }
}
