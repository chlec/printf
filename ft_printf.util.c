/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:33:57 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/12 12:03:24 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	arg_len(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

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
	
	nb = ft_atoi(ft_strsub(str, 0, 3));
	if (nb > 0x7F && MB_CUR_MAX < 2)
		return (0);
	else if (nb > 0x7FF && MB_CUR_MAX < 3)
		return (0);
	else if (nb > 0xFFFF && MB_CUR_MAX < 4)
		return (0);
	return (1);
}
