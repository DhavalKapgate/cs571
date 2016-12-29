%module swig

%inline %{
int (*new_arr())[9] {
	return (int (*)[9]) malloc(81*sizeof(int));
}

void free_arr(int (*distances)[9]) {
   free(distances);
}
void arr_set(int distances[9][9], int i, int j, int v) {
   distances[i][j] = v;
}
int arr_get(int distances[9][9], int i, int j) {
   return distances[i][j];
}
%}
%{
extern int my_dijkstras(int distances[9][9],int num_cities, int src, int dst);
%}
extern int my_dijkstras(int distances[9][9],int num_cities, int src, int dst);
