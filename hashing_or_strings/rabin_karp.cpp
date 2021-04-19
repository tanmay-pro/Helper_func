/*
1. String hashing is used to find the ocurrences of a string in a text. {Rabin-karp function}
*/

vl rabin_karp(string &s, string &t)
{
    int p = 31;
    int m = 1e9 + 9;
    ll S = s.size(), T = t.size();

    ll maxel = max(S, T);
    ll p_pow[maxel];
    p_pow[0] = 1;
    for (int i = 1; i < maxel; i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    ll h[T + 1, 0];
    for (int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    ll h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vl occurences;
    for (int i = 0; i + S - 1 < T; i++)
    {
        ll cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurences.push_back(i);
    }
    return occurences;
}