/* Sortowanie przez proste wybieranie
// Dane:    int a[n]
// Wyjście: tablica posortowana niemalejąco
// Sposób postępowania:
// Wyznaczamy najmniejszy element ciągu a[0]...a[n-1] - zamieniamy miejscami z pierwzym elementem ciągu
// Wyznaczamy najmniejszy element w a[1]..a[n-1] - zamieniamy z drugim elementem w ciągu
// Wyznaczamy najmniejszy element w a[n-2],a[n-1] - zamieniamy z (n-1)szym elementem w ciągu
*/

void selectsort(){
    int k, x;

    for (int i=0; i<n; i++) {
        k=i;
        x=a[i]
        for(int j = i+1; j<n; j++)  {
            if(a[j]<x){
                k=j;
                x=a[j];
            }
            a[k]=a[i];
            a[i]=x;
        }
    }
}