#include <iostream>

using namespace std;


void merge(int v[], int p, int q, int r)
{
  int n = q - p + 1;
  int m = r - q;


  int L[n], M[m];

  for (int i = 0; i < n; i++)
    L[i] = v[p + i];
  for (int j = 0; j < m; j++)
    M[j] = v[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n && j < m)
    {
    if (L[i] <= M[j])
     {
      v[k] = L[i];
      i++;
     }
    else
        {
      v[k] = M[j];
      j++;
        }
    k++;
  }


  while (i < n) {
    v[k] = L[i];
    i++;
    k++;
  }

  while (j < m) {
    v[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int v[], int l, int r)
{
  if (l < r)
    {

     int m = l + (r - l) / 2;

     mergeSort(v, l, m);
     mergeSort(v, m + 1, r);
     merge(v, l, m, r);
    }
}

void afisare(int v[], int size)
{
  for (int i = 0; i < size; i++)

    cout << v[i] << " ";
  cout << endl;
}

  int main()
  {
  int v[] = {6, 5,10, 9, 1,67,90};
  int size = sizeof(v) / sizeof(v[0]);

  mergeSort(v, 0, size - 1);

   cout << "Vectorul sortat: \n";
   afisare(v, size);

  return 0;
}

