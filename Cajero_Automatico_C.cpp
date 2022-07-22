#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>

float cantidad=207530;float deposito; float retirar;float transferir;float resultado;
int eleccion;int clave;int k;int intento=0;int descuentoConsultaSaldo=200;int descuentoGiro=300;int descuentoTransferencia=300;
char transaccion = 's';

float consultaSaldo(float x)
{
 	cantidad=x-descuentoConsultaSaldo;
 	return cantidad;
}

float girarDinero(float x)
{
	cantidad = cantidad-x-descuentoGiro;
	return cantidad;
}
float depositarDinero(float x)
{
	cantidad = cantidad + x;
	return cantidad;
}
float TransferirDinero(float x)
{
	cantidad = cantidad-x-descuentoTransferencia;
	return cantidad;
}

main(){
	printf("\n\n*** BIENVENIDO ***\n\n" );
	do {
        if (intento==3)
        {
           system("cls");
           printf("\n* Ha excedido  el limite de intentos, Acceso denegado *");
           exit(1);
        }
        printf("\nIngrese su CLAVE SECRETA: ");
        scanf("%d",&clave);
        intento++;
       } while (clave!=123654);      
	system("cls");
	do{
		printf("\n*** CAJERO AUTOMATICO ***\n\n" );
		printf("1. Consultar saldo. \n" );
		printf("2. Girar dinero. \n" );
		printf("3. Depositar de dinero. \n" );
		printf("4. Transferencia de dinero. \n" );
		printf("5. Informacion y costo sobre movimiento de su cuenta. \n" );
		printf("6. Salir. \n" );
		printf("\n------------------------------------------*\n\n" );
		printf("Ingrese su eleccion: " );
		scanf("%d",&eleccion);
		system("cls");
		switch (eleccion){
		case 1:
			resultado= consultaSaldo(cantidad);
			printf("\n ** TU SALDO ES: %.f **",resultado); 
			printf("*\nRecuerde que se aplico un recargo de 200 pesos por consulta de saldo* \n");
			printf("\n\n\nPresione una techa para continuar...");
			getch();
			system("cls");
			break;
		case 2:
			printf("\n Cuanto desea Girar? " );		
			scanf("%f", &retirar);
			if (retirar > cantidad){
				printf("\n*SALDO INSUFICIENTE*" );
			}else{
 			resultado = girarDinero(retirar);
 			system("cls");
			printf("\n*DINERO RETIRADO EXITOSAMENTE*" );
			printf("\n\nTU SALDO QUEDA EN: %.f", resultado);
			printf("*\nRecuerde que se aplico un recargo de 300 pesos por concepto de Giro* \n" );
			printf("\n*** GRACIAS POR OPERAR ***\n\n" );
			}
			printf("Presione una techa para continuar...");
			getch();
			system("cls");break;
		case 3:
			printf("\n Cuanto desea depositar? ");
			scanf("%f", &deposito);
 			resultado = depositarDinero(deposito);
 			system("cls");
			printf("\n TU SALDO QUEDA EN: %.f", resultado);
			printf("\n*** GRACIAS POR OPERAR ***\n\n" );
			printf("Presione una techa para continuar...");
			getch();
			system("cls");
			break;
		case 4:			
			printf("\n Cuanto desea Transferir? ");
			scanf("%f", &transferir);
			if (transferir > cantidad){
				printf("\n*SALDO INSUFICIENTE PARA TRANSFERIR*" );
			}else{
			  resultado=TransferirDinero(transferir);
			printf("\n*TRANSFERENCIA EXITOSA*" );
			printf("\n\nTU SALDO QUEDA EN: %.f", resultado);
			printf("\n*Recuerde que se aplico un recargo de 300 pesos por concepto de Transferencia* \n" );
			printf("\n*** GRACIAS POR OPERAR ***\n\n" );
			}
			printf("Presione una techa para continuar");
			getch();
			system("cls");
		break;
		case 5:
			printf("\n*** MODULO DE INFORMACION ***\n\n" );
			printf("\n*EL COSTO POR CONCEPTO DE CONSULTAR SALDO ES DE 200 CLP*" );
			printf("\n*EL COSTO POR CONCEPTO DE GIRO ES DE 300 CLP*" );
			printf("\n*EL COSTO POR CONCEPTO DE TRANSFERENCIA ES DE 300 CLP*" );
			printf("\n*NO TIENE COSTO POR CONCEPTO DE DEPOSITOS/ABONO DE DINERO\n\n" );
			printf("\n*** FIN ***\n" );
			printf("\n-------------------------------------------------------------\n\n" );
			printf("Presione una techa para continuar");
			getch();
			system("cls");
			break;

		case 6:
			printf("\n\n**Desea salir? (s/n): " );
			fflush(stdin);
			scanf("%c", &transaccion); 
		if (transaccion ==  'n'|| transaccion ==  'N'){
			system("cls");
				break;
		}
		else {
    		printf("\n Gracias por usar el cajero automatico!"); 
    		exit(1);		
		}
			break;
			
		default: printf("\n OPCION NO VALIDA");
		//aqui cuando ingreso opcion fuera de rango, el cajero me sigue consultando si quiero otra operacion o salir
		printf("\n\n\n**Desea otra transaccion?(s/n): " );
		fflush(stdin);
		scanf("%c", &transaccion); 
		if (transaccion ==  'n'|| transaccion ==  'N')
			k = 1;
			system("cls");
		}
	}
	while (!k);{
    printf("\n Gracias por usar el cajero automatico!"); 
}
}
