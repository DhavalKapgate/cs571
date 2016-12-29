
section .text
	global_start
_start:
	mov edx,len
	mov ecx,hello
	mov ebx,1
	mov eax,4
	int 0x80
	mov eax,1
	int 0x80

section .data
hello db 'Hello World, this is Dhaval kapgate'
len equ $ - hello
