/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:14:09 by kadjane           #+#    #+#             */
/*   Updated: 2023/03/10 20:05:26 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	nbrword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s && *s)
	{
		while (*s == c || *s == '\n')
			s++;
		if (s && *s)
			i++;
		while (s && *s && *s != c)
			s++;
	}
	return (i);
}

int	lenword(char const *s, char c)
{
	int	i;

	i = 0;
	while (s && *s && *s++ != c)
		i++;
	return (i);
}

void	rempltab(char const *s, char **tabstr, char c)
{
	int	j;
	int	i;
	int	len;

	i = -1;
	len = nbrword(s, c);
	// printf("len == %d\n", len);
	while (++i < len && *s/* && *s != '\n'*/)
	{
		// printf("*s == %s\n", s);
		while (s && *s == c)
			s++;
		if (s && *s)
		{
			*(tabstr + i) = malloc(lenword(s, c) + 1);
			if (!(*(tabstr + i)))
				return ;
		}
		j = -1;
		while (*s && *s != c /*&& *s != '\n'*/)
			tabstr[i][++j] = *s++;
		tabstr[i][++j] = '\0';
		// printf("tabstr[%d] == %s \n", i, tabstr[i]);
	}
	// printf("--------> i == %d\n", i);
	if (c == '\n')
		tabstr[i++] = ft_strdup("\n");
	tabstr[i] = NULL;
	// printf("tabstr[] == %s \n", i, tabstr[i]);
	
}

char	**ft_split(char const *s, char c)
{
	char	**tabstr;

	if (!s)
		return (0);
	// printf("%s\n",s);
	if (c == '\n')
		tabstr = malloc((nbrword(s, c) + 2) * sizeof(char *));
	else
		tabstr = malloc((nbrword(s, c) + 1) * sizeof(char *));
	if (!tabstr)
		return (0);
	rempltab(s, tabstr, c);
	return (tabstr);
}
