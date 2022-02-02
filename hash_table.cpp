#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;
const int T_S = 200;

class HashTableEntry
{
public:
   int key;
   int value;
   HashTableEntry(int key, int value)
   {
      this->key = key;
      this->value = value;
   }
};
class HashMapTable
{
private:
   HashTableEntry **t;

public:
   HashMapTable()
   {
      t = new HashTableEntry *[T_S];
      for (int i = 0; i < T_S; i++)
      {
         t[i] = NULL;
      }
   }
   int HashFunc(int key)
   {
      return key % T_S;
   }
   void Insert(int key, int value)
   {
      int h = HashFunc(key);
      while (t[h] != NULL && t[h]->key != key)
      {
         h = HashFunc(h + 1);
      }
      if (t[h] != NULL)
         delete t[h];
      t[h] = new HashTableEntry(key, value);
   }
   int SearchKey(int key)
   {
      int h = HashFunc(key);
      while (t[h] != NULL && t[h]->key != key)
      {
         h = HashFunc(h + 1);
      }
      if (t[h] == NULL)
         return -1;
      else
         return t[h]->value;
   }
   void Remove(int key)
   {
      int h = HashFunc(key);
      while (t[h] != NULL)
      {
         if (t[h]->key == key)
            break;
         h = HashFunc(h + 1);
      }
      if (t[h] == NULL)
      {
         cout << "Nenhum elemento encontrado com esta chave" << key << endl;
         return;
      }
      else
      {
         delete t[h];
      }
      cout << "Elemento deletado" << endl;
   }
   ~HashMapTable()
   {
      for (int i = 0; i < T_S; i++)
      {
         if (t[i] != NULL)
            delete t[i];
         delete[] t;
      }
   }
};
int main()
{
   HashMapTable hash;
   int key, value;
   int c;
   while (1)
   {
      cout << "1.Inserir elemento na Tabela" << endl;
      cout << "2.Procurar elemento pela chave" << endl;
      cout << "3.Apagar elemento pela chave" << endl;
      cout << "4.Sair" << endl;
      cout << "Entre com a opcao desejada: ";
      cin >> c;
      switch (c)
      {
      case 1:
         cout << "\nEntre com o elemento a ser inserido: ";
         cin >> value;
         cout << "Entre com a chave que o valor a ser inserido tera: ";
         cin >> key;
         hash.Insert(key, value);
         break;
      case 2:
         cout << "\nEntre a chave do elemento a ser procurado: ";
         cin >> key;
         if (hash.SearchKey(key) == -1)
         {
            cout << "\nNenhum elemento encontrado com esta chave " << key << "\n"
                 << endl;
            continue;
         }
         else
         {
            cout << "Elemento na chave " << key << " : ";
            cout << hash.SearchKey(key) << endl;
         }
         break;
      case 3:
         cout << "Entre a chave a ser deletada: ";
         cin >> key;
         hash.Remove(key);
         break;
      case 4:
         exit(1);
      default:
         cout << "\nEntre com uma opcao valida\n";
      }
   }
   return 0;
}