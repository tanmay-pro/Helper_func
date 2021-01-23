/* 
1. We use z_ algorithm when we need to check the longest substring starting from any character which 
matches with the prefix.

2. Algorithm: 

vector<int> z_function(string s) 
{
    int n = (int) s.length();
    
    vector<int> z(n);
    
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;   // returns a vector
}

3. Explanantion:

[l, r] are the indices of the rightmost string match. The index r can be seen as the boundary to 
which our string has been scanned by the algorithm.
