
import math
import sys

def valueA(num):
    if num>0:
        a=num*num+math.log(num)
        return a;
    else: 
        print("Ar ievadīto skaitli funkciju aprēķināt nevar.")
        mainTask();
        #sys.exit() nevis mainTask() ja grib pārtraukt programmu
    
def valueB(num):
    if (num+num*num-10)>0:
        b=math.sqrt(num+num*num-10)
        return b;
    else:
        print("Ar ievadīto skaitli funkciju aprēķināt nevar.")
        mainTask();
        #sys.exit() nevis mainTask() ja grib pārtraukt programmu
    
def funkcija1(num1,num2):
    y1=num1/2 +(num1+num2)/2
    return y1;
    
def funkcija2(num1,num2):
    y2=(num1*num1 +num2*num2)/(num1*num2)
    return y2;
    
def comparison(valA,valB):
    if (valA/10)<valB :
        print("Rezultāts funkcijai Y: ", "%.3f" %funkcija1(valA,valB))
    else:
        print("Rezultāts funkcijai Y: ", "%.3f" %funkcija2(valA,valB))

def ievade():
    while True:
        user_input=input("Ievadiet skaitli X:")
        try:
            valueX=float(user_input)
            return valueX
            #print("viss ok")
            break
        except ValueError:
            print("Kļūda ievadē")

print("Jolanta Bērziņa 181RDB178  8.grupa")

def mainTask():
    valX=ievade()
    a=valueA(valX)
    b=valueB(valX)
    comparison(a,b)
    
    answer=input("Vai turpināt darbu ar programmu?[y/n]")
    if (answer=="y" or answer=="Y"):
        mainTask()
    else:
        sys.exit()

mainTask()