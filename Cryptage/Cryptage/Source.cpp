#include "Header.h"

using namespace std;

string adresse;
ifstream fichier_in;
ofstream fichier_out;

void Cryptage(int cle) {
	string texteComplet;
	string line;

	while (getline(fichier_in, line)) texteComplet += line;
	
	int longueurFichier = texteComplet.length();

	fichier_out.open(adresse);

	for (int i = 0; i < longueurFichier; i++) texteComplet[i] += cle;

	fichier_out << texteComplet;
}

void Choix() {
	int choix = 0;

	do {
		cout << "Tapez 1 pour crypter le fichier ou 2 pour le decrypter" << endl;
		cin >> choix;
		system("cls");
	} while (choix < 1 || choix >2);

	int cleDecryptage = 1;

	if (choix == 2) cleDecryptage = -1;

	Cryptage(cleDecryptage);
}


void main() {
	do {
		cout << "Entrez l'adresse d'un fichier .txt existant (le nom du fichier ne doit pas avoir d'espace) :" << endl;
		cin >> adresse;
		fichier_in.open(adresse);

		if (!fichier_in) {
			cout << "Ce fichier n'existe pas..." << endl;
			system("pause");
		}

		system("cls");

	} while (!fichier_in);

	Choix();

	fichier_out.close();
}
