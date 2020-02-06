//
//  ProgC.c
//
//
//  Created by Adam DIAKITE on 11/03/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#define _DEFAULT_SOURCE
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

//////////////TP1///////////////////////////////////////////////////////////////////////////////////

//ex2 TP1

//void interruptHandler(int n) {
//    printf("Terminaison (recu signal %d)\n", n);
//    fflush(stdout);
//    system("/bin/stty icanon echo");
//    exit(0);
//}
//
//int main(int argc, char *argv[]) {
//    signal(SIGINT, interruptHandler);
//    system("/bin/stty -icanon -echo");
//    char c;
//    while(1) {
//        scanf("%c", &c);
//        printf("%c %d %x\n", c, c, c);
//    }
//}


//ex3 TP1

//int a;
//
//void f(int i) {
//    printf("%de niveau d'appel de f\n", i);
//    printf("Adresse de i        : %p\n", &i);
//    int *p;
//    p = malloc(10 * sizeof(int));
//    printf("malloc (dans f)     : %p\n", p);
//    if (i < 4) f(i+1);
//}
//
//int main(void) {
//    int b = 42;
//    int *p;
//    printf("Adresse de f        : %p\n", &f);
//    printf("Adresse de main     : %p\n", &main);
//    printf("Adresse de a        : %p\n", &a);
//    p = malloc(10 * sizeof(int));
//    printf("malloc (dans main)  : %p\n", p);
//    printf("Adresse de b        : %p\n", &b);
//    f(1);
//}




//////////////TP2///////////////////////////////////////////////////////////////////////////////////


//ex2 tp2
//const int STRING_LENGTH = 300;
//
//void info(char *);
//void readCmdline(char *, char *);
//int countFiles(char *);
//
//int main(void) {
//    DIR *d = opendir("/proc/.");
//    struct dirent *de;
//    while (de = readdir(d)) {
//        if (de->d_type == DT_DIR && atoi(de->d_name) > 0) {
//            info(de->d_name);
//        }
//    }
//    closedir(d);
//    return 0;
//}
//
//void info(char *s) {
//    char cmdline[STRING_LENGTH];
//    readCmdline(s, cmdline);
//    int n = countFiles(s);
//    printf("Processus n° %s : %s\n", s, cmdline);
//    if (n >= 0) {
//        printf("  %d fichier(s) ouvert(s)\n", n);
//    }
//}
//
//void readCmdline(char *s, char *cmdline) {
//    char pathname[STRING_LENGTH];
//    snprintf(pathname, STRING_LENGTH, "/proc/%s/cmdline", s);
//    FILE *cmdlinefile = fopen(pathname, "rb");
//    fgets(cmdline, STRING_LENGTH, cmdlinefile);
//    fclose(cmdlinefile);
//}
//
//int countFiles(char *s) {
//    char pathname[STRING_LENGTH];
//    snprintf(pathname, STRING_LENGTH, "/proc/%s/fd", s);
//    struct dirent *de;
//    int n = -1;
//    DIR *d = opendir(pathname);
//    if (d) {
//        n = 0;
//        while ((de = readdir(d)) != NULL) {
//            if (de->d_type == DT_LNK) n++;
//        }
//        closedir(d);
//    }
//    return n;
//}


//ex3 tp2
//
//
//
//int main(void) {
//    int fd = open("fic1", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP);
//    lseek(fd, 4095, SEEK_SET);
//    char c[] = { 0xFF };
//    write(fd, c, 1);
//    close(fd);
//    return 0;
//}

//ex4 tp2
//
//int main(void) {
//    int fd = open("fic1", O_RDWR);
//    if (fd == -1) {
//        perror("erreur d'ouverture du fichier");
//        return -1;
//    }
//    struct flock verrou = { F_WRLCK, SEEK_SET, 0, 0, 0 };
//    printf("Attente pose de verrou\n");
//    if (fcntl(fd, F_SETLKW, &verrou) != -1) {
//        printf("Verrou posé\n");
//        getchar();
//    } else {
//        perror("erreur de verrouillage du fichier");
//    }
//    close(fd);
//    return 0;
//}

