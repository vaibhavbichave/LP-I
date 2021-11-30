//Vaibhav Bichave

/*Write a program to implement Bellman-Ford Algorithm using 
Dynamic Programming and verify the time complexity*/

#include <bits/stdc++.h>
using namespace std;


struct Edge{
	// start and end vertices of the edge
	char u, v;
	int wt;		// weight of the edge
};

struct Graph{
	int V;	// no of vertices
	int E;	// no of edges
	struct Edge* edge;
};

class MinimumDistance {
private:
	struct Graph* graph;
	bool status = false;
	char vertex_array[20],src;
	int vertices, edges;
	int distance[20];
	int previous[20];
	void createAdjList();	// for creating the graph
	int getVertex_i(char c);	// helper function to get index of vertex
	// to display the path taken
	void displayPath(int src_index);	

public:
	MinimumDistance();
	void input();
	void display();
	void bellmanFord();
	void display_result();
	virtual ~MinimumDistance();
};
MinimumDistance::MinimumDistance(){
	graph = new Graph;
	graph->V = 0;
	graph->E = 0;
}

// helper function to get index of vertex
int MinimumDistance::getVertex_i(char c){
	for (int i=0; i<vertices; i++){
		if (c == vertex_array[i]) return i;
	}
	cout << "Error!"<< endl;
	return -1;
}

// method to create adjacency list
void MinimumDistance::input(){
	int v, e;
	// taking inputs for no of vertices and edges in the graph
	cout << "Enter no of Vertices: ";
	cin >> v;
	cout << "Enter no of Edges: ";
	cin >> e;
	graph->V = v;
	graph->E = e;
	cout << "Enter Vertices name: ";
	for(int i=0; i<graph->V; i++) cin >> vertex_array[i];
	cout << "\nEnter 'Starting' 'Ending' 'Weight'" << endl;
	graph->edge = new Edge[graph->E];
	for (int i=0; i<graph->E; i++){
		cout << "Edge " << i+1 << ": " ;
		cin >> graph->edge[i].u >> graph->edge[i].v >> graph->edge[i].wt;
	}
	cout << "\nGraph Created Successfully!\n" << endl;
	
	cout<<" Enter Source Vertex : ";
	cin>>src;
	status = true;

}

void MinimumDistance::display(){
	if(!status) {
		cout<<"Input graph first !!!! \n";
		return;
	}
	cout << "\n-------------------------------\n";
	cout << "Edge Starting Ending  Weight";
	cout << "\n-------------------------------\n";
	for (int i=0; i<graph->E; i++){
		cout << i+1 <<"\t"<< graph->edge[i].u <<"\t"<< graph->edge[i].v <<"\t"<< graph->edge[i].wt<<"\n";
	}
	cout << "\n-------------------------------\n";
}

// method to display the path taken
void MinimumDistance::display_result(){
	if(!status) {
		cout<<"Input graph first !!!! \n";
		return;
	}
	cout << "\n------------------------------------\n";
	cout << "Vertex \tDistance \t Path";
	cout << "\n------------------------------------\n";
	for (int i=0; i<graph->V; i++){
		int temp1, target = getVertex_i(src);
		cout << vertex_array[i] << "\t" << distance[i] << "\t\t" << vertex_array[i];
		temp1 = previous[i];
		while(temp1 != target){
			cout << "<-" << vertex_array[temp1];
			temp1 = previous[temp1];
		}
		cout << "<-" << src << endl;
	}
	cout << "\n------------------------------------\n";
}

// bellman ford algotithm
void MinimumDistance::bellmanFord(){
	if(!status) {
		cout<<"Input graph first !!!! \n";
		return;
	}
	int src_index = getVertex_i(src);
	int i, j;
	// initialise all distances to maximum
	for (i=0; i<graph->V; i++){
		distance[i] = INT_MAX;
	}
	distance[src_index] = 0;
	previous[src_index] = src_index;
	int temp;
	int u, v;
	// iterating thorough all the vertices
	for (i=1; i<graph->V; i++){
		// check distance for each edge
		for (j=0; j<graph->E; j++){
			u = getVertex_i(graph->edge[j].u);
			v = getVertex_i(graph->edge[j].v);
			temp = distance[u] + graph->edge[j].wt;
			// if distance is less than earlier distance
			// then update to new distance
			if (distance[u]!=INT_MAX && temp < distance[v]){
				distance[v] = temp;
				previous[v] = u;
			}
		}
	}
	cout<<"\nBellman Ford Applied Successfully."<<endl;

}

MinimumDistance::~MinimumDistance() {
	delete graph;
}



int main(){
	int choice;
	MinimumDistance M;
	cout<<"=================  WELCOME  =================\n";
	while(1){
		cout<<"\n----------------------------------------------\n";
		cout<<"1. Input"<<endl;
		cout<<"2. Display Graph"<<endl;
		cout<<"3. Apply Bellman Ford"<<endl;
		cout<<"4. Result"<<endl;
		cout<<"5. exit"<<endl<<endl;
		cout<< "Enter the Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				M.input();
				break;
			case 2:
				M.display();
				break;
			case 3:
				M.bellmanFord();
				break;
			case 4:
				M.display_result();
				break;
			case 5:
				exit(0);
				break;
			default:
				cout<<"Enter Valid Choice..."<<endl<<endl;
				break;
		}
		
	}
	return 0;
}
/*=================  WELCOME  =================

----------------------------------------------
1. Input
2. Display Graph
3. Apply Bellman Ford
4. Result
5. exit

Enter the Choice : 1
Enter no of Vertices: 5
Enter no of Edges: 8
Enter Vertices name: A B C D E

Enter 'Starting' 'Ending' 'Weight'
Edge 1: A B -1
Edge 2: A B 4
Edge 3: B C 3
Edge 4: B D 2
Edge 5: B E 2
Edge 6: D B 1
Edge 7: D C 5
Edge 8: E D -3

Graph Created Successfully!

 Enter Source Vertex : A

----------------------------------------------
1. Input
2. Display Graph
3. Apply Bellman Ford
4. Result
5. exit

Enter the Choice : 2

-------------------------------
Edge Starting Ending  Weight
-------------------------------
1       A       B       -1
2       A       B       4
3       B       C       3
4       B       D       2
5       B       E       2
6       D       B       1
7       D       C       5
8       E       D       -3

-------------------------------

----------------------------------------------
1. Input
2. Display Graph
3. Apply Bellman Ford
4. Result
5. exit

Enter the Choice : 3

Bellman Ford Applied Successfully.

----------------------------------------------
1. Input
2. Display Graph
3. Apply Bellman Ford
4. Result
5. exit

Enter the Choice : 4

------------------------------------
Vertex  Distance         Path
------------------------------------
A       0               A<-A
B       -1              B<-A
C       2               C<-B<-A
D       -2              D<-E<-B<-A
E       1               E<-B<-A

------------------------------------

----------------------------------------------
1. Input
2. Display Graph
3. Apply Bellman Ford
4. Result
5. exit

Enter the Choice : 5

--------------------------------
Process exited after 176.2 seconds with return value 0
Press any key to continue . . .*/
