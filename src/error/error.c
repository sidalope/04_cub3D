/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abisiani <abisani@student.42berlin.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:30:17 by abisiani          #+#    #+#             */
/*   Updated: 2026/11/12 16:24:08 by abisiani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* A fatal error not requiring strerror */
static void	exit_error(char *context)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(context, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

/* A fatal error requiring strerror */
static void	exit_syserror(char *context)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	perror(context);
	ft_putstr_fd("\n", STDERR_FILENO);
}

/* 
* Single entry point for all errors.
* Dispatches to the right handler based on error_code.
*
* Does NOT necessarily exit or clean up.
*/
void	error(t_game *data, char *context, t_error error_code)
{
	if (error_code == ERR_MALLOC || error_code == ERR_FILEOP)
		exit_syserror(context);
	else
		exit_error(context);
	clean_up(data);
	exit(1);
}

// Might ultimately be best to only have fatal and non-fatal error 
// funtions, and distinguish them by their printouts.
// Is error handling behaviour always going to be fatal?
// Might actually be better to simply have exit errors for perror-setting 
// 		and non-perror-setting error codes

// static void	syscall_error_handler(t_game *data, char *context)
// {
// 	ft_putstr_fd("Error: syscall: ", STDERR_FILENO);
// 	perror(context);
// 	clean_up(data);
// 	exit(ERR_MALLOC + 1);
// }

// static void	fileop_error_handler(t_game *data, char *context)
// {
// 	ft_putstr_fd("Error: File operation: ", STDERR_FILENO);
// 	perror(context);
// 	clean_up(data);
// 	exit(ERR_FILEOP + 1);
// }
