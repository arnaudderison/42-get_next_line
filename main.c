/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:33:17 by arnaud            #+#    #+#             */
/*   Updated: 2023/12/11 14:02:30 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

void	main(void)
{
	int	fd_test;
	int	fd_file;

	fd_test = open("./test", O_RDONLY);
	fd_file = open("./file", O_RDONLY);
	printf("%s", get_next_line(fd_test));
	printf("%s", get_next_line(fd_file));
	printf("%s", get_next_line(fd_test));
	printf("%s", get_next_line(fd_file));
	printf("%s", get_next_line(fd_test));
	printf("%s", get_next_line(fd_file));
	printf("%s", get_next_line(fd_test));
	printf("%s", get_next_line(fd_file));
	close(fd_test);
}
