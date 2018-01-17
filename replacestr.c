/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:51:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/16 11:18:56 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replacestr(char *dest, char *find, char *content)
{
	char	*after_find;
	char	*temp;

	if (!(after_find = ft_strstr(dest, find)))
		return (dest);
	after_find = &after_find[ft_strlen(find)];
	if (!(temp = (char*)malloc(sizeof(char) *
					((ft_strlen(dest) - ft_strlen(find))
					+ ft_strlen(content) + 1))))
		return (0);
	ft_strcat(temp, ft_strndup(dest, ft_strlen(dest)
				- ft_strlen(after_find) - ft_strlen(find)));
	if (content)
		ft_strcat(temp, content);
	else if (find[ft_strlen(find) - 1] == 's')
		ft_strcat(temp, "(null)");
	ft_strcat(temp, after_find);
	dest = temp;
	return (dest);
}
