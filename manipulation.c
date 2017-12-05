/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:56:47 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/05 13:59:29 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_0x(char *str)
{
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(str + 3))))
		return (0);
	ft_strcat(ret, "0x");
	ft_strcat(ret, str);
	return (ret);
}
