# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaniec <jjaniec@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/27 18:10:31 by jjaniec           #+#    #+#              #
#    Updated: 2020/04/18 16:42:35 by jjaniec          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_strace

UNAME_S := $(shell uname -s)

SRC_NAME =	main.c \
			show_calls_summary.c \
			resolve_path.c \
			print_syscall_info.c \
			parse_opts.c \
			handle_wait_status.c \
			ft_strerror.c \
			ft_strace.c \
			get_fmt_flags.c \
			format_reg_value.c \
			get_binary_architecture.c \
			str_signo.c

INCLUDES_NAME = ft_strace.h \
				syscall_table_32.h \
				syscall_table_64.h

SRC_DIR = ./srcs/
INCLUDES_DIR = ./includes/
OBJ_DIR = ./objs/

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra # -Werror
DEV_FLAGS = -g # -fsanitize=address -fno-omit-frame-pointer
IFLAGS = -I./ft_printf/includes -I./$(INCLUDES_DIR)
LFLAGS = -L./ft_printf -lftprintf

CFLAGS += $(DEV_FLAGS)
FT_PRINTF_DIR = ./ft_printf
LIBFTPRINTF = $(addprefix $(FT_PRINTF_DIR),"/libftprintf.a")

MAKEFILE_STATUS = $(addprefix $(addprefix $(FT_PRINTF_DIR),"/libft"),"/.makefile_status.sh")

UNAME_S := $(shell uname -s)

define ui_line
	$(MAKEFILE_STATUS) $(1) $(2) || true
endef

all : $(NAME)

$(NAME) : $(LIBFTPRINTF) $(OBJ)
	@cp $(LIBFTPRINTF) ./libftprintf.a
ifeq ($(UNAME_S),Linux)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) $(LIBFTPRINTF) -o $(NAME)
endif
ifeq ($(UNAME_S),Darwin)
	@$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $(NAME)
endif

$(OBJ_DIR)%.o : $(SRC_DIR)%.c includes/ft_strace.h
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $(IFLAGS) $< -o $@ && $(call ui_line, $@, $(NAME))

$(FT_PRINTF_DIR):
	@git clone https://github.com/jjaniec/ft_printf 2> /dev/null || true

$(LIBFTPRINTF): $(FT_PRINTF_DIR)
	make -C $(FT_PRINTF_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(FT_PRINTF_DIR)

fclean: clean
	@make fclean -C $(FT_PRINTF_DIR)
	@rm -f $(NAME)

tests_exec:
	for i in tests/*; do \
		gcc -pthread -m32 -o $$i.32.out $$i; \
		gcc -pthread -m64 -o $$i.64.out $$i; \
	done;

re: fclean all

.PHONY: clean fclean all re tests_exec
