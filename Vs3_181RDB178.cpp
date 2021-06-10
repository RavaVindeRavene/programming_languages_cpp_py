
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool checkIfString(string name) {
	bool upper = true;
	bool lower = true;
	for (int i = 0; i < name.size(); i++)
	{

		if ((int)(name[i]) < 65 || (int)(name[i]) > 90)  upper = false;
		if ((int)(name[i]) < 97 || (int)(name[i]) > 122) lower = false;
		if (upper == false && lower == true) {
			upper = true; continue;
		}
		if (upper == true && lower == false) {
			lower = true; continue;
		}
		if (upper == false || lower == false) {

			return false;
		}
		return true;
	}
}

bool checkIfNumber(const string& st)
{
	string::const_iterator it = st.begin();
	while (it != st.end() && isdigit(*it)) ++it;
	return !st.empty() && it == st.end();
}

class automobilis {
public:
	string marka;
	string gads;
	string parnesumkarba;
	string registracijasNr;
	string nobraukums;
	bool invalid = false;
	void setMarka(string fromDoc) {
		if (checkIfString(fromDoc) == false) {
			invalid = true;
		}
		marka = fromDoc;
	}

	void setGads(string fromDoc) {
		if (checkIfNumber(fromDoc) == false && fromDoc.length() != 4) {
			invalid = true;
		}
		gads = fromDoc;
	}

	void setParnesumkarba(string fromDoc) {
		if (checkIfString(fromDoc) == false && fromDoc.length() != 1 && (fromDoc != "a" || fromDoc != "m")) {
			invalid = true;
		}
		parnesumkarba = fromDoc;
	}

	void setRegistracijasNr(string fromDoc) {
		string burti = fromDoc.substr(0, 2);
		string cipari = fromDoc.substr(3);
		if (fromDoc.substr(2, 1) != "-" || checkIfNumber(cipari) == false || checkIfString(burti) == false) {
			invalid = true;
		}
		registracijasNr = fromDoc;
	}

	void setNobraukums(string fromDoc) {
		if (checkIfNumber(fromDoc) == false) {
			invalid = true;
		}
		nobraukums = fromDoc;
	}
	
	
	void print() {
		if (invalid == true)return;
		cout << setw(16)<<marka << "  ";
		cout << gads << " " << "\t";
		cout << parnesumkarba << "  " << "\t";
		cout << registracijasNr << "  " << "\t";
		cout << nobraukums << "\n";
	}

};

void formesana() {
	cout << " ----------------------------------------------------------- \n";
}
int userInputInteger() {
	bool ok = false; int x;
	cout << "\n";
	while (!ok)
	{
		cin >> x;
		if (!cin.fail() && (cin.peek() == EOF || cin.peek() == '\n') && (x==1 || x==2 || x==3))
		{
			ok = true; return x;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\n Ievades kluda. Atkartoti ievadiet skaitli: " << endl;
		}
	}
	return -1;
}
string userInputString() {
	bool ok = false; string x;
	cout << "\n";
	while (!ok)
	{
		cin >> x;
		if (x == "y" || x == "Y" || x == "n" || x == "N")
		{
			ok = true; return x;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\n Ievades kluda. Atkartoti ievadiet izveli [y/n] " << endl;
		}
	}return "";
}
string userInputGear() {
	bool ok = false; string x;
	cout << "\n";
	while (!ok)
	{
		cin >> x;
		if (x == "a" || x == "m")
		{
			ok = true; return x;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\n Ievades kluda. Atkartoti ievadiet parnesumkarbas tipu [a/m] " << endl;
		}
	}
	return"";
}
string userInputYear() {
	bool ok = false; int x;
	string gads;
	cout << "\n";
	while (!ok)
	{
		cin >> x;
		gads = to_string(x);
		if (gads.length()==4 && !cin.fail() && (cin.peek() == EOF || cin.peek() == '\n') )
		{
			ok = true; return gads;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "\n Ievades kluda. Atkartoti ievadiet izlaidma gadu: " << endl;
		}
	}
	return "";
}

