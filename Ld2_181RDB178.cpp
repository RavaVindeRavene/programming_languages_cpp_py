#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include<ctime>

using namespace std;
double userInputDouble(){
    bool ok = false; double x;
    while (!ok)
    {
            cin >> x;
        if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n'))
        {
            ok = true; return x;
        }
        else
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Ievades kļūda. Atkārtoti ievadiet skaitli: "  <<endl;
        }
    }
    return -1;
}
void manualaIevade(int Rinda, int Kolonna, double **mas){
   double x;
   for ( int i=0; i<Rinda; i++)
    {
        for (int j=0; j<Kolonna; j++)
        {
            printf("Ievadiet masīva %d %d elementu: ",i,j);
            x = userInputDouble();
            mas[i][j]=x;
            //cin>>mas[i][j];
            cout << "\n"; 
        }
    } 
}
void randomIevade(int Rinda, int Kolonna, double **mas){
    for ( int i=0; i<Rinda; i++)
    {
        for (int j=0; j<Kolonna; j++)
        {
          mas[i][j]=(float)rand()*101-51; 
        }
    } 
}

void masivaIzvade (int Rinda, int Kolonna, double **mas){
    cout<<"\nMasivs:"<<endl;
        for (int i=0; i<Rinda; i++) {
            cout << "\n";
            for (int j=0; j<Kolonna; j++){
                printf("%7.2f\t", mas[i][j]);
            }
        }
}

void masivaParveide (int rinda, int kollona, double **mas){
    int swapi=0; int swapj=1; float temp;
    if (rinda%2==0){
        for(int i=0; i<rinda; i=i+2){
            for(int j=0; j<kollona; j=j+2){
                temp=mas[swapi][j];
                mas[swapi][j]=mas[swapj][j];
                mas[swapj][j]=temp;
            }
        swapi=swapi+2;
        swapj=swapj+2;
        }
    }
    else {
        for(int i=0; i<rinda-1; i=i+2){
            for(int j=0; j<kollona; j=j+2){
               temp=mas[swapi][j];
                mas[swapi][j]=mas[swapj][j];
                mas[swapj][j]=temp; 
            }
        swapi=swapi+2;
        swapj=swapj+2;
        }
    }
}

int userInputInteger(string msg){
    bool ok = false;
        int x;
        cout << msg << "\n";
    while (!ok)
    {
        cin >> x;
        if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n'))
        {
            ok = true; return x;
        }
        else
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Ievades kļūda. Atkārtoti ievadiet skaitli: " << endl;
        }
    }
            return -1;
}

int main( int argc, char *argv[])
{
    cout<<"Jolanta Bērziņa 181RDB178 8. grupa\n";
    int  rows, col, i;
    rows=userInputInteger("Ievadiet rindu skaitu:");
    col=userInputInteger("Ievadiet kollonu skaitu:");
    string arguments;
    //masīva izmera inicializacija
    double **mas=new double*[rows];
    for (int i=0; i<rows; i++){
        mas[i]=new double[col];
    }
    arguments=argv[i];
    if (arguments == "-rand") {
        randomIevade(rows, col, mas);
        masivaIzvade(rows,col, mas);
    }
    else {
        manualaIevade(rows,col, mas);
        masivaIzvade(rows,col,mas);
    }
    cout<<"\n"<<endl;
    cout<<"Masīvs pēc pārveidošanas: "<<endl;
    masivaParveide(rows, col, mas);
    masivaIzvade(rows,col,mas);
    
    return 0;
}


