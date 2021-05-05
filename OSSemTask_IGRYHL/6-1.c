#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>




int main()

{

    srand(time(NULL));

    int fd;

  
    char * myfifo = "/tmp/myfifo";


    mkfifo(myfifo, 0666);

  
    int ertek;
    int ertekd;


        fd = open(myfifo, O_WRONLY);


        ertek = rand() % (100 + 1 - 0) + 0;

		
        write(fd, &ertek, sizeof(ertek));

        close(fd);
		
		
        fd = open(myfifo, O_RDONLY);
        read(fd, &ertekd, sizeof(ertekd));


        printf("%d duplája: %d\n", ertek, ertekd);
        close(fd);

        unlink(myfifo);

  

    return 0;

}
