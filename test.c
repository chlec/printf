/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/08 11:45:02 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	setlocale(LC_ALL, "");
	//simple test
	char *s = "225/136/180";
	char **split = ft_strsplit(s, '/');
	int		i;
	i = 0;
	unsigned char nb;
	while (split[i]) {
		nb = (unsigned char)ft_atoi(split[i]);
		write(1, &nb, 1);
		i++;
	}
	//end
	int e = 7;
	printf("%d\n", ft_printf("%24S %-5s%s |%6.4d| %#20X\n", L"我是一只猫。","haha", "bb", 17, &e));
	printf("%d\n",    printf("%24S %-5s%s |%6.4d| %#20X\n", L"我是一只猫。","haha", "bb", 17, &e));
	return (0);
}
