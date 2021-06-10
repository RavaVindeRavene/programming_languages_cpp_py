import math
import random
import array

def manualaIavede (rows, col): 
    arr=[]
    for i in range (rows):
        a=[]
        for j in range(col):
            print ("Ievadiet masīva elementu ", i, j)
            a.append(ievadeFloat())
        arr.append(a)   
    return arr    
def randIevade(rows, col):
    arr=[]
    for i in range(rows):
        a=[]
        for j in range(col):
            a.append(random.uniform(-50,50))
        arr.append(a)
    return arr
def parveidot(arr, rows, col):
    swapi=0
    swapj=1
    if rows%2==0:
        for i in range(0,rows,2):
            for j in range(col):
                arr[swapi][j],arr[swapj][j]=arr[swapj][j],arr[swapi][j]
        swapi=swapi+2
        swapj=swapj+2
    else:
        for i in range(0,rows-1,2):
            for j in range(col):
                arr[swapi][j],arr[swapj][j]=arr[swapj][j],arr[swapi][j]
        swapi=swapi+2
        swapj=swapj+2
def ievade():
    while True:
        user_input=input()
        try:
            valueX=int(user_input)
            return valueX
            break
        except ValueError:
            print("Kļūda ievadē")
def ievadeFloat():
    while True:
        user_input=input()
        try:
            valueFloat=float(user_input)
            return valueFloat
            break
        except ValueError:
            print ("Kļūda ievadē")
def masivaIzvade(arr, rows,col):
    print ("Masīvs: ")
    for i in range(rows):
        for j in range(col):
            print("%7.2f" %arr[i][j], end="|")
        print() 
    return arr
#main part
print("Jolanta Bērziņa 181RDB178  8.grupa")
print ('Ievadiet matricas rindu skaitu: ')
rows=ievade()
print('Ievadiet kollonu skaitu: ')
col=ievade()
answer=input("Vai skaitļus ievadīt manuāli: [y/n]")
if (answer=="y" or answer=="Y"):
    arr=manualaIavede(rows, col)
else:
    arr=randIevade(rows,col)
masivaIzvade(arr, rows,col)
parveidot(arr,rows,col)
print("Masīvs pēc pārveidošanas: ")
masivaIzvade(arr, rows,col)
