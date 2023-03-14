/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:29:34 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/09 19:45:24 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parser.h"

int	nbr_word(char const *s)
{
	int	i;

	i = 0;
	while (s && *s)
	{
		while (is_whitespace(*s) || *s == '\n')
			s++;
		if (s && *s)
			i++;
		while (s && *s && !is_whitespace(*s))
			s++;
	}
	return (i);
}

int	len_word(char const *s)
{
	int	i;

	i = 0;
	while (s && *s && !is_whitespace(*s++))
		i++;
	return (i);
}

void	full_tab(char const *s, char **tab_str)
{
	int	j;
	int	i;
	int	len;

	i = -1;
	len = nbr_word(s);
	while (++i < len && *s)
	{
		while (s && is_whitespace(*s))
			s++;
		if (s && *s)
		{
			*(tab_str + i) = malloc(len_word(s) + 1);
			if (!(*(tab_str + i)))
				return ;
		}
		j = -1;
		while (*s && !is_whitespace(*s))
			tab_str[i][++j] = *s++;
		tab_str[i][++j] = '\0';
	}
	tab_str[i] = NULL;
}

char	**ft_split_textures(char const *s)
{
	char	**tab_str;

	if (!s)
		return (0);
	tab_str = malloc((nbr_word(s) + 1) * sizeof(char *));
	if (!tab_str)
		return (0);
	full_tab(s, tab_str);
	return (tab_str);
}
