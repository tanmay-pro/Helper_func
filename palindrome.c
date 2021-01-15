int isPalindrome(char str[])
{
    int l = 0;
    int c = 0; // counter
    int h = strlen(str) - 1;
    while (h > l)
    {
        if (str[l++] != str[h--])
        {
            c++;
            return;
        }
    }
    if (c == 0)
        return 1; // It is plaindrome
    else
        return 0; // Not palindrome
}