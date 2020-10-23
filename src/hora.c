#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<time.h>

void hora(){

	//time_t tiempo = time(NULL);
	printf("Hola, aqui te dire la hora: \n");
}

void signal_handler( int signal_num ) { 
	static int trials = 0;
	
	trials++;

	printf("Interrupt signal is (%d).\n", signal_num );
	//std::cout << "Interrupt signal is (" << signal_num << ").\n"; 
  
	if(trials == 2){
		exit(signal_num);  
	} 
} 

int main(int argc, char const *argv[])
{	
	
	int count=0;
	signal(SIGTERM, signal_handler);   
	signal(SIGINT, signal_handler);  
	signal(SIGUSR1, hora);
	printf("Programa hora ejecutandose. PID=%d.\n",getpid());
	

	while(1) { 
		
		printf("Listo para recibir la señal SIGUSR1.\n");
		//wait(true);
		sleep(1000);
		//std::cout << "Hello ... PID=" << getpid() << std::endl; 
		
	}
	
	return EXIT_SUCCESS;
}