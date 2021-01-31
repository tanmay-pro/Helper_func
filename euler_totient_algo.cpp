// This tells us about the nnumber of integers coprime to n which are less than n and >=1

// Method 1: Direct formula usage
ll phi(int n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
//Method 2: Using SOE. If you want totient values for each integer from 1 to n
ll phi_soe(int n)
{
    vi phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        phi[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi[n];
}
