/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ischmutz <ischmutz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:15:31 by ischmutz          #+#    #+#             */
/*   Updated: 2024/01/04 11:58:57 by ischmutz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	liberator(char **imprisoned_ptr)
{
	if (imprisoned_ptr)
	{
		free(*imprisoned_ptr);
		*imprisoned_ptr = NULL;
	}
}

void	*ft_memset_gnl(void *s, int c, size_t size)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *) s;
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

void	*ft_calloc_gnl(size_t num, size_t size)
{
	void	*buffer;
	size_t	bytesize;

	if (size == 0 || num == 0)
		return (malloc(0));
	bytesize = num * size;
	if (bytesize / num != size || bytesize > 2147483647)
		return (NULL);
	buffer = malloc(bytesize);
	if (buffer == NULL)
		return (NULL);
	ft_memset_gnl(buffer, '\0', bytesize);
	return (buffer);
}

static char	*readme(char **rawstr, int fd)
{
	int		bytes_read;
	char	*tinybuffer;

	tinybuffer = (char *)ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	if (tinybuffer == NULL)
	{
		liberator(rawstr);
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr_gnl(tinybuffer, '\n') && (bytes_read > 0))
	{
		bytes_read = read(fd, tinybuffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (liberator(&tinybuffer), liberator(rawstr), NULL);
		if (bytes_read == 0)
			break ;
		tinybuffer[bytes_read] = '\0';
		*rawstr = ft_strjoin_gnl(*rawstr, tinybuffer);
		if (*rawstr == NULL)
			return (NULL);
	}
	liberator(&tinybuffer);
	return (*rawstr);
}

char	*get_next_line(int fd, int mode)
{
	char		*cookeds;
	char		*tmp;
	static char	*rawstr = NULL;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0 || mode == 1)
		return (free(rawstr), rawstr = NULL, NULL);
	rawstr = readme(&rawstr, fd);
	if (rawstr == NULL)
		return (NULL);
	len = linlen(rawstr);
	cookeds = ft_substr_gnl(rawstr, 0, len);
	if (cookeds == NULL)
		return (liberator(&rawstr), NULL);
	if (((ft_strlen_gnl(rawstr) + 1) - len) > 0)
	{
		tmp = ft_substr_gnl(rawstr, len, ((ft_strlen_gnl(rawstr) + 1) - len));
		if (tmp == NULL)
			return (liberator(&rawstr), liberator(&cookeds), NULL);
		liberator(&rawstr);
		rawstr = tmp;
	}
	else
		liberator(&rawstr);
	return (cookeds);
}

//static variables remember their value, therefore u need to set them to NULL
//after liberatoring them

// ft_substr_gnl(rawstr, len, ((ft_strlen_gnl(rawstr) + 1) - len))

/* void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	size_t	alloc;
	char	*blob;
	size_t	idx;

	alloc = nmemb * size;
	if (alloc != 0 && alloc / nmemb != size)
		return (NULL);
	blob = malloc(alloc);
	if (blob == NULL)
		return (NULL);
	idx = 0;
	while (idx < alloc)
		blob[idx++] = 0;
	return (blob);
} */