#include "config.h"

#include <stdio.h>
#include <string.h>

config *first_c = NULL;

void push(char *k, char *v) {
    config *new = malloc(sizeof(config));
    new->key = k;
    new->value = v;
    new->next = first_c;
    
    first_c = new;
}

config *pop() {
    config *r = first_c;
    free(first_c);
    
    first_c = r->next;
    
    return r;
}

char *get_config(char *k) {
    config *ptr = first_c;
    while(ptr != NULL) {
        if(strncmp(ptr->key, k, strlen(k)) == 0) {
            return ptr->value;
        }
        ptr = ptr->next;
    }
    
    return NULL;
}

void save_config() {
    config *ptr = first_c;
    char line[50];
    FILE *file = fopen("configuration", "w");
    
    while(ptr != NULL) {
        //sprintf(line, "%s=%s\n", ptr->key, ptr->value);
        //fwrite(line, 1, sizeof(line), file);
        fprintf(file, "%s=%s\n", ptr->key, ptr->value);
        ptr = ptr->next;
    }
    
    fclose(file);
}

void read_config() {
    FILE *file = fopen("configuration", "r");
    char *k, *v, line[64], ch = '=';
    int index, i, j;
    
    if(file != NULL) {
        while(fgets(line, sizeof(line), file) != NULL) {
            if(strchr(line, ch) != NULL) {
                index = strchr(line, ch) - line;
                k = malloc((index + 1) * sizeof(char));
                v = malloc(5 * sizeof(char));

                for(i = 0; i < index; i++)
                    k[i] = line[i];
                k[i] = '\0';

                for(i = 0, j = index+1; i < 4 && j < 64; j++, i++) {
                    if(line[j] == '\n') break;
                    v[i] = line[j];
                }
                v[i] = '\0';

                push(k, v);
            }
        }
        fclose(file);
    }
}

void change_config(char *k, int step) {
    config *ptr = first_c;
    int val;
    
    while(ptr != NULL) {
        if(strncmp(ptr->key, k, strlen(k)) == 0) {
            val = atoi(ptr->value);
            val += step;
            sprintf(ptr->value, "%d", val);
            return;
        }
        ptr = ptr->next;
    }
}