#include <iostream>
#include <vector>

using namespace std;

long long count1 = 0;

void inversionSort(vector<long long> &team,long long l, long long r){

  //for every element in the second part - doing the inversion sort
  for(long long i=(r-l)/2 + 1; i<=r;i++){
    long long j = i;
    while(j-1>=l && team[j] < team[j-1]){
      team[j-1] += team[j];
      team[j] = team[j-1] - team[j];
      team[j-1] -= team[j];
      count1++;
      j--;
    }
  }
}

void merge(vector<long long> &team,long long l,long long r){
  if(l>=r)
    return;
  merge(team,l,l + (r-l)/2);
  merge(team,l + (r-l)/2+1,r);
  inversionSort(team,l,r);
}


int main(){
  long long n;cin>>n;
  vector<long long> team(n);
  for(long long i=0;i<n;i++)
    cin>>team[i];
  merge(team,0,n-1);
  cout<<count1<<endl;
}
