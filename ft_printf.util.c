/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:33:57 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/12 13:00:33 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_flag(char *str)
{
	int		i;
	char	*ret;
	char	*validchar;

	validchar = " +-#0123456789.hljz";
	i = 1;
	while (str[i])
	{
		if (ft_strchr(validchar, str[i]))
			i++;
		else
			return (ft_strndup(str, i + 1));
	}
	ret = ft_strdup(str);
	return (ret);
}

char	*get_length_flag(char *flag)
{
	char	*valid;
	int		i;
	int		j;
	char	*ret;

	ret = 0;
	valid = "hljz";
	i = 0;
	while (!ft_strchr(valid, flag[i]))
		i++;
	if (flag[i])
	{
		j = i;
		while (ft_strchr(valid, flag[j]))
			j++;
		ret = ft_strsub(flag, i, j - i);
	}
	return (ret);
}

int		valid_unicode(char *str)
{
	int		nb;
    char    *t;

    t = ft_strsub(str, 0, 3);
	nb = ft_atoi(t);
    ft_strdel(&t);
	if (nb <= 0x7F && MB_CUR_MAX > 0)
		return (1);
	else if (nb <= 0x7FF && MB_CUR_MAX > 1)
		return (1);
	else if (nb <= 0xFFFF && MB_CUR_MAX > 2)
		return (1);
	else if (nb <= 0x1FFFFF && MB_CUR_MAX > 3)
		return (1);
	return (0);
}
