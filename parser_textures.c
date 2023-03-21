/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:29:05 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/18 12:54:10 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**split_texture(char *textures)
{
	char	**line;

	line = ft_split_textures(textures);
	if (len_tab(line) != 2)
		ft_error("textures not correct\n");
	return (line);
}

int	parse_textures_2(char **line, t_data **d)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (line && !ft_strcmp(*line, ((*d)->identifier)[i]))
		{
			(*d)->tab_identifier = check_dup((*d)->tab_identifier, *line);
			if (!ft_strcmp(*line, "F") || !ft_strcmp(*line, "C"))
				check_ceiling_floor(*(line + 1));
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
		line = split_texture(texture);
		i = parse_textures_2(line, data);
		if (i == 6)
			ft_error("identifier not exist \n");
	}
	ft_free(line);
}
