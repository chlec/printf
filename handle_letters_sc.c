/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_letters_sc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:25:06 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/08 13:29:39 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_s(char *flag, char *ret, char *length_flag, va_list *args)
{
	if (!ft_strcmp(length_flag, "l"))
	{
		flag = replacestr(flag, "s", "S");
		return (handle_other_flags(flag, args));
	}
	else
		ret = va_arg(*args, char*);
	return (ret);
}

char	*handle_c(char *flag, char *ret, char *length_flag, va_list *args)
{
	if (!ft_strcmp(length_flag, "l"))
	{
		flag = replacestr(flag, "c", "C");
		return (handle_other_flags(flag, args));
	}
	else
		ret = ft_ctos(va_arg(*args, int));
	return (ret);
}
