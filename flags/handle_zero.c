/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:26:41 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/08 13:09:10 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_temp(char *ret, char **temp)
{
	if (ft_strncmp(ft_strtolower(ret), ft_strtolower("0x"), 2) == 0)
	{
		*temp = "0x";
		ret = &ret[2];
	}
	else if (ft_strchr(ret, '-'))
	{
		*temp = "-";
		ret = &ret[1];
	}
	else if (ft_strchr(ret, '+'))
	{
		*temp = "+";
		ret = &ret[1];
	}
	else if (ft_strchr(ret, ' '))
	{
		*temp = " ";
		ret = &ret[1];
	}
	return (ret);
}

char		*handle_zero(char *flag, char *ret)
{
	int		i;
	int		nb;
	char	*temp;
	char	flag_letter;

	i = -1;
	flag_letter = flag[ft_strlen(flag) - 1];
	temp = 0;
	while (flag[++i])
		if (flag[i] == '0' && !ft_isdigit(flag[i - 1]))
		{
			if (!ft_strchr(flag, '-'))
			{
				nb = ft_atoi(&flag[i + 1]);
				ret = get_temp(ret, &temp);
				while (ft_strlen(ret) + ft_strlen(temp) < (size_t)nb)
					ret = add_begin(ret, "0");
				if (temp)
					ret = add_begin(ret, temp);
			}
			flag = replacestr(flag, get_0_param(&flag[i]), "");
			return (handle_conversion(flag, ret));
		}
	return (0);
}
