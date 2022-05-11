/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   close_exit.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: atrilles <atrilles@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/22 17:40:41 by atrilles		  #+#	#+#			 */
/*   Updated: 2022/04/22 17:41:03 by atrilles		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../pipex.h"

void	close_success(t_data *data)
{
	if (data->path1)
		free(data->path1);
	if (data->path2)
		free(data->path2);
	if (data->fd1 != -1)
		close(data->fd1);
	if (data->fd2 != -1)
		close(data->fd2);
}

void	exit_mymessage(char *s, t_data *data)
{
    write(2, s, str_len(s));
    write(2, "\n", 1);
	if (data->path1)
		free(data->path1);
	if (data->path2)
		free(data->path2);
	if (data->fd1 != -1)
		close(data->fd1);
	if (data->fd2 != -1)
		close(data->fd2);
	exit(EXIT_SUCCESS);
}

void	exit_errormessage(char *s, t_data *data)
{
	perror(s);
	if (data->path1)
		free(data->path1);
	if (data->path2)
		free(data->path2);
	if (data->fd1 != -1)
		close(data->fd1);
	if (data->fd2 != -1)
		close(data->fd2);
	exit(EXIT_FAILURE);
}
