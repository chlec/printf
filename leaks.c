#include <strings.h>
#include <locale.h>
#include <limits.h>
#include <stdio.h>
int ft_printf(char const *str, ...);
int main(void)
{
	setlocale(LC_ALL, "");
    char    c;
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
	/*ft_printf("%#08x\n", 42);
	ft_printf("%#.x %#.0x\n", 0, 0);
	ft_printf("%5.x %5.0x\n", 0, 0);
	ft_printf("%hhx, %hhx\n", 0, UCHAR_MAX + 42);
	ft_printf("%hho, %hho\n", 0, UCHAR_MAX + 42);
	ft_printf("%.4d\n", -424242);
	ft_printf("%#.O\n", 0);
	ft_printf("%s%d%p%%%S%D%i%o%O%u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ft_printf("%");*/
	printf("Length: %d\n", ft_printf("{%-30S}\n", L"我是一只猫。"));
	printf("Length: %d\n", printf("{%-30S}\n", L"我是一只猫。"));
	while (1);
	return (0);
}