int main()
{
	cout << "Jolanta Berzina 8.grupa\n";
	cout << "Ievadiet faila nosaukumu.\n";
	string fileName;
	cin >> fileName;
	vector<string> rinda;
	ifstream in(fileName.c_str());
	if (!in)
	{
		cerr << "Fails netika atrasts : " << fileName << endl;
		return false;
	}
	string str;
	int carSkaits = 0;

	while (getline(in, str)) {
		if (str.size() > 0) {
			rinda.push_back(str);
			carSkaits++;
		}
	}
	in.close();

	automobilis* masivs = new automobilis[carSkaits];
	string word = "";
	int struktura = 0;
	
	for (int sk = 0; sk < carSkaits; sk++) {
		struktura = 0;
		for (auto x : rinda[sk]) {
			if (x == ';' || x == '\n') {
				struktura++;
				if (struktura == 1)masivs[sk].setMarka(word);
				if (struktura == 2)masivs[sk].setGads(word);
				if (struktura == 3)masivs[sk].setParnesumkarba(word);
				if (struktura == 4)masivs[sk].setRegistracijasNr(word);
				if (struktura == 5)masivs[sk].setNobraukums(word);
				word = "";
			}
			else {
				if (x == ' ')continue;
				word = word + x;
			}
		}
	}
	/*formesana();   izvada visus auto
	for (int i = 0; i < carSkaits; i++) { masivs[i].print(); }
	cout << "\n"; */
	string turpinat;
	do {
		cout << "Meklet automasinas pec markas - 1 \n";
		cout << "Meklet automasinas pec  parnesumkarbas tipa - 2 \n";
		cout << "Meklet automasinas, kas tika izlaistas noteikta gada - 3 \n";
		int izvele;
		izvele= userInputInteger();

		if (izvele == 1) {
			string choice1 = "y";
			while (choice1 == "y" || choice1 == "Y") /* mekle auto pec markas*/
			{
				cout << "\n Ievadiet automasinas marku:" << "\n";
				string searchMark;
				cin >> searchMark;
				formesana();
				bool atrasts = false;
				for (int i = 0; i < carSkaits; i++) {
					if (masivs[i].marka == searchMark) {
						atrasts = true;
						masivs[i].print();
					}
				}
				if (atrasts == true) {
					cout << "\n Vai velaties meklet citas markas automasinas?<Y/N>\n";
					choice1=userInputString();

				}
				else {
					cout << "\n Nav nevienas sadas markas automasinas.Vai velaties meklet citu?<Y/N>\n";
					choice1=userInputString();

				}
			}
		}
		else if (izvele == 2) {
			string choice2 = "y";
			while (choice2 == "y" || choice2 == "Y") /* mekle auto pec parnesumkarbas*/
			{
				cout << "\n Ievadiet automasinas parnesumkarbas tipu [a/m]:" << "\n";
				string searchGear;
				searchGear=userInputGear();
				bool atrasts = false;
				formesana();
				for (int i = 0; i < carSkaits; i++) {
					if (masivs[i].parnesumkarba == searchGear) {
						atrasts = true;
						masivs[i].print();
					}
				}
				if (atrasts == true) {
					cout << "\n Vai velaties meklet cita vieda parnesumkarbas automasinas?<Y/N>\n";
					choice2=userInputString();
				}
				else {
					cout << "\n Nav nevienas sadas automasinas.Vai velaties meklet citu?<Y/N>\n";
					choice2=userInputString();
				}
			}
		}
		else {
			string choice3 = "y";
			while (choice3 == "y" || choice3 == "Y") /* mekle auto pec gada*/
			{
				cout << "\n Ievadiet automasinas izlaiduma gadu:" << "\n";
				string searchYear;
				searchYear=userInputYear();
				formesana();
				bool atrasts = false;
				for (int i = 0; i < carSkaits; i++) {
					if (masivs[i].gads == searchYear) {
						atrasts = true;
						masivs[i].print();
					}
				}
				if (atrasts == true) {
					cout << "\n Vai velaties meklet cita gada automasinas?<Y/N>\n";
					choice3 = userInputString();

				}
				else {
					cout << "\n Nav nevienas noradita gada automasinas.Vai velaties meklet citu?<Y/N>\n";
					choice3=userInputString();

				}
			}
		}

		cout << "Vai velaties veikt citu meklesanu (y/n)?";
		turpinat= userInputString();

	} while (turpinat == "y" || turpinat == "Y");


	string directory;
	const size_t last_slash_idx = fileName.rfind('\\');
	if (string::npos != last_slash_idx)
	{
		directory = fileName.substr(0, last_slash_idx);
	}
	ofstream outfile;
	outfile.open(directory + "/err.txt");
	for (int i = 0; i < carSkaits; i++) {
		if (masivs[i].invalid == true)
			outfile << masivs[i].marka << " " << masivs[i].gads << " " << masivs[i].parnesumkarba << " " << masivs[i].registracijasNr << " " << masivs[i].nobraukums << "\n";
	}
	outfile.close();
	return 0;

}