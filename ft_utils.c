/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:18:52 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/17 17:48:14 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_atoi(const char	*str)
{
	unsigned int	cmp;
	int				n;

	cmp = 0;
	n = 1;
	while (*(str))
	{
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
		if (*str == '+' || *str == '-')
		{
			if (*str++ == '-')
				n = -1;
		}
		while (*str >= '0' && *str <= '9')
		{
			cmp = (cmp * 10) + (*str++ - '0');
			if (n > 0 && cmp > 2147483647)
				return (-1);
			if (n < 0 && cmp > 2147483648)
				return (0);
		}
		return (n * cmp);
	}
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
		return (s1[i] - s2[i]);
	}
	else
		return (0);
}

int	ft_isum(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

void	remove_space_in_the_end(char **line)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;
	char	*line_without_space;

	i = 0;
	j = 0;
	tmp = *line;
	while (tmp && tmp[ft_strlen(tmp) - (++i)] == ' ')
		j++;
	i = 0;
	line_without_space = malloc(ft_strlen(tmp) - j + 1);
	len = (ft_strlen(tmp) - j);
	while (tmp && *tmp && i < len)
		line_without_space[i++] = *tmp++;
	line_without_space[i] = '\0';
	free(*line);
	*line = line_without_space;
}

void	ft_error(char *error)
{
	write (1, "ERROR :", 7);
	write (1, error, ft_strlen(error));
	exit(1);
}
