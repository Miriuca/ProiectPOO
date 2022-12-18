#include <iostream>
#include "bilete.h"
using namespace std;

eveniment::eveniment()
{
	tip = "";
	locatie = "";
}

ostream& operator<<(ostream& out, eveniment e)
{
	out << "Tip eveniment: " << e.tip << endl;
	out << "Locatie: " << e.locatie << endl;
	return out;
}

istream& operator>>(istream& in, eveniment& e)
{
	cout << "Tip eveniment: ";
	getline(in, e.tip);
	cout << "Locatie: ";
	getline(in, e.locatie);
	return in;
}

string eveniment::getTip()
{
	return tip;
}

string eveniment::getLocatie()
{
	return locatie;
}

void eveniment::setTip(string t)
{
	tip = t;
}

void eveniment::setLocatie(string l)
{
	locatie = l;
}


int bilete::nrTotal = 0;

bilete::bilete()
{
	numeClient = NULL;
	nrTotal++;
	locScaun = "";
	id = nrTotal;
	ocupat = false;
	UID = NULL;
	dimUID = 0;
}
bilete::bilete(char* nume)
{	
	numeClient = new char[strlen(nume) + 1];
	strcpy(numeClient, nume);
	nrTotal++;
	id = nrTotal;
	ocupat = false;
	UID = NULL;
	dimUID = 0;
}

bilete::bilete(const string nume)
{
	numeClient = new char[nume.length() + 1];
	strcpy(numeClient, nume.c_str());
	nrTotal++;
	id = nrTotal;
	ocupat = false;
	UID = NULL;
	dimUID = 0;
}

bilete::bilete(const bilete& b)
{
	numeClient = new char[strlen(b.numeClient) + 1];
	strcpy(numeClient, b.numeClient);
	nrTotal++;
	id = nrTotal;
	ocupat = b.ocupat;
	UID = new int[b.dimUID];
	for (int i = 0; i < b.dimUID; i++)
	{
		UID[i] = b.UID[i];
	}
	dimUID = b.dimUID;
}

bilete& bilete::operator=(const bilete& b)
{
	if (this != &b)
	{
		if (numeClient != NULL)
		{
			delete[] numeClient;
			numeClient = NULL;
		}
		if (b.numeClient != NULL)
		{
			numeClient = new char[strlen(b.numeClient) + 1];
			strcpy(numeClient, b.numeClient);
		}
		id = b.id;
		ocupat = b.ocupat;
		if (UID != NULL)
		{
			delete[] UID;
			UID = NULL;
		}
	}
}

ostream& operator<<(ostream& out, bilete b)
{

	out << "Nume client: " << b.numeClient << endl;
	out << "UID: ";
	for (int i = 0; i < b.dimUID; i++)
		out << b.UID[i];
	out << endl << endl;
	return out;
}

istream& operator>>(istream& in, bilete& b)
{
	cout << "Nume client: ";
	string buffer;
	getline(cin, buffer);
	if (b.numeClient != nullptr)
		delete[] b.numeClient, b.numeClient = nullptr;
	b.numeClient = new char[strlen(buffer.c_str()) + 1];
	strcpy_s(b.numeClient, strlen(buffer.c_str()) + 1, buffer.c_str());
	b.ocupat = true;
	if (b.UID != nullptr)
		delete[] b.UID, b.UID = nullptr;;
	b.UID = new int[log10(b.id) + strlen(b.numeClient) + 1];
	b.dimUID = log10(b.id) + strlen(b.numeClient) + 1;
	int i = 0;
	int copie = b.id;
	while (copie)
	{
		b.UID[i] = copie % 10;
		copie /= 10;
		i++;
	}
	for (int j = i; j < b.dimUID; j++)
		b.UID[j] = b.numeClient[j - i];
	return in;
}

		bool bilete::operator==(const bilete & b)
		{
			if (strcmp(numeClient, b.numeClient) == 0 && id == b.id && ocupat == b.ocupat && dimUID == b.dimUID)
			{
				for (int i = 0; i < dimUID; i++)
				{
					if (UID[i] != b.UID[i])
					{
						return false;
					}
				}
				return true;
			}
			return false;
		}

		bool bilete::operator<(const bilete & b)
		{
			if (id < b.id)
			{
				return true;
			}
			return false;
		}

		bilete::~bilete()
		{
			if (numeClient)
				delete[] numeClient, numeClient = nullptr;
			if (UID)
				delete[] UID, UID = nullptr;
		}
		int bilete::getNrBilete()
		{
			return nrTotal;
		}

		int bilete::getId()
		{
			return id;
		}

		bool bilete::getValabil()
		{
			return ocupat;
		}

		string bilete::getNumeClient()
		{
			return numeClient;
		}

		int* bilete::getUID()
		{
			return UID;
		}

		int bilete::getdim()
		{
			return dimUID;
		}
		void bilete::setNr(int nr)
		{
			nrTotal = nr;
		}

		void bilete::setId(int id)
		{
			this->id = id;
		}

		void bilete::setValabil(bool valabil)
		{
			ocupat = valabil;
		}

		void bilete::setNume(const string nume)
		{
			if (numeClient != NULL)
			{
				delete[] numeClient;
				numeClient = NULL;
			}
			numeClient = new char[nume.length() + 1];
			strcpy(numeClient, nume.c_str());
		}

		void bilete::setUID(int* uid, int dim)
		{
			if (UID != NULL)
			{
				delete[] UID;
				UID = NULL;
			}
			UID = new int[dim];
			for (int i = 0; i < dim; i++)
			{
				UID[i] = uid[i];
			}
			dimUID = dim;
		}

		bool bilete::checkUID(char* uid)
		{
			int dim = strlen(uid);
			if (dim != dimUID)
			{
				return false;
			}
			for (int i = 0; i < dim; i++)
			{
				if (uid[i] != UID[i])
				{
					return false;
				}
			}
			return true;
		}

		LocScaun::LocScaun()
		{
			scaun[0][0];
		}

		bool LocScaun::getSeat(int rand, int col) {
			return scaun[rand][col];
		}

		void LocScaun::setSeat(int rand, int col, bool availability) {
			scaun[rand][col] = availability;
		}


		tipServiciu::tipServiciu()
		{
			serviciu = "";
			oferta = "";
			pret = 0;
		}

		string tipServiciu::getServiciu()
		{
			return serviciu;
		}

		string tipServiciu::getOferta()
		{
			return oferta;
		}

		int tipServiciu::getPret()
		{
			return pret;
		}

		void tipServiciu::setServiciu(string s)
		{
			serviciu = s;
		}

		void tipServiciu::setOferta(string o)
		{
			oferta = o;
		}

		void tipServiciu::setPret(int p)
		{
			pret = p;
		}
