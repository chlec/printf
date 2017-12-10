/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/08 11:45:02 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_precision(char *flag, char *ret)
{
	int		i;
	int		nb;
	char	flag_letter;
	char	*temp;

	i = -1;
	temp = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	while (flag[++i])
		if (flag[i] == '.')
		{
			nb = ft_atoi(&flag[i + 1]);
			if (ft_strchr("diouxX", flag_letter) && nb > 0)
			{
				if (ft_strncmp(ft_strtolower(ret), ft_strtolower("0x"), 2) == 0)
				{
					temp = "0x";
					ret = &ret[2];
				}
				else if (ft_strchr(ret, '-'))
				{
					temp = "-";
					ret = &ret[1];
				}
				else
					temp = "";
				ret = ft_itoa(ft_atoi(ret));
				while (ft_strlen(ret) < (size_t)nb)
					ret = add_begin(ret, "0");
				ret = add_begin(ret, temp);
				flag = replacestr(flag, ft_itoa(ft_atoi(&flag[i + 1])), "");
			}
			else if (ft_strchr("sS", flag_letter)) {

			}
			flag = replacestr(flag, ".", "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}