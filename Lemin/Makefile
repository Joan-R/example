##
## EPITECH PROJECT, 2023
## B-CPE-200-MAR-2-1-lemin-tom.calogheris
## File description:
## Makefile
##

ET_C =	*.c

SRC = 	src/affichage.c \
		src/algo.c \
		src/ants.c \
		src/base_list.c \
		src/base.c \
		src/change_dist.c \
		src/find_base.c \
		src/free.c \
		src/gestion_erreur.c \
		src/graph.c \
		src/help.c \
		src/linked_list_room.c \
		src/main.c \
		src/memset.c \
		src/my_str_to_words_array.c \
		src/recup_file.c \
		src/room.c \
		src/string.c \
		src/suite_str_to_words_array.c \
		src/tunnel.c \
		src/write.c \
		src/tuyau.c \
		src/tuyau_next.c \
		src/check_garbage.c \

NAME =	lem_in

FLAGS_T =	-g3

FLAGS_K =	-W -Wextra -Wall

FLAGS_J =	-ansi -pedantic -Wuninitialized

all :	tom

tom :
	gcc $(SRC) -o $(NAME) $(FLAGS_T)

kenzo :
	gcc $(SRC) -o $(NAME) $(FLAGS_T) $(FLAGS_K)

joan :
	gcc $(SRC) -o $(NAME) $(FLAGS_T) $(FLAGS_K) $(FLAGS_J)

clean :
	find . -type f \( -name "#*#" -o -name "*~" \) -delete
	rm -f coding-style-reports.log

fclean :	clean
	rm -f $(NAME)

style :	fclean
	coding-style.sh ./ ./
	cat coding-style-reports.log

re :	fclean all
