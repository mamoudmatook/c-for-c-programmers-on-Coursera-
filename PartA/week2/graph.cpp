#include <vector>
#include <queue>   //priority_queue
#include <iostream>
#include <climits>      //INT_MAX
#include <cstdlib.h>    //srand(),rand()
#include <ctime>      //time(0)
using namespace std;
class Graph
{
	private:
		typedef pair<double,int> di; //vertex weight and index
		int v; //number of vertices
		priority_queue<di,vector<di>,greater<di> > Q; //for distance values and weights easy to implemnt Dijkstra Algorihtm with.
		vector<vectort<int>  > edges; //for edge values;
		int edg_count;  // number of edges 
                double Max;
		vector<double>distances;
		double Max,sum;

	public:
		Graph(int vertices=1):v(vertices),edg_count(0)
	{
	 Max=static_cast<double>(INT_MAX);
	 distances=vector<double>(v,Max);
	 edges=vector<vector<double> >(v,vector<double>(v,0.0));

	}
	      	int Vertices()   //return number of vertices
		{
			return v;
		}
		int E()  //return number of edges
		{
			return edge_count;
		}
		void neighbours(int v) //print list of adjcent nodes to a vertex                {
			for (int i=0;i<edges[v].size();i++)
				if(edges[v][i])
					cout<<i<<",";
		        cout<<endl;
                }
                int  adjcent(int x,int y) // if y is adjcent to x
		{
			return edges[x][y].first;
		}
		void add(int x,int y ,double  weight) // add edg between x,y
		{
			edges[x][y]=weight;
			edges[y][x]=weight;
			edge_count+=2; //for number of edges 
		}
		void del(int x,int y) //del edge between x and y
		{
			edges[x][y]=0.0;
		}
		double  get_edge_value(int x,int y) //return edge value between x,y
		{
			return edges[x][y];
		}
		void set_node_value(int x,double v )
		{
			distances[x]=v;
		}
		double get_node_value(int x) //for getting distance of that node
		{
			return distances[x];
		}

                void  set_edge_value(int x,int y,double w) //return edge value between 2 vertices
		{
		  edges[x][y]=w;
		}
		void random_generator(double density,double min,double max)
		{       double prob,weight;
			for (int i=0;i<v;i++)
				for (int j=i+1;j<v;j++)
				{
					prob=static_cast<double>(rand())/RAND_MAX;
					if(prob<=density)
					{
						weight=min+(max-min)*(static_cast<double>(rand())/RAND_MAX);
						add(i,j,weight);
					}
				}
		}
		double average()
		{
			int vv=v;
			sum=0;
			for (int i=0;i<v;i++)
			{
				if(distances[i]==Max)
					vv--;   //for holding number of adjcent vertices;
				else sum+=distances[i];
			}
			return sum/vv;
		}

		double dijkstra(int sr=0) //implemnting dijkstra algorithm
		{
			distance[sr]=0.0;
			Q.push(di(0.0,sr));
			while(!Q.empty())
			{
				di top=Q.top();
				double d=top.first;
				int vv=top.second;
				Q.pop();
				if(d<=distances[vv])
				{
					for(int i=0;i<v;i++)
					{
						if(edges[v][i] && distances[i]>distances[v]+edges[v][i])
						{
							distances[i]=distances[v]+edges[v][i];
							Q.push(di(distances[i],i);
					        }
						
					}
				}
			}
			return average();
			}
		        void reset()
                        {
        	//we reset all the data structures so that the same object can be reused

        		priority_queue<ii, vector<ii>, greater<ii> > empty;
        		swap(Q,empty);
       		 	distances.clear();
       		 	edges.clear();
		 }

};

int main()
{
    Graph G20,G40;
    double sum20=0,sum40=0;

    //iterate 10000 times and create new graphs each time
    for(int i=1;i<=10000;++i)
    {
        G20=Graph(50);
        G40=Graph(50);
        G20.monteCarloSimulation(0.20,1.0,10.0);
        G40.monteCarloSimulation(0.40,1.0,10.0);
        sum20+=G20.dijkstra(1);
        sum40+=G40.dijkstra(1);
	G20.reset();
        G40.reset();
    }

    cout<<"**Monte Carlo Simulation for Average Shortest Paths in Graphs**"<<endl;
    cout<<"Average Shortest Path for a Graph with 20% Density and edge weights between 1.0 to 10.0 is: "<<sum20/10000<<endl;
    cout<<"Average Shortest Path for a Graph with 40% Density and edge weights between 1.0 to 10.0 is: "<<sum40/10000<<endl;

    return 0;
		 
}
					  


