#include "types.h"
#include "user.h"
#include "stat.h"

int main(void) {
    int pid;
    pid = fork();

    if (pid == -1) {
        printf(1, "Bad forking.\n");
        return -1;
    }

    if (pid == 0) {
        //child process
        for (int i=0; i<5; i++) {
            printf(1, "I'm the child at i=%d; doing some I/O\n", i);
        }
        exit();
    }

    else {
        //parent
        int stime, retime, rutime;
        printf(1, "I'm the parent, waiting for my child.\n");
        wait2(&stime, &retime, &rutime);
        printf(1, "Child had\nsleep time\t%d\nready time\t%d\nrunningtime\t%d\n", stime, retime, rutime);
        exit();
    }

    return 0;
}