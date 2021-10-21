#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<unistd.h>
#include<fcntl.h> 


int main()
{
    char write_buf[100];
    char read_buf[100];
    int fd=open("/dev/mydevice",O_RDWR);
    
    printf("Enter a string to be written: ");
    scanf("%[^\n]s",write_buf);
    
    //printf("%ld",strlen(write_buf));
    //printf("\n");
    
    printf("Writing into device..\n");
    if(write(fd,write_buf,strlen(write_buf)))
    	printf("Written successfully\n");
    	
    printf("Reading from the device..\n");
    printf("The string is: ");
    read(fd,read_buf,100);
   
    printf("%s",read_buf);
    printf("\n");
    close(fd);
}


