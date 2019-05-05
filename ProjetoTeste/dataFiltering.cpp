//Código para trabalhar o sinal sensor.log

//Foi criado um arquivo .txt a partir dos dados fornecidos que exclue os valores de tempo para facilitar o trabalho com os dados

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

void modulation()
{
	//Recuperação dos dados
	ifstream dados;
	ofstream arquivo1;
	dados.open("dados.txt");
	arquivo1.open("modulation.log");

	//Criação de um vetor com os dados contidos no arquivo dados.txt
	double myData;
	vector <double> myDataVect;

	while (!dados.eof()) {
		dados >> myData;
		myDataVect.insert(myDataVect.end(), myData);
	}

	//Variável para adicionar os timestamps ao arquivo de dados
	double t = 2.40;

	//Loop para trabalhar os dados usando o vetor de dados 
	for (int i = 0; i < (myDataVect.size()); i++) {
		arquivo1 << t << " ";
		arquivo1 << (myDataVect.at(i) * 2.0) << "\n";
		t = t + 0.02;
	}
	arquivo1.close();
}


void mean() 
{	
	//Recuperação dos dados
	ifstream dados;
	ofstream arquivo2;
	dados.open("dados.txt");
	arquivo2.open("mean.log");

	//Criação de um vetor com os dados contidos no arquivo dados.txt
	double myData;
	vector <double> myDataVect;

	while (!dados.eof()) {
		dados >> myData;
		myDataVect.insert(myDataVect.end(), myData);
	}
	//Variável para adicionar os timestamps ao arquivo de dados
	double t = 2.40;

	//Loop para trabalhar os dados usando o vetor de dados 
	double a = 0;
	double b = 0;

	for (int i = 0; i < (myDataVect.size()); i++) {
		if (i < 20) {
			a = a + myDataVect.at(i);
		}
		else if (i == 20) {
			b = (a / 20);
			arquivo2 << t << " ";
			arquivo2 << b << "\n";
			t = t + 0.02;
		}
		else if (i > 20) {
			a = a + myDataVect.at(i) - myDataVect.at(i - 21);
			b = (a / 20);
			arquivo2 << t << " ";
			arquivo2 << b << "\n";
			t = t + 0.02;
		}
	}
	arquivo2.close();
}


void lowpass() 
{
	//Recuperação dos dados
	ifstream dados;
	ofstream arquivo3;
	dados.open("dados.txt");
	arquivo3.open("lowpass.log");

	//Criação de um vetor com os dados contidos no arquivo dados.txt
	double myData;
	vector <double> myDataVect;

	while (!dados.eof()) {
		dados >> myData;
		myDataVect.insert(myDataVect.end(), myData);
	}
	//Variável para adicionar os timestamps ao arquivo de dados
	double t = 2.40;

	//Implementação do filtro passa baixa. 
	double tau = 0.1;
	double T = 0.02; 

	double alpha = T / (2 * tau + T);
	double beta = (T - 2 * tau) / (T + 2 * tau);

	double y = 0;

	for (int k = 1; k < myDataVect.size(); k++) {
		y = alpha * (myDataVect.at(k) + myDataVect.at(k - 1)) - beta*y;
		arquivo3 << t << " ";
		arquivo3 << y << "\n";
		t = t + 0.02;
	}
	arquivo3.close();
}

int main()
{
	
	modulation();
	mean();
	lowpass();

}

