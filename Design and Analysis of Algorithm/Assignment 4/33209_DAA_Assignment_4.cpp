//Vaibhav Bichave

/*Write a program to solve the travelling salesman problem and to 
print the path and the cost using LC Branch and Bound.*/

#include<bits/stdc++.h>
using namespace std;
class ShortestDistance {
private:
	char vertex_array[20];
	int vertices, edges;
	int visited[20];
	int previous[20];
	int getVertex_i(char c);
	int cost_matrix[20][20];
public:
	ShortestDistance();
	void createGraph();
	int row_col_deduction(int matrix[][20]);
	void travellingSalesman();
	void printMatrix(int matrix[][20]);
	virtual ~ShortestDistance();
};



ShortestDistance::ShortestDistance() {
	// inputs, graph
	int i, j, u, v, wt;
	char c1, c2;
	// no of vertex and edges

	for (i=0; i<vertices; i++) visited[i] = 0;
	createGraph();
	travellingSalesman();
}

int ShortestDistance::getVertex_i(char c){
	for (int i=0; i<vertices; i++){
		if (c == vertex_array[i]) return i;
	}
	cout << "Error!"<< endl;
	return -1;
}

void ShortestDistance::createGraph(){
	int i, j, u, v, wt;
	char c1, c2;
	// no of vertex and edges
	cout << "Enter no of Vertices: ";
	cin >> vertices;
	cout << "Enter no of Edges: ";
	cin >> edges;
	cout << "Enter Vertices name: ";
	for(i=0; i<vertices; i++) cin >> vertex_array[i];
	for (i=0; i<vertices; i++)
		for (j=0; j<vertices; j++)
			cost_matrix[i][j] = 444;
	
	cout << "Enter SOURCE, DEST and Weight: -" << endl;
	for (i=0; i<edges; i++){
		cout << "Edge " << i << ": " ;
		cin >> c1 >> c2 >> wt;
		u = getVertex_i(c1);
		v = getVertex_i(c2);
		cost_matrix[u][v] = wt;
	}
	cout << "Graph Created Successfully!" << endl;
	cout << "\nCost Matrix is: " << endl;
	printMatrix(cost_matrix);
}

void ShortestDistance::printMatrix(int matrix[][20]){
int i, j;
	for(i=0; i<vertices; i++){
		for(j=0; j<vertices; j++) cout << matrix[i][j] << " ";
		cout << endl;
	}
}


// retruns cost after row and column minimisation
int ShortestDistance::row_col_deduction(int matrix[][20]){
	int i, j, k, min;
	int cost = 0;

	// row deduction
	for(i=0; i<vertices; i++){
		min = 444;
		for(j=0; j<vertices; j++){
			if(matrix[i][j] < min) min = matrix[i][j];
		}
		// subtracting min for a row
		for (j=0; j<vertices; j++){
			if (matrix[i][j] == 444 || min==444) continue;
			matrix[i][j] = matrix[i][j] - min;
		}
		if (min != 444) cost = cost + min;
	}

	// col deduction
	for(i=0; i<vertices; i++){
		min = 444;
		for(j=0; j<vertices; j++){
			if(matrix[j][i] < min) min = matrix[j][i];
		}
		// subtracting min for a col
		for (j=0; j<vertices; j++){
			if (matrix[j][i] == 444 || min==444) continue;
			matrix[j][i] = matrix[j][i] - min;
		}
		if (min != 444) cost = cost + min;
	}
	return cost;
}


void ShortestDistance::travellingSalesman(){
	int i, j, k, mincost;
	int current=0;
	int next;
	previous[0] = 0;
	int netcost = row_col_deduction(cost_matrix);
	mincost = 444;
	int temp_matrix[20][20];
	int temp2_matrix[20][20];
	int cost;	// for cost after visiting
	for (i=0; i<vertices-1; i++){
		cout << "\n--------------------------------------------------" << endl;
		cout << "Current Vertex: "<< vertex_array[current] << endl;
		// visiting the vertices and checking for min cost
		for (j=0; j<vertices; j++){
//			cout << "\ncurrent first line : " << current << endl;
			cost = 0;
			//temp_matrix equal to cost_matrix;
			visited[current] = 1;
			for (k=0; k<vertices; k++){
				for(int m=0; m<vertices; m++) temp_matrix[k][m] = cost_matrix[k][m];
			}

			if (visited[j] == 1) continue;
//			// visiting vertex j
//			// noting m[a][b]
			cost = cost_matrix[current][j];
//			// making row a and col b infinity
			for (int k=0; k<vertices; k++){
				temp_matrix[current][k] = 444;
				temp_matrix[k][j] = 444;
			}

			temp_matrix[j][current] = 444;

//			printMatrix(temp_matrix);
			if (cost != 444) cost = cost + row_col_deduction(temp_matrix);

			if (cost <= mincost){
				mincost = cost;
				next = j;

				for (k=0; k<vertices; k++)
					for(int m=0; m<vertices; m++) 
						temp2_matrix[k][m] = temp_matrix[k][m];
				
			}
			cout << "Cost for path " << vertex_array[current] << " -> " << vertex_array[j] << ": ";
			cout << netcost << " + " << cost << " = " << netcost+cost << endl;
		}
		// now current is one with min cost
		cout << "\nvisiting Vertex : " << vertex_array[current] << " -> " << vertex_array[next];

		previous[next] = current;
		current = next;
		visited[current] = 1;

		netcost = netcost + mincost;
		for (k=0; k<vertices; k++){
			for(int m=0; m<vertices; m++) cost_matrix[k][m] = temp2_matrix[k][m];
		}

	}
	previous[0] = current;
	cout << "\n==================================================" << endl;
	cout << "\nOptimal Path is :- ";
	int temp1 = 0;
	for (i=0; i<vertices; i++){
			cout << vertex_array[temp1] << " <- " ;
			temp1 = previous[temp1];
	}
	cout << "A" <<  "\nCost of Optimal path :- " << netcost << " units" << endl;

}

ShortestDistance::~ShortestDistance() {
	// TODO Auto-generated destructor stub
}




int main() {
	cout << "\n--- WELCOME TO TRAVELLING SALEMAN PROBLEM ---" << endl<<endl;
	ShortestDistance S;
	return 0;
}


/*
--- WELCOME TO TRAVELLING SALEMAN PROBLEM ---

Enter no of Vertices: 4
Enter no of Edges: 10
Enter Vertices name: A B C D
Enter SOURCE, DEST and Weight: -
Edge 0: A B 4
Edge 1: A D 7
Edge 2: A C 12
Edge 3: B A 5
Edge 4: B D 18
Edge 5: C A 11
Edge 6: C D 6
Edge 7: D A 10
Edge 8: D B 2
Edge 9: D C 3
Graph Created Successfully!

Cost Matrix is:
444 4 12 7
5 444 200 18
11 200 444 6
10 2 3 444

--------------------------------------------------
Current Vertex: A
Cost for path A -> B: 18 + 18 = 36
Cost for path A -> C: 18 + 7 = 25
Cost for path A -> D: 18 + 8 = 26

visiting Vertex : A -> C
--------------------------------------------------
Current Vertex: C
Cost for path C -> B: 25 + 215 = 240
Cost for path C -> D: 25 + 0 = 25

visiting Vertex : C -> D
--------------------------------------------------
Current Vertex: D
Cost for path D -> B: 25 + 0 = 25

visiting Vertex : D -> B
==================================================

Optimal Path is :- A <- B <- D <- C <- A
Cost of Optimal path :- 25 units

--------------------------------
Process exited after 134 seconds with return value 0
Press any key to continue . . .*/
