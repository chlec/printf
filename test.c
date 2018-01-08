/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/08 16:11:54 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	int e = 7;
	printf("Length: %d\n", ft_printf("%d %-20S || %-5s%.7s %c |%lx| %20p\n", 234, L"我是一只猫", "haha", "abcdef", 97, 2147483649, &e));
	printf("Length: %d\n",    printf("%d %-20S || %-5s%.7s %c |%lx| %20p\n", 234, L"我是一只猫", "haha", "abcdef", 97, 2147483649, &e));
	ft_printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95);
	printf("%--.4u et %#O%#012O%1lc\n", -12, 0, 0, 95);
	ft_printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc");
	printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "cooc");
	ft_printf("%C\n", L'à');
	printf("%C\n", L'à');
	return (0);
}
