#include "libft.h"
#include <stdio.h> 
#include <locale.h>
#include <stdlib.h>

 int main()
{
	char *l;
//	l = NULL;
	l = setlocale(LC_ALL, "");
//	ft_printf("%%   %", "test");
    printf ("or [%10C]\n", 999);
     ft_printf ("my [%10C]\n", 999);
//	ft_printf ("my [%#x]\n", l);
//	ft_printf("%s\n", "ff)
//	printf("or [%p]\n", 92);
//	ft_printf("my [%p]\n", 92);

	return (0);
}

