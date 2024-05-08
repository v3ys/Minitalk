NAME = serverclient.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_printf/libftprintf.a

CLIENT = client
SERVER = server

SRCS = server.c client.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SERVER) $(CLIENT) $(OBJS)

$(SERVER): $(OBJS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) server.c $(PRINTF) -o $@

$(CLIENT): $(OBJS)
	$(CC) $(CFLAGS) client.c $(PRINTF) -o $@
	@echo "\033[33m             _       _ _        _ _    "
	@echo "\033[33m  _ __ ___ (_)_ __ (_) |_ __ _| | | __"
	@echo "\033[33m | '_ \` _ \| | '_ \| | __/ _\` | | |/ /"
	@echo "\033[34m | | | | | | | | | | | || |_| | |   < "
	@echo "\033[34m |_| |_| |_|_|_| |_|_|\__\__,_|_|_|\_\\"
	@echo "\033[0m"


clean:
	make clean -C ./ft_printf
	rm -rf $(SERVER) $(CLIENT) $(OBJS)

fclean: clean
	make fclean -C ./ft_printf

re: fclean all

.PHONY: all clean fclean re 
