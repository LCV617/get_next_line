/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line.c									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ewaltz <ewaltz@student.42.fr>				+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2025/12/05 14:15:18 by ewaltz			   #+#	  #+#			  */
/*	 Updated: 2025/12/11 11:31:41 by ewaltz			  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*rest;
	char			buffer[BUFFER_SIZE + 1];
	char			*ligne;
	int				bytes;
	int				index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (get_index(rest) == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (rest);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			rest = str_join(rest, buffer);
		}
	}
	if (get_index(rest) == -1)
    {
	  index = ft_strlen(rest);
	  ligne = ft_strdup(rest, index);
	  rest = get_rest(rest, index);
    }
	else
	{
	  index = get_index(rest) + 1;
	  ligne = ft_strdup(rest, index);
	  rest = get_rest(rest, index);
	}
	return (ligne);
}
