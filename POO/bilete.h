#pragma once
#include <iostream>
#include <string>
using namespace std;

class eveniment
{
private:
	string tip;
	string locatie;
public:
	eveniment();
	friend ostream& operator<<(ostream&, eveniment);
	friend istream& operator>>(istream&, eveniment&);
	string getTip();
	string getLocatie();
	void setTip(string t);
	void setLocatie(string l);
};

class bilete
{
private:
	static int nrTotal;
	char* numeClient;
	string locScaun;
	int id;
	bool ocupat;
	int* UID;
	int dimUID;
public:
	bilete();
	bilete(char*);
	bilete(const string);
	bilete(const bilete&);
	bilete& operator=(const bilete&);
	friend ostream& operator<<(ostream&, bilete);
	friend istream& operator>>(istream&, bilete&);
	bool operator==(const bilete&);
	bool operator<(const bilete&);
	~bilete();
	static int getNrBilete();
	int getId();
	bool getValabil();
	string getNumeClient();
	int* getUID();
	int getdim();
	void setNr(int);
	void setId(int);
	void setValabil(bool);
	void setNume(const string);
	void setUID(int*, int);
	bool checkUID(char*);
};

class LocScaun {
private:
	bool scaun[100][100];

public:

	LocScaun() {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scaun[i][j] = false;
			}
		}
	}

	bool getSeat(int rand, int col) {
		return scaun[rand][col];
	}
	void setSeat(int rand, int col, bool availability) {
		scaun[rand][col] = availability;
	}
};

class tipServiciu
{
private:
	string serviciu;
	string oferta;
	int pret;
public:
	tipServiciu();
	string getServiciu();
	string getOferta();
	int getPret();
	void setServiciu(string s);
	void setOferta(string o);
	void setPret(int p);

};