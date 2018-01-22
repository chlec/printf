/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_SC.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:05:35 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/22 13:02:12 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_index(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	if (!needle[0])
		return (-1);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
			return (i);
		i++;
	}
	return (-1);
}

static int	not_only_0(char *str)
{
	int		i;

	if (ft_strlen(str) == 1)
		return (1);
	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

static void	display_unicode(char *conversion, char *temp, int idx)
{
	int				h;
	unsigned char	nb;
	int				k;
    char            *t;

	h = 0;
	k = idx;
	while ((ft_isdigit(conversion[k]) || conversion[k] == '-') && temp[h])
	{
		if (h % 3 == 0)
		{
            t = ft_strndup(&temp[h], 3);
			nb = (unsigned char)ft_atoi(t);
            ft_strdel(&t);
			write(1, &nb, 1);
		}
		h += 3;
		k++;
	}
}

void		manip_sc_up(char *conversion, char *ret, char *temp)
{
	int				idx;
	int				j;

	idx = get_index(conversion, ret);
	//printf("conversion: %s, ret: %s, temp: %s, idx: %d\n", conversion, ret, temp, idx);
	j = -1;
	if (idx > -1 && not_only_0(conversion))
	{
		while ((size_t)++j < ft_strlen(conversion))
		{
			if ((j < idx || j > idx) && conversion[j])
				ft_putchar(conversion[j]);
			if (j == idx)
			{
				display_unicode(conversion, temp, idx);
				j += ft_strlen(ret) - 1;
			}
		}
	}
	else
		ft_putstr(conversion);
}
