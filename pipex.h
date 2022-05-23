/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:59:27 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 16:01:47 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h> 
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_data {
	int			fd1;
	int			fd2;
	char		*path1;
	char		*path2;
	char		**agv;
	char		**env;
}				t_data;

// pipex
void	child1(t_data *data, int my_pipe[2]);
void	child2(t_data *data, int my_pipe[2]);
t_data	*pipex(t_data *data);
int		main(int argc, char **argv, char **envp);

// paths
char	**find_paths(char **envp);
char	**modify_paths(char **paths);
char	*find_right_path(char **paths, char *cmd);
char	*find_path(char **envp, char *cmd);

// close_exit
void	close_success(t_data *data);
void	exit_mymessage(char *s, t_data *data);
void	exit_errormessage(char *s, t_data *data);

// functions
int		str_len(char const *str);
char	*str_join(char *s1, char *s2);
char	*emptystr(void);
char	*sub_str(char const *s, unsigned int start, size_t len);
int		str_n_cmp(const char *s1, const char *s2, size_t n);

// split
char	*line(char const *str, char c);
char	*forward(char const *str, char c);
int		count(char const *str, char c);
char	**my_split(char const *s, char c);

#endif