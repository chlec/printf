/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/29 16:32:44 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*get_flag(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i + 1] == '\0')
		{
			ret = ft_strndup(str, i);
			return (ret);
		}
	}
	ret = ft_strdup(str);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			i;
	char		*flag;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			flag = get_flag(&format[i]);		
		}
	}
}
