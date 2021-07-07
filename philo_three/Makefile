NAME =			philo_three

# SOURCES
SRC =			$(SRC_NAME)
SRC_PATH =		srcs/

SRC_NAME =		main.c init.c parse.c utils.c write.c time.c clean.c controller.c semaphores.c

# HEADER
HEAD_PATH =		inc/

# All .o (object file)
OBJS_PATH =		objs/
OBJS =			$(SRC:%.c=$(OBJS_PATH)%.o)

# Compilation
GCC =			gcc
FSAN =			-fsanitize="address"

# Compilation flags
GCCFLAGS =		-Werror -Wall -Wextra 
# -fsanitize=address


all:			$(OBJS)
				$(GCC) $(GCCFLAGS) $(OBJS) $(LIB) -o $(NAME) -lpthread
				@echo "\033[1;32mDone !\033[m"

fs :			$(OBJS)
				$(GCC) $(GCCFLAGS) $(FSAN) $(OBJS) $(LIB) -o $(NAME)
				@echo "\033[1;32mDone with fsanitize !\033[m"
				
$(NAME):	all

# Getting .o from .c rule
$(OBJS_PATH)%.o: $(SRC_PATH)%.c
				$(GCC) $(GCCFLAGS) -I $(HEAD_PATH) -c $< -o $@

$(OBJS):		$(OBJS_PATH)

$(OBJS_PATH):
				@echo "\033[1;32mCreating objects...\033[m"
				@mkdir $(OBJS_PATH)


fclean:
				rm -rf $(OBJS_PATH) $(NAME)
				@echo "\033[1;31mDeleating all\033[m"
clean:
				@rm -rf $(OBJS_PATH)
				@echo "\033[1;31mDeleting objects\033[m"

re:				fclean all

.PHONY:			all clean fclean re