//ex5 tp2
//
//int main(int argc, char *argv[]) {
//    if (argc != 3) {
//        printf("Paramètres incorrects\n");
//        return -1;
//    }
//    int debut = atoi(argv[1]);        // début de la zone à verrouiller
//    int fin = atoi(argv[2]);          // fin de la zone à verrouiller
//    if (fin < debut) {
//        printf("Paramètres incorrects\n");
//        return -1;
//    }
//    int fd = open("fic1", O_RDWR);
//    if (fd == -1) {
//        perror("erreur d'ouverture du fichier");
//        return -1;
//    }
//    struct flock verrou = { F_WRLCK, SEEK_SET, debut, fin - debut, 0 };
//    printf("Attente pose de verrou\n");
//    if (fcntl(fd, F_SETLKW, &verrou) != -1) {
//        printf("Verrou posé\n");
//        getchar();
//    } else {
//        perror("erreur de verrouillage du fichier");
//    }
//    close(fd);
//    return 0;
//}

//ex6 tp2
//
//int main(int argc, char *argv[]) {
//    fprintf(stderr, "Message d'erreur 1\n");
//    int i = open("err.txt",  O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP);
//    close(STDERR_FILENO);
//    dup(i);
//    fprintf(stderr, "Message d'erreur 2\n");
//    return 0;
//}




//////////////TP3///////////////////////////////////////////////////////////////////////////////////

//ex1 TP3
//int main(void) {
//
//    const int x = 4;
//    int pid = fork();
//
//    if (pid == 0) {
//        /* processus fils car pid = 0 */
//        int j;
//        for(j=1; j<=x; j++) {
//            printf("processus fils (n° %d) %d\n", getpid(), j);
//            fflush(stdout);
//            sleep(1);
//        }
//    } else {
//        /* processus père (reçoit le pid > 0 du nouveau processus) */
//        printf("Processus père (n° %d) - Attente fin du processus fils (n° %d)\n", getpid(), pid);
//        fflush(stdout);
//        wait(NULL);
//        printf("Fin du processus fils\n");
//    }
//
//}


//ex2 TP3

//int main(void) {
//
//    const int n = 3;
//    const int x = 4;
//
//    int i;
//    for(i=0; i<n; i++) {
//        int pid = fork();
//        if (pid == 0) {
//            int j;
//            for(j=1; j<=x; j++) {
//                printf("processus n° %d - %d\n", getpid(), j);
//                fflush(stdout);
//                sleep(1);
//            }
//            break; /* le processus nouvellement créé ne doit pas reprendre la boucle for */
//        }
//    }
//
//    wait(NULL);
//}



//ex3a TP3

//int main(void) {
//
//    const int n = 2;
//
//    int i;
//    for(i=0; i<n; i++) {
//        int pid = fork();
//        if (pid == 0) {
//            srand(time(NULL) ^ (getpid()<<16));
//            int k = 2 + rand()%7; /* génère un entier aléatoire de 2 à 8 */
//            int j;
//            for(j=1; j<=k; j++) {
//                sleep(1);
//                printf("processus n° %d - (parent n° %d) - itération %d sur %d\n", getpid(), getppid(), j, k);
//                fflush(stdout);
//            }
//            return 0;
//        }
//    }
//
//    wait(NULL);
//
//}

//ex3b TP3


//int main(void) {
//
//    const int n = 3;
//
//    int i;
//    for(i=0; i<n; i++) {
//        int pid = fork();
//        if (pid == 0) {
//            srand(time(NULL) ^ (getpid()<<16));
//            int k = 2 + rand()%7; /* génère un entier aléatoire de 2 à 8 */
//            int j;
//            for(j=1; j<=k; j++) {
//                sleep(1);
//                printf("processus n° %d - (parent n° %d) - itération %d sur %d\n", getpid(), getppid(), j, k);
//                fflush(stdout);
//            }
//            return 0;
//        }
//    }
//
//    for(i=0;i<n;i++) wait(NULL);
//    return 0;
//}


//ex3c TP3

