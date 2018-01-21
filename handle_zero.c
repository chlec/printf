/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:26:41 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/17 15:20:21 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_temp(char *ret, char **temp)
{
	char	*t;
	char	*t2;
	char	*c;

	c = 0;
	t = ft_strtolower(ret);
	t2 = ft_strtolower("0x");
	if (ft_strncmp(t, t2, 2) == 0)
	{
		*temp = ft_strdup("0x");
		c = ft_strdup(&ret[2]);
	}
	else if (ft_strchr(ret, '-'))
	{
		*temp = ft_strdup("-");
		c = ft_strdup(&ret[1]);
	}
	else if (ft_strchr(ret, '+'))
	{
		*temp = ft_strdup("+");
		c = ft_strdup(&ret[1]);
	}
	else if (ft_strchr(ret, ' '))
	{
		*temp = ft_strdup(" ");
		c = ft_strdup(&ret[1]);
	}
	ft_strdel(&t);
	ft_strdel(&t2);
	if (c)
	{
		ft_strdel(&ret);
		ret = c;
	}
	return (ret);
}

char		*handle_zero(char *flag, char *ret)
{
	int		i;
	int		nb;
	char	*temp;
    
	i = -1;
	temp = 0;
	while (flag[++i])
		if (flag[i] == '0' && !ft_isdigit(flag[i - 1]))
		{
			if (!ft_strchr(flag, '-'))
			{
				nb = ft_atoi(&flag[i + 1]);
				ret = get_temp(ret, &temp);
				while (ft_strlen(ret) + ft_strlen(temp) < (size_t)nb)
					ret = add_begin(ret, ft_strdup("0"));
				if (temp)
					ret = add_begin(ret, temp);
			}
			flag = replacestr(flag, get_0_param(&flag[i]), NULL);
			return (handle_conversion(flag, ret));
		}
	return (0);
}
