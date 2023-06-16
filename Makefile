NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS_1 =   src/push_swap.c

SRCS_2 = src/sort_1.c \
       src/sort_2.c \
       src/sort_3.c \
       src/utils_1.c \
       src/utils_2.c \
       src/utils_3.c \
       src/rules_1.c \
       src/rules_2.c \
       src/rules_3.c

BONUS_SRCS =	src/checker.c \
				src/get_next_line.c



OBJS_1 =  $(SRCS_1:.c=.o)
OBJS_2 =  $(SRCS_2:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

PRINTF_DIR = include/libftprintf
PRINTF = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)

$(NAME): $(OBJS_1) $(OBJS_2) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) -o $(NAME) -L$(PRINTF_DIR) -L$(LIBFT_DIR) -lftprintf -lft

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) $(PRINTF_INC) -c $< -o $@

all: $(NAME) $(BONUS_NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(OBJS_2) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(OBJS_2) -o $(BONUS_NAME) -L$(PRINTF_DIR) -L$(LIBFT_DIR) -lftprintf -lft

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@rm -f $(OBJS_1) $(OBJS_2)
	@rm -f $(BONUS_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
