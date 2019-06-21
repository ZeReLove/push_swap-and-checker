CHECKER = checker
PUSH_SWAP = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror -g

SRCDIR = srcs/
OBJDIR = obj/

CH_FILES = checker
CH_SRC = $(addprefix $(SRCDIR), $(addsuffix .c,$(CH_FILES)))
CH_OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(CH_FILES)))

PS_FILES = 	sorting		push_swap 	mediana_functions_for_a \
			mediana_functions_for_b 
PS_SRC = $(addprefix $(SRCDIR), $(addsuffix .c,$(PS_FILES)))
PS_OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(PS_FILES)))

COMMON = 	functions		functions2		functions3 \
			filling_struct	check
COMMON_SRC = $(addprefix $(SRCDIR), $(addsuffix .c,$(COMMON)))
COMMON_OBJ = $(addprefix $(OBJDIR),$(addsuffix .o,$(COMMON)))

LIBFT = ./libft/libft.a 
INCDIR = -I ./includes
LIBLINK = -L ./libft -lft
LIBINC = -I ./libft/includes

all: $(LIBFT) $(CHECKER) $(PUSH_SWAP)

$(LIBFT):
	@make -C ./libft

$(OBJDIR):
	@echo "Creating Push_Swap object files directory..."
	@mkdir $(OBJDIR)
	@echo "Directory created!"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(OBJDIR)
	@$(CC) $(FLAGS) $(INCDIR) $(LIBINC) -c $< -o $@

$(CHECKER): $(CH_OBJ) $(COMMON_OBJ)
	@echo "Compiling checker..."
	@$(CC) $(LIBLINK) -o $(CHECKER) $(CH_OBJ) $(COMMON_OBJ)
	@echo "Checker is compiled!"

$(PUSH_SWAP): $(PS_OBJ) $(COMMON_OBJ)
	@echo "Compiling push_swap..."
	@$(CC) $(LIBLINK) -o $(PUSH_SWAP) $(PS_OBJ) $(COMMON_OBJ)
	@echo "Push_swap is compiled!"

libclean:
	@make clean -C ./libft

clean: libclean
	@echo "Deleting Push_swap object files..."
	@rm -rf $(OBJDIR)
	@echo "Push_swap object files are deleted!"

fclean: clean
	@echo "Deleting push_swap and checker..."
	@rm -rf $(CHECKER) $(PUSH_SWAP)
	@echo "Executable files are deleted!"
	@make fclean -C ./libft
	@echo "Everything is cleaned!"

re: fclean
	@$(MAKE) all