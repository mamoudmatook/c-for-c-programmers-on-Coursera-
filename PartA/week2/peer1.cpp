// The 200 words explanation of program will be shown in the output of the program
#include<iostream>
#include<ctime>
using namespace std;
const int INF=100;
const int vertices=10;
const int distance_parameter=10;
const float edge_density=0.2;
const int source=0;
class Graph{
    private:
        int matrix[vertices][vertices];
    public:
        Graph(){          // Creates graph randomly and printing the adjacency matrix  
            int x;
            x=edge_density*vertices*vertices;         
            int i,j,a[(vertices* vertices) - x], b[(vertices* vertices) - x];
            srand(time(0));

            for (i=0; i<vertices; i++){
                for (j=0; j<vertices; j++){
                    matrix[i][j] = matrix[j][i] = 1 + rand() % distance_parameter;
                } 
                matrix[i][i]=0;
            }
            
            for (int i=0; i<((vertices*vertices) - x)/2; i++){
                a[i]=rand() % (vertices-1);
                b[i]=rand() % (vertices-1);
                if(a[i]!=b[i])
                    matrix[a[i]][b[i]]=matrix[b[i]][a[i]]=INF;
            }
            
            
            cout<<"the adjacency matrix representation of randomly generated graph is"<<endl;
            for (int i=0; i<vertices; i++){
                for (int j=0; j<vertices; j++){
                    if(matrix[i][j]==INF)
                        cout<<"NDP\t";             //NDP denotes no direct path is possible
                    else
                        cout<<matrix[i][j]<<"\t";
                }
                cout<<endl;
            }
        }
        int V(){
            return vertices;
        }
        int E(){
            int i,j,edges=0;
            for (i=0; i<vertices; i++){
                for (j=0; j<vertices; j++){
                    if(matrix[i][j]!=0 && matrix[i][j]!=INF)
                        edges++;
                }
            }
            return (edges/2);
        }
        int get_edge_value(int s_point, int d_point){
            return(matrix[s_point][d_point]);
        }
};
int main()
{
    Graph g1;
    int c = g1.V(), nearest_point, min_dist;
    cout<<"number of vertices: "<<c<<endl;
    cout<<"number of edges: "<<g1.E()<<endl;
    int distance[vertices], visited[vertices]; // visited array keeps values 1 and 0. 1 refers to point has been visited and 0 refers to unvisited point.
    for(int i=0; i<vertices; i++){
        distance[i] = (g1.get_edge_value(source,i));
        visited[i] = 0;
    }
    visited[source]=1;
    for (int j=0; j<vertices; j++){
        min_dist=INF;
        for (int k=0; k<vertices; k++){
            if(distance[k]<=min_dist && visited[k]==0 && j!=k){
                min_dist=distance[k];
                nearest_point=k;
            }
        }
        visited[nearest_point]=1;
        for (int v=0; v<vertices; v++){
            if(visited[v]==0 && distance[v] > distance[nearest_point] + (g1.get_edge_value(nearest_point,v)))
                distance[v]=distance[nearest_point] + (g1.get_edge_value(nearest_point,v));
        }
    }
    cout<<"vertex\t"<<"minimum distance from source"<<endl;
    for(int a=0; a<vertices; a++){
        cout<<a<<"\t"<<distance[a]<<"\t"<<visited[a]<<endl;
    }
    cout<<"                              The Dijkstras Algorithm"<<endl;
    cout<<"* It is one of the most intuitive ways to solve the shortest path algorithm based on greedy algorithmic techniques"<<endl;
    cout<<"* In my program I have first created a Class called graph in which I have created all the graph and all its related functions"<<endl;
    cout<<"* The Graph has been generated randomly with required edge density and the distance range parameter"<<endl;
    cout<<"* The randomly generated graph can be seen in the output as the adjacency matrix representation"<<endl;
    cout<<"* The source point is 0 and can be changed by changing the const int source value declared globally"<<endl;
    cout<<"* Similarly the no. of vertices is 10 and can be changed as per users requirements"<<endl;
    cout<<"* For computing minimum distances of each point from source I have created a distance array and a visited array"<<endl;
    cout<<"* Initially distance array keeps 0 for the source vertex and INF or infinite for non adjacent vertex"<<endl;
    cout<<"* Then the vertex with minimum distance is computed"<<endl;
    cout<<"* To check for which of the vertices has been visited I have created an array called visited"<<endl;
    cout<<"* From the minimum distance vertex then the distance from source of the adjacent vertices to it will be computed"<<endl;
    cout<<"* And the vertex will be marked as 1 in visited array"<<endl;
    cout<<"* The above process will be repeated untill all the vertices has been visited"<<endl;
    cout<<"* In this way minimum distances from source is determined"<<endl;
}
