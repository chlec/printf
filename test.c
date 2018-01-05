/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/05 12:00:26 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	setlocale(LC_ALL, "");
	//simple test
	/*char *s = "225/136/180";
	char **split = ft_strsplit(s, '/');
	int		i;
	i = 0;
	unsigned char nb;
	while (split[i]) {
		nb = (unsigned char)ft_atoi(split[i]);
		write(1, &nb, 1);
		i++;
	}*/
	//end
	int e = 7;
	printf("Length: %d\n", ft_printf("%-20S || %-5s%.7s %c |%lx| %20p\n", L"我是一只猫", "haha", "abcdef", 97, 2147483649, &e));
	printf("Length: %d\n",    printf("%-20S || %-5s%.7s %c |%lx| %20p\n", L"我是一只猫", "haha", "abcdef", 97, 2147483649, &e));
	ft_printf("%.4S\n", L"我是一只猫。");
	printf("%.4S\n", L"我是一只猫。");	
	ft_printf("%15.4S\n", L"我是一只猫。");
	printf("%15.4S\n", L"我是一只猫。");	
	ft_printf("%4.15S\n", L"我是一只猫。");
	printf("%4.15S\n", L"我是一只猫。");
	ft_printf("%4.1S\n", L"Jambon");
	printf("%4.1S\n", L"Jambon");
	return (0);
}
