all: 1.hs 2.c 3.c
	@ghci
	@gcc -o 2 2.c
	@./2
	@gcc -o 3 3.c
	@./3

1: 1.hs
	@ghci 
		
2: 2.c
	@gcc -o 2 2.c
	@./2

3: 3.c
	@gcc -o 3 3.c
	@./3


	
