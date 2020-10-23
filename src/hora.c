#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

void hora(){
	printf("Hola, aqui te dire la hora.\n");
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

	while(++count) { 
		sleep(1);
		printf("Hello... PID=%d\n",getpid());
		//std::cout << "Hello ... PID=" << getpid() << std::endl; 
		
	}
	
	return EXIT_SUCCESS;
}