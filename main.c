#include <stdio.h>
//#include "ft_printf.h"
#include <limits.h>
#include <float.h>
#include <math.h>

int		main(void)
{
	/*
	double a = 64.3654494499494494949949949;
	int ret;
	ft_printf("%# .3543434324342f\n", a);
	if ((ret = printf("coucou %# .3543434324342f Coucou\n", a)) < 0)
		printf("ON A RATE\n");
	printf("ret : %d\n", ret);
	printf("value_printf: %-8.3o\n", 64);
	*/

	//long double a = 1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583.000000;
	//printf("%d", ft_strequ(ft_ldtoa(a), ft_ldtoa(a - 200000000000000)));
	//printf("%Lf\n", a);
	

	//ft_printf("%f\n", DBL_MAX);
	//printf("%s\n", "99999999999999981139503267596847425176765179308926185662298078548582170379439067165044410288854031049481594743364161622187121841818187648603927125262209438639553681654618823985640760188731793867961170022535129351893330180773705244319986644578003569234231285691342840034082734135647456849389933411990123839488.000000");
	printf("%.1000LE\n", LDBL_MAX);
	//printf("%.f\n", M_PI);
	//printf("%ld\n", LONG_MAX);
	//int a = 5;
	//printf("%d\n", a);
	//double f = (double)a;
	//printf("%f\n", f);
	//int size_array = 0;
	//ft_printf("%f\n", 350.54);
	//printf("PRINTF: %f\n", a);


	//printf("%d\n", ret);
	//printf("ft_ret double: %d\n", ret);
	//ret = printf("Un double trop long vaut : %.3543434324342f", 3.5);
	//printf("ret double: %d\n", ret);
	//ft_putstr(a);
	//printf("%s\n", a);
	return (0);
}