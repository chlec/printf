/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/14 13:03:02 by clecalie         ###   ########.fr       */
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
	ft_printf("@moulitest: |%5.x| |%5.0x|\n", 0, 0);
	printf("@moulitest: |%5.x| |%5.0x|\n", 0, 0);
	ft_printf("%jx\n", -4294967297);
	printf("%jx\n", -4294967297);	
	return (0);
}
