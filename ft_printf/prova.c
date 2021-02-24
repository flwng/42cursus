#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
void prova(t_info *info)
{
	info->width = 0;
}

int main()
{
	const char *a = "10abc";
	const char **s = &a;

	if (*(*s)++ == '1')
		printf("ciao\n");
	printf("%c\n", **s);
}
