/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:52:03 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/08 12:17:18 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_end_map(t_data *data)
{
	int	i;

	i = 0;
	while (*data->line && (*data->line)[i] && is_whitespace((*data->line)[i]))
		i++;
	if (*data->line && (*data->line)[i] && (*data->line)[i] != '\n')
		ft_error("ERROR\n");
	else if (*data->line && (*data->line)[i] && (*data->line)[i] == '\n')
		return (1);
	return (0);
}

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
		ft_error("ERROR\n");
}

void	check_first_last_line(char *line)
{
	while (line && *line == ' ')
		line++;
	while (*line == '1' || *line == ' ')
		line++;
	if (line && *line && *line != '1' && *line != ' ')
		ft_error("ERROR\n");
}

void	check_surroundings_zero(char **map, int i, int j)
{
	if ((!valid_char(map[i][j]) && map[i][j] != ' ')
		|| (map[i][j] == '0' && (!valid_char(map[i][j - 1])
		|| !valid_char(map[i][j + 1])
		|| !valid_char(map[i - 1][j]) || !valid_char(map[i + 1][j]))))
		ft_error("ERROR\n");
}
