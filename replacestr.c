/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:51:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/19 11:56:44 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replacestr(char *dest, char *find, char *content)
{
	char	*after_find;
	char	*temp;

	if (!(after_find = ft_strstr(dest, find)))
		return (dest);
	after_find = ft_strdup(&after_find[ft_strlen(find)]);
    temp = ft_strnew(0);
	temp = add_end(temp, ft_strndup(dest, ft_strlen(dest)
				- ft_strlen(after_find) - ft_strlen(find)));
	if (content)
		temp = add_end(temp, content);
	else if (find[ft_strlen(find) - 1] == 's')
		temp = add_end(temp, "(null)");
	temp = add_end(temp, after_find);
	dest = ft_strdup(temp);
	ft_strdel(&temp);
	ft_strdel(&find);
	return (dest);
}
