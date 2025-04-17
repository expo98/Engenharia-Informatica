CC = gcc
CFLAGS = -g -pthread


all: mobile_user backoffice_user 5g_auth_platform

mobile_user: mobile_user.o
	$(CC) $(CFLAGS) mobile_user.o -o mobile_user

mobile_user.o: mobile_user.c
	$(CC) $(CFLAGS) -c mobile_user.c -o mobile_user.o

backoffice_user: backoffice_user.o
	$(CC) $(CFLAGS) backoffice_user.o -o backoffice_user

backoffice_user.o: backoffice_user.c
	$(CC) $(CFLAGS) -c backoffice_user.c -o backoffice_user.o

5g_auth_platform: 5g_auth_platform.o
	$(CC) $(CFLAGS) 5g_auth_platform.o -o 5g_auth_platform

5g_auth_platform.o: system_manager.c
	$(CC) $(CFLAGS) -c system_manager.c -o 5g_auth_platform.o
