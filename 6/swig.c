#include <stdio.h>
#include <limits.h>

int minDistance(int dist[], int sptSet[])
{
   int min = INT_MAX, min_index;
    int i;
   for (i = 0; i < 9; i++)
     if (sptSet[i] == 0 && dist[i] <= min)
         min = dist[i], min_index = i;
   return min_index;
}

int my_dijkstras(int distances[9][9],int num_cities, int src, int dst)
{
/*the matrix under consideration:   
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
  */
     int dist[9];
     int i;
     int sptSet[9];
     for (i = 0; i < 9; i++)
        dist[i] = INT_MAX, sptSet[i] = 0;
     dist[0] = 0;
     int count;
     for (count = 0; count < 9-1; count++)
     {
       int u = minDistance(dist, sptSet);
       sptSet[u] = 1;
       int i;
       for (i = 0; i < 9; i++)
         if (!sptSet[i] && distances[u][i] && dist[u] != INT_MAX && dist[u]+distances[u][i] < dist[i])
            dist[i] = dist[u] + distances[u][i];
     }
   printf("Distance from Source %d to destination %d : \n",src,dst);
   return dist[dst];
}

