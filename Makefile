# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abalasub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 13:47:10 by abalasub          #+#    #+#              #
#    Updated: 2024/04/11 20:53:57 by abalasub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/libftprintf.a

SRC = push_swap.c \
      operations.c \
      operations2.c \
      operations3.c  \
      operations4.c   \
      init_stack.c     \
      algo_utils.c      \
      algo_utils2.c      \
      loop.c              \
      closest_bigger.c     \
      closest_smaller.c     \
      turk_algo.c            \
      check_arg.c             \
      rmin_rmax.c              \
	  sorts.c 

OBJS = $(SRC:.c=.o)

NAME_BONUS = checker

SRC_BONUS = test.c      \
	    operations.c \
	    operations2.c \
	    operations3.c  \
	    operations4.c   \
	    init_stack.c     \
	    check_arg.c       \
	    algo_utils.c       \
	    get_next_line.c     \
	    get_next_line_utils.c\

OBJS_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	$(MAKE) --no-print-directory -C ./libft
	echo "=> 𝙇𝙄𝘽𝙁𝙏 𝙀𝙎𝙏 𝘾𝙊𝙈𝙋𝙄𝙇𝙀́  📚"
	$(MAKE) --no-print-directory -C ./ft_printf
	echo "=> 𝙁𝙏_𝙋𝙍𝙄𝙉𝙏𝙁 𝙀𝙎𝙏 𝘾𝙊𝙈𝙋𝙄𝙇𝙀́  📚"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	echo "=> 𝙋𝙐𝙎𝙃_𝙎𝙒𝘼𝙋 𝙀𝙎𝙏 𝙋𝙍𝙀̂𝙏 📊"

bonus: $(NAME_BONUS)

$(NAME_BONUS):$(OBJS_BONUS)
	$(MAKE) --no-print-directory -C ./libft
	echo "=> 𝙇𝙄𝘽𝙁𝙏 𝙀𝙎𝙏 𝘾𝙊𝙈𝙋𝙄𝙇𝙀́  📚"
	$(MAKE) --no-print-directory -C ./ft_printf
	echo "=> 𝙁𝙏_𝙋𝙍𝙄𝙉𝙏𝙁 𝙀𝙎𝙏 𝘾𝙊𝙈𝙋𝙄𝙇𝙀́  📚"
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(FT_PRINTF) -o $(NAME_BONUS)
	echo "=> 𝘾𝙃𝙀𝘾𝙆𝙀𝙍 𝙀𝙎𝙏 𝙋𝙍𝙀̂𝙏 ✅"

clean: 
	$(MAKE) --no-print-directory -C ./libft fclean
	$(MAKE) --no-print-directory -C ./ft_printf fclean
	rm -rf $(OBJS) $(OBJS_BONUS)
	echo "🔴 𝗧𝗢𝗨𝗦 𝗟𝗘𝗦 𝗢𝗕𝗝𝗘𝗧𝗦 𝗢𝗡𝗧 𝗘́𝗧𝗘́ 𝗦𝗨𝗣𝗣𝗥𝗜𝗠𝗘́ 🚮"

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)
	echo "🔴 𝙋𝙐𝙎𝙃_𝙎𝙒𝘼𝙋 𝙀𝙏 𝘾𝙃𝙀𝘾𝙆𝙀𝙍 𝙊𝙉𝙏 𝙀́𝙏𝙀́ 𝙎𝙐𝙋𝙋𝙍𝙄𝙈𝙀́ 🚮"

re: fclean all

.PHONY: all, clean, fclean, re

.SILENT:
