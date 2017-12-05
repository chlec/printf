/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/05 14:12:02 by clecalie         ###   ########.fr       */
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
	char	*flags;

	flags = "sSpdDioOuUxXcC%";
	i = 1;
	while (str[i])
	{
		if (ft_strchr(flags, str[i]) || str[i + 1] == ' ')
		{
			ret = ft_strndup(str, i + 1);
			return (ret);
		}
		i++;
	}
	ret = ft_strdup(str);
	return (ret);
}

char	*replacestr(char *dest, char *flag, void *content)
{
	char	*after_flag;
	char	*temp;

	if (!(after_flag = ft_strstr(dest, flag)))
		return (dest);
	after_flag = &after_flag[ft_strlen(flag)];
	if (!(temp = (char*)malloc(sizeof(char) *
		((ft_strlen(dest) - ft_strlen(after_flag)) + ft_strlen(content) + 1))))
		return (0);
	ft_strcat(temp, ft_strndup(dest, ft_strlen(dest) - ft_strlen(after_flag) - ft_strlen(flag)));
	ft_strcat(temp, (char*)content);
	ft_strcat(temp, after_flag);
	dest = temp;
	return (dest);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	char		*flag;
	char		*conversion;

	if (!format)
		return (0);
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			flag = get_flag((char*)&format[i]);
			conversion = handle_conversion(flag, &args);
			if (conversion)
				format = replacestr((char*)format, flag, conversion);
		}
		i++;
	}
	va_end(args);
	ft_putstr(format);
	return (0);
}
/*
int		main(void)
{
	int e = 7;

	ft_printf("%s, %p %X %u %c?\n", "Salut", &e, 48964, 17u, '\0');
	printf("%-s, %p %X %u %c?\n", "Salut", &e, 48964, 17u, '\0');
	return (0);
}*/
