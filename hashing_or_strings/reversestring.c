void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void reverseStr(char str[])
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        swap(&str[i], &str[n - i - 1]);
    }
}