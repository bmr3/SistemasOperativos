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

int main() {
  int fd, n;
  fd = creat("/Users/bruno/Desktop/OS/datos2.txt", 777);
  ErrorCheck(fd);

  float num1 = 0.72;
  n = write(fd, &num1, sizeof(float));
  printf("%d \n", n);
  
  float num2 = 9.39;
  n = write(fd, &num2, sizeof(float));
  printf("%d\n", n);

  float num3 = 4.81;
  n = write(fd, &num3, sizeof(float));
  printf("%d\n", n);

  float num4 = 5.12;
  n = write(fd, &num4, sizeof(float));
  printf("%d\n", n);

  float num5 = 2.48;
  n = write(fd, &num5, sizeof(float));
  printf("%d\n", n);

  ErrorCheck(fd);
  close(fd);
  return 0;
}
