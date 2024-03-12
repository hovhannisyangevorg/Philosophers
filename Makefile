# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gevorg <gevorg@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 14:22:52 by gevorg            #+#    #+#              #
#    Updated: 2024/03/01 18:01:33 by gevorg           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directory names
NAME			= philo
SRC_DIR 		= Src
INC_DIR			= Includes
OBJ_DIR			= Obj

SRCS			= $(wildcard $(SRC_DIR)/*.c)
HEADERS			= $(wildcard $(INC_DIR)/*.h)
OBJS			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
INCS			= -I$(INC_DIR)

CC				= cc 
RM				= rm -rf
THRED_FSAN		= -g3 -fsanitize=address
CFLAGS			= -Wall -Wextra -Werror $(THRED_FSAN)
MK				= mkdir -p
CORE_COUNT 		= $(shell nproc)
ALL			= all
CLEAN		= clean
FCLEAN		= fclean
RE			= re

$(ALL):	$(OBJ_DIR) $(NAME)

$(OBJ_DIR): $(SRC_DIR)
	$(MK) $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS)

$(CLEAN):
	$(RM) $(OBJ_DIR)

$(FCLEAN):			$(CLEAN)
				$(RM) $(NAME)
				
$(RE):				$(FCLEAN) $(ALL)

.PHONY:			$(ALL) $(CLEAN) $(FCLEAN) $(RE)

