import java.util.Scanner;
class SalesMan extends HumanBeing implements Worker
{
	public native int my_dijkstras(int distances[][],int num_cities,int src,int dst);
	public native void display(int distance[][]);
	static{System.loadLibrary("dijkstras");}

	public void doWork()
	{
	int N=2000;
	Scanner in=new Scanner(System.in);
	int[][] distance = new int[][]
        		{
        		{0,20,N,80,N,N,90,N},
        		{N,0,N,N,N,10,N,N},
        		{N,N,0,10,N,50,N,20},
        		{N,N,10,0,N,N,20,N},
        		{N,50,N,N,0,N,30,N},
        		{N,N,10,40,N,0,N,N},
        		{20,N,N,N,N,N,0,N},
        		{N,N,N,N,N,N,N,0}
        		};
	System.out.print("\nThe Graph under consideration contains 8 nodes numbered 0-7 (A-H)\n");
	this.display(distance);
	System.out.print("Enter the source and destination respectively:\nSOURCE : ");
	int src=in.nextInt();
	System.out.print("DESTINATION : ");
	int dst=in.nextInt();
	System.out.println();
	int dis=this.my_dijkstras(distance,num_cities,src,dst);	//value of num_cities comes from HumanBeing.java
	if(dis<2000)
		System.out.println("DISTANCE BETWEEN SOURCE AND DESTINATION : "+dis);
	else
		System.out.println("NO PATH BETWEEN SOURCE AND DESTINATION");
	}

	public static void main(String args[]) 
	{
	//System.out.println(num_cities);
	SalesMan man=new SalesMan();
	man.doWork();
	}

}
