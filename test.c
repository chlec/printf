/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/24 15:16:26 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_printf(const char *format, ...);
#include <locale.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

int		main(void)
{
	wchar_t	s[4];

	setlocale(LC_ALL, "");
	/*s[0] = 0x53;
	  s[1] = 0x3abc;
	  s[2] = 0x81000;
	  s[3] = '\0';*/
	int e = 7;
	printf("Length: %d\n", ft_printf("%d %.4S || %-5s%.7s %c |%lx| %20p\n", 234, L"我是一只猫。", "haha", "abcdef", 97, 2147483649, &e));
	printf("Length: %d\n",    printf("%d %.4S || %-5s%.7s %c |%lx| %20p\n", 234, L"我是一只猫。", "haha", "abcdef", 97, 2147483649, &e));
	printf("Length 2: %d\n", ft_printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc"));
	printf("Length 2: %d\n", printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc"));
	printf("Length 3: %d\n", ft_printf("me/ %10C test\n", L'à'));
	printf("Length 3: %d\n", printf("em/ %10C test\n", L'à'));
	printf("Length 4: %d\n", ft_printf("Test/ %s aaaaaaa\n", NULL));
	printf("Length 4: %d\n", printf("Test/ %s aaaaaaa\n", NULL));
	printf("Length 5: %d\n", ft_printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95));
	printf("Length 5: %d\n",   printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95));
	ft_printf("%C\n", 800);
	printf("%C\n", 800);
	ft_printf("%s\n", "salut");
	ft_printf("%1.4s et %-6.8s et %4.2s\n", "tuuu", "12345", "hu");
	printf("%1.4s et %-6.8s et %4.2s\n", "tuuu", "12345", "hu");
	ft_printf("%.3S\n", s);
	printf("%.3ls\n", s);
	s[0] = 'a';
	s[1] = 250;
	s[2] = 'b';
	s[3] = '\0';
	printf("%d\n", ft_printf("%-4S\n", s));
	printf("%d\n", printf("%-4S\n", s));
	//	while (1);
	return (0);
}
