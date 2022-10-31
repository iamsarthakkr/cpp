#include<bits/stdc++.h>

// Simple Segment tree with sum and other function(point update and range calc)
struct segtree {
   int leftmost, rightmost;
   segtree* left;
   segtree* right;

   long long sum;

   segtree(int l, int r, long long v) {
      this->leftmost = l;
      this->rightmost = r;
      if(r == l + 1) {
         sum = v;
         return;
      }

      int m = (r + l) / 2;
      left = new segtree(l, m, v);
      right = new segtree(m, r, v);
      recalc();
   }
   
   template<typename T>
   segtree(int l, int r, std::vector<T>& arr) {
      this->leftmost = l;
      this->rightmost = r;
      if(r == l + 1) {
         sum = arr[l];
         return;
      }

      int m = (r + l) / 2;
      left = new segtree(l, m, arr);
      right = new segtree(m, r, arr);
      recalc();
   }

   // OPERATIONS ON SEGMENT TREE
   void update(int i, long long v) {
      if(rightmost - leftmost == 1) {
         sum = v;
         return;
      }
      int m = (leftmost + rightmost) / 2;
      if(i < m) left->update(i, v);
      else right->update(i, v);

      recalc();
   }


   int calc(int lx, int rx) {
      if(rightmost <= lx || leftmost >= rx) return 0LL;
      if(lx <= leftmost && rightmost <= rx) return sum;

      int m = (leftmost + rightmost) / 2;
      return left->calc(lx, rx) + right->calc(lx, rx);
   }

   // recalculate value in the current node
   void recalc() {
      if(rightmost == leftmost + 1) return;
      sum = left->sum + right->sum;
   }
};