#include <bits/stdc++.h>
#include<fstream>
using namespace std;
ifstream fin("date1.in");
ofstream fout("date1.out");

class node{
public:
   int data;
   node *leftChild, *rightChild;
};
node* newNode(int data){
   node* Node = new node();
   Node->data = data;
   Node->leftChild = Node->rightChild = NULL;
   return (Node);
}
node *rightChildRotate(node *x){
   node *y = x->leftChild;
   x->leftChild = y->rightChild;
   y->rightChild = x;
   return y;
}
node *leftChildRotate(node *x){
   node *y = x->rightChild;
   x->rightChild = y->leftChild;
   y->leftChild = x;
   return y;
}

///splay
node *splay(node *root, int data){
   if (root == NULL || root->data == data)
      return root;
   if (root->data > data) {
      if (root->leftChild == NULL) return root;
      if (root->leftChild->data > data) {
         root->leftChild->leftChild = splay(root->leftChild->leftChild, data);
         root = rightChildRotate(root);
      } else if (root->leftChild->data < data) {
         root->leftChild->rightChild = splay(root->leftChild->rightChild, data);
         if (root->leftChild->rightChild != NULL)
            root->leftChild = leftChildRotate(root->leftChild);
      }
      return (root->leftChild == NULL)? root: rightChildRotate(root);
   } else {
      if (root->rightChild == NULL) return root;
      if (root->rightChild->data > data) {
         root->rightChild->leftChild = splay(root->rightChild->leftChild, data);
         if (root->rightChild->leftChild != NULL)
            root->rightChild = rightChildRotate(root->rightChild);
      } else if (root->rightChild->data < data) {
         root->rightChild->rightChild = splay(root->rightChild->rightChild, data);
         root = leftChildRotate(root);
      }
      return (root->rightChild == NULL)? root: leftChildRotate(root);

   }
   return root;
}
///functie de inserare
struct node* insert(struct node *root, int k){
   if (root == NULL) return newNode(k);
   root = splay(root, k);
   if (root->data == k) return root;
   struct node *newnode = newNode(k);
   if (root->data > k) {
      newnode->rightChild = root;
      newnode->leftChild = root->leftChild;
      root->leftChild = NULL;
   } else {
      newnode->leftChild = root;
      newnode->rightChild = root->rightChild;
      root->rightChild = NULL;
   }
   return newnode;
}
///functie de stergere
node* deletenode(struct node* root, int data){
   struct node* temp;
   if (root == NULL)
      return NULL;
   root = splay(root, data);
   if (data != root->data)
      return root;
   if (!root->leftChild) {
      temp = root;
      root = root->rightChild;
   } else {
      temp = root;
      root = splay(root->leftChild, data);
      root->rightChild = temp->rightChild;
   }
   free(temp);
   return root;
}
/// functie de cautare
void search(node* root, int data){
    if (!root){
        fout << 0 << "\n";
        return;
    }
    node* temp1 = root;
    node* temp2 = NULL;
    while (temp1){
        temp2 = temp1;
        if (data < temp1->data) temp1 = temp1->leftChild;
        else if (data > temp1->data) temp1 = temp1->rightChild;
        else {
            fout << 1 << "\n";
            return;
        }
    }
    fout << 0 << "\n";
}

/// functia care cauta cel mai mare nod din arbore care este mai mic sau egal cu x
int maximY(node* root, int x) {
    if (!root) return -1;

    node* maxi = NULL;
    while (root) {
        if (root->data <= x) {
            maxi = root;
            root = root->rightChild;
        } else {
            root = root->leftChild;
        }
    }

    if (!maxi) return -1;
    return maxi->data;
}
/// functia care cauta cel mai mic nod din arbore care este mai mare sau egal cu x
int minimY(node* root, int x){
    if (!root) return -1;

    node* mini = NULL;
    while (root) {
        if (root->data >= x) {
            mini = root;
            root = root->leftChild;
        } else {
            root = root->rightChild;
        }
    }

    if (!mini) return -1;
    return mini->data;
}


void sortareInterval(node* root, int x, int y) {
    if (!root) return;
    if (root->data >= x && root->data <= y){
        sortareInterval(root->leftChild, x, y);
        fout << root->data << " ";
        sortareInterval(root->rightChild, x, y);
    } else if (root->data < x){
        sortareInterval(root->rightChild, x, y);
    } else {
        sortareInterval(root->leftChild, x, y);
    }
}
void Interval(node* root, int x, int y) {
    if (!root) return;
    if (root->data > y) sortareInterval(root->leftChild, x, y);
    else if (root->data < x) sortareInterval(root->rightChild, x, y);
    else {
        sortareInterval(root->leftChild, x, y);
        fout << root->data << " ";
        sortareInterval(root->rightChild, x, y);
    }
}

/*void print(node* root){
    if(root){
        cout << root->data << endl;
        cout << "Nodul stang " << root->data<<endl;
        print(root->leftChild);
        cout << "Nodul drept " << root->data<<endl;
        print(root->rightChild);
    }
}
*/

int q,op, x, y;
int main(){
    fin >> q;

    node* root = NULL;
     for (int i = 0; i < q; i++)
        {

        fin >> op >> x;
            switch (op) {
                    case 1:
                           root = insert(root, x);

                    break;
                    case 2:
                            root = deletenode(root, x);

                    break;
                    case 3:
                            search(root, x) ;
                    break;
                    case 4:
                            fout << maximY(root, x) << "\n";
                    break;
                    case 5:
                            fout <<minimY(root, x) << "\n";
                    break;
                    case 6:
                            fin >> y;
                            Interval(root, x, y);
                            fout << "\n";
                    break;

                }
            }

    fin.close();
    fout.close();
    return 0;
}

