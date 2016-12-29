#include<iostream>
#include<limits>
#include<jni.h>
#include "SalesMan.h"
#include <stdlib.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
int my_dijkstras(int **distances,int num_cities, int src, int dst)
{
        int *min_dist,*tree;
        int infinity=numeric_limits<int>::max();
        min_dist=(int*)malloc(num_cities*sizeof(int));
        tree=(int*)malloc(num_cities*sizeof(int));
        for(int i=0;i<num_cities;i++)
        {
                min_dist[i]=infinity;           //distance is infinity to all nodes
                tree[i]=0;                                      //no nodes in tree/graph
        }
        min_dist[src]=0;
        int index,min;
        for(int i=0;i<num_cities;i++)
        {
                min=infinity;
                for(int j=0;j<num_cities;j++)
                        if(min_dist[j]<=min && tree[j]==0)
                                {min=min_dist[j];index=j;}
                tree[index]=1;
                for(int j=0;j<num_cities;j++)
                        if(tree[j]==0 && min_dist[index]+distances[index][j]>0 && min_dist[index]+distances[index][j]<min_dist[j])
                                min_dist[j]=min_dist[index]+distances[index][j];
        }
	free(tree);
	int dis=min_dist[dst];
	free(min_dist);
        return dis;
}
///////////////////////////////////////////////////////////////////////////////////////////
JNIEXPORT void JNICALL Java_SalesMan_display(JNIEnv *env, jobject o, jobjectArray distance)
{
	int len1 = env -> GetArrayLength(distance);
        jintArray dim=  (jintArray)env->GetObjectArrayElement(distance, 0);
        int len2 = env -> GetArrayLength(dim);
        int **arr;
        // allocate localArray using len1
        arr = new int*[len1];
        for(int i=0; i<len1; ++i)
        {
                jintArray oneDim= (jintArray)env->GetObjectArrayElement(distance, i);
                jint *element=env->GetIntArrayElements(oneDim, 0);
                //allocate localArray[i] using len2
                arr[i] = new int[len2];
                for(int j=0; j<len2; ++j)
                        arr[i][j]= element[j];
        }

	int i;
	cout<<"THE DISTANCE MATRIX :\n";
	char node='A';
	for(i=0;i<8;i++){cout<<"\t"<<node;node++;}
	cout<<endl;
	node='A';
	for(i=0;i<8;i++)
	{	cout<<node;
		node++;
		for(int j=0;j<8;j++)
			if(arr[i][j]<2000)
			cout<<"\t"<<arr[i][j];
			else
			cout<<"\t∞";		//copied ∞ from extended ascii table
		cout<<endl;
	}

}
//////////////////////////////////////////////////////////////////////////////////////////
JNIEXPORT jint JNICALL Java_SalesMan_my_1dijkstras
  (JNIEnv *env, jobject o, jobjectArray distance, jint num_cities, jint src, jint dst)
{
	int len1 = env -> GetArrayLength(distance);
	jintArray dim=  (jintArray)env->GetObjectArrayElement(distance, 0);
	int len2 = env -> GetArrayLength(dim);
	int **localArray;
	// allocate localArray using len1
	localArray = new int*[len1];
	for(int i=0; i<len1; ++i)
	{
		jintArray oneDim= (jintArray)env->GetObjectArrayElement(distance, i);
		jint *element=env->GetIntArrayElements(oneDim, 0);
		//allocate localArray[i] using len2
		localArray[i] = new int[len2];
		for(int j=0; j<len2; ++j) 
        		localArray[i][j]= element[j];
	}
	//print(localArray);
	if(src<num_cities && dst<num_cities  && src>=0 && dst>=0)
	{
		int shortest_distance=my_dijkstras(localArray,8,src,dst);
		return shortest_distance;
	}
	else
	{
		if(src>num_cities && src<0)
			cout<<"Invalid source\nABORTING!!!!!\n";
		else
			cout<<"Invalid destination\nABORTING!!!!!\n";
		return numeric_limits<int>::max();
	}
}

