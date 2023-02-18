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
    int fd = open("/Users/bruno/Desktop/OS/datos.txt", 0);
    ErrorCheck(fd);
    off_t size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    char buffer[size];
    read(fd, buffer, size);
    float *arr = (float*) buffer;
    int num_elems = size / sizeof(float);
    ErrorCheck(fd);
    for (int i = 0; i < num_elems; i++) {
        printf("%f\n", arr[i]);
    }
    close(fd);
    return 0;
}
