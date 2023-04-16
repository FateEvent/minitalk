/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:06:45 by faventur          #+#    #+#             */
/*   Updated: 2022/11/20 18:55:57 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strsub() allocates (with malloc(3)) and returns a "fresh"
** null-terminated copy of the string passed as a parameter. The
** substring starts at the start index and is of length len. If
** start and len don't designate a valid substring, the function
** behaviour is undefined. If the allocation fails, the function
** returns a NULL pointer.
*/

#include "libft.h"

static char	*ft_malloc(char *str, unsigned start, size_t len, size_t size)
{
	if (size - start < len)
		str = (char *)malloc(sizeof(char) * (size - start + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	substr = NULL;
	if (!s)
		return (NULL);
	if (start > s_len)
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	substr = ft_malloc(substr, start, len, s_len);
	if (substr == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
