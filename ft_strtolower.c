/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:05:50 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/19 11:49:37 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtolower(char *str)
{
	int		i;
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(str))))
		return (0);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		if (str[i] >= 'A' && str[i] <= 'Z')
			ret[i] += 32;
		i++;
	}
	return (ret);
}
