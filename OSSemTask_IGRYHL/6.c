#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

  
int main()

{

    int fd1;


    char * myfifo = "/tmp/myfifo";


    mkfifo(myfifo, 0666);

    int ertek = 0;


        fd1 = open(myfifo, O_RDONLY);

        read(fd1, &ertek, sizeof(ertek));

        close(fd1);

        printf("A kapott szám %d\n", ertek);


        int ertekd = ertek + ertek;        

        fd1 = open(myfifo, O_WRONLY);

        write(fd1, &ertekd, sizeof(ertekd));

        close(fd1);

    return 0;

}