//int main(void) {
//
//    const int n = 3;
//
//    int i;
//    for(i=0; i<n; i++) {
//        int pid = fork();
//        if (pid == 0) {
//            srand(time(NULL) ^ (getpid()<<16));
//            int k = 2 + rand()%7; /* génère un entier aléatoire de 2 à 8 */
//            int j;
//            for(j=1; j<=k; j++) {
//                sleep(1);
//                printf("processus n° %d - (parent n° %d) - itération %d sur %d\n", getpid(), getppid(), j, k);
//                fflush(stdout);
//            }
//            exit(k);
//        }
//    }
//
//    int somme = 0;
//    for(i=0;i<n;i++) {
//        int wstatus;
//        wait(&wstatus);
//        somme = somme + WEXITSTATUS(wstatus);
//    }
//    printf("somme = %d\n", somme);
//    return 0;
//}



//ex4 tp4
//
//#include <stdio.h>
//#include <unistd.h>
//#include <string.h>
//#include <sys/wait.h>
//
//int main(void) {
//
//    int pid, tube[2];
//
//    pipe(tube);
//    pid = fork();
//
//    if (pid > 0) {
//        char c;
//        close(tube[1]);
//        while (read(tube[0], &c, 1) > 0) {
//            printf("%c", c);
//        }
//        wait(NULL);
//    } else {
//        char msg[] = "Hello\n";
//        close(tube[0]);
//        sleep(2);
//        write(tube[1], msg, sizeof(msg));
//        sleep(2);
//    }
//
//}



//////////////TP4///////////////////////////////////////////////////////////////////////////////////


//int main (){
//    int fd;
//    char *s = "Hello World";
//
//    if((fd = open("/Users/adamdiakite/Desktop/tube", O_WRONLY)) == -1){
//        perror("erreur d'accès a tube 1 ");
//        exit(1);
//    }
//
//    write(fd, s, strlen(s)+1);
//    close(fd);
//}

//int main (void){
//    char *t [] = {"ls", "-AlX", NULL};
//
//    const int buf_size=200;
//    char buf [buf_size];
//    printf("veuillez entrer un nom de dossier");
//    fgets(buf, buf_size, stdin);
//    buf [(strcspn (buf, "\n"))] = '\0';
//          printf("deplacement dans le dossier %s longueur = %ld", buf, strlen(buf));
//}

//////////////TP5///////////////////////////////////////////////////////////////////////////////////



// stop processus.


//void interruptHandler (int n ) {
//    printf("recu signal %d", n );
//    fflush(stdout);
//}
//void fct(char s[]) {
//    printf("%d %d\n", sizeof(s), strlen(s));
//}
//
//int main(void) {
//    char s[] = "abcde";
//    printf("%d %d ", sizeof(s), strlen(s));
//    fct(s);
//    return 0;
//}


// ex adresse internet
//#include <arpa/inet.h>
//#include <stdio.h>
//
//void print_uint32(uint32_t a) {
//
//    unsigned char *t = (unsigned char *)&a;
//
//    printf("%d %d %d %d\n", t[0], t[1], t[2], t[3]);
//    printf("%x %x %x %x\n", t[0], t[1], t[2], t[3]);
//
//}
//
//int main(void) {
//
//    // in_addr_t inet_addr(const char *cp);
//
//    //   conversion de la chaine de caractère cp de notation IPv4 x.x.x.x
//    //   en représentation binaire dans l'ordre du réseau
//    //   retourne un type in_addr_t équivalent de uint32_t
//    //   soit un entier non signé sur 32 bits
//
//    uint32_t adr = inet_addr("127.0.0.1");
//    print_uint32(adr);
//    printf("%x\n", adr);
//
//    return 0;
//}


//droits fichier
//
//#include <stdio.h>
//#include <sys/stat.h>
//
//int main(void) {
//
//    int a = 0776;
//    int b = a & ~(S_IXGRP | S_IXOTH);
//
//    printf("%o %o\n", a, b);
//
//    return 0;
//}


