//Código para trabalhar o sinal sensor.log
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

ifstream dados;
ofstream arquivof; 

double myData = 0;
vector <double> myDataVect;


//A ideia é fazer com que essa função faça os cálculos e executá-la no main
//Foi criado um arquivo .txt a partir dos dados fornecidos que exclue os valores de tempo para facilitar o trabalho com os dados
void modulation()
{
	dados.open("dados.txt");
	arquivof.open("modulation.log");
	
	//Criação de um vetor com os dados contidos no arquivo dados.txt
	double myData;
	vector <double> myDataVect;

	while (!dados.eof()) {
		dados >> myData;
		myDataVect.insert(myDataVect.end(), myData);
	}

	//Loop para trabalhar os dados usando o vetor de dados 
	for (int i = 0; i < (myDataVect.size()); i++) {
		arquivof << (myDataVect.at(i) * 2.0) << "\n";
	}

	//Tentativa inicial, agora aperfeiçoada com o vector de dados.
	/*
	double item;
	
	//Lê a lista de dados até o final, multiplicando cada valor por 2 e armazenando em um novo arquivo .log
	while (!dados.eof()) {

		dados >> item;
		item = item * 2.0;

		arquivof << item << "\n";
	}
	*/
	arquivof.close();
	cout << "Seu arquivo modulation.log foi criado com sucesso!" << endl;
}


void mean() 
{
	dados.open("dados.txt");
	arquivof.open("mean.log");

	//Criação de um vetor com os dados contidos no arquivo dados.txt
	double myData;
	vector <double> myDataVect;

	while (!dados.eof()) {
		dados >> myData;
		myDataVect.insert(myDataVect.end(), myData);
	}

	//Loop para trabalhar os dados usando o vetor de dados 
	double a = 0;
	double b = 0;

	for (int i = 0; i < (myDataVect.size()); i++) {
		if (i < 20) {
			a = a + myDataVect.at(i);
		}
		else if (i == 20) {
			b = (a / 20);
			arquivof << b << "\n";
		}
		else if (i > 20) {
			a = a + myDataVect.at(i) - myDataVect.at(i - 21);
			b = (a / 20);
			arquivof << b << "\n";
		}
	}
	arquivof.close();
	cout << "Seu arquivo mean.log foi criado com sucesso!" << endl;
}


int main()
{
	//modulation();
	mean();
	cin.get();

}

