#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t;cin>>t;
  int s,a,f,x=0,y=0;
  while(t--){
    cin>>s>>a>>f;
    vector<vector<int> > grid(s,vector<int> (a,0));
    vector<int> ss, aa;
    int median_s = 0;
    for(int i=0;i<f;i++){
      cin>>x>>y;
      grid[x-1][y-1] = 1;
      ss.push_back(x-1);
      aa.push_back(y-1);
    }
    sort(ss.begin(),ss.end());
    median_s = ss[(ss.size()-1)/2];
    sort(aa.begin(),aa.end());
    int median_a = aa[(aa.size()-1)/2];

    cout<<"(Street: "<<median_s+1<<", Avenue: "<<median_a+1<<")"<<endl;
  }
}
      