//lectures non bloquantes
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <sys/select.h>
//#include <termios.h>
//
//struct termios saved_term;
//
//void reset_term() {
//    tcsetattr(0, TCSANOW, &saved_term);
//}
//
//void set_raw_term() {
//
//    // prépare la restauration de l'état du terminal
//    // en fin de programme
//
//    tcgetattr(0, &saved_term);
//    atexit(reset_term);
//
//    // passe le terminal en mode raw
//
//    struct termios t;
//
//    tcgetattr(0, &t);
//
//    t.c_lflag = t.c_lflag & ~ECHO;    // désactive le bit ECHO
//    t.c_lflag = t.c_lflag & ~ICANON;  // désactive le bit ICANON
//
//    tcsetattr(0, TCSANOW, &t);
//}
//
//int lecture() {
//    struct timeval t = { 0L, 0L };
//    fd_set fds;
//    FD_ZERO(&fds);
//    FD_SET(0, &fds);
//    int s;
//    s = select(1, &fds, NULL, NULL, &t);
//
//    // printf("%d ", s);
//    // fflush(stdout);
//
//    if (s == 0) {
//        write(1, ".", 1);
//    } else {
//        unsigned char c;
//        if (read(0, &c, sizeof(c)) > 0) {
//            write(1, &c, 1);
//            if (c == 'Q') return 0;
//        }
//    }
//    return 1;
//}
//
//int main(int argc, char *argv[]) {
//
//    set_raw_term();
//
//    while (lecture()) {
//        sleep(1); // attente hors select
//    }
//
//    return 0;
//}
//
///*
// #define ISIG    0000001
// #define ICANON    0000002
// #define ECHO    0000010
// #define ECHOE    0000020
// #define ECHOK    0000040
// #define ECHONL    0000100
// #define NOFLSH    0000200
// #define TOSTOP    0000400
// #define IEXTEN    0100000
// */

//ex 4 shm
//#include <stdio.h>
//#include <unistd.h>
//#include <sys/wait.h>
//#include <sys/ipc.h>
//#include <sys/shm.h>
//#include <sys/stat.h>
//
//const int n = 5;
//const int nb_process = 2;
//
//void count(int);
//
//int main(void) {
//
//    int id_shm;
//    int *ct;         // pointeur qui fera référence à un int dans un segment de mémoire partagé
//    // cet int servira de compteur global
//
//    id_shm = shmget(IPC_PRIVATE, sizeof(int), S_IWUSR | S_IRUSR | IPC_CREAT);
//    printf("id du segment de mémoire partagé = %d\n", id_shm);
//
//    ct = (int *) shmat(id_shm, NULL, 0);
//    *ct = 50; // valeur initiale du compteur global
//
//    int i;
//    for(i=0; i<nb_process; i++) {
//        // boucle de création de processus
//        if (fork() == 0) {
//            count(id_shm);
//            return 0;
//        }
//    }
//
//    // attend la fin des processus fils
//    for(i=0; i<nb_process; i++) {
//        wait(NULL);
//    }
//
//    printf("%d\n", *ct);
//
//    // supprime le segment de mémoire partagé
//    shmctl(id_shm, IPC_RMID, NULL);
//
//    return 0;
//}
//
//void count(int id_shm) {
//    int *ct1;
//    ct1 = (int *) shmat(id_shm, NULL, 0);
//
//    // dans un processus fils : incrémente n fois le compteur global
//    int x;
//    for(x=0; x<n; x++) {
//        *ct1 = *ct1 + 1;
//    }
//
//}



