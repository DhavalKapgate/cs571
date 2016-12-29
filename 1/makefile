all:C CPP JAVA PYTHON JS HASKELL ASM 

C: hello.c
	@echo '1) C:'
	gcc hello.c -o hello
	./hello
	@echo''

CPP: Hello.cpp
	@echo '2) CPP:'
	g++ Hello.cpp -o Hello
	./Hello
	@echo''

JAVA: Hello.java
	@echo '3) JAVA:'
	javac Hello.java
	java Hello
	@echo''

PYTHON: hello.py
	@echo '4) PYTHON:'
	python hello.py
	@echo''

JS: hello.html
	@echo '5) JavaScript'
	firefox hello.html&
	@echo''

HASKELL: hello.hs
	@echo '6) HASKELL:'
	ghc -o hello hello.hs
	./hello
	@echo''

ASM: hello.asm
	@echo '7) ASSEMBLY LANGUAGE(NASM):'
	nasm -f elf64 hello.asm
	ld -s -o hello hello.o 
	./hello
	@echo''
