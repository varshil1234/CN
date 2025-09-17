#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const lli mod=1e9+7;
const lli siz=1e6;
lli mod_mul(lli a,lli b){
    return (a%mod * b%mod)%mod;
}
vector<lli>fact(siz+1,1);
vector<lli>ifact(siz+1,1);
lli bin_expo(lli a,lli b){
    lli res=1;
    while(b>0){
        if(b&1){
            res=mod_mul(res,a);
        }
        a=mod_mul(a,a);
        b>>=1;
    }
    return res;
}
void cal_fact(){
    for(lli i=1;i<=siz;i++){
        fact[i]=mod_mul(fact[i-1],i);
    }
    ifact[siz]=bin_expo(fact[siz],mod-2);
    for(lli i=siz-1;i>=0;i--){
        ifact[i]=mod_mul(i+1,ifact[i+1]);
    }    
}
lli mod_sum(lli a,lli b){
    return (a+b)%mod;
}
lli ncr(lli n,lli r){
    return mod_mul(fact[n],mod_mul(ifact[r],ifact[n-r]));
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
 lli n;
 cin>>n;
 cal_fact();
 lli sum=0;
 for(lli partitions=0;partitions<=n-1;partitions++){
 lli N=n+partitions-1;
 lli R=partitions;
 sum=mod_sum(sum,ncr(N,R));
 }
 sum=mod_mul(sum,2);
 sum=(sum-n+mod)%mod;
 cout<<sum<<"\n";
}