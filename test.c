/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/03 15:49:17 by clecalie         ###   ########.fr       */
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
	ft_printf("{%#.5x}\n", 1);
	printf("{%#.5x}\n", 1);
	ft_printf("%#x\n", 0);
	printf("%#x\n", 0);
	ft_printf("%#.3o\n", 1);
	printf("%#.3o\n", 1);
	ft_printf("{%05.S}\n", L"42 c est cool");
	printf("{%05.S}\n", L"42 c est cool");
	ft_printf("%.c\n", 0);
	printf("%.c\n", 0);
	ft_printf("{%05.c}\n", 0);
	printf("{%05.c}\n", 0);
	ft_printf("%lc\n", L'ÿ≠');
	printf("%lc\n", L'ÿ≠');
	return (0);
}
