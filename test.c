/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/07 16:17:27 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	setlocale(LC_ALL, "");
	int e = 7;
	unsigned char c;
    c = 0xc6;
    write(1, &c, 1);
    c = 0xb7;
    write(1, &c, 1);
	printf("%d\n", ft_printf("%S %-5 s% s |%022+d| %-15#p\n", L"tሴst","haha", "bb", -4, &e));
	printf("%d\n",    printf("%S %-5 s% s |%022+d| %-15#p\n", L"tሴst","haha", "bb", -4, &e));
	return (0);
}
