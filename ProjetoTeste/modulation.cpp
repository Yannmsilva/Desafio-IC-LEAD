//Código referente a modulação do sinal sensor.log
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//A ideia é fazer com que essa função faça os cálculos e o executá-la no main
//Foi criado um arquivo .txt a partir dos dados fornecidos que exclue os valores de tempo para facilitar o trabalho com os dados
void modulation()
{
	ifstream dados;
	ofstream arquivof;
	dados.open("dados.txt");
	arquivof.open("modulation.log");
	
	double item;

	//Ler a lista de dados até o final armazenando em um novo arquivo .log
	while (!dados.eof()) {

		dados >> item;
		item = item * 2.0;

		arquivof << item << "\n";
	}
	arquivof.close();
	cout << "Seu arquivo foi criado com sucesso!" << endl;
}



int main()
{
	modulation();
	cin.get();
}

