remove :
	rm *.class *.h *.so
	
java : SudokuSolver.java JavaSolver.java
	javac SudokuSolver.java
	javah -jni SudokuSolver
	gcc SudokuSolver.c -I/usr/lib/jvm/default-java/include -o libSudokuSolver.so -shared -rdynamic -fPIC -lc
	java -Djava.library.path=. SudokuSolver lang=java -o output.txt input.txt

c : SudokuSolver.java SudokuSolver.c
	javac SudokuSolver.java
	javah -jni SudokuSolver
	gcc SudokuSolver.c -I/usr/lib/jvm/default-java/include -o libSudokuSolver.so -shared -rdynamic -fPIC -lc
	java -Djava.library.path=. SudokuSolver lang=c -o output.txt input.txt
	
javascript :
	javac SudokuSolver.java
	javah -jni SudokuSolver
	gcc SudokuSolver.c -I/usr/lib/jvm/default-java/include -o libSudokuSolver.so -shared -rdynamic -fPIC -lc
	java -Djava.library.path=. SudokuSolver lang=javascript -o output.txt input.txt

python :
	javac SudokuSolver.java
	javah -jni SudokuSolver
	gcc SudokuSolver.c -I/usr/lib/jvm/default-java/include -o libSudokuSolver.so -shared -rdynamic -fPIC -lc
	java -Djava.library.path=. SudokuSolver lang=python -o output.txt input.txt	
