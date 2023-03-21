/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:52:03 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/18 09:04:10 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	else
		return (0);
}

void	check_first_char(char *line)
{
	while (line && *line == ' ')
		line++;
	if (line && *line && *line != '1')
		ft_error("wall not exist in first\n");
}

void	check_first_last_line(char *line)
{
	while (line && *line == ' ')
		line++;
	while (*line == '1' || *line == ' ')
		line++;
	if (line && *line && *line != '1' && *line != ' ')
		ft_error("gap in the floor or ceiling\n");
}

void	check_surroundings_zero(char **map, int i, int j)
{
	if ((!valid_char(map[i][j]) && map[i][j] != ' ')
		|| (map[i][j] == '0' && (!valid_char(map[i][j - 1])
		|| !valid_char(map[i][j + 1])
		|| !valid_char(map[i - 1][j]) || !valid_char(map[i + 1][j]))))
		ft_error("player in the risque\n");
}
