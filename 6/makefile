all: 2 3
	make 2
	make 3
2: 2.py
	python 2.py
3: swig.c swig.i
	swig2.0 -python swig.i
	gcc -c -fpic swig.c swig_wrap.c -I/usr/include/python2.7
	gcc -shared swig.o swig_wrap.o -o _swig.so
	python
