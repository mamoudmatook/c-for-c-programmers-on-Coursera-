/* the last assignment we created an artificial graph using the density value
 * and the random method to generate random values.
 * this time we will create a graph by reading values from a file 
 * i prefred to start a new class here for this problem as i decided to add ponus point 
 * _colored edges_   after peers reviews
 * here i'll use prim algorithm to find MST */
#include <iostream>
#include <vector>
#include <fstream>
#include <limits.h>
using namespace std;
class Graph
{
	private:
		int v; //number of vertices
		vecotr<vector<int> > edges;  
		ifstream infile;
		vector<bool> mst;   
		vector<int>  key;
		vector <int> parent;

	public:
		Graph(string file)
		{
			inflile.open(file);
			infile>>v; //read number of vertices
			edges=vector<vector<int> > (v,vector<int>(v,0));
			mst=vector<bool>(v,false);   //intialize mst as  an empty set
			key=vector<int>(v,INT_MAX);  //intialize key values of vertices with the biggest value
			parent=vector<int>(v,-1); // intialize parent array
		}
		void generate()
		{      int u,v,w; //values to read from file
			while(!infile.eof())
			{
				infile>>u>>v>>w;
				edges[u][v]=w;   
			}
		}
		int minKey()
		{
			int min=INT_MAX,min_index;
			for (int i = 0; i < v; i++)
    			if (mst[i] == false && key[i] < min)
        		min = key[i], min_index = i;
			return min_index;
		}
		int printMST() 
		{ 
			printf("Edge \tWeight\n"); 
			for (int i = 1; i < v; i++) 
    				printf("%d - %d \t%d \n", parent[i], i, edges[i][parent[i]]); 
		}
	        void primMST() 
		{ 
        		for (int count = 0; count < v-1; count++) 
    				{ 
        				// Pick the minimum key vertex from the  
        				// set of vertices not yet included in MST 
        				int u = minKey(); 
  
        				// Add the picked vertex to the MST Set 
        				mst[u] = true; 
  
        				// Update key value and parent index of  
        				// the adjacent vertices of the picked vertex.  
        				// Consider only those vertices which are not  
        				// yet included in MST 
        				for (int i = 0; i < v; i++) 
  
        					// graph[u][v] is non zero only for adjacent vertices of m 
        					// mstSet[v] is false for vertices not yet included in MST 
        					// Update the key only if graph[u][v] is smaller than key[v] 
        					if (edges[u][i] && mst[i] == false && edes[u][i] < key[i]) 
            					parent[i] = u, key[i] = edges[u][i]; 
   				 } 
  
   			// print the constructed MST 
    			printMST(); 
		} 	

};
int main()
{       

	
	Graph G("input.txt");
	G.generate();
	G.primMST();
}


                
