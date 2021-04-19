/* 
1. Using string hashing we can efficiently check whether two strings are equal by comparing their hash 
values. A hash value is an integer that is calculated from the characters of the string. 

2. If two strings are equal, their hash values are also equal,which makes it possible to compare 
strings based on their hash values. However, the vice versa may not be true.

3. The hashing shown below is known as the rolling polynomial hashing technique.

4. Hashing can make comparing substrings very time efficient like in problems of: pattern matching, 
distince substrings, Minimal rotation problem(string hashing + binary search).

5. When should hashing be avoided?  -> When we are comparing all strings to each other. The the probability
of two strings having same hash is approximately 1. { When number of strings is 1e6 and m = 1e9+9 }
In such a case it is best to calculate two hashes for the same string with m = 1e9 + 9. Now the m 
corresponds to approx 1e18 
*/

ll get_hash(string s)
{
    int p = 31; // Take 53 if both uppercase and lowercase letters
    int m = 1e9 + 9;
    ll hash_value = 0;
    char c;
    ll power[s.length()];
    power[0] = 1;
    for (int i = 1; i < s.length(); i++)
        power[i] = (power[i - 1] * p) % m;
    for (int i = 0; i < s.length(); ++i)
    {
        c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * power[i]) % m;
    }
    return hash_value;
}

/*
6. String hashing is used to find the ocurrences of a string in a text. {Rabin-karp function}
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