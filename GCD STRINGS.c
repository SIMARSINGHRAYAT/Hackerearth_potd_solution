#include<stdio.h>
#define m 1000000007u
typedef long long unsigned llu;
typedef unsigned u;
u P(u b,u e){
u r=1;
for(;e;e>>=1){
if(e&1)r=r*(llu)b%m;
b=b*(llu)b%m;
}
return r;
}
u G(u b,u e,u x){
if(e<2)return e*x;
u r=1,s=b,k=1u<<31;
while(!(k&e))k>>=1;
for(;k>>=1;){
r=r*(llu)(b+1)%m;
b=b*(llu)b%m;
if(e&k){
if((r+=b)>=m)r-=m;
b=b*(llu)s%m;
}
}
return r*(llu)x%m;
}
u D[64],M[64],R[64],L[64],PL[64],E;
u S(u n,u s){
if(!n)return 0;
if(n<L[s]){
if(s==E)return P(2,n-1);
else return S(n,s+1);
}
return(G(PL[s],n/L[s],R[s])*(llu)P(2,n%L[s])+S(n%L[s],s))%m;
}
void F(u a,u b,u s){
D[s]=a/b;
PL[s]=P(2,L[s]=a);
if((M[s]=a%b)){
F(b,a%b,s+1);
R[s]=S(a,s+1);
}
else R[E=s]=P(2,a-1);
}
int main(){
u t,x,y;
for(scanf("%u",&t);t--;){
scanf("%u%u",&x,&y);
F(x,y,0);
printf("%u\n",*R);
}
return 0;
}