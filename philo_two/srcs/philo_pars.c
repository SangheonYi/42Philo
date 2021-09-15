/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayi <sayi@student.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 14:14:00 by hmin              #+#    #+#             */
/*   Updated: 2021/02/27 09:40:40 by sayi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

/*
** semaphore_unlink();
**
** To unlink sem files in case of crash before clear_space();
**
** *****************************************************************************
** sem_open("/forks", O_CREAT | O_EXCL, S_IRWXU, info->rules[SUM_PH]);
**
** O_CREAT is specified, and a semaphore with the given name already exists,
** then mode and value are ignored.
**
** O_EXCL are specified in oflag, then an error is returned if a semaphore with
** the given name already exists.
**
** *****************************************************************************
** Note about 'NOT unlinked' sem files related issue
**
** Errno 0 Undefined error: 0. Not used.
**
** Errno 2 ENOENT No such file or directory.  A component of a specified
** pathname did not exist, or the pathname was an empty string.
**
** Errno 17 EEXIST File exists. An existing file was mentioned in an
** inappropriate context, for instance, as the new link name in a link(2)
** function.
**
** O_EXCL
*/

void			semaphore_unlink(void)
{
	sem_unlink("/forks");
	sem_unlink("/write");
	sem_unlink("/l_check");
	sem_unlink("/last_eat");
	sem_unlink("/take");
}

int				init_info(t_info *info)
{
	info->dead_phi = 0;
	info->monitor = NULL;
	semaphore_unlink();
	info->forks = sem_open("/forks", O_CREAT, S_IRWXU, info->rules[SUM_PH]);
	info->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	info->l_check = sem_open("/l_check", O_CREAT, S_IRWXU, 1);
	info->last_eat = sem_open("/last_eat", O_CREAT, S_IRWXU, 1);
	info->take = sem_open("/take", O_CREAT, S_IRWXU, 1);
	return (OK);
}

static int		set_rules(t_info *info, char *argv, int i)
{
	info->rules[i] = ft_atoi(argv);
	if (info->rules[i] < 2)
		return (ERR_N_EN_PHILO);
	return (OK);
}

int				philo_pars(char **argv, t_info *info)
{
	int	i;
	int	status;

	info->rules[T_MST_E] = -1;
	i = 0;
	while (argv[++i])
	{
		status = set_rules(info, argv[i], i - 1);
		if (status)
			return (status);
	}
	if ((status = init_info(info)))
		return (status);
	return (OK);
}
