/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:29:34 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/08 09:53:30 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	nbr_word(char const *s)
{
	int		i;

	i = 0;
	while (is_whitespace(*s) || *s == '\n')
		s++;
	if (s && *s)
	{
		i++;
		while (s && *s && !is_whitespace(*s))
			s++;
		while (is_whitespace(*s) || *s == '\n')
			s++;
		if (s && *s)
			i++;
	}
	return (i);
}

int	len_word(char *s, int k)
{
	int	i;

	i = 0;
	if (k == 0)
		while (s && *s && !is_whitespace(*s++))
			i++;
	else
		return (ft_strlen(s));
	return (i);
}

void	full_str(int *i, t_data *data, char *s, char **tab_str)
{
	int	j;
	int	len;
	int	flag;

	flag = 0;
	if (s && s[data->itr])
	{
		len = len_word(&(s[data->itr]), data->nbr);
		*(tab_str + *i) = malloc(len + 1);
		if (!(*(tab_str + *i)))
			return ;
		j = -1;
		while (s && s[data->itr] && s[data->itr] != '\n'
			&& !is_whitespace(s[data->itr]) && !(data->nbr))
			tab_str[*i][++j] = s[(data->itr)++];
		while (s && s[data->itr] && s[data->itr] != '\n' && data->nbr)
			tab_str[*i][++j] = s[(data->itr)++];
		tab_str[*i][++j] = '\0';
		remove_space_in_the_end(&tab_str[*i], flag);
	}
}

void	full_tab(char *s, char **tab_str, t_data *data)
{
	int	i;
	int	nbr;

	i = -1;
	data->itr = 0;
	data->nbr = 0;
	nbr = nbr_word(s);
	while (++i < nbr && s[data->itr])
	{
		while (s && is_whitespace(s[data->itr]))
			data->itr++;
		full_str(&i, data, s, tab_str);
		data->nbr++;
	}
	tab_str[i] = NULL;
}

char	**ft_split_textures(char *s, t_data *data)
{
	char	**tab_str;

	if (!s)
		return (0);
	tab_str = malloc((nbr_word(s) + 1) * sizeof(char *));
	if (!tab_str)
		return (0);
	full_tab(s, tab_str, data);
	return (tab_str);
}
