#include <iostream>
#include <string>

using namespace std;
string kthChildNthGeneration(int n, long long int k) {
  // Write your code here
  if(n==1||k==1) return "Male";
  long long int parent = (k+1)/2;
  string pG = kthChildNthGeneration(n-1, parent);
  if(k==2*parent-1) return pG;
  else{
	  if(pG == "Male") return "Female";
	  else return "Male";
  }

}
int main(){
   int n;
   long long int k;
   cin>>n>>k;
   cout<<kthChildNthGeneration(n,k);
}
