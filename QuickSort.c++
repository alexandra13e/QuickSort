#include <iostream>

using namespace std;

int a[1000003],n;
void Citire()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}
///alegem pivotul, facem impartirea in doua
///subsecvente si returneaza pozitia
///finala a pivotului

int Pivot (int st, int dr)
{
    int piv, i, j;
    piv=a[st];
    i = st + 1;
    j = dr;
    while ( i<=j )
    {
        if(a[i] <= piv) i++;
        if(piv < a[j]) j--;
        if(i < j && a[i] > piv && piv >= a[j])
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    swap(a[st],a[i-1]);
    return i-1;
}

void Qsort(int st, int dr)
{
    int p = Pivot(st,dr);
    ///[st, p-1] , [p+1, dr]
    if(st < p - 1) Qsort(st, p - 1);
    if(p + 1 < dr) Qsort(p + 1, dr);
}

void Afisare ()
{
    for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << "\n";
}
int main()
{
    Citire();
    Qsort(1,n);
    Afisare();
    return 0;
}
