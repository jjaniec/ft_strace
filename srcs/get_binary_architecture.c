/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary_architecture.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:03:14 by jjaniec           #+#    #+#             */
/*   Updated: 2020/04/17 17:14:36 by jjaniec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_strace.h>

unsigned char	get_binary_architecture(const char *abspath)
{
	int				fd;
	Elf64_Ehdr		hdr;
	unsigned char	elf_class;

	if ((fd = open(abspath, O_RDONLY)) == -1)
	{
		dprintf(STDERR_FILENO, "Failed to open binary\n");
		exit (1);
	}
	if (read(fd, &hdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "File is too short to be in the ELF Format!");
		exit (1);
	}
	if ((elf_class = hdr.e_ident[EI_CLASS]) == ELFCLASSNONE)
	{
		dprintf(STDERR_FILENO, "Invalid ELF class!\n");
		exit(1);
	}
	close(fd);
	return (elf_class);
}
