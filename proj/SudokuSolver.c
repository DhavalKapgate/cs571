#include <stdio.h>
#include <time.h>
#include <jni.h>
#include "SudokuSolver.h"

int isAvailable(int sudoku[][16], int row, int col, int num)
{
	int RStart = (row/4) * 4;
    	int CStart = (col/4) * 4;
    	int i, j;
    	for(i=0; i<16; ++i)
    	{
        	if (sudoku[row][i] == num) return 0;
        	if (sudoku[i][col] == num) return 0;
        	if (sudoku[RStart + (i%4)][CStart + (i/4)] == num) return 0;
    	}
    	return 1;
}

int fillSudoku(int sudoku[][16], int row, int col)
{
    	int i;
    	if(row<16 && col<16)
    	{
        	if(sudoku[row][col] != -1)
     		{
            		if((col+1)<16) return fillSudoku(sudoku, row, col+1);
            		else if((row+1)<16) return fillSudoku(sudoku, row+1, 0);
            		else return 1;
        	}
        	else
        	{
			for(i=0; i<16; ++i)
            		{
                		if(isAvailable(sudoku, row, col, i))
                		{
                    			sudoku[row][col] = i;
                    			if((col+1)<16)
                    			{
                        			if(fillSudoku(sudoku, row, col +1)) return 1;
                        			else sudoku[row][col] = -1;
                    			}
                    			else if((row+1)<16)
                    			{
                        			if(fillSudoku(sudoku, row+1, 0)) return 1;
                        			else sudoku[row][col] = -1;
                    			}
                    			else return 1;
                		}
            		}
        	}
        	return 0;
    	}
    	else return 1;
}

JNIEXPORT jstring JNICALL Java_SudokuSolver_SudokuSolve(JNIEnv *env, jobject o,jstring inp)
{
    	int i,j;
	const char *input = (*env)->GetStringUTFChars( env, inp , NULL );
	char ret[256];
	int sudoku[16][16];
	int count = 0;
	for(i=0;i<16;i++)
	{
		for(j=0;j<16;j++)
		{
			if(input[count] == '.')
			{
				sudoku[i][j] = -1;
			}
			else if(input[count] == 'A')
			{
				sudoku[i][j] = 10;
			}
			else if(input[count] == 'B')
			{
				sudoku[i][j] = 11;
			}
			else if(input[count] == 'C')
			{
				sudoku[i][j] = 12;
			}
			else if(input[count] == 'D')
			{
				sudoku[i][j] = 13;
			}
			else if(input[count] == 'E')
			{
				sudoku[i][j] = 14;
			}
			else if(input[count] == 'F')
			{
				sudoku[i][j] = 15;
			}
			else
			{
				sudoku[i][j] = input[count]-'0';
			}
			count++;
		}
	}
	count = 0;
	if(fillSudoku(sudoku, 0, 0))
    	{
		for(i=0;i<16;i++)
		{
			for(j=0;j<16;j++)
			{
				if(sudoku[i][j] == 10)
				{
					ret[count] = 'A';
				}
				else if(sudoku[i][j] == 11)
				{
					ret[count] = 'B';
				}
				else if(sudoku[i][j] == 12)
				{
					ret[count] = 'C';
				}
				else if(sudoku[i][j] == 13)
				{
					ret[count] = 'D';
				}
				else if(sudoku[i][j] == 14)
				{
					ret[count] = 'E';
				}
				else if(sudoku[i][j] == 15)
				{
					ret[count] = 'F';
				}
				else
				{
					ret[count] = sudoku[i][j] + '0';
				}
				count++;
			}
		}
    	}
    	else printf("\n\nNO SOLUTION\n\n");
	return (*env)->NewStringUTF(env, ret);
}

//http://codereview.stackexchange.com/questions/37430/sudoku-solver-in-c

/*
The jstring type represents strings in the Java virtual machine, and is different from the regular C string type (a pointer to characters, char *).  So we cannot use a jstring as a normal C string. We must use the appropriate JNI functions to convert jstring objects to C/C++ strings.  The JNI supports conversion both to and from Unicode and UTF-8 strings. Unicode strings represent characters as 16-bit values, whereas UTF-8 strings use an encoding scheme that is upward compatible with 7-bit ASCII strings. UTF-8 strings act like NULL-terminated C strings.

jstring, which requires a subroutine call to in order to convert a Java Unicode string (2 bytes) to a C-style char* string (1 byte UTF-8 format).

To convert a jstring to a C-style string, you might write code like the following:

1
2
3
4
5
6
7
8
9
JNIEXPORT void JNICALLJava_MyJavaClass_printName(JNIEnv *env, jobject obj,
	jstring name)
{
	const char *str= (*env)->GetStringUTFChars(env,name,0);
	printf(“%s”, str);
	//need to release this string when done with it in order to
	//avoid memory leak
	(*env)->ReleaseStringUTFChars(env, name, str);
}
To convert a C-style string to jstring , you can use the (*env)->NewStringUTF() function to create a new jstring from a C-style string. For example, a C function that needs to return a Java string could contain the following code:

1
2
3
4
JNIEXPORT jstring JNICALLJava_MyJavaClass_getName(JNIEnv *env, jobject obj)
{
	return (*env)->NewStringUTF(env, “Electrofriends.com”)

*/
