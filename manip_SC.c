/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_SC.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:05:35 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/05 12:29:47 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_index(const char *haystack, const char *needle)
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

int		not_only_0(char *str)
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

void	manip_SC(char *conversion, char *ret, char *temp)
{
	int				idx;
	int				j;
	int				h;
	int				k;
	unsigned char	nb;

	idx = get_index(conversion, ret);
	j = 0;
	k = 0;
	if (idx > -1 && not_only_0(conversion))
	{
		while ((size_t)j < ft_strlen(conversion))
		{
			if ((j < idx || k > idx) && conversion[j])
				ft_putchar(conversion[j]);
			if (j == idx)
			{
				h = 0;
				k = idx;
				while (ft_isdigit(conversion[k]) && temp[h])
				{
					if (h % 3 == 0)
					{
						nb = (unsigned char)ft_atoi(ft_strndup(&temp[h], 3));
						if (!(nb >= 224 && !ft_isdigit(conversion[k + 1])) && !(nb >= 192 && !ft_isdigit(conversion[k + 1])))	
							write(1, &nb, 1);
					}
					h += 3;
					k++;
				}
				j += ft_strlen(ret) - 1;
			}
			j++;
		}
	}
	else
		ft_putstr(conversion);
}
