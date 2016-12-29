1. THE REPORT FOR THE FIRST QUESTION IS : pl report.docx (Word file)

2.For executing the 2nd question type the command (if only make is typed both questions 2 and 3 are executed respectively) 
	make 2

3.SWIG PROGRAM
For executing the 3rd question typethe command 
	make 3
I have taken 9 cities under consideration.
the distance matrix being:
distances[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

Commands for the swig program:
1)make 3 //(consists of commands till u get to python console)
2)//python console code:
import swig
a =swig.new_arr()
swig.arr_set(a,0,0,0)
swig.arr_set(a,0,1,4)
swig.arr_set(a,0,2,0)
swig.arr_set(a,0,3,0)
swig.arr_set(a,0,4,0)
swig.arr_set(a,0,5,0)
swig.arr_set(a,0,6,0)
swig.arr_set(a,0,7,8)
swig.arr_set(a,0,8,0)
swig.arr_set(a,1,0,4)
swig.arr_set(a,1,1,0)
swig.arr_set(a,1,2,8)
swig.arr_set(a,1,3,0)
swig.arr_set(a,1,4,0)
swig.arr_set(a,1,5,0)
swig.arr_set(a,1,6,0)
swig.arr_set(a,1,7,11)
swig.arr_set(a,1,8,0)
swig.arr_set(a,2,0,0)
swig.arr_set(a,2,1,8)
swig.arr_set(a,2,2,0)
swig.arr_set(a,2,3,7)
swig.arr_set(a,2,4,0)
swig.arr_set(a,2,5,4)
swig.arr_set(a,2,6,0)
swig.arr_set(a,2,7,0)
swig.arr_set(a,2,8,2)
swig.arr_set(a,3,0,0)
swig.arr_set(a,3,1,0)
swig.arr_set(a,3,2,7)
swig.arr_set(a,3,3,0)
swig.arr_set(a,3,4,9)
swig.arr_set(a,3,5,14)
swig.arr_set(a,3,6,0)
swig.arr_set(a,3,7,0)
swig.arr_set(a,3,8,0)
swig.arr_set(a,4,0,0)
swig.arr_set(a,4,1,0)
swig.arr_set(a,4,2,0)
swig.arr_set(a,4,3,9)
swig.arr_set(a,4,4,0)
swig.arr_set(a,4,5,10)
swig.arr_set(a,4,6,0)
swig.arr_set(a,4,7,0)
swig.arr_set(a,4,8,0)
swig.arr_set(a,5,0,0)
swig.arr_set(a,5,1,0)
swig.arr_set(a,5,2,4)
swig.arr_set(a,5,3,0)
swig.arr_set(a,5,4,10)
swig.arr_set(a,5,5,0)
swig.arr_set(a,5,6,2)
swig.arr_set(a,5,7,0)
swig.arr_set(a,5,8,0)
swig.arr_set(a,6,0,0)
swig.arr_set(a,6,1,0)
swig.arr_set(a,6,2,0)
swig.arr_set(a,6,3,14)
swig.arr_set(a,6,4,0)
swig.arr_set(a,6,5,2)
swig.arr_set(a,6,6,0)
swig.arr_set(a,6,7,1)
swig.arr_set(a,6,8,6)
swig.arr_set(a,7,0,8)
swig.arr_set(a,7,1,11)
swig.arr_set(a,7,2,0)
swig.arr_set(a,7,3,0)
swig.arr_set(a,7,4,0)
swig.arr_set(a,7,5,0)
swig.arr_set(a,7,6,1)
swig.arr_set(a,7,7,0)
swig.arr_set(a,7,8,7)
swig.arr_set(a,8,0,0)
swig.arr_set(a,8,1,0)
swig.arr_set(a,8,2,2)
swig.arr_set(a,8,3,0)
swig.arr_set(a,8,4,0)
swig.arr_set(a,8,5,0)
swig.arr_set(a,8,6,6)
swig.arr_set(a,8,7,7)
swig.arr_set(a,8,8,0)
swig.my_dijkstras(a,9,0,8)

