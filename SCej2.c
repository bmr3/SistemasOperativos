#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

void ErrorCheck (int fd) {
    if(fd<0) {
        if( errno == EAGAIN) {
            printf("Archivo bloqueado \n");
        }
        else if(errno == EACCES) {
            printf("Problema de permisos del archivo. \n");
        }
        else if (errno == EBADF) {
            printf("Mal descriptor del archivo. \n");
        }
        else {
            printf("Error: %s \n", strerror(errno));
        }
    }
}

int main () {
  int fd, size;
  float arr[] = {1.42, 6.87, 9.7, 6.65, 0.33};
  fd = creat("/Users/bruno/Desktop/OS/datos.txt", 777);
  ErrorCheck(fd);
  size = sizeof(arr)/sizeof(float);
  write(fd, arr, size*sizeof(float));
  ErrorCheck(fd);
  close(fd);
  return 0;
}
