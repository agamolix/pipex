/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:47:39 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 15:51:04 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child1(t_data *data, int my_pipe[2])
{
	char	**options;

	close(my_pipe[0]);
	if (dup2(data->fd1, 0) == -1)
		exit_mymessage("Dup2 child1 (stdin): unexpected error", data);
	if (dup2(my_pipe[1], 1) == -1)
		exit_mymessage("Dup2 child1 (stdout): unexpected error", data);
	if (dup2(data->fd2, 2) == -1)
		exit_mymessage("Dup2 child1 (stderr): unexpected error", data);
	options = my_split(data->agv[2], ' ');
	if (options == 0)
		exit_mymessage("Options child1: unexpected error", data);
	data->path1 = find_path(data->env, options[0]);
	if (data->path1 == 0)
		exit_errormessage("Error cmd1", data);
	execve(data->path1, options, data->env);
}

void	child2(t_data *data, int my_pipe[2])
{
	char	**options;

	close(my_pipe[1]);
	if (dup2(my_pipe[0], 0) == -1)
		exit_mymessage("Dup2 child2 (stdin): unexpected error", data);
	if (dup2(data->fd2, 1) == -1)
		exit_mymessage("Dup2 child2 (stdout): unexpected error", data);
	if (dup2(data->fd2, 2) == -1)
		exit_mymessage("Dup2 child2 (stderr): unexpected error", data);
	options = my_split(data->agv[3], ' ');
	if (options == 0)
		exit_mymessage("Options child2: unexpected error", data);
	data->path2 = find_path(data->env, options[0]);
	if (data->path2 == 0)
		exit_errormessage("Error cmd2", data);
	execve(data->path2, options, data->env);
}

t_data	*pipex(t_data *data)
{
	int		status;
	pid_t	fork1;
	pid_t	fork2;
	int		my_pipe[2];

	if (pipe(my_pipe) == -1)
		exit_errormessage("Pipe error", data);
	fork1 = fork();
	if (fork1 < 0)
		exit_errormessage("Fork1 error", data);
	if (fork1 == 0)
		child1(data, my_pipe);
	fork2 = fork();
	if (fork2 < 0)
		exit_errormessage("Fork2 error", data);
	if (fork2 == 0)
		child2(data, my_pipe);
	close(my_pipe[0]);
	close(my_pipe[1]);
	waitpid(fork1, &status, 0);
	waitpid(fork2, &status, 0);
	return (data);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	data.agv = argv;
	data.env = envp;
	data.fd1 = -1;
	data.fd2 = -1;
	data.path1 = 0;
	data.path2 = 0;
	if (argc != 5)
		exit_mymessage("Use 4 arguments: file1 cmd1 cmd2 file2", &data);
	data.fd1 = open(argv[1], O_RDONLY);
	if (data.fd1 == -1)
		exit_errormessage("Open file1 error", &data);
	data.fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0640);
	if (data.fd2 == -1)
		exit_errormessage("Open file2 error", &data);
	pipex(&data);
	close_success(&data);
	return (0);
}
