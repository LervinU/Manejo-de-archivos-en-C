#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

main() {
		
	typedef struct {
		int codigo;
		char nombre[50];
		char apellido[50];
		char decanato[50];
	}profesor;
	
	typedef struct {
		int codigo;
		char nombre[50];
		int horaE[23];
		int horaS[23];
		int totalHT;
	}asistencia;
	
	//Variables 
	int terminar = 1;
	int variable_seleccion;
	char auxiliar[512];
	char auxiliar_1[512];
	int ret_1;
	int ret_2;
	profesor data;
	asistencia data_asis;
	FILE *info;
	FILE *info_1;
	FILE *info_2;
	FILE *info_3;
	FILE *info_4;
	FILE *info_asistencia;
	FILE *info_salida;
		
	//Manejo del tiempo
	time_t now = time(NULL);
	struct tm tm =  *localtime(&now);

	
	
	while(terminar != 0) {
		printf("\t\t\t PROGRAMA FINAL ESTRUCTURA DE DATOS \n");
		printf("\t\t Realizado por: Lervin Urena Matricula: 2017-0541 \n");		
		printf("\t\t\t\t  %d/%d/%d \n \n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
		printf("******************* MENU DE OPCIONES ***********************\n \n");
		printf("1.AGREGAR PROFESOR A BASE DE DATOS\n2.REGISTRAR ASISTENCIA DE PROFESOR\n3.REGISTRAR SALIDA DE PROFESOR\n4.REPORTE PROFESORES DE UNIVERSIDAD\n5.REPORTE ASISTENCIA\n6.SALIR \n");
		printf("************************************************************\n Opcion: ");
		scanf("%d", &variable_seleccion);
		
		
	switch(variable_seleccion) {
		
	case 1: 
	
	info = fopen("information.txt", "a+");
	
	if(info == NULL) {
		printf("ERROR!");
		exit(1);
	}
	printf("Introduza codigo de profesor: ");
	scanf("%d", &data.codigo);
	getchar();
	printf("Introduzca nombre de profesor: ");
	gets(&data.nombre);
	printf("Introduzca apellido de profesor: ");
	gets(&data.apellido);
	printf("Introduzca decanato del profesor: ");
	gets(&data.decanato);
	printf("\n");
	
	rewind(info);
	char str[50];
	itoa(data.codigo, str, 10);
	while(fgets(&auxiliar, sizeof(auxiliar), info) != NULL) { // Verifica si el empleado ya esta registrado

	int ret = strstr(auxiliar, str);
	if (ret != NULL) {
		printf("Empleado ya registrado, porfavor,  intente denuevo");
		exit(1);
		}
		
	}	
	fprintf(info, "** ID: %d \t Nombre: %s\t Apellido: %s\t Decanato: %s\n", data.codigo, &data.nombre, &data.apellido, &data.decanato);
	printf("Empleado Registrado Satisfactoriamente. \n \n");
	fclose(info);
	printf("Digite 0 para terminar o cualquier otro numero para continuar: ");
	scanf("%d", &terminar);
	system("CLS");
	break;
	
	case 2:
	
	info_1 = fopen("information.txt", "r");
	if(info_1 == NULL ){	printf("Error"); exit(1);	}
	printf("Introduzca el *Codigo* del empleado: ");
	scanf("%d", &data_asis.codigo);
	
	rewind(info_1);
	char str_asis[50];
	itoa(data_asis.codigo, str_asis, 10);
	while(fgets(&auxiliar, sizeof(auxiliar), info_1) != NULL) { // Verifica si el empleado esta registrado
//	 printf("%s", auxiliar);
	 
	 ret_1 = strstr(auxiliar, str_asis);

	if (ret_1 != NULL) {
		
		fclose(info_1);
		info_asistencia = fopen("info_asistenacia.txt", "a+");
		
		if(info_asistencia == NULL) {
			printf("Ha ocurrido un error tratando de abrir el archivo");
		}
		
		fprintf(info_asistencia, "ID: %d \t Hora de entrada: %d:%d \t Fecha: %d/%d/%d\n", data_asis.codigo, tm.tm_hour, tm.tm_min, tm.tm_mday, tm.tm_mon + 1, tm.tm_year +1900 );
		printf("\n Hora de asistencia registrada satisfactoriamente. \n \n");
		fclose(info_asistencia);
		printf("Digite 0 para terminar o cualquier otro numero para continuar: ");
		scanf("%d", &terminar);
		system("CLS");
			} 
		}
		if(ret_1 == NULL) { printf("Empleado no registrado, porfavor, hacerlo"); exit(1);}
		
		break;
		case 3:
	
	info_3 = fopen("information.txt", "r");
	if(info_3 == NULL ){	printf("Error"); exit(1);	}
	printf("Introduzca el *Codigo* del empleado: ");
	scanf("%d", &data_asis.codigo);
	
	rewind(info_3);
	char str_salida[50];
	itoa(data_asis.codigo, str_salida, 10);
	while(fgets(&auxiliar, sizeof(auxiliar), info_3) != NULL) { // Verifica si el empleado esta registrado
//	 printf("%s", auxiliar);
	 
	 ret_2 = strstr(auxiliar, str_salida);

	if (ret_2 != NULL) {
		
		fclose(info_3);
		info_salida = fopen("info_asistenacia.txt", "a+");
		
		if(info_salida == NULL) {
			printf("Ha ocurrido un error tratando de abrir el archivo");
		}
		
		fprintf(info_salida, "ID: %d \t Hora de salida: %d:%d \t Fecha: %d/%d/%d\n", data_asis.codigo, tm.tm_hour, tm.tm_min, tm.tm_mday, tm.tm_mon + 1, tm.tm_year +1900 );
		printf("\n Hora de salida registrada satisfactoriamente. \n \n");
		fclose(info_salida);
		printf("Digite 0 para terminar o cualquier otro numero para continuar: ");
		scanf("%d", &terminar);
		system("CLS");
			} 
		}
		if(ret_2 == NULL) { printf("Empleado no registrado, porfavor, hacerlo"); exit(1);}
		
		break;
		case 4: 
		
		info_2 = fopen("information.txt", "r");
		if(info_2 == NULL) {
			printf("Error");
			exit(1);
		}
		printf("******************REPORTE DE PROFESORES REGISTRADOS*********************** \n");
		while(fgets(&auxiliar, sizeof(auxiliar), info_2) != NULL) {
			printf("%s", auxiliar);
		}
		printf("\n Digite 0 para terminar o cualquier otro numero para continuar: ");
		scanf("%d", &terminar);
		system("CLS");		
		fclose(info_2);	
		break;
		
		case 5 :
			info_4 = fopen("info_asistenacia.txt", "r");
			
			if(info_4 == NULL) {
				printf("Error");
				exit(1);
			}
			printf("******************REPORTE DE ASISTENCIAS*********************** \n");
			while(fgets(&auxiliar, sizeof(auxiliar), info_4) != NULL) {
				printf("%s", auxiliar);
			}
			printf("Digite 0 para terminar o cualquier otro numero para continuar: ");
			scanf("%d", &terminar);
			system("CLS");
			fclose(info_4);
		break;
		case 6 :
			printf("\n \t **Programa finalizado.");
			terminar = 0;
	}
	
}
	return 0;
}
