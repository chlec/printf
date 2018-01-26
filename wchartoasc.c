/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchartoasc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:05:27 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/25 11:33:13 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Gestion des masques.
** 0XXXXXXX -> Si le caractère est inférieure ou égal à 127
** 110XXXXX 10XXXXXX -> Si le caractère est entre 128 et 2047 (size 11)
** 1110XXXX 10XXXXXX 10XXXXXX -> Si le caractère est entre 2048
** et 65535 (size 16)
** 11110XXX 10XXXXXX 10XXXXXX 10XXXXXX -> Si le caractère est
** entre 65536 et 2097151 (size 21)
**
** Les 3 masques: 0xC080 / 0xE08080 / 0xF0808080
*/

static char	*get_size_11(unsigned int c)
{
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;
	char			*ret;

	ret = ft_strnew(2);
	b2 = (c << 26) >> 26;
	b1 = ((c >> 6) << 27) >> 27;
	byte = (0xC080 >> 8) | b1;
	ret[0] = byte;
	byte = (((long)0xC080 << 24) >> 24) | b2;
	ret[1] = byte;
	return (ret);
}

static char	*get_size_16(unsigned int c)
{
	unsigned char	b3;
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;
	char			*ret;

	ret = ft_strnew(3);
	b3 = (c << 26) >> 26;
	b2 = ((c >> 6) << 26) >> 26;
	b1 = ((c >> 12) << 28) >> 28;
	byte = (0xE08080 >> 16) | b1;
	ret[0] = byte;
	byte = (((long)0xE08080 << 16) >> 24) | b2;
	ret[1] = byte;
	byte = (((long)0xE08080 << 24) >> 24) | b3;
	ret[2] = byte;
	return (ret);
}

static char	*get_size_21(unsigned int c)
{
	unsigned char	b3;
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;
	char			*ret;

	ret = ft_strnew(4);
	b3 = ((c >> 6) << 26) >> 26;
	b2 = ((c >> 12) << 26) >> 26;
	b1 = ((c >> 18) << 29) >> 29;
	byte = (0xF0808080 >> 24) | b1;
	ret[0] = byte;
	byte = ((0xF0808080 << 8) >> 24) | b2;
	ret[1] = byte;
	byte = ((0xF0808080 << 16) >> 24) | b3;
	ret[2] = byte;
	byte = ((0xF0808080 << 24) >> 24) | (c << 26) >> 26;
	ret[3] = byte;
	return (ret);
}

static char	*get_unicode(int c)
{
	char	*ret;

	if (c <= 0x7F)
	{
		ret = ft_strnew(1);
		ret[0] = c;
		return (ret);
	}
	else if ((c >= 0xD800 && c <= 0xDB7F) || (c >= 0xDC00 && c <= 0xDFFF))
		return ("-1");
	else if (c > 0x7F && c <= 0xFF && MB_CUR_MAX == 1)
		return (get_unicode((char)c));
	else if (c > 0x7F && c <= 0xFF && MB_CUR_MAX > 1)
		return (get_size_11(c));
	else if (c <= 0x7FF && MB_CUR_MAX > 1)
		return (get_size_11(c));
	else if (c <= 0xFFFF && MB_CUR_MAX > 2)
		return (get_size_16(c));
	else if (c <= 0xFFFFF && MB_CUR_MAX > 3)
		return (get_size_21(c));
	else
		return ("-1");
}

char		*wchartoasc(wchar_t *str)
{
	int				i;
	int				c;
	char			*ret;
	char			*temp;

	if (!str)
		return (0);
	i = -1;
	ret = ft_strnew(0);
	while (str[++i])
	{
		c = str[i];
		temp = get_unicode(c);
		if (c > 0x0 && !ft_strequ(temp, "-1"))
			ret = add_end(ret, temp);
		else
		{
			ft_strdel(&ret);
			return ("-1");
		}
	}
	return (ret);
}
