#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;
void llenarVector(int vector[], int total)
{
    // Número aleatorios entre 1 y 50000:
    for(int i=0; i<total; i++)
        vector[i]=1+rand()%(50000);
}
void imprimirVector(int vector[], int total)
{
    cout<<"\nElementos del vector: \n";
    for(int i=0; i<total; i++)
        cout<<vector[i]<< " ";
}
void intercambiar(int &a, int &b)
{
    int aux=a;
    a=b;
    b=aux;
}
void ordenSecuencial(int vector[], int total)
{
    for(int i=0; i<total; i++)
    {
        for(int j=i+1; j<total; j++)
        {
            if(vector[i]>vector[j])
                intercambiar(vector[i], vector[j]);
        }
    }
}
void ordenBurbuja(int v[], int n){
    int i=0,j=0;
    int aux;
    for(i=1;i<n;i++)
        for(j=0;j<(n-i);j++){
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
}
void burbujaMejorado(int arreglo[], int tamano)
{
    int comparaciones = tamano;
    bool termino = false;
    for (int i = 0; i<(tamano-1) ; i++)
    {
        if (termino)
            break;
        termino = true;
        for (int j = 0; j<comparaciones-1 ; j++)
            if(arreglo[j] > arreglo[j+1])
            {
                intercambiar(arreglo[j],arreglo[j+1]);
                termino = false;
            }
        comparaciones--;
    }
}
void OrdenamientoQuicksort(int a[], int primerValor, int ultimoValor)
{
    int central, i, j, pivote;
    central= (primerValor+ultimoValor)/2; //Posicion central del arreglo
    pivote= a[central]; //Capturar el valor medio del arreglo
    i = primerValor;
    j = ultimoValor;
    do{
        //Separando en dos partes el arreglo
        while(a[i] < pivote) i++; //Separando los valores menores al pivote
        while(a[j] > pivote) j--; //Separando los valores mayores al pivote
        if(i<=j){
            int temporal;
            //Intercambio de valores
            temporal = a[i];
            a[i] = a[j];
            a[j] = temporal;
            i++;
            j--;
        }
    }while(i<=j);
    if (primerValor < j)
        OrdenamientoQuicksort(a, primerValor, j);
    if (i < ultimoValor)
        OrdenamientoQuicksort(a, i, ultimoValor);
}
void ordenShell(int a[], int n){
    int ints,i,aux;
    bool band;
    ints=n;
    while(ints>1){
        ints=ints/2;
        band=true;
        while(band==true){
            band=false;
            i=0;
            while((i+ints)<n){
                if(a[i]>a[i + ints]){
                    aux=a[i];
                    a[i]=a[i + ints];
                    a[i + ints]=aux;
                    band=true;
                }
                i++;
            }
        }
    }
}
void ordenShell2(int a[], int n){
    //optimizado
    int i,j,inc;
    int temp;
    for(inc=1;inc<n;inc=inc*3+1);
    while(inc>0){
        for(i=inc;i<n;i++){
            j=i;
            temp=a[i];
            while((j>=inc)&&(a[j-inc]>temp)){
                a[j]=a[j-inc];
                j=j-inc;
            }
            a[j]=temp;
        }
        inc=inc/2;
    }
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);
    return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}
