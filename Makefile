NAME		=	push_swap
BONUS_NAME	=	checker

INCLUDES	=	includes/
SRCS_FOLDER	=	sources/
OBJS_FOLDER	=	objects/

SRCS_FILES	=	error.c parse_input.c pile.c print.c swap.c rotate.c push.c \
				solution.c

OBJS		=	$(addprefix $(OBJS_FOLDER),$(SRCS_FILES:.c=.o))
SRCS		=	$(addprefix $(SRCS_FOLDER),$(SRCS_FILES))

LIBFT		=	libft/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g3 -I$(INCLUDES)

.PHONY		=	all clean fclean test re bonus

all: $(NAME)

test: $(NAME)
	./$(NAME)

$(NAME): $(LIBFT) $(OBJS) $(OBJS_FOLDER)main.o
	@echo "\n-----COMPILING PUSH_SWAP-------\n"
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_FOLDER)main.o -Llibft/ -lft -o $(NAME)
	@echo "Executable has been successfully created."

$(BONUS_NAME): $(LIBFT) $(OBJS) $(OBJS_FOLDER)checker.o
	@echo "\n-----COMPILING CHECKER-------\n"
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_FOLDER)checker.o -Llibft/ -lft -o $(BONUS_NAME)
	@echo "Executable has been successfully created."

bonus: $(BONUS_NAME)

$(OBJS_FOLDER)%.o: $(SRCS_FOLDER)%.c Makefile $(INCLUDES)libft.h $(INCLUDES)push_swap.h $(LIBFT)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

$(INCLUDES)libft.h: libft/libft.h
	@echo "------ UPDATING LIBFT HEADER -------\n"
	cp libft/libft.h includes/libft.h

$(LIBFT): $(INCLUDES)libft.h
	@echo "\n-------COMPILING LIBFT--------------\n"
	make -C libft/
	make clean -C libft/
	@echo "\n\n"

clean:
	@echo "\n-------------CLEAN--------------\n"
	make clean -C libft/
	rm -rf $(OBJS) libft.a $(OBJS_FOLDER)main.o
	rm -rf $(OBJS_FOLDER)
	@echo "object files have been removed."

fclean: clean
	@echo "\n-------------FORCE CLEAN--------------\n"
	make fclean -C libft/
	rm -f $(NAME)
	@echo "$(NAME) and object files have been removed."

re: fclean all
