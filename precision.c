/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:20:30 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/12 14:39:58 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*remove_0(char *flag)
{
	int		i;

	i = 0;
	while (flag[i])
	{
		if (flag[i] == '0' && !ft_isdigit(flag[i - 1]))
			flag = replacestr(flag, "0", "");
		i++;
	}
	return (flag);
}

char	*handle_precision(char *flag, char *ret)
{
	int		i;
	int		nb;
	char	flag_letter;
	char	*temp;

	i = -1;
	temp = "";
	flag_letter = flag[ft_strlen(flag) - 1];
	while (flag[++i])
		if (flag[i] == '.')
		{
			nb = ft_atoi(&flag[i + 1]);
			flag = remove_0(flag);
			if (ft_strchr("diouxX", flag_letter) && nb > 0)
			{
				if (ft_strncmp(ft_strtolower(ret), ft_strtolower("0x"), 2) == 0)
				{
					temp = add_begin(temp, "0x");
					ret = &ret[2];
				}
				else if (ft_strchr(ret, '-'))
				{
					temp = add_begin(temp, "-");
					ret = &ret[1];
				}
				ret = ft_itoa(ft_atoi(ret));
				while (ft_strlen(ret) < (size_t)nb)
					ret = add_begin(ret, "0");
				ret = add_begin(ret, temp);
				flag = replacestr(flag, ft_itoa(nb), "");
			}
			else if (ft_strchr("sS", flag_letter)) {

			}
			flag = replacestr(flag, ".", "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}
