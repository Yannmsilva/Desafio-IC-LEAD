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


void lowpass() 
{
	dados.open("dados.txt");
	arquivof.open("lowpass.log");

	//Criação de um vetor com os dados contidos no arquivo dados.txt
	double myData;
	vector <double> myDataVect;

	while (!dados.eof()) {
		dados >> myData;
		myDataVect.insert(myDataVect.end(), myData);
	}

	//Implementação do filtro passa baixa. 
	float tau = 0.1;
	float T = 0.02; 

	float alpha = T / (2 * tau + T);
	float beta = (T - 2 * tau) / (T + 2 * tau);

	double y = 0;

	for (int k = 1; k < myDataVect.size(); k++) {

		y = alpha*(myDataVect.at(k) + myDataVect.at(k - 1)) - beta*y;
		//cout << "Meu y: " << y << endl;
		arquivof << y << "\n";
	}
	arquivof.close();
	cout << "Seu arquivo lowpass.log foi criado com sucesso!" << endl;
}

int main()
{
	//modulation();
	//mean();
	lowpass();
	cin.get();

}

