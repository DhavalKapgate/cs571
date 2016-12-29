import java.io.*;
import java.util.*;

public class JavaSolver
{
	public static int isAvailable(int puzzle[][],int row,int col,int num){
		int rowStart = (row/4) * 4;
		int colStart = (col/4) * 4;

		for(int i=0; i<16; ++i){
			if (puzzle[row][i] == num) return 0;
			if (puzzle[i][col] == num) return 0;
			if (puzzle[rowStart + (i%4)][colStart + (i/4)] == num) return 0;
		}
		return 1;
	}

	public static int fillSudoku(int puzzle[][],int row,int col){
		if(row<16 && col<16){

			if(puzzle[row][col]!= -1){
				if((col+1)<16) return fillSudoku(puzzle, row, col+1);
				else if((row+1)<16) return fillSudoku(puzzle, row+1, 0);
				else return 1;
			}
			else{
				for(int i=0; i<16; ++i)
				{
					if(isAvailable(puzzle, row, col, i) != 0)
					{
						puzzle[row][col] = i;
						if((col+1)<16)
						{
							if(fillSudoku(puzzle, row, col +1) != 0) return 1;
							else puzzle[row][col] = -1;
						}
						else if((row+1)<16)
						{
							if(fillSudoku(puzzle, row+1, 0) != 0) return 1;
							else puzzle[row][col] = -1;
						}
						else return 1;
					}
				}
			}
			return 0;
		}
	else return 1;
	}
	public static String solve_java(String puzzle){
		String[] inp = puzzle.split("");
		int[][] sudoku = new int[16][16];
		int count = 0;
		String ret_str = "";
		for(int i=0;i<16;i++){
			for(int j=0;j<16;j++){
					if(inp[count].equals(".")){
						sudoku[i][j] = -1;
					}
					else if(inp[count].equals("A")){
						sudoku[i][j] = 10;
					}
					else if(inp[count].equals("B")){
						sudoku[i][j] = 11;
					}
					else if(inp[count].equals("C")){
						sudoku[i][j] = 12;
					}
					else if(inp[count].equals("D")){
						sudoku[i][j] = 13;
					}
					else if(inp[count].equals("E")){
						sudoku[i][j] = 14;
					}
					else if(inp[count].equals("F")){
						sudoku[i][j] = 15;
					}
					else{
						sudoku[i][j] = Integer.parseInt(inp[count]);
					}
					count++;				
				
			}
		}
		
		// for(int i=0;i<16;i++){
			// for(int j=0;j<16;j++){
				
				// System.out.print(sudoku[i][j]);				
				
			// }
		// }
		
		
		if(fillSudoku(sudoku,0,0) != 0){
			
			// for(int y = 0; y < 16; y++){
				// for(int x = 0; x < 16; x++){

					// if(sudoku[y][x] >= 10){
						// System.out.print(Character.toChars(65 + (sudoku[y][x] - 10)));
					// }

					// else{
						// System.out.print(sudoku[y][x]);
					// }
						
				// }
			// }
			
			// System.out.println();
			// System.out.println("END in JAVA");

			for(int i=0;i<16;i++){
				for(int j=0;j<16;j++){

					if(sudoku[i][j] == 10){
						ret_str+= 'A';				
					}
					else if(sudoku[i][j] == 11){
						ret_str+= 'B';				
					}
					else if(sudoku[i][j] == 12){
						ret_str+= 'C';				
					}
					else if(sudoku[i][j] == 13){
						ret_str+= 'D';				
					}
					else if(sudoku[i][j] == 14){
						ret_str+= 'E';				
					}
					else if(sudoku[i][j] == 15){
						ret_str+= 'F';				
					}
					else{
						ret_str+= Integer.toString(sudoku[i][j]);
					}

				}	
			}
		}
		
		else{
			System.out.println("NO SOLUTION");
			ret_str = null;
		}
		
	return ret_str;
	
	}
}
