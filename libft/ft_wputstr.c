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

static void	print_size_11(wchar_t c)
{
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;
	int				mask;
	mask = 0xC080;
	b2 = (c << 26) >> 26;
	b1 = ((c >> 6) << 27) >> 27;
	byte = (mask >> 8) | b1;
	write(1, &byte, 1);
	byte = ((mask << 24) >> 24) | b2;
	write(1, &byte, 1);
}

static void	print_size_16(wchar_t c)
{
	unsigned char	b3;
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;
	unsigned int	mask;
	
	mask = 0xE08080;
	b3 = (c << 26) >> 26;
	b2 = ((c >> 6) << 26) >> 26;
	b1 = ((c >> 12) << 28) >> 28;
	byte = (mask >> 16) | b1;
	write(1, &byte, 1);
	byte = ((mask << 16) >> 24) | b2;
	write(1, &byte, 1);
	byte = ((mask << 24) >> 24) | b3;
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
		{

		}	
		i++;
	}
}
