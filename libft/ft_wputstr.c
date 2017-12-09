/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:05:27 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/08 11:53:15 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	print_size_11(unsigned int c)
{
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;

	b2 = (c << 26) >> 26;
	b1 = ((c >> 6) << 27) >> 27;
	byte = (0xC080 >> 8) | b1;
	write(1, &byte, 1);
	byte = ((0xC080 << 24) >> 24) | b2;
	write(1, &byte, 1);
}

static void	print_size_16(unsigned int c)
{
	unsigned char	b3;
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;

	b3 = (c << 26) >> 26;
	b2 = ((c >> 6) << 26) >> 26;
	b1 = ((c >> 12) << 28) >> 28;
	byte = (0xE08080 >> 16) | b1;
	write(1, &byte, 1);
	byte = ((0xE08080 << 16) >> 24) | b2;
	write(1, &byte, 1);
	byte = ((0xE08080 << 24) >> 24) | b3;
	write(1, &byte, 1);
}

static void print_size_21(unsigned int c)
{
	unsigned char	b4;
    unsigned char	b3;
    unsigned char	b2;
    unsigned char	b1;
    unsigned char	byte;

    b4 = (c << 26) >> 26;
    b3 = ((c >> 6) << 26) >> 26;
    b2 = ((c >> 12) << 26) >> 26;
    b1 = ((c >> 18) << 29) >> 29;
    byte = (0xF0808080 >> 24) | b1;
    write(1, &byte, 1);
    byte = ((0xF0808080 << 8) >> 24) | b2;
    write(1, &byte, 1);
    byte = ((0xF0808080 << 16) >> 24) | b3;
    write(1, &byte, 1);
    byte = ((0xF0808080 << 24) >> 24) | b4;
    write(1, &byte, 1);
}

void		ft_wputstr(wchar_t *str)
{
	int				i;
	unsigned int	c;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c <= 0x7F)
			write(1, &c, 1);
		else if (c <= 0x7FF)
			print_size_11(c);
		else if (c <= 0xFFFF)
			print_size_16(c);
		else if (c <= 0x1FFFFF)
			print_size_21(c);
		i++;
	}
}