int busquedabinaria(int vector[], int tamanio, int num)
{
    int izq=0, der=tamanio;
    int central = (izq+der)/2;
    while(izq < der && num!=vector[central])
    {
        if(num>vector[central])
            izq=central+1;
        else if (num < vector[central])
            der=central-1;

        central = (izq+der)/2;
    }
    if(vector[central]==num)
        return central+1;
    else
        return -1; // no lo encontrar
}
void n1vector(string nombres[], int tamanio) {
    for (int k = 0; k < tamanio; k++) {
        cout << endl << nombres[k];
    }
}
void ordenar21(string vector[], int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        for (int j = i + 1; j < tamanio; j++) {
            if (vector[i].compare(vector[j]) < 0) {
                string aux;
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
    }
}
void raa(string ciudad[], int temp[], const int tam)
{
    for (int i = 0; i < tam; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (ciudad[i].compare(ciudad[j]) > 0) {
                string aux;int au;
                aux = ciudad[i];
                ciudad[i] = ciudad[j];
                ciudad[j] = aux;
                au=temp[i];
                temp[i]=temp[j];
                temp[j]=au;
            }
        }
    }
}
void ordenSecuencialnume(int vector[], const int total, string ciudad[]) {
    for (int i = 0; i < total; i++) {
        for (int j = i + 1; j < total; j++) {
            if (vector[i] > vector[j]){
                intercambiar(vector[i], vector[j]);
                string aux;
                aux = ciudad[i];
                ciudad[i] = ciudad[j];
                ciudad[j] = aux;
            }
        }
    }
}
int main() {
    bool y;
    LARGE_INTEGER t_ini, t_fin;
    int total = 86000;
    int vectorsec[total];
    int vectorburbuja[total];
    int vectoriburbuja2[total];
    int vectoriquicksort[total];
    int vectorisheel[total];
    int vectorisheel2[total];
    srand(time(NULL));
    //Numeros aleatorios
    for(int x=0; x<total; x++ ){
        int elemento = 1+rand()%(20000);
        vectorsec[x]= elemento;
        vectorburbuja[x]= elemento;
        vectoriburbuja2[x]= elemento;
        vectoriquicksort[x]= elemento;
        vectorisheel[x]= elemento;
        vectorisheel2[x]= elemento;
    }
    const int tama=4;
    string ciudades[tama] = {"Quito", "Guayaquil","Esmeraldas","Cali"};
    int tempe[tama]={17, 23, 28, 18};
    int b;
    do {
    double secs;
        cout << "Cual metodo de ordenamiento desea usar?" << endl;
        cout << "1. Ordenamiento secuencial" << endl;
        cout << "2. Ordenamiento burbuja" << endl;
        cout << "3. Ordenamiento burbuja mejorado" << endl;
        cout << "4. Ordenamiento Quicksort" << endl;
        cout << "5. Ordenamiento shell" << endl;
        cout << "6. Ordenamiento shell2" << endl;
        cout << "7. Ordenar de manera alfabetica las ciudades" << endl;
        cout << "8. Ordenar de manera numerica las temperaturas" << endl;
        cin >> b;
        switch (b) {
            case 1 :
            {
    //orden sec
    QueryPerformanceCounter(&t_ini);
    ordenSecuencial(vectorsec,total);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout<<"Tiempo de orden del secuencial"<<endl;
    cout<<(secs*1000.0);
    cout<<""<<endl;
    break;
                }
    case 2:
    {
    // orden burbuja
    QueryPerformanceCounter(&t_ini);
    ordenBurbuja(vectorsec,total);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout<<"Tiempo de orden del burbuja"<<endl;
    cout<<(secs*1000.0);
    cout<<""<<endl;
    break;
        }
    case 3:
    {
    // orden burbuja mejorado
    QueryPerformanceCounter(&t_ini);
    burbujaMejorado(vectorsec,total);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout<<"Tiempo de orden del burbuja mejorado"<<endl;
    cout<<(secs*1000.0);
    cout<<""<<endl;
    break;
        }
            case 4:
            {
    // orden burbuja Quicksort
    QueryPerformanceCounter(&t_ini);
    OrdenamientoQuicksort(vectorsec,0,total-1);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout<<"Tiempo de orden del Quicksort"<<endl;
    cout<<(secs*1000.0);
    cout<<""<<endl;
    break;
                }
                case 5:
                {
    // orden burbuja shell
    QueryPerformanceCounter(&t_ini);
    ordenShell(vectorsec,total);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout<<"Tiempo de orden del shell"<<endl;
    cout<<(secs*1000.0);
    cout<<""<<endl;
    break;
                    }
                    case 6:
                    {
    // orden burbuja shell 2
    QueryPerformanceCounter(&t_ini);
    ordenShell2(vectorsec,total);
    QueryPerformanceCounter(&t_fin);
    secs = performancecounter_diff(&t_fin, &t_ini);
    cout<<"Tiempo de orden del shell 2"<<endl;
    cout<<(secs*1000.0);
    cout<<""<<endl;
    break;
                        }
    case 7:
    {
        raa(ciudades,tempe,tama);
        cout<<endl<<endl<<"Se ordenara de manera alfabetica los nombres de las ciudades con sus temperaturas"<<endl;
        for (int aa = 0; aa < tama; aa++) {
            cout << endl <<"Ciudad "<<ciudades[aa]<<";temperatura "<<tempe[aa]<<endl;
        }
        break;
        }
        case 8:
        {
            ordenSecuencialnume(tempe,tama,ciudades);
            cout<<endl<<endl<<"Se ordenara de manera numerica las temperaturas junto con sus ciudades "<<endl;
            for (int gg = 0; gg < tama; gg++) {
                cout << endl <<"Ciudad  "<<ciudades[gg]<<";temperatura "<<tempe[gg]<<endl;
            }
            break;

            }
    }
    cout<<""<<endl;
    cout<<"Quiere repetir el proceso"<<endl;
        cout<<"1= si | 0 = no"<<endl;
        cin>>y;
} while (y == 1);
    return 0;
}
