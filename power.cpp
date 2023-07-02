#include <iostream>
#include <string>

using namespace std;
#include <iostream>

using namespace std;

long long Pow(int X, int N) {
    if (N == 0) {
        return 1;
    }

    return X * Pow(X, N - 1);
}

int main(){
   int x;
   int n;
   cin>>x>>n;
   cout<<Pow(x,n);

}
