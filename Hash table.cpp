#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;
const int T_S = 200;

class HashTableEntry {
   public:
      int k;
      int v;
      HashTableEntry(int k, int v) {
         this->k= k;
         this->v = v;
      }
};
class HashMapTable {
   private:
      HashTableEntry **t;
   public:
      HashMapTable() {
         t = new HashTableEntry * [T_S];
         for (int i = 0; i< T_S; i++) {
            t[i] = NULL;
         }
      }
      int HashFunc(int k) {
         return k % T_S;
      }
      void Insert(int k, int v) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] != NULL)
            delete t[h];
         t[h] = new HashTableEntry(k, v);
      }
      int SearchKey(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL && t[h]->k != k) {
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL)
            return -1;
         else
            return t[h]->v;
      }
      void Remove(int k) {
         int h = HashFunc(k);
         while (t[h] != NULL) {
            if (t[h]->k == k)
               break;
            h = HashFunc(h + 1);
         }
         if (t[h] == NULL) {
            cout<<"Nenhum elemento encontrado com esta chave"<<k<<endl;
            return;
         } else {
            delete t[h];
         }
         cout<<"Elemento deletado"<<endl;
      }
      ~HashMapTable() {
         for (int i = 0; i < T_S; i++) {
            if (t[i] != NULL)
               delete t[i];
               delete[] t;
         }
      }
};
int main() {
   HashMapTable hash;
   int k, v;
   int c;
   while (1) {
      cout<<"1.Inserir elemento na Tabela"<<endl;
      cout<<"2.Procurar elemento pela chave"<<endl;
      cout<<"3.Apagar elemento pela chava"<<endl;
      cout<<"4.Sair"<<endl;
      cout<<"Entre com a opção desejada: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"Entre com o elemento a ser inserido: ";
            cin>>v;
            cout<<"Entre com a chave que o valor a ser inserido terá: ";
            cin>>k;
            hash.Insert(k, v);
         break;
         case 2:
            cout<<"Entre a chave do elemento a ser procurado: ";
            cin>>k;
            if (hash.SearchKey(k) == -1) {
               cout<<"Nenhum elemento encontrado com esta chava "<<k<<endl;
               continue;
            } else {
               cout<<"Element at key "<<k<<" : ";
               cout<<hash.SearchKey(k)<<endl;
            }
         break;
         case 3:
            cout<<"Entre a chave a ser deletada: ";
            cin>>k;
            hash.Remove(k);
         break;
         case 4:
            exit(1);
         default:
            cout<<"\nEntre com uma opção válida\n";
      }
   }
   return 0;
}