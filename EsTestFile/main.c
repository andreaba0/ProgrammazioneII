#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char*argv[]) {
    if(argc!=2||strlen(argv[1])==0) {
        printf("Richiesto il nome del file da analizzare\n");
        return 1;
    }

    FILE*file = fopen(argv[1], "r+");
    if(file==NULL) {
        printf("Impossibile aprire il file\n");
        return 1;
    }
    rewind(file);
    char str[20];
    int ok;
    while(1) {
        ok=fscanf(file, "%19s", str);
        if(ok!=1) break;
        printf("Stringa: '%10s', len: %5d\n", str, (int)strlen(str));
    }
    rewind(file);
    char c;
    while(1) {
        ok=fscanf(file, "%c", &c);
        if(ok!=1) break;
        if(c!='\n') printf("Carattere: '%c', ASCII: %d\n", c, c);
        else printf("ASCII simbolo a capo: '%d'\n", c);
    }
    fclose(file);
    return 0;
}