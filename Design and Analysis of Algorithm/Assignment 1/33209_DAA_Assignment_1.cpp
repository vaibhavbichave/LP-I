//Vaibhav Bichave

/*Write a program to implement Fractional knapsack using Greedy algorithm 
and 0/1 knapsack using dynamic programming. Show that Greedy strategy does not 
necessarily yield an optimal solution over a dynamic programming approach.*/


#include <bits/stdc++.h>
using namespace std;

struct shop{
	
	double ratio;
	int price;
	int weight;
};

bool compare(shop a ,shop b){
	return (a.ratio>b.ratio);
}


class Knapsack
{
	private:
		int num,capacity,result;
		shop arr[500];
		int val[500],wt[500];
		bool status;
	public :
		void input();
		void display();
		void maxi();
		void greedy();
		void dynamicpro();
};


void Knapsack::input(){
	int i=0;
	cout<<"Enter number of item in store : ";
	cin>>num;
	
	//taking price and weight from user
	while(i<num){
		int a,b;
		cout<<"\nItem "<<i+1<<" :: Value & Weight: ";
		
		cin>>a>>b;
		if(a>0 && b>0){
			val[i]=a;
			wt[i]=b;
			arr[i].price=a;
			arr[i].weight=b;
			arr[i].ratio=(double)arr[i].price/arr[i].weight;
			i++;
			
		}
		else{
			cout<<"Enter valid value of element and weight again... "<<endl;
		}
	}
	//taking Capacity of knapsack from user
	cout<<"\nEnter Capacity of knapsack : ";
	cin>>capacity;
	while(capacity<0){
		cout<<"\nCapacity can not be negative !!!!";
		cout<<"\nEnter Valid Capacity of knapsack : ";
		cin>>capacity;
	}
	cout<<endl;
	status = true;
}
void Knapsack::display(){
	if(!status) {
		cout<<"Input Item info first !!!! \n";
		return;
	}
	cout<<fixed<<setprecision(4);
	cout<<"----------------------------------------------\n";
	cout<<"\tValue "<<" Weight "<<endl;
	for(int i=0;i<num;i++){
		cout<<"\t "<<val[i]<<"\t "<<wt[i]<<endl;
	}
	cout<<"----------------------------------------------\n";
}

void Knapsack::greedy(){
	if(!status) {
		cout<<"Input Item info first !!!! \n";
		return;
	}
	int weight = capacity;
	sort(arr,arr+num,compare);
//	display();
	//calculating maximum value in knapsack 
	for(int i=0;i<num;i++){
		if(weight>arr[i].weight){
			result+=arr[i].price;
			weight-=arr[i].weight;
			continue;
		}
		result+=arr[i].ratio*weight;
		break;
	}
	
	cout<<"Greedy algorithm applied successfully"<<endl;
}


void Knapsack:: dynamicpro(){
	if(!status) {
		cout<<"Input Item info first !!!! \n";
		return;
	}
	// making and initializing dp array
    int dp[capacity + 1]={0};
 
    for (int i = 0; i < num ; i++) {
        for (int w = capacity; w >=0; w--) {
			if (wt[i] <= w)     
                dp[w] = max(dp[w],dp[w - wt[i]] + val[i]);
        }
    }
    result = dp[capacity]; 
    cout<<"Dynamic programming applied successfully"<<endl;
}
void Knapsack::maxi(){
	if(!status) {
		cout<<"Input Item info first !!!! \n";
		return;
	}
	cout<<"\nMaximum total value in knapsack : "<<result<<endl;
}


int main(){
	int choice;
	Knapsack Knapsack;
		cout<<"=================  WELCOME  =================\n";
	while(1){
		cout<<"----------------------------------------------\n";
		cout<<"1. Input"<<endl;
		cout<<"2. Display Item Info"<<endl;
		cout<<"3. Fractional Knapsack (Greedy)"<<endl;
		cout<<"4. 01 Knapsack (dynamic)"<<endl;
		cout<<"5. Maximum Possible Value"<<endl;
		cout<<"6. Exit"<<endl<<endl;
		cout<< "Enter the Choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				Knapsack.input();
				break;
			case 2:
				Knapsack.display();
				break;
			case 3:
				Knapsack.greedy();
				break;
			case 4:
				Knapsack.dynamicpro();
				break;
			case 5:
				Knapsack.maxi();
				break;
			case 6:
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
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 1
Enter number of item in store : 3

Item 1 :: Value & Weight: 60 10

Item 2 :: Value & Weight: 100 20

Item 3 :: Value & Weight: 120 30

Enter Capacity of knapsack : 50

----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 2
----------------------------------------------
        Value  Weight
         60      10
         100     20
         120     30
----------------------------------------------
----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 3
Greedy algorithm applied successfully
----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 5

Maximum total value in knapsack : 240
----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 1
Enter number of item in store : 3

Item 1 :: Value & Weight: 100 10

Item 2 :: Value & Weight: 280 40

Item 3 :: Value & Weight: 120 20

Enter Capacity of knapsack : 60

----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 2
----------------------------------------------
        Value  Weight
         100     10
         280     40
         120     20
----------------------------------------------
----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 3
Greedy algorithm applied successfully
----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 5

Maximum total value in knapsack : 680
----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 4
Dynamic programming applied successfully
----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 5

Maximum total value in knapsack : 400
----------------------------------------------
1. Input
2. Display Item Info
3. Fractional Knapsack (Greedy)
4. 01 Knapsack (dynamic)
5. Maximum Possible Value
6. Exit

Enter the Choice : 6

--------------------------------
Process exited after 402.4 seconds with return value 0
Press any key to continue . . .*/
