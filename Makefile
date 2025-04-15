CC=cc
CFLAGS=-Wall -Wextra -Werror
ARCHIVES=libprint.a

all: client server

client: client.c $(ARCHIVES)
	$(CC) $(CFLAGS) -o client client.c

server: server.c $(ARCHIVES)
	$(CC) $(CFLAGS) -o server server.c

$(ARCHIVES):
	$(MAKE) -C ft_printf

clean:
	$(MAKE) -C ft_printf clean
	rm -f client server
	rm -f $(ARCHIVES)

fclean: clean
	$(MAKE) -C ft_printf fclean
	rm -f client server
	rm -f $(ARCHIVES)

re: fclean all

.PHONY: all clean fclean re