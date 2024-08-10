#include<bits/stdc++.h>
using namespace std;

template<typename T, typename T_Iterable> 
vector<pair<T, int>> run_length_encoding(const T_Iterable& a) {
   vector<pair<T, int>> res;
   int n = (int)a.size();
   
   int i = 0;
   while(i < n) {
      int j = i;
      while(j < n && a[j] == a[i]) j++;
      res.emplace_back(a[i], j - i);
      i = j;
   }
   return res;
}