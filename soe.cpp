// To Find all prime numbers between 1 and n

vl sieve(ll n)
{
    int is_composite[n + 5] = {0};
    is_composite[0] = is_composite[1] = 1;

    for (int i = 2; i * i <= n; i++)
        if (!is_composite[i])
            for (int j = i * i; j <= n; j += i)
                is_composite[j] = 1;

    vl primes;
    for (int i = 0; i <= n; i++)
        if (!is_composite[i])
            primes.push_back(i);
    return primes;
}

// To find the number of divisors of a number

ll num[n + 1];
for (int i = 1; i <= n; i++)
{
    for (int j = i; j <= n; j += i)
    {
        num[j]++;
    }
}

// To find the sum of all divisors of a number

ll sum[n + 1];

for (int i = 1; i <= n; i++)
{
    for (int j = i; j <= n; j += i)
    {
        sum[j] += i;
    }
}