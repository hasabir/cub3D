/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasabir <hasabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:56:07 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/27 07:43:33 by hasabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	init_data(t_data *data, char **av)
{
	(data->line) = malloc(sizeof(char *));
	*(data)->line = ft_strdup("");
	(data)->tab_identifier = NULL;
	(data)->identifier = fill_tab_identifier();
	(data)->init_map = ft_strdup("");
	(data)->map = malloc(sizeof(char *));
	(data)->textures = malloc(sizeof(char *) * 7);
	(data)->fd = open(av[1], O_RDONLY);
	if (!data->line || !(data)->textures || !data->map || data->fd < 0)
		exit(1);
}

char	**fill_tab_identifier(void)
{
	char	**identifier;

	identifier = malloc(sizeof(char *) * 7);
	if (!identifier)
		return (NULL);
	identifier[0] = ft_strdup("NO");
	identifier[1] = ft_strdup("SO");
	identifier[2] = ft_strdup("WE");
	identifier[3] = ft_strdup("EA");
	identifier[4] = ft_strdup("F");
	identifier[5] = ft_strdup("C");
	identifier[6] = NULL;
	return (identifier);
}

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free (tab[i]);
	free(tab);
}
