#ifndef EXPRESION_TREE_H
#define EXPRESION_TREE_H
#include <vector>
#include "StackComoListaEnlazada.h"
using namespace std;
template <typename T>
class ExpresionTree{
public:
    int getHeight(Node<T>* node){
        if(!node)return 0;
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
   void fill(Node<T>* node,vector<vector<char>>& ret, int lvl,int l,int r){
        if(!node || node->valor==0)return;
        ret[lvl][(l + r) / 2] = node->valor;
        fill(node->left, ret, lvl + 1, l, (l + r) / 2);
        fill(node->right, ret, lvl + 1, (l + r + 1) / 2, r);
   }
   vector<vector<char>> printTree(Node<T>* root) {
      int h = getHeight(root);
      //Equivale a 2 a la h menos 1,es el operador de movimiento de bits
      int leaves = (1 << h) - 1;
      vector < vector <char> > ret(h, vector <char>(leaves));
      fill(root, ret, 0, 0, leaves);
      return ret;
   }
   void imprimir(Node<T>* root){
        vector<vector<char>>ans =printTree(root);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
   }

};
#endif
