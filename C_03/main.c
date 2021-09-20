#include <stdio.h>
#include <string.h>
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	char s1[100] = "AASSD";
	char s2[100] = "ASDFASDF";


	printf("%s %s\n",s1, s2);

	printf("%lu\n", strlcat(s1, s2, 8));

	printf("%s %s\n",s1, s2);

	printf("%d\n", ft_strlcat(s1, s2, 8));

	printf("%s %s\n",s1, s2);

	return 0;
}