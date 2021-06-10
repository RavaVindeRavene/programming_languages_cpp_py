import sys
import re

class automobilis:
    def __init__(self, marka='default', gads=0, parnesumkarba='default',registracijasNr='default', nobraukums=0):
        self._marka=marka
        self._gads=gads
        self._parnesumkarba=parnesumkarba
        self._registracijasNr=registracijasNr
        self._nobraukums=nobraukums
    def show(self):
        return '{:16}'.format(self._marka)+ " | "+ '{:8}'.format(self._gads)+ " | "+ '{:15}'.format(self._parnesumkarba) +" | "+ '{:18}'.format(self._registracijasNr)+ " | "+ '{:14}'.format(self._nobraukums)
    def saveErr(self):
        return self._marka+ " "+ self._gads +" "+ self._parnesumkarba +" "+ self._registracijasNr +" "+self._nobraukums
    def marka(self):
        return self._marka
    def gads(self):
        return self._gads
    def parnesumkarba(self):
        return self._parnesumkarba
    def registracijasNr(self):
        return self._registracijasNr
    def nobraukums(self):
        return self._nobraukums
    def dashRegistracijasNrCheck(self):
        garums=len(self._registracijasNr)
        if self._registracijasNr[2]=='-':
            regNrList=self._registracijasNr.split('-')
            if re.match(r"[A-Z][A-Z]$", regNrList[0]) and int(regNrList[1])>=1 and int(regNrList[1])<=9999:
                return 0
            else: 
                return 1
        else:
            return 1
    def spaceRegistracijasNrCheck(self):
        if " " in self._registracijasNr:
            return 1
        else:
            return 0
    def parnesumkarbaCheck(self):
        if re.match(r"[am]$", self._parnesumkarba):
            return 0
        else:
            return 1
    def nobraukumsCheck(self):
        try:
            int(self._nobraukums)
            return 0 
        except ValueError:
            return 1
    def spaceParnesumKarba(self):
        if ' ' in self._parnesumkarba:
            return 1
        else:
            return 0
    def spaceNobraukumsCheck(self):
        if ' ' in self._nobraukums:
            return 1
        else:
            return 0
    def gadsCheck(self):
        try:
            int(self._gads)
            if int(self._gads)>=1600 and int(self._gads)<=2020:
                return 0
        except ValueError:
            return 1
    def spaceGadsCheck(self):
        if ' ' in self._gads:
            return 1
        else:
            return 0
    def spaceMarka(self):
        x=len(self._marka)
        if self._marka[0]==' ' or self._marka[x-1]==' ':
            return 1
        else:
            return 0
def formateshana():
    print(f'{"Marka":<18s}{ "Gads":<10s}{"Parnesumkarba":<18s}{"RegistracijasNRr":<20s}{"Nobraukums":<14s}')
    print("-----------------------------------------------------------------------------")
    


if __name__ == '__main__':
    
    print("Jolanta Bērziņa 181RDB178  8.grupa")
    print (" ")

    while True:
        try:
           fails=input("Ievadiet faila nosaukumu: \n")
           INPUTFILE = fails
           dokuments=open(INPUTFILE,'r')
           break
        except IOError:
           print("Tada faila nav. Meginiet velreiz.\n")
           continue
    open('err.txt', 'w' ).close()
    automasinas=list()
    derigiIeraksti=list()

    for line in dokuments.readlines():
        newlist=line.split(';')

        if len(newlist)!=5:
            errlist=newlist
            with open("err.txt", "a" ) as file:
                file.write(" ".join(errlist)+'\n')
            file.close()
            continue
        marka,gads,parensumkarba,registracijasNr,nobraukums=newlist
        automasinas.append(automobilis(marka,gads,parensumkarba,registracijasNr,nobraukums))
    dokuments.close()
    formateshana()
    with open("err.txt", "a") as file:
        for n in automasinas:
            if n.spaceMarka()!=0:
                file.write(n.saveErr()+'\n')
            elif n.gadsCheck()!=0 or n.spaceGadsCheck()!=0:
                file.write(n.saveErr()+'\n')
            elif n.parnesumkarbaCheck()!=0 or n.spaceParnesumKarba()!=0 :
                file.write(n.saveErr()+'\n')
            elif n.spaceRegistracijasNrCheck()!=0 or n.dashRegistracijasNrCheck()!=0:
                file.write(n.saveErr()+'\n')
            elif n.nobraukumsCheck()!=0 or n.spaceNobraukumsCheck()!=0:
                file.write(n.saveErr()+'\n')
            else:
                derigiIeraksti.append(n)
                print(n.show())
    file.close()
    sys.stdout.flush()
    while True:
        print("Izvelaties vienu no meklesanas kriterijiem:\n")
        print(" Atrast automasinas pec markas - 1")
        print(" Atrast automasinas pec to parnesumkarbas veida - 2")
        print (" Atrast automasinas pec to izlaisanas gada - 3")
        print(" Partraukt programmas darbu - 4")

        try:
            choice=int(input("Meklet pec : \n"))
        except ValueError:
            print("Tika ievadita nepareiza vertiba. Meginiet velreiz. \n")
            continue

        if choice==1:
            markaUserInput=input("Ievadiet automasinas markas nosaukumu: \n")
            formateshana()
           
            autoskaits=0
            for n in derigiIeraksti:
                if markaUserInput==n.marka():
                    autoskaits=autoskaits+1
                    print(n.show())
            if autoskaits==0:
                print("Netika atrasta nevina sadas markas automasina. Meginiet velreiz.\n" )
                continue
            continueChoice=input("Vai velaties turpinat veikt meklesanu? [y/n]\n")
            if continueChoice=="y" or continueChoice=="Y":
                continue
            else: 
                break
        
        elif choice==2:
            parnesumkarbaUserInput=input("\n Ievadiet parnesumkarbas tipu pec kura meklet [a/m]: \n")
            if re.match(r"[am]$", parnesumkarbaUserInput):
                formateshana()
                autoskaits=0
                for n in derigiIeraksti:
                    if parnesumkarbaUserInput==n.parnesumkarba():
                        autoskaits=autoskaits+1
                        print(n.show())
                if autoskaits==0:
                    print("Netika atrasta nevina sada automasina. Meginiet velreiz.\n" )
                    continue
                continueChoice=input("Vai velaties turpinat veikt meklesanu? [y/n]\n")
                if continueChoice=="y" or continueChoice=="Y":
                    continue
                else:
                    break
            else:  
                print("\n Nepareizi ievadits parnesumkarbas tips. Meginiet velreiz.\n")
                continue
        
        elif choice==3:
            
            try:
                gadsUserInput=int(input("\n Ievadiet automasinas izlaisanas gadu: \n" ))
            except ValueError:
                print("Tika ievadits nepareizs izlaiduma gads. Meginiet velreiz.\n")
                continue

            autoskaits=0
            formateshana()
            for n in   derigiIeraksti:
                if int(gadsUserInput)<=int(n.gads()):
                        autoskaits=autoskaits+1
                        print(n.show())
            if autoskaits==0:
                print("Netika atrasta nevina sada automasina. Meginiet velreiz.\n" )
                continue
            continueChoice=input("Vai velaties turpinat veikt meklesanu? [y/n]")
            if continueChoice=="y" or continueChoice=="Y":
                continue
            else:
                break
            
        elif choice==4:
            print("Programma tiek partraukta.")
            break
        else:
            print("\n Tika ievadita nepareiza vertiba. Meginiet velreiz.\n")
    
    

