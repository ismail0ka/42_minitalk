CC=cc
CFLAGS=-Wall -Wextra -Werror -Iheaders
ARCHIVES=ft_printf/libftprintf.a

all: client server

client: client.c $(ARCHIVES)
	$(CC) $(CFLAGS) client.c $(ARCHIVES) -o client

server: server.c $(ARCHIVES)
	$(CC) $(CFLAGS) server.c $(ARCHIVES) -o server

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