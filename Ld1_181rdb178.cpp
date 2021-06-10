

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <cmath>

using namespace std;

float valueA (float x){
    float valA = x*x+ log(x);
    return valA;
}

float valueB (float x){
    float valB =sqrt(x+x*x-10);
    return valB;
}

float function1 (float a, float b) {
    float Y1  = a/2 +(a+b)/2;
    return Y1;
}

float function2 (float a, float b){
    float Y2 = (a*a +b*b)/(a*b);
    return Y2;
}

void comparison (float a,float b){
    if ((a/10)<b) {
        cout<<"Rezultāts funkcijai Y: "<<setprecision(3)<<fixed<< function1(a,b);
    }
    else  {
        cout<<"Rezultāts funkcijai Y: "<<setprecision(3)<<fixed<< function2(a,b);
    }
}

void checkValue(float x){
    if (x<=0.0001 || (x+x*x-10)<=0.0001) 
    {
        cout<< "Kļūda! Ar ievadīto X vertibu funkcijas izpildīt nevar. ";
        exit(0);
    }
}

int main()
{
    //cout<<"Jolanta Bērziņa 181RDB178 8. grupa\n";
    float x;
    string answer;
       
    cout<<"Ievadiet vertību X:\n";
    cin >> x;
                
        if (!cin.fail() && (cin.peek()==EOF || cin.peek()=='\n') ) 
        {       
              
            checkValue(x);
            float a=valueA(x);
            float b=valueB(x);
            comparison(a,b);
            
            //iztukšot buferi pirms jaunas datu ievades... 
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\nVai vēlaties turpināt? (y/n)\n";
            cin>>answer;
            if  (answer=="y"||answer=="Y") main();
        }
        else 
        {
            cout << "\nKļūda! Jūs neievadījāt skaitli!\n";
            cin.clear();
            cin.ignore(100,'\n');
            main();
        }
        
    return 0;    
}


