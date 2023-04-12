/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:49:15 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/10 11:32:12 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_surroundings_player(char **map, int i, int j)
{
	if (!map[i][j + 1] || map[i][j - 1] == ' '
		|| map[i - 1][j] == ' ' || !map[i - 1][j]
		|| map[i][j + 1] == ' ' || !map[i + 1][j] || map[i + 1][j] == ' ')
		ft_error("ERROR\n");
}

void	check_map(int *i, char **map, int nbr_player)
{
	int	j;

	while (map[++(*i)] && ft_strcmp(map[(*i) + 1], "\n"))
	{
		j = 0;
		while (map[*i][j] && map[*i][j] == ' ')
			j++;
		if (!map[*i][j] || (map[*i][j]
			&& is_whitespace(map[*i][j]) && map[*i][j] != ' '))
			break ;
		check_first_char(map[*i]);
		remove_space_in_the_end(&map[*i], 1);
		while (map[*i][++j])
		{
			if (valid_char(map[*i][j])
				&& map[*i][j] != '0' && map[*i][j] != '1')
			{
				check_surroundings_player(map, *i, j);
				nbr_player++;
			}
			check_surroundings_zero(map, *i, j);
		}
	}
	if (nbr_player != 1)
		ft_error("ERROR\n");
}

void	parse_map(char **map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (map && *map)
	{
		check_first_char(map[0]);
		check_first_last_line(map[0]);
		check_map(&i, map, 0);
		while (map[i] && map[i][j] && is_whitespace(map[i][j]))
			j++;
		if ((map[i] && !map[i][j]) ||
			(map[i] && (map[i][j] && map[i][j] == '\n')))
		{
			check_first_last_line(map[i - 1]);
			check_end(map, &i);
		}
		else
		{
			check_first_last_line(map[i]);
			check_end(map, &i);
		}
	}
}
