//Vaibhav Bichave

/*Write a recursive program to find the solution of placing n queens 
on the chessboard so that no two queens attack each other using Backtracking.*/

#include <bits/stdc++.h>
using namespace std;


/* A utility function to print solution */
void printSolution(int **board,int N)
{
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d |", board[i][j]);
		printf("\n");
	}
}

bool isSafe(int **board, int row, int col,int N)
{
	int i, j;

	/* Check this row on left side */
	for (j = 0; j < col; j++)
		if (board[row][j])
			return false;

	/* Check upper diagonal on left side */
	 i = row;
	 j = col;
	while(i>=0 && j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;
		j--;
	}
	/* Check lower diagonal on left side */
	i =	row ;
	j = col ;
	while(j >= 0 && i < N){
		if(board[i][j]==1){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

bool nQueen(int **board, int col,int N)
{
	
	if (col >= N)
		return true;
	for (int i = 0; i < N; i++) {
		
		if (isSafe(board, i, col,N)) {
			board[i][col] = 1;
			if (nQueen(board, col + 1,N))
				return true;

			board[i][col] = 0; // BACKTRACK
		}
	}
	
	return false;
}

void solve()
{
	int n;
	cout<<"\n  =============  WELCOME TO N_QUEEN  ============= ";
	cout<<"\n\nEnter size of chess board : ";
	cin>>n;
 	int** arr = new int*[n];
 	for(int i=0;i<n;i++){
 		arr[i]= new int[n];
 		for(int j=0;j<n;j++){
			arr[i][j]=0;
		}
	}

	if (nQueen(arr, 0,n)) {
		printSolution(arr,n);
	}
	else{
		printf("Solution does not exist");
	}
	
}

// driver program to test above function
int main()
{
	int temp;
	do{
		solve();
		cout<<"\nWant to continue (0/1) : ";
		cin>>temp;
	}while(temp);
	return 0;
}

/*
  =============  WELCOME TO N_QUEEN  =============

Enter size of chess board : 4

 0 | 0 | 1 | 0 |
 1 | 0 | 0 | 0 |
 0 | 0 | 0 | 1 |
 0 | 1 | 0 | 0 |

Want to continue (0/1) : 1

  =============  WELCOME TO N_QUEEN  =============

Enter size of chess board : 6

 1 | 0 | 0 | 0 | 0 | 0 |
 0 | 0 | 0 | 0 | 0 | 1 |
 0 | 0 | 0 | 0 | 1 | 0 |
 0 | 1 | 0 | 0 | 0 | 0 |
 0 | 0 | 0 | 1 | 0 | 0 |
 0 | 0 | 1 | 0 | 0 | 0 |

Want to continue (0/1) : 0

--------------------------------
Process exited after 19.53 seconds with return value 0
Press any key to continue . . .*/
