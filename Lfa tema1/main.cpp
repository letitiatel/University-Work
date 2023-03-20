#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
int n,i,j,si,k,x,muc,fnl,s1,s2,v[100],ok,nou[100];
char cuv[100],c,m[100][100];

int main()
{
    f>>n; // nr de stari
    f>>muc; // nr de muchii
    f>>fnl; // nr de stari finale
    f>>si;  // starea initiala
    f>>cuv; // cuvantul


    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            m[i][j]='-'; //matricea de adiacenta initial goala

    for(i=0; i<muc; i++)
    {
        f>>s1>>s2>>c;
        m[s1][s2]=c; // se construieste matricea de adiacenta cu muchiile automatului

    }

     for(i=0; i<fnl; i++)
    {
        f>>x;
        v[i]=x; //vector cu starile finale
    }



    int actual = (int)si;// starea actuala ia valoarea starii initiale

    for(int i = 0 ; i <strlen(cuv) ; i++) // parcurgem cuvantul
        for(int j = 0 ; j < n; j++) // parcurgem matricea pe linii
            {
                if(m[actual][j] == cuv[i]) // daca litera respectiva se regaseste in matrice pe linie o salvam intr un nou vector
                  {
                     actual = j;
                     nou[++k]=j;
                     break;
                  }
            }

       ok =0;
     for(int i = 0 ; i < fnl ; i++) //parcurgem vectorului starilor finale
        {

            if(v[i] == actual) // daca ultima starea actuala este in vector atunci cuvantul este valid
       {

            g<<"Cuvantul este acceptat"<<endl;
            for(i=0;i<k;i++) //parcurgem vectorului nou creat care reprezinta drumul si il afisam
                g<<nou[i]<<" ";
                ok = 1;
                break;
    }
}
if(ok!=1)
    cout<<"Cuvantul nu este acceptat";
    return 0;
}

