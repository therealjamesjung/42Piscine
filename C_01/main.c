#include <stdio.h>
#include <stdlib.h>

extern void ft_ultimate_ft(int *nbr);

int main()
{
	int *n = malloc(sizeof(int)*3);
	*n = 4;

	printf("%d\n", *n);
	ft_ultimate_ft(&(*n));
	printf("%d", *n);

	return 0;
}