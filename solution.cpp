#include <bits/stdc++.h>

using namespace std; 

struct factno 
{ 
   long long value; 
   int factorial_signs; 
   factno(string s)
   { 
      factorial_signs=0; 
      sscanf(s.c_str(),"%lld",&value); 
      assert(value<(1000000000L));
      for(int i=0;i<s.size();i++) 
         if(s[i]=='!') 
            factorial_signs++; 

      while(factorial_signs && value<=12)
      { 
         long long f=1; 
         for(int i=2;i<=value;i++)
            f*=i; 
         value=f; 
         factorial_signs--; 
      }

   }

};

bool operator < (const factno &A, const factno &B)
{ 
   if(A.factorial_signs!=B.factorial_signs)
      return A.factorial_signs<B.factorial_signs; 
   if(A.value!=B.value)
      return A.value<B.value; 
   return 0; 
} 

int compare(factno X, factno Y)
{ 
   if(X<Y)
      return -1; 
   if(Y<X)
      return 1; 
   return 0; 
} 

int main()
{
   int t;
   cin>>t;
   assert(t<=200);
   while(t--)
   {
      string a,b;
      cin>>a>>b;
      assert(a.length()>=1 && a.length()<=50);
      assert(b.length()>=1 && b.length()<=50);
      
      factno A(a), B(b);
      cout<<compare(A,B)<<endl;
   }
   return 0;
}
