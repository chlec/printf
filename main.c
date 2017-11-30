/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/30 16:43:57 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
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
	char	*flags;

	flags = "sSpdDioOuUxXcC";
	i = 0;
	while (str[i])
	{
		if (ft_strchr(flags, str[i]))
		{
			ret = ft_strndup(str, i + 1);
			return (ret);
		}
		i++;
	}
	ret = ft_strndup(str, i);
	return (ret);
}

char	*ft_replaceflag(char *dest, char *flag, void *content)
{
	char	*after_flag;
	char	*temp;

	if (!(after_flag = ft_strstr(dest, flag)))
		return (dest);
	//simply get the string just after the flag
	after_flag = &after_flag[ft_strlen(flag)];
	if (!(temp = (char*)malloc(sizeof(char) * ((ft_strlen(dest) - ft_strlen(after_flag)) + ft_strlen(content) + 1))))
		return (0);
	//adding the first part without flag and the part after the flag
	ft_strcat(temp, ft_strndup(dest, ft_strlen(dest) - ft_strlen(after_flag) - ft_strlen(flag)));
	//putting content
	ft_strcat(temp, (char*)content);
	//then putting the rest
	ft_strcat(temp, after_flag);
	dest = temp;
	return (dest);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			i;
	char		*flag;
	char		*result;

	if (!format)
		return (0);
	i = 0;
	result = (char*)format;
	va_start(arg, format);
	//get next flag
	while (format[i])
	{
		if (format[i] == '%')
		{
			flag = get_flag((char*)&format[i]);
			//need to find a way to replace char* below by the appropriate type
			result = ft_replaceflag(result, flag, va_arg(arg, char*));
		}
		i++;
	}
	va_end(arg);
	ft_putstr(result);
	return (0);
}

int		main(void)
{
	ft_printf("%s, %s    kdkdk %s ?\n", "salUt", "ca", 4);
	return (0);
}