//ex5 shm
//
//#include <stdio.h>
//#include <unistd.h>
//#include <sys/wait.h>
//#include <sys/ipc.h>
//#include <sys/shm.h>
//#include <sys/sem.h>
//#include <sys/stat.h>
//
//const int n = 5000;
//const int nb_process = 20;
//
//void count(int, int);
//
//int main(void) {
//
//    int id_shm;
//    int id_sem;
//
//    int *ct;         // pointeur qui fera référence à un int dans un segment de mémoire partagé
//    // cet int servira de compteur global
//
//    id_shm = shmget(IPC_PRIVATE, sizeof(int), S_IWUSR | S_IRUSR | IPC_CREAT);
//    printf("id du segment de mémoire partagé = %d\n", id_shm);
//
//    ct = (int *) shmat(id_shm, NULL, 0);
//    *ct = 50; // valeur initiale du compteur global
//
//    id_sem = semget(IPC_PRIVATE, 1, S_IWUSR | S_IRUSR | IPC_CREAT);
//    printf("id du tableau de sémaphore = %d\n", id_sem);
//
//    // valeur initial du sémaphore = 1
//    if (semctl(id_sem, 0, SETVAL, 1) == -1) {
//        perror("semctl");
//    }
//
//    int i;
//    for(i=0; i<nb_process; i++) {
//        // boucle de création de processus
//        if (fork() == 0) {
//            count(id_shm, id_sem);
//            return 0;
//        }
//    }
//
//    // attend la fin des processus fils
//    for(i=0; i<nb_process; i++) {
//        wait(NULL);
//    }
//
//    printf("%d\n", *ct);
//
//    // supprime le segment de mémoire partagé
//    shmctl(id_shm, IPC_RMID, NULL);
//
//    return 0;
//}
//
//void count(int id_shm, int id_sem) {
//    int *ct1;
//    ct1 = (int *) shmat(id_shm, NULL, 0);
//    // ct1 pointe vers le même int que ct dans le programme principale
//
//    struct sembuf p[1] = { {0, -1, 0} };  // opération P (proberen = tester)      : décrémente le sémaphore, bloque si valeur du sémaphore < 0
//    struct sembuf v[1] = { {0,  1, 0} };  // opération V (verhogen = incrémenter) : incrémente le sémaphore
//
//    // dans un processus fils : incrémente n fois le compteur global
//    int x;
//    for(x=0; x<n; x++) {
//        semop(id_sem, p, 1);
//        *ct1 = *ct1 + 1;
//        semop(id_sem, v, 1);
//    }
//
//}

//ex5 msgrcv
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/stat.h>
//#include <sys/ipc.h>
//#include <sys/msg.h>
//
//const int max_size=200;
//
//struct msgbuf {
//    long mtype;
//    char mtext[1];
//};
//
//int main(int argc, char *argv[]) {
//
//    if (argc != 2) {
//        printf("Veuiller indiquer une clé\n");
//        return -1;
//    }
//
//    int id_msq;
//
//    id_msq = msgget(atoi(argv[1]), S_IWUSR | S_IRUSR | IPC_CREAT);
//    printf("id de la file de message = %d\n", id_msq);
//
//    char msg[max_size];
//    struct msgbuf msgp;
//
//    int l;
//
//    while (1) {
//        l = msgrcv(id_msq, &msgp, max_size, 1, 0);
//        msgp.mtext[l] = 0;
//        printf("Message recu : %s\n", msgp.mtext);
//    }
//
//    return 0;
//}

//ex msgsnd
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/stat.h>
//#include <sys/ipc.h>
//#include <sys/msg.h>
//
//const int max_size=200;
//
//struct msgbuf {
//    long mtype;
//    char mtext[1];
//};
//
//int main(int argc, char *argv[]) {
//
//    if (argc != 2) {
//        printf("Veuiller indiquer une clé\n");
//        return -1;
//    }
//
//    int id_msq;
//
//    id_msq = msgget(atoi(argv[1]), S_IWUSR | S_IRUSR | IPC_CREAT);
//    printf("id de la file de message = %d\n", id_msq);
//
//    char msg[max_size];
//    struct msgbuf msgp;
//
//    while (1) {
//        printf("Veuillez entrer un message : ");
//        fgets(msg, max_size, stdin);
//        msgp.mtype = 1;
//        strcpy(msgp.mtext, msg);
//        msgsnd(id_msq, &msgp, strlen(msg), IPC_NOWAIT);
//    }
//
//    return 0;
//}

//////////THREADS/////////////
// EX7

//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <pthread.h>
//
//void *task1() {
//    printf("Début tache 1\n");
//    sleep(3);
//    printf("suite tache 1\n");
//    sleep(3);
//    printf("Fin tache 1\n");
//}
//
//int main(void) {
//
//    pthread_t tid;
//
//    if (pthread_create(&tid, NULL, task1, NULL) < 0) {
//        perror("Ne peut créer tache 1");
//        exit(-1);
//    }
//
//    printf("Dans thread principal\n");
//    sleep(3);
//    printf("Suite thread principal\n");
//
//    return 0;
//}

