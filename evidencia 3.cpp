#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main(){
	ifstream entradaArch;
	ofstream salidaArch;
	int votaciones[4][5];
	int vTotal = 0;
	int votos1 = 0;
	int votos2 = 0;
	int votos3 = 0;
	int votos4 = 0;
	double total1 = 0.0;
	double total2 = 0.0;
	double total3 = 0.0;
	double total4 = 0.0;
	double primero = 0.0;
	double segundo = 0.0;
	char ganador;
	char seguidor;
	entradaArch.open("Datosev1.txt");
	if(entradaArch.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		system("PAUSE");
		exit(1);
	}
	salidaArch.open("Resev1.txt");
	for(int i = 0;i<4;i++){
		for(int j = 0;j<5;j++){
			entradaArch>>votaciones[i][j];
		}
	}
	cout<<"Operacion realizada"<<endl;
	salidaArch<<"Distrito        1   2   3   4   5"<<endl;
	salidaArch<<"Juan Montes    "<<votaciones[0][0]<<" "<<votaciones[0][1]<<" "<<votaciones[0][2]<<" "<<votaciones[0][3]<<" "<<votaciones[0][4]<<endl;
	salidaArch<<"Pedro Zapata   "<<votaciones[1][0]<<"  "<<votaciones[1][1]<<"  "<<votaciones[1][2]<<"  "<<votaciones[1][3]<<"  "<<votaciones[1][4]<<endl;  //Impresion de tabla
	salidaArch<<"Ana Martinez   "<<votaciones[2][0]<<" "<<votaciones[2][1]<<" "<<votaciones[2][2]<<" "<<votaciones[2][3]<<" "<<votaciones[2][4]<<endl;
	salidaArch<<"Rogelio Guerra "<<votaciones[3][0]<<"  "<<votaciones[3][1]<<"  "<<votaciones[3][2]<<"  "<<votaciones[3][3]<<"  "<<votaciones[3][4]<<endl;
	for(int i = 0;i<4;i++){
		for(int j = 0;j<5;j++){
			vTotal = vTotal + votaciones[i][j];
		}
	}
	salidaArch<<"Votos totales: "<<vTotal<<endl;
	int i = 0;
	for(int j = 0;j<5;j++){
		votos1 = votos1 + votaciones[i][j];
	}
	salidaArch<<"Juan Montes tiene "<<votos1<<" votos"<<endl;
	total1 = ((votos1*100)/vTotal);
	primero = total1;
	segundo = total1;
	ganador = '1';
	seguidor = '1';
	i++;
	for(int j = 0;j<5;j++){
		votos2 = votos2 + votaciones[i][j];
	}
	salidaArch<<"Pedro Zapata tiene "<<votos2<<" votos"<<endl;
	total2 = ((votos2*100)/vTotal);
	if(total2 > primero){
		primero = total2;
		ganador = '2';
	}else{
		segundo = total2;
		seguidor = '2';
	}
	i++;
	for(int j = 0;j<5;j++){
		votos3 = votos3 + votaciones[i][j];
	}                                                           //para la comparacion y obtener los datos del primero y segundo en cuanto a cantidad de votos
	salidaArch<<"Ana Martinez tiene "<<votos3<<" votos"<<endl;
	total3 = ((votos3*100)/vTotal);
	if(total3 > primero){
		primero = total3;
		ganador = '3';
		if(total2 > total1){
			segundo = total2;
			seguidor = '2';
		}else{
			segundo = total1;
			seguidor = '1';
		}
	}else{if(total3 > segundo){
		segundo = total3;
		seguidor = '3';
	}
	}
	i++;
	for(int j = 0;j<5;j++){
		votos4 = votos4 + votaciones[i][j];
	}
	salidaArch<<"Rogelio Guerra tiene "<<votos4<<" votos"<<endl;
	total4 = ((votos4*100)/vTotal);
	if(total4 > primero){
		primero = total4;
		ganador = '4';
		if(total1 > total2 && total1 > total3){
			segundo = total1;
			seguidor = '1';
			}else{if(total2 > total3){
				segundo = total2;
				seguidor = '2';
			}else{
				segundo = total3;
				seguidor = '3';
			}
			}
		}else{if(total4 > segundo){
		segundo = total4;
		seguidor = '4';
	}
	}
	if(primero > 50.0){
		salidaArch<<"El ganador de las elecciones es: "<<endl;
		switch(ganador){
			case '1': salidaArch<<"Juan Montes\n";
			          break;
			case '2': salidaArch<<"Pedro Zapata\n";
			          break;
			case '3': salidaArch<<"Ana Martinez\n";
			          break;
			case '4': salidaArch<<"Rogelio Guerra\n";
			          break;
		}
	}else{
		salidaArch<<"Los candidatos que pasan a la siguiente son: "<<endl;    //verificar lo de si es mayor a 50% y determinar ganador o los que siguen con vida
		switch(ganador){
			case '1': salidaArch<<"Juan Montes\n";
			          break;
			case '2': salidaArch<<"Pedro Zapata\n";
			          break;
			case '3': salidaArch<<"Ana Martinez\n";
			          break;
			case '4': salidaArch<<"Rogelio Guerra\n";
			          break;
		}
		switch(seguidor){
			case '1': salidaArch<<"Juan Montes\n";
			          break;
			case '2': salidaArch<<"Pedro Zapata\n";
			          break;
			case '3': salidaArch<<"Ana Martinez\n";
			          break;
			case '4': salidaArch<<"Rogelio Guerra\n";
			          break;
		}
}
	entradaArch.close();
	salidaArch.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}
