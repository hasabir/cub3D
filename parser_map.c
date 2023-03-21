/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:49:15 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/18 09:04:51 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_map(int *i, char **map)
{
	int	j;
	int	nbr_player;

	nbr_player = 0;
	while (map[++(*i)] && ft_strcmp(map[(*i) + 1], "\n"))
	{
		j = 0;
		while (map[*i][++j] == ' ')
			;
		check_first_char(map[*i]);
		remove_space_in_the_end(&map[*i]);
		while (map[*i][++j])
		{
			if (valid_char(map[*i][j])
				&& map[*i][j] != '0' && map[*i][j] != '1')
				nbr_player++;
			check_surroundings_zero(map, *i, j);
		}
	}
	if (nbr_player != 1)
		ft_error("Number player not correct\n");
}

void	parse_map(char **map)
{
	int		i;

	i = 0;
	if (map && *map)
	{
		check_first_char(map[0]);
		check_first_last_line(map[0]);
		check_map(&i, map);
		check_first_last_line(map[i]);
	}
}
