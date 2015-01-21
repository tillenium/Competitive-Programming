#include <iostream>
#include <vector>

using namespace std;

bool test_for_zero(vector<vector<char> > grid){
  for(int i=1;i<=3;i++)
    for(int j=1;j<=3;j++){
      if(grid[i][j]=='1')
	return false;
    }
  return true;
}



int main(){
  int n;
  cin>>n;
  vector<vector<char> > grid(5,vector<char>(5,'0'));
  vector<vector<char> > next(5,vector<char>(5,'0'));
  while(n-->0){
    for(int i=1;i<=3;i++)
      for(int j=1;j<=3;j++)
	cin>>grid[i][j];
    int i=-1;
    while(!test_for_zero(grid)){
      for(int i=1;i<=3;i++){
	for(int j=1;j<=3;j++){
	  next[i][j] = (grid[i-1][j] - '0' + grid[i+1][j] - '0'  + grid[i][j-1] - '0' + grid[i][j+1] - '0') % 2 + '0';
     
	}
	
      }
      grid = next;
      i++;
    }
    cout<<i<<endl;
  }
}
