#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

#define ll long long
#define PI 3.14159265
#define br printf("\n")
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define file_read                     \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
ll m = 1e9 + 7;


void merge_arr(int a[], int l, int m, int r);

void Perform_merge_sort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid_value = left + (right - left) / 2;
        Perform_merge_sort(array, left, mid_value);
        Perform_merge_sort(array, mid_value + 1, right);
        merge_arr(array, left, mid_value, right);
    }
}

void merge_arr(int array[], int left_val, int mid_value, int right_val)
{
    Each_Medal left_array[mid_value - left_val + 1], right_array[right_val - mid_value];
    int x = 0;
    int y = 0;
    fo(i, right_val - mid_value)
    {
        right_array[i] = array[mid_value + 1 + i];
    }
    fo(i, mid_value - left_val + 1)
    {
        left_array[i] = array[left_val + i];
    }
    int left_val_temp = left_val;
    while (x < mid_value - left_val + 1 && y < right_val - mid_value)
    {
        if (left_array[x].net_value > right_array[y].net_value)
        {
            array[left_val_temp] = left_array[x];
            x++;
        }
        else
        {
            array[left_val_temp] = right_array[y];
            y++;
        }
        left_val_temp++;
    }
    while (y < right_val - mid_value)
    {
        array[left_val_temp] = right_array[y];
        left_val_temp++;
        y++;
    }
    while (x < mid_value - left_val + 1)
    {
        array[left_val_temp] = left_array[x];
        left_val_temp++;
        x++;
    }
}
