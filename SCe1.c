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
            printf("Error: %s  \n",strerror(errno));
        }
    }
}

int main() {
  return 0;
}
