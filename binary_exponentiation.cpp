// To calculate a raised to b

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1 == true) // Equivalent to b%2
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1; // Equivalent to b/=2
    }
    return res;
}