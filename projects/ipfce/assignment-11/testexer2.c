#include <assert.h>
#include <stdio.h>

long recursive_product (int n, int l[]);

int main (void)
{
int l[] = {2, 2, 2};
int n = 3;
long result = recursive_product (n, l);
printf ("The product of the array is: %ld\n", result);
return 0;
}

/* product of an array function definition */
long recursive_product (int n, int l[])
{
/* pre-condition */
assert (n >= 0);

/* post-condition */
if (n >= 1)
return recursive_product (n - 1, l)*l[n-1];
else
return 1;
}
