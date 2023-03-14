/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:49:15 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/11 15:54:41 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

void check_first_char(char *line)
{
	while (line && *line == ' ')
		line++;
	if (line && *line && *line != '1')
	{
		printf("ERROR_5: map invalid \n");
		exit(1);
	}
}

void	check_first_last_line(char *line)
{
	// printf ("--------> {%s}\n", line);
	while (line && *line == ' ')
		line++;
	while (*line == '1' || *line == ' ')
		line++;
	if (line && *line && *line != '1' && *line != ' ')
	{
		printf("ERROR_4: map invalid \n");
		exit(1);
	}
}

void	check_surroundings_zero(char **map, int i, int j)
{
	if ((!valid_char(map[i][j]) && map[i][j] != ' ')
		|| (map[i][j] == '0' && (!valid_char(map[i][j - 1])
		|| !valid_char(map[i][j + 1])
		|| !valid_char(map[i - 1][j]) || !valid_char(map[i + 1][j]))))
	{
		printf ("ERROR_3: map invalid \n");
		exit (1);
	}
}

void	parse_map(char **map)
{
	int		i;
	int		j;
	int		nbr_player;

	i = 0;
	j = 0;
	nbr_player = 0;
	if (map && *map)
	{
		check_first_char(map[0]);
		check_first_last_line(map[0]);
		while (map[++i] && ft_strcmp(map[i + 1], "\n"))
		{
			j = 0;
			while (map[i][++j] == ' ')
				;
			check_first_char(map[i]);
			remove_space(&map[i]);
			while (map[i][++j])
			{
				if (valid_char(map[i][j]) && map[i][j] != '0' && map[i][j] != '1')
					nbr_player++;
				check_surroundings_zero(map, i, j);
			}
		}
		check_first_last_line(map[i]);
		if (nbr_player != 1)
		{
			printf("ERROR_2: map invalid \n");
			exit(1);
		}
	}
}
