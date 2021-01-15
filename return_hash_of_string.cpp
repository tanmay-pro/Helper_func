
long long compute_hash(string const& s) {
    const int p = 31; // Take 53 if both uppercase and lowercase letters
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    char c;
    for (int i=0; i<s.length(); ++i) 
    {
        c = s[i];
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}