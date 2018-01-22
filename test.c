/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/22 16:24:49 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_printf(const char *format, ...);
#include <locale.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	int e = 7;
	while (1)
	{
	printf("Length: %d\n", ft_printf("%d %-30S || %-5s%.7s %c |%lx| %20p\n", 234, L"我是一只猫。", "haha", "abcdef", 97, 2147483649, &e));
	printf("Length: %d\n",    printf("%d %-30S || %-5s%.7s %c |%lx| %20p\n", 234, L"我是一只猫。", "haha", "abcdef", 97, 2147483649, &e));
	printf("Length 2: %d\n", ft_printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc"));
	printf("Length 2: %d\n", printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc"));
	printf("Length 3: %d\n", ft_printf("me/ %10C test\n", L'à'));
	printf("Length 3: %d\n", printf("em/ %10C test\n", L'à'));
	printf("Length 4: %d\n", ft_printf("Test/ %s aaaaaaa\n", NULL));
	printf("Length 4: %d\n", printf("Test/ %s aaaaaaa\n", NULL));
	printf("Length 5: %d\n", ft_printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95));
	printf("Length 5: %d\n",   printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95));
	ft_printf("%C\n", 0xd800);
	printf("%C\n", 0xd800);
	ft_printf("%s\n", "salut");
	}
	// while (1);
	return (0);
}

//leaks below
/*
int main(void)
  {
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
  while (1);
  return (0);
  }*/
