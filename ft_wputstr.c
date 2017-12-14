/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:05:27 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/14 15:33:31 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*print_size_11(unsigned int c)
{
	unsigned char	b2;
	unsigned char	b1;
	unsigned char	byte;
	char			*ret;

	ret = "";
	b2 = (c << 26) >> 26;
	b1 = ((c >> 6) << 27) >> 27;
	byte = (0xC080 >> 8) | b1;
	//write(1, &byte, 1);
    ret = add_end(ret, ft_itoa(byte));
	byte = (((long)0xC080 << 24) >> 24) | b2;
	//write(1, &byte, 1);
    ret = add_end(ret, ft_itoa(byte));
	return (ret);
}

static char	*print_size_16(unsigned int c)
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
	//write(1, &byte, 1);
    ret = add_end(ret, ft_itoa(byte));
	byte = (((long)0xE08080 << 16) >> 24) | b2;
	ret = add_end(ret, ft_itoa(byte));
	//write(1, &byte, 1);
	byte = (((long)0xE08080 << 24) >> 24) | b3;
	//write(1, &byte, 1);
    ret = add_end(ret, ft_itoa(byte));
	return (ret);
}

static char	*print_size_21(unsigned int c)
{
	unsigned char	b4;
    unsigned char	b3;
    unsigned char	b2;
    unsigned char	b1;
    unsigned char	byte;
	char			*ret;

	ret = "";
    b4 = (c << 26) >> 26;
    b3 = ((c >> 6) << 26) >> 26;
    b2 = ((c >> 12) << 26) >> 26;
    b1 = ((c >> 18) << 29) >> 29;
    byte = (0xF0808080 >> 24) | b1;
    ret = add_end(ret, ft_itoa(byte));
	//write(1, &byte, 1);
    byte = ((0xF0808080 << 8) >> 24) | b2;
 //   write(1, &byte, 1);
    ret = add_end(ret, ft_itoa(byte));
    byte = ((0xF0808080 << 16) >> 24) | b3;
    //write(1, &byte, 1);
   	ret = add_end(ret, ft_itoa(byte));
	byte = ((0xF0808080 << 24) >> 24) | b4;
    //write(1, &byte, 1);
    ret = add_end(ret, ft_itoa(byte));
	return (ret);
}

char		*ft_wputstr(wchar_t *str)
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
			ret = add_end(ret, ft_strlen(ft_itoa(c)) > 2 ? ft_itoa(c) : add_begin(ft_itoa(c), "0") );	
		else if (c <= 0x7FF)
			ret =  add_end(ret, print_size_11(c));
		else if (c <= 0xFFFF)
			ret = add_end(ret, print_size_16(c));
		else if (c <= 0x1FFFFF)
			ret = add_end(ret, print_size_21(c));
		i++;
	}
	return (ret);
}
