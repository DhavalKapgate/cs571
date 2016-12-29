import java.io.*;
import java.util.*;
import javax.script.Invocable;
import javax.script.ScriptEngineManager;
import javax.script.ScriptEngine;

class SudokuSolver
{
	public native String SudokuSolve(String input);
	static
	{
		System.loadLibrary("SudokuSolver");
	}
	public static void main(String []args) throws IOException,Exception
	{
		    long start,end,total;
		String[] lang;
		String ret;
		if(args.length==4)
		{
      			SudokuSolver driver = new SudokuSolver();
			lang = args[0].split("=");
			BufferedReader br = new BufferedReader(new FileReader(args[3]));
			BufferedWriter bw = new BufferedWriter(new FileWriter(args[2],true));
			String input = br.readLine();
			System.out.println(lang[1]);
			if(lang[1].equals("c"))
			{
				start = System.currentTimeMillis();
				ret = driver.SudokuSolve(input);
				System.out.println("C Result:");
				System.out.println(ret);
				end = System.currentTimeMillis();
				total = end - start;
				System.out.println("\nTime Taken (C language): "+total+" milli-seconds");
				bw.write("\nC Result:\n\nInput of Sudoku\n"+input+"\nOutput of Sudoku:\n"+ret);
				bw.write("\nTime Taken (C language): "+total+"milliseconds");
				bw.close();
			}
			else if(lang[1].equals("java"))
			{
			        JavaSolver solve = new JavaSolver();
				start = System.currentTimeMillis();
				ret = solve.solve_java(input);
				System.out.println("JAVA RESULT:");
				System.out.println(ret);
				end = System.currentTimeMillis();
				total = end - start;
				System.out.println("\nTime Taken (JAVA language) : "+total+" milli-seconds");
				bw.write("\nJAVA Result:\n\nInput of Sudoku\n"+input+"\nOutput of Sudoku:\n"+ret);
				bw.write("\nTime Taken (JAVA language): "+total+"milliseconds");
                                bw.close();
			}
			else if(lang[1].equals("javascript"))
			{
				String ret_script;
				String conv_ret = "";
				start = System.currentTimeMillis();

				ScriptEngineManager manager = new ScriptEngineManager();
				ScriptEngine engine = manager.getEngineByName("JavaScript");
				if (!(engine instanceof Invocable))
				{
				  System.out.println("Invoking methods is not supported.");
				  return;
				}
				Invocable inv = (Invocable) engine;
				String scriptPath = "sudoscript.js";

				engine.eval("load('" + scriptPath + "')");

				Object sudo = engine.get("sudo");

				ret_script = (String)inv.invokeMethod(sudo,"SudoKiller",input);

				System.out.println("The string returned from JavaScript");
				System.out.println(ret_script);
				end = System.currentTimeMillis();
				total = end - start;

				System.out.println("Total Time in JavaScript : "+(double)(total / 1000)+" seconds");
			}
			else if(lang[1].equals("python"))
			{
				start = System.currentTimeMillis();
				ProcessBuilder pb = new ProcessBuilder("python","hexadoku.py",input);
				Process proc = pb.start();
				BufferedReader in = new BufferedReader(new InputStreamReader(proc.getInputStream()));
				ret = in.readLine();
				end = System.currentTimeMillis();
				total = end - start;
				System.out.println("\nPYTHON Result:\n\nInput of Sudoku\n"+input+"\nOutput of Sudoku:\n"+ret);
				System.out.println("\nTime Taken (PYTHON language): "+total+" milli-seconds");
                                bw.write("\nPYTHON Result:\n\nInput of Sudoku\n"+input+"\nOutput of Sudoku:\n"+ret);
                                bw.write("\nTime Taken (PYTHON language): "+total+"milliseconds");
                                bw.close();
			}
			else if(lang[1].equals("prolog"))
				System.out.println("SORRY WE COULDNT INTEGRATE PROLOG BUT WE DO HAVE THE PROGRAM.");
			else
				System.out.println("Arguments are empty");
	}
}
}
