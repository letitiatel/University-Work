#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

ifstream f("teste.txt");
ofstream g("timp.out");

int *v = new int[10000000];
int *copie= new int[10000000];
int n,maxi=0,nrteste;

void generarefisier();
bool test_sort(int v[],int n);


void merge(int v1[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int m = r - q;


  int L[n1], M[m];

  for (int i = 0; i < n1; i++)
    L[i] = v1[p + i];
  for (int j = 0; j < m; j++)
    M[j] = v1[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < m)
    {
    if (L[i] <= M[j])
     {
      v1[k] = L[i];
      i++;
     }
    else
        {
      v1[k] = M[j];
      j++;
        }
    k++;
  }


  while (i < n1) {
    v1[k] = L[i];
    i++;
    k++;
  }

  while (j < m) {
    v1[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int v1[], int l, int r)
{
  if (l < r)
    {

     int m = l + (r - l) / 2;

     mergeSort(v1, l, m);
     mergeSort(v1, m + 1, r);
     merge(v1, l, m, r);
    }
}

int maxim(int v[100],int n)
{
    int maxi=v[0];
    for (int i=1;i<n;i++)
        if(v[i]>maxi)
            maxi=v[i];
    return maxi;
}

void sortcifre(int v[100],int n,int exp)
{
    int v2[n],fr[10]={0};

    for(int i=0;i<n;i++)
        fr[(v[i]/exp)%10]++;//calculam frecvente fiecarei cifre

    for(int i=1;i<10;i++)
        fr[i]=fr[i]+fr[i-1];

    for(int i=n-1;i>=0;i--)
    {
        v2[fr[(v[i]/exp)%10]-1]=v[i];
        fr[(v[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
        v[i]=v2[i];

}

void radixsort(int v[100],int n)
{
    int maxi=maxim(v,n);
    for(int exp=1;maxi/exp>0;exp=exp*10)
        sortcifre(v,n,exp);
}



void shellSort(int v3[], int n3)
{

  for (int intr = n3 / 2; intr > 0; intr /= 2)
    {
    for (int i = intr; i < n3; i += 1)
        {
          int temp = v3[i];
          int j;
          for (j = i; j >= intr && v3[j - intr] > temp; j -= intr)
             {
                 v3[j] = v3[j - intr];
             }
          v3[j] = temp;
        }
    }
}

void countSort(int v[], int n)
{
    int maxi=v[0];
    for (int i=1; i<n; i++)
        if (v[i]>maxi)
            maxi=v[i];

    int *vcount=new int[maxi+1];

    for(int i=0;i<maxi+1;i++)
        vcount[i]=0;


    for (int i=0; i<n; i++)
        vcount[v[i]]++;

    for (int i=1; i<=maxi; i++)
        vcount[i]=vcount[i]+vcount[i-1];

    int sortedv[n];
    for (int i=n-1; i>=0; i--)
    {
        sortedv[vcount[v[i]]-1]=v[i];
        vcount[v[i]]--;
    }

    for (int i=0; i<n; i++)
            v[i] = sortedv[i];

    delete[] vcount;
}
void heapify(int v5[], int n5, int i)
  {
    // gasim cea mai mare radacina si copilul stang/drept
    int larg = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n5 && v5[l] > v5[larg])
      larg = l;

    if (r < n5 && v5[r] > v5[larg])
      larg = r;

    // facem swap si daca radacina nu este mai mare continuam algoritmul
    if (larg != i) {
      swap(v5[i], v5[larg]);
      heapify(v5, n5, larg);
    }
  }

  void heapSort(int v5[], int n5)
  {
    // se construieste  max heap ul
    for (int i = n5 / 2 - 1; i >= 0; i--)
      heapify(v5, n5, i);

    // Heap sort
    for (int i = n5 - 1; i >= 0; i--)
        {
      swap(v5[0], v5[i]);


      heapify(v5, i, 0);
    }
  }



  bool test_sort(int v[],int n)
{
    if(n==0 || n==1)
        return true;
    for(int i=1;i<n;i++)
        if(v[i] < v[i-1])
        return false;
    return true;
}




/*void generarefisier()
{
    ofstream a("teste.txt");
    a<<24<<endl;
    // test cu un numar mic de elemente, hardcoded
    a<<10<<endl<<"248206 585825 652412 335040 72031 1797668 282309 975160 609689 473890"<<endl;
}
*/

int main()
{

    //generarefisier();
    clock_t inceput,final;
    int nr,p,maxi;
    f>>nr;
    for(p=1;p<=nr;p++)
{
       g<<"testul"<<" "<<p<<":"<<endl;
       g<<endl;
       f>>n>>maxi;

    for(int i=0;i<n;i++)
    {
        v[i]=rand()%maxi;
        cout<<v[i]<<" ";

    }

     cout<<endl;

      for(int i=0;i<n;i++)
           {
               copie[i]=v[i];
           }
    cout<<endl;

     //inceput = clock();
     auto start = high_resolution_clock::now();
     mergeSort(copie,0,n-1);

    //final = clock();
    if(test_sort(copie,n))
    {
        cout<<"MergeSort: ";
        for (int i=0; i<n; i++)
            cout<<copie[i]<< " ";
            cout<<endl;
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(stop- start);

        g<<"timpul de executare:"<<duration.count()<<" nanosecunde"<<endl;

    }

     for(int i=0;i<n;i++)
            {copie[i]=v[i];
            }
    //inceput = clock();
    auto start1 = high_resolution_clock::now();
    heapSort(copie,n);

    //final = clock();
    if(test_sort(copie,n))
    {

        cout<<"HeapSort: ";
        for (int i=0; i<n; i++)
            cout<<copie[i]<< " ";
            cout<<endl;
             auto stop1 = high_resolution_clock::now();
            auto duration1 =duration_cast<nanoseconds>(stop1- start1);
        g<<"timpul de executare:"<<duration1.count()<<" nanosecunde"<<endl;

    }


      for(int i=0;i<n;i++)
            {copie[i]=v[i];
             }
    //inceput = clock();
    auto start2 = high_resolution_clock::now();
    shellSort(copie,n);
    //final = clock();
    if(test_sort(copie,n))
    {
       cout<<"shellSort:";
        for (int i=0; i<n; i++)
            cout<<copie[i]<< " ";
            cout<<endl;
            auto stop2 = high_resolution_clock::now();
            auto duration2 =duration_cast<nanoseconds>(stop2- start2);
        g<<"timpul de executare:"<<duration2.count()<<" nanosecunde"<<endl;

    }


        for(int i=0;i<n;i++)
            {copie[i]=v[i];
             }
    //inceput = clock();
    auto start3 = high_resolution_clock::now();
    radixsort(copie,n);
    //final = clock();
    if(test_sort(copie,n))
    {
       cout<<"radixsort:";
        for (int i=0; i<n; i++)
            cout<<copie[i]<< " ";
            cout<<endl;
            auto stop3 = high_resolution_clock::now();
            auto duration3 =duration_cast<nanoseconds>(stop3- start3);
        g<<"timpul de executare:"<<duration3.count()<<" nanosecunde"<<endl;


    }

    //inceput = clock();
     auto start4 = high_resolution_clock::now();
    countSort(copie,n);
    //final = clock();
    if(test_sort(copie,n))
    {
       cout<<"Countsort:";
        for (int i=0; i<n; i++)
            cout<<copie[i]<< " ";
            cout<<endl;
            auto stop4 = high_resolution_clock::now();
            auto duration4 =duration_cast<nanoseconds>(stop4- start4);
        g<<"timpul de executare:"<<duration4.count()<<" nanosecunde"<<endl;
        g<<endl;


    }

}


      if(v!=NULL)
    {
        delete[] v;
        v = NULL;
    }

    if(copie!=NULL)
    {
        delete[] copie;
        copie = NULL;
    }

    return 0;
}
