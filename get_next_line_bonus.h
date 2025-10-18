/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbosnak <bbosnak@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:24:27 by bbosnak           #+#    #+#             */
/*   Updated: 2023/07/27 11:24:30 by bbosnak          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

int		ft_notnewline(char *s);
int		ft_linelen(char *s);
int		ft_strlen(char *s);
char	*ft_strndup(char *save, int len);
char	*save_rest(char *save, int len);
char	*get_next_line(int fd);

#endif
