#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<time.h>
//count evita la repeticion del mensaje de espera SIGUSR1
int count=0;


//Funcion que mostrara la hora al recibir la señal SIGUSR1
void hora(){
	//Se ocupa la libreria time para mostrar la hora del sistema
	time_t tiempo;
	time(&tiempo);
	printf("Señal SIGUSR1 recibida: %s",ctime(&tiempo));
	//Se devuelve count a 0 para poder mostrar denuevo el mensaje
	count=0;
}

//Funcion que recibira Ctrl+c o señal por consola para salir
void signal_handler( int signal_num ) { 
	static int trials = 0;
	
	trials++;

	//printf("Interrupt signal is (%d).\n", signal_num );
	//std::cout << "Interrupt signal is (" << signal_num << ").\n"; 

	//salto de linea para que se muestre el mensaje como el PDF
	printf("\n");

  	//Aqui se especifica que se necesita 2 veces la llamada para salir exitosamente
	if(trials == 2){
		exit(signal_num);   
	} 
} 

//Funcion principal
int main(int argc, char const *argv[])
{	
	
	//Funcion para esperar las señales
	signal(SIGTERM, signal_handler);   
	signal(SIGINT, signal_handler);
	//Señal que espera el programa para dar la hora y fecha
	signal(SIGUSR1, hora);
	printf("Programa hora ejecutandose. PID=%d.\n",getpid());
	

	while(1) { 
		//aqui se ocupa count para evitar que el mensaje de señal se repita ya que es un bucle infinito
		if (count == 0)
		{
			printf("Listo para recibir la señal SIGUSR1.\n");
			count++;
		}else{
			sleep(1000);
		}
		
		
		
		//std::cout << "Hello ... PID=" << getpid() << std::endl; 
		
	}
	
	return EXIT_SUCCESS;
}