//EX8
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <pthread.h>
//
//int a;
//int *p;
//
//void *task1() {
//    int i;
//    i = 0;
//    printf("Début tache 1, i = %d\n", i);
//    a = a + 1;
//    i = i + 1;
//    sleep(3);
//    printf("suite tache 1\n");
//    sleep(3);
//    p[0] = 2;
//    printf("Fin tache 1, i = %d\n", i);
//}
//
//void *task2() {
//    int i;
//    i = 0;
//    printf("Début tache 2, i = %d\n", i);
//    sleep(3);
//    printf("suite tache 2\n");
//    a = a + 1;
//    sleep(3);
//    p[1] = 5;
//    printf("Fin tache 2, i = %d\n", i);
//}
//
//int main(void) {
//
//    pthread_t tid1;
//    pthread_t tid2;
//
//
//    p = (int *)malloc(2 * sizeof(int));
//
//    if (pthread_create(&tid1, NULL, task1, NULL) < 0) {
//        perror("Ne peut lancer tache 1");
//        exit(-1);
//    }
//
//    if (pthread_create(&tid2, NULL, task2, NULL) < 0) {
//        perror("Ne peut lancer tache 2");
//        exit(-1);
//    }
//
//    printf("Dans thread principal\n");
//    sleep(3);
//    printf("Suite thread principal\n");
//
//    pthread_join(tid1, NULL);
//    pthread_join(tid2, NULL);
//
//    printf("a = %d, p[0] = %d, p[1] = %d\n", a, p[0], p[1]);
//
//    return 0;
//}
//

//EX9

//#include <stdio.h>
//#include <stdlib.h>
//#include <pthread.h>
//
//const int n = 5000;
//const int nb_thread = 20;
//
//int ct = 0;
//
//void *mytask() {
//
//    int i;
//    for(i = 0; i < n; i++) {
//        ct = ct + 1;
//    }
//}
//
//int main(void) {
//
//    int i;
//    pthread_t tid[nb_thread];
//
//    for(i = 0; i < nb_thread; i++) {
//        if (pthread_create(&tid[i], NULL, mytask, NULL) < 0) {
//            perror("could not create thread");
//            exit(-1);
//        }
//    }
//
//    for(i = 0; i < nb_thread; i++) {
//        pthread_join(tid[i], NULL);
//    }
//
//    printf("%d\n", ct);
//
//    return 0;
//}


//EX10

//#include <stdio.h>
//#include <stdlib.h>
//#include <pthread.h>
//
//const int n = 500;
//const int nb_thread = 20;
//
//int ct = 0;
//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
//
//void *mytask() {
//
//    int i;
//    for(i = 0; i < n; i++) {
//        pthread_mutex_lock(&lock);
//        ct = ct + 1;
//        pthread_mutex_unlock(&lock);
//    }
//}
//
//int main(void) {
//
//    int i;
//    pthread_t tid[nb_thread];
//
//    for(i = 0; i < nb_thread; i++) {
//        if (pthread_create(&tid[i], NULL, mytask, NULL) < 0) {
//            perror("could not create thread");
//            exit(-1);
//        }
//    }
//
//    for(i = 0; i < nb_thread; i++) {
//        pthread_join(tid[i], NULL);
//    }
//
//    printf("%d\n", ct);
//
//    return 0;
//}


////////TP6//////

///client

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <netdb.h>
//#include <unistd.h>
//
//const char hostname[] = "localhost";
//const int portnum = 2345;
//
//void main() {
//
//    int sd;  // n° fd de la socket
//    int ret;
//
//    struct hostent *host;
//    struct sockaddr_in addrsrv;
//
//    char msg[128];
//
//    if ( (sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
//        perror("Erreur socket");
//    else
//        printf("socket = %d\n", sd);
//
//    if ( (host = gethostbyname(hostname)) == NULL) {
//        herror("gethostbyname");
//        exit(-1);
//    }
//
//    bcopy(host->h_addr, (char *) &addrsrv.sin_addr, host->h_length);
//    addrsrv.sin_family = AF_INET;
//    addrsrv.sin_port = htons(portnum);
//
//    connect(sd, (const struct sockaddr*)&addrsrv, sizeof(addrsrv));
//
//    for(;;) {
//        printf("Entrer message : ");
//        scanf("%s", msg);
//
//        if ( (ret = send(sd, msg, strlen(msg), 0)) == -1)
//            perror("Erreur sendto");
//        else
//            printf("sendto = %d; msg = %s\n", ret, msg);
//
//        if ((ret = recv(sd, msg, sizeof(msg), 0)) == -1)
//            perror("Erreur recvfrom");
//        else {
//            msg[ret] = '\0'; printf("recvfrom = %d; msg = %s\n", ret, msg);
//        }
//    }
//}

//serveur

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <netdb.h>
//#include <unistd.h>
//#include <pthread.h>
//#include <signal.h>
//
//const int portnum = 2345;
//
//void *connection_handler(void *ptr_sd) {
//
//    int sd = *(int*)ptr_sd;
//    int ret;
//
//    char msg[128];
//    char replymsg[128];
//
//    printf("début connexion sd = %d\n", sd);
//    for(;;) {
//        ret = recv(sd, msg, sizeof(msg), 0);
//        if (ret == -1 )
//            perror("Erreur recvfrom");
//        else if (ret == 0) {
//            printf("fin connexion sd = %d\n", sd);
//            close(sd);
//            int r;
//            r = 0;
//            pthread_exit(&r);
//        } else {
//            msg[ret] = '\0'; printf("recvfrom = %d; msg = %s\n", ret, msg);
//            snprintf(replymsg, sizeof(replymsg), "recu : %s", msg);
//            if ( (ret = send(sd, replymsg, strlen(replymsg), 0)) == -1)
//                perror("Erreur sendto");
//            else
//                printf("sendto = %d; msg = %s\n", ret, msg);
//        }
//    }
//}
//
//void main() {
//
//    int sd;  // n° fd de la socket
//    int ret;
//    int accept_sd;
//
//    struct sockaddr_in addrsrv;
//
//    pthread_t thread_id;
//
//    if ( (sd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
//        perror("Erreur socket");
//    else
//        printf("socket = %d\n", sd);
//
//    // force l'utilisation de l'adresse même si des connexions clientes sont en cours
//    int optval = 1;
//    if (setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(int)) < 0)
//        perror("Erreur setsockopt");
//
//    addrsrv.sin_family = AF_INET;
//    addrsrv.sin_port = htons(portnum);
//    addrsrv.sin_addr.s_addr = htonl(INADDR_ANY);
//
//    if ( (ret = bind(sd, (const struct sockaddr *)&addrsrv, sizeof(addrsrv))) != 0)
//        perror("Erreur bind");
//
//    // passe la socket sd en mode "passif"
//    listen(sd, 1);
//
//    for(;;) {
//        // attente d'une connexion
//        accept_sd = accept(sd, NULL, NULL);
//        if (pthread_create(&thread_id, NULL, connection_handler, (void *)&accept_sd) < 0)
//            perror("could not create thread");
//    }
//}

const int nombre_client = 10;
int pipe(int pipefd[2]);

void client(int);

int main(void) {
    
    
    int i;
    int pipe(int pipefd[2]);
    for(i=0;i<nombre_client;i++) {
        int pid_client = fork();
        if (pid_client==0) {
            client(i);
        }
    }
    
    /* processus père se met en attente de terminaison des processus fils */
    for(i=0;i<nombre_client;i++) {
        wait(NULL);
    }
    
    return 0;
    
}

/*
 simule l'arrivée aléatoire de messages par un client n° n
 */
void client(int n) {
    char buf[128];
    int fd1[2], fd2[2];
    
    // processus fils qui compte
    
    
    srand(time(NULL) ^ (getpid()<<16));
    for(;;) {
        if (rand()%100 == 0) {
            printf("client %d envoi un message\n", n);
            write(fd1[1], "quelconque \0", strlen("quelconque") + 1); read(fd2[0], buf, sizeof(buf));
            printf("Message reçu du fils : %s\n", buf);
            exit(0);
        }
        usleep(100 * 1000);
    }
}
