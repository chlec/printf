/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_SC.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 10:05:35 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/05 10:08:36 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	manip_SC(char *conversion, char *ret, char *temp)
{
	int				idx;
	int				j;
	int				h;
	unsigned char	nb;

	idx = get_index(conversion, ret);
	j = 0;
	if (idx > -1)
	{
		while ((size_t)j < ft_strlen(conversion))
		{
			if (j == idx)
			{
				h = 0;
				while (ft_isdigit(conversion[idx]) && temp[h])
				{
					if (h % 3 == 0)
					{
						nb = (unsigned char)ft_atoi(ft_strndup(&temp[h], 3));
						if (!(nb >= 224 && !ft_isdigit(conversion[idx + 1])) && !(nb >= 192 && !ft_isdigit(conversion[idx + 1])))
						{
							write(1, &nb, 1);
						}
					}
					h += 3;
					idx++;
				}
				j += 3;
				//printf("J: %d, idx: %d\n", j, idx);
			}
			else
				ft_putchar(conversion[idx++]);
			j++;
		}
	}
	else
		ft_putstr(conversion);
}
