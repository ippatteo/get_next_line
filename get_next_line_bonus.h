/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcamilli <mcamilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 08:46:49 by mcamilli          #+#    #+#             */
/*   Updated: 2023/05/25 08:48:15 by mcamilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s, char *b);
char	*ft_strchr(char *s, int c);
char	*risultato(char *s);
char	*ft_read_file(int fd, char *stash);
char	*next(char *s);
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dest, char *source, size_t n);

#endif
