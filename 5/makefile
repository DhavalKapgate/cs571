all: SalesMan.java HumanBeing.java Worker.java my_dijkstras.cpp
	javac SalesMan.java
	javah -jni SalesMan	
	g++ my_dijkstras.cpp -I/usr/lib/jvm/default-java/include -o libdijkstras.so -shared -rdynamic -fPIC -lc
	java -Djava.library.path=. SalesMan

clean: 
	-rm HumanBeing.class
	-rm libdijkstras.so
	-rm SalesMan.h
	-rm Worker.class
	-rm SalesMan.class
