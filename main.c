#include <stdio.h>
void		lol(void* a)
{
	int b;
	b = *((int*)a);
	printf("%hd\n", *((short*)a));
	printf("%hd\n", (short)b);

}

int		main(void)
{
	int a = 245678955;
	lol((void*)(&a));
	//ft_printf("%#230.56ld Bonjour\n", 45);
	return (0);
}