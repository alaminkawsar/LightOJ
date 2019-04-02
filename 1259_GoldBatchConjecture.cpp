/*Problem Link: http://lightoj.com/volume_showproblem.php?problem=1259 */
/*Sol: At first all prime number from 2 to MAX stored in an boolean array named num[] through sieve function, After that for a given number,subtract prime one by one from the given number and check the subtraction result prime or not trough the boolean array named num[].If the subtraction result is prime then count it.
Continue this process until the resulting prime not more than the previous prime.*/
/*author: Al Amin Kawsar
  Date  : 3/4/2019
*/
#include<bits/stdc++.h>
#define MAX 10000000
#define clr(a) memset(a,0,sizeof(a))
using namespace std;

vector<int>prime;
bool num[MAX+2];
void sieve(){
    num[0] = true;
    num[1] = true;

    for (int i = 2; i <= MAX; i++) {
        if(num[i] == false) {
            prime.push_back(i);
            for (int j = 2 * i; j <= MAX; j = j + i) {
                num[j] = true;
            }
        }
    }
}

int main()
{
    sieve();
    int test,t=0;
    scanf("%d",&test);
    while(test--){
        int n;
        scanf("%d",&n);
        int cnt=0,tr=0;
        for (int i=0; ;i++){
            int t=n-prime[i];
            if (prime[i]>t) break;
            if (num[t]==0){
                cnt++;
            }
        }
        printf("Case %d: %d\n",++t,cnt);
    }


    return 0;
}
