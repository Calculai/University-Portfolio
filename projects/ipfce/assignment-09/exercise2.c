// write a recursive function that sums the integer array a of length n
int sum(const int a[], int n) {
    if (n==0)
    {
        return 0;
    }
    
    return a[n-1] + sum(a, n-1);
}