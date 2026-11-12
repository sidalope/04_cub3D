/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:30:17 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/12 20:06:40 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* A fatal error not requiring strerror */
void	exit_error(t_game *data, char *error_id)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_id, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	clean_up(data);
	exit(1);
}

/* A fatal error requiring strerror */
void	exit_syserror(t_game *data, char *error_id)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	perror(error_id);
	ft_putstr_fd("\n", STDERR_FILENO);
	clean_up(data);
	exit(1);
}

/* 
* Single entry point for all errors.
* Dispatches to the right handler based on error_code.
*
* Does NOT necessarily exit or clean up.
*/
// void	error(t_game *data, char *context, t_error error_code)
// {
// 	if (error_code == ERR_MALLOC || error_code == ERR_FILEOP)
// 		exit_syserror(context);
// 	else
// 		exit_error(context);
// 	clean_up(data);
// 	exit(1);
// }