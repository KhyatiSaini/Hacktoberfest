//============================================================================
// Name        : knapsack.cpp
// Author      : Koushal Bhat
// Roll no.    : 33332
// batch       : L11
// Subject     : LP 
//============================================================================

#include<bits/stdc++.h>
using namespace std;
class item_struct{
      public:
        int id;
        double profit,weight;
        double ratio;
    };

//------------Merge sort---------------------------------------------------
void merge(item_struct *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; 
   nr = r-m;
   item_struct larr[nl], rarr[nr];
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;

   
   while(i < nl && j<nr) {
      //sorting w.r.t. ratio
      if(larr[i].ratio >= rarr[j].ratio) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {    
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(item_struct *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}
//-----------------------Fractional_Knapsack -------------------------------------------
double fractional_knapsack(item_struct * item, int n, int c)
{
   double totalWeight = 0, totalProfit = 0;
   int i;
   item_struct result[n]; //to store the selected items

   //sort the items by profit/weight ratio in descending order
   mergeSort(item,0,n-1);

   //looping through all elements
   for(i=0;i<n;i++)
   {
      //check if the entire item can be used
      if(totalWeight + item[i].weight <= c)
      {
         //add the total weight and profit to final profit
         totalWeight+=item[i].weight;
         totalProfit+=item[i].profit;
         //save the item in result array
         result[i] = item[i];
      }

      //if the weight of item is more than capacity
      else
      {
         //calculte the remaining capacity 
         double remain = c - totalWeight;
         //update the final weight by adding remaining weight
         totalWeight+= remain;
         //update the final profit by adding the profit of item by selecting remaining weight
         totalProfit+= item[i].profit * remain/item[i].weight;

         //save item with selected weight and obtained profit in result array
         result[i].id = item[i].id;
         result[i].weight = remain;
         result[i].profit = item[i].profit * remain/item[i].weight;
         break; //stop 
      }

   }

   //display result
//    cout<<"======================================================================"<<endl;
//    cout<<"Items with selected weight and earned profit"<<endl;
//    cout<<"ID."<<"\tWeight"<<"\tProfit"<<endl;
//    for(int j=0;j<i;j++)
//    {
//       cout<<result[j].id<<"\t"<<result[j].weight<<"\t"<<result[j].profit<<endl;
//    }
    cout<<"Total Profit earned Fractional ::"<<totalProfit<<endl;
    return totalProfit;
    
}
//-----------------------01-Knapsack-----------------------------
int knapsack01dp(item_struct * item, int n, int W) {
    int dp[n+1][W+1];
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=W; j++) {
			if(i*j == 0) {
				dp[i][j] = 0;
			} 
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=W; j++) {
			if(item[i-1].weight <= j) {
				dp[i][j] = max(int(item[i-1].profit+dp[i-1][j-int(item[i-1].weight)]), dp[i-1][j]);
			} 
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
    cout<<"Total Profit earned 0/1 DP ::"<<dp[n][W] << endl;
	return dp[n][W];
}

//-----------------------01-Knapsack-Greedy-----------------------------
void compare(item_struct * item, int n, int W) {

   int totalWeight = 0, totalProfit = 0;
   int i;
   item_struct result[n]; //to store the selected items

   //sort the items by profit/weight ratio in descending order
   mergeSort(item,0,n-1);

   //looping through all elements
   for(i=0;i<n;i++)
   {
      //check if the entire item can be used
      if(totalWeight + item[i].weight <= W)
      {
         //add the total weight and profit to final profit
         totalWeight+=item[i].weight;
         totalProfit+=item[i].profit;
         //save the item in result array
         result[i] = item[i];
      }

   }

   //display result
//    cout<<"======================================================================"<<endl;
//    cout<<"Items with selected weight and earned profit"<<endl;
//    cout<<"ID."<<"\tWeight"<<"\tProfit"<<endl;
//    for(int j=0;j<i;j++)
//    {
//       cout<<result[j].id<<"\t"<<result[j].weight<<"\t"<<result[j].profit<<endl;
//    }
      cout<<"Total Profit earned 0/1 Fractional::"<<totalProfit<<endl;

    double dp_profit=knapsack01dp(item,n,W);
    if(dp_profit>totalProfit)
    {
       cout<<"DP Approach yields a better Profit than Greedy Approach\n";
       return;
    }
    else
    {
       cout<<"Greedy Approach Yields The same Solution\n";
       return;
    }
}
//-----------------------Driver function------------------------------
int main() {
    int n;
    double c;
    cout<<"=========Knapsack Problem======================================="<<endl;
    cout<<"Enter number of items:";
    cin>>n;
    item_struct item[n];
    cout<<"Enter weight and profit for each item:"<<endl;
    for(int i=0;i<n;i++)
    {
        item[i].id = i+1;
        cout<<"Item "<<i+1<<endl;
        cout<<"Weight:";
        cin>>item[i].weight;
        cout<<"Profit:";
        cin>>item[i].profit;
        item[i].ratio = item[i].profit/item[i].weight;
        //validation for negative values
        if(item[i].weight<0 || item[i].profit<0)
        {
           cout<<"Please enter positive values"<<endl;
           i--;
        }
        
    }
    cout<<"Enter capacity of container:";
    cin>>c;
   
    while(true) {

            cout << "1. Fractional Knapsack  \n2. 0/1 Knapsack \n3. Compare  0/1 Knapsack DP and Greedy\n";
            cout << "Your choice: ";
            int option;
            cin >> option;

            switch (option) {
                case 1: fractional_knapsack(item,n,c);
                        break;
                case 2: knapsack01dp(item,n,c);;
                        break;
                case 3: compare(item,n,c);
                        break;
                default: cout << "Invalid choice!\n";
                        break;
            }

        
        char choice;
        cout << "Do you wish to continue: Y/N ";
        cin >> choice;

        if(choice != 'Y' && choice != 'y') {
            cout << "\n----- Thank you! ----";
            break;
        }
    }
    return 0;
}


//Output
// =========Knapsack Problem=======================================
// Enter number of items:3
// Enter weight and profit for each item:
// Item 1
// Weight:3
// Profit:3
// Item 2
// Weight:4
// Profit:5
// Item 3
// Weight:6
// Profit:8
// Enter capacity of container:7
// 1. Fractional Knapsack  
// 2. 0/1 Knapsack 
// 3. Compare  0/1 Knapsack DP and Greedy
// Your choice: 1
// Total Profit earned Fractional ::9.25
// Do you wish to continue: Y/N y
// 1. Fractional Knapsack  
// 2. 0/1 Knapsack 
// 3. Compare  0/1 Knapsack DP and Greedy
// Your choice: 2
// Total Profit earned 0/1 DP ::8
// Do you wish to continue: Y/N y
// 1. Fractional Knapsack  
// 2. 0/1 Knapsack 
// 3. Compare  0/1 Knapsack DP and Greedy
// Your choice: 3
// Total Profit earned 0/1 Fractional::8
// Total Profit earned 0/1 DP ::8
// Greedy Approach Yields The same Solution
// Do you wish to continue: Y/N n

// ----- Thank you! ----