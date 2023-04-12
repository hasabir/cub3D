/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:05 by kadjane           #+#    #+#             */
/*   Updated: 2023/04/08 12:18:11 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**split_texture(char *textures, t_data *data)
{
	char	**line;

	line = ft_split_textures(textures, data);
	if (len_tab(line) != 2)
		ft_error("ERROR\n");
	return (line);
}

void	ft_check_path(char **path)
{
	int		fd;
	int		nbr;
	char	buff[2];

	fd = open(*(path + 1), O_RDONLY);
	if (fd < 0 || !check_file_name(*(path + 1), ".xpm"))
		ft_error("ERROR\n");
	nbr = read(fd, buff, 1);
	if (nbr == 0 || nbr < 0)
		ft_error("ERROR\n");
	close(fd);
}

int	parse_textures_2(char **line, t_data **data)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (line && !ft_strcmp(*line, ((*data)->identifier)[i]))
		{
			(*data)->tab_identifier
				= check_dup((*data)->tab_identifier, *line);
			if (!ft_strcmp(*line, "F") || !ft_strcmp(*line, "C"))
				check_ceiling_floor((line), *data);
			else
				ft_check_path(line);
			break ;
		}
	}
	return (i);
}

void	parse_texture(t_data **data)
{
	char	**line;
	char	*texture;
	int		i;

	i = -1;
	line = NULL;
	texture = *(*data)->line;
	if (texture)
	{
		while (is_whitespace(*texture))
			texture++;
		line = split_texture(texture, *data);
		i = parse_textures_2(line, data);
		if (i == 6)
			ft_error("ERROR\n");
	}
	ft_free(line);
}
