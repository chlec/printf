/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchartoasc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:05:27 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/08 16:09:02 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_size_11(unsigned int c)
{
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;
	char			*ret;

	ret = "";
	b2 = (c << 26) >> 26;
	b1 = ((c >> 6) << 27) >> 27;
	byte = (0xC080 >> 8) | b1;
	ret = add_end(ret, ft_itoa(byte));
	byte = (((long)0xC080 << 24) >> 24) | b2;
	ret = add_end(ret, ft_itoa(byte));
	return (ret);
}

static char	*get_size_16(unsigned int c)
{
	unsigned char	b3;
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;
	char			*ret;

	ret = "";
	b3 = (c << 26) >> 26;
	b2 = ((c >> 6) << 26) >> 26;
	b1 = ((c >> 12) << 28) >> 28;
	byte = (0xE08080 >> 16) | b1;
	ret = add_end(ret, ft_itoa(byte));
	byte = (((long)0xE08080 << 16) >> 24) | b2;
	ret = add_end(ret, ft_itoa(byte));
	byte = (((long)0xE08080 << 24) >> 24) | b3;
	ret = add_end(ret, ft_itoa(byte));
	return (ret);
}

static char	*get_size_21(unsigned int c)
{
	unsigned char	b3;
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;
	char			*ret;

	ret = "";
	b3 = ((c >> 6) << 26) >> 26;
	b2 = ((c >> 12) << 26) >> 26;
	b1 = ((c >> 18) << 29) >> 29;
	byte = (0xF0808080 >> 24) | b1;
	ret = add_end(ret, ft_itoa(byte));
	byte = ((0xF0808080 << 8) >> 24) | b2;
	ret = add_end(ret, ft_itoa(byte));
	byte = ((0xF0808080 << 16) >> 24) | b3;
	ret = add_end(ret, ft_itoa(byte));
	byte = ((0xF0808080 << 24) >> 24) | (c << 26) >> 26;
	ret = add_end(ret, ft_itoa(byte));
	return (ret);
}

char		*wchartoasc(wchar_t *str)
{
	int				i;
	unsigned int	c;
	char			*ret;

	if (!str)
		return (0);
	i = 0;
	ret = "";
	while (str[i])
	{
		c = str[i];
		if (c <= 0x7F)
			ret = add_end(ret, ft_strlen(ft_itoa(c)) > 2
				? ft_itoa(c) : add_begin(ft_itoa(c), "0"));
		else if (c > 0x7F && c <= 0xFF) {
			if (MB_CUR_MAX > 1)
				ret = add_end(ret, get_size_11(c));
			else
			{
				c = (char)c;
 				write(1, &c, 1);
			}
		}
		else if (c <= 0x7FF && MB_CUR_MAX > 1)
			ret = add_end(ret, get_size_11(c));
		else if (c <= 0xFFFF && MB_CUR_MAX > 2)
			ret = add_end(ret, get_size_16(c));
		else if (c <= 0x1FFFFF && MB_CUR_MAX > 3)
			ret = add_end(ret, get_size_21(c));
		else
			return ("-1");
		i++;
	}
	return (ret);
}
