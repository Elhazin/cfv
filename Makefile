NAME:= minishell
EXE := minishell
src = lxr.c pars.c main.c syntax_error.c expand.c leacks_cheker_ex.c execution.c lexer_utils.c signals.c
OBJ = $(src:.c=.o)
INC_DIR := include
CC := cc
LDFLAGS ?= -lreadline -L /Users/abouzanb/goinfre/homebrew/Cellar/readline/8.2.1/lib 
CFLAGS ?=  -I$(INC_DIR) -I /Users/abouzanb/goinfre/homebrew/Cellar/readline/8.2.1/include


all : $(NAME)

$(NAME): minishell
HEADERS := 	$(INC_DIR)/minishell.h\

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

# Objects ========================================

OBJS := $(src:.c=.o)

# Recipes ========================================

minishell : $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $(EXE) -lreadline



clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -rf $(NAME)

re:		fclean all
