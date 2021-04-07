#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <math.h> 

#define SIZE 20 

#define h(k) k%SIZE 
#define h_probe(k,i) (h(k)+i)%SIZE 

struct node{ 
    char* key; 
    char* val; 
}; 

struct node T[SIZE]; 

void init(){ 
    int i; 
    for(i=0; i< SIZE; i++){ 
        T[i].key = NULL; 
    } 
} 

int keyToValue(char* key){ 
    int n = strlen(key); 
    int i; 
    int radix128 = 0; 
    for(i=0; i<n; i++){
        radix128 += key[n-1-i]*pow(128,i);  
    } 
    return radix128; 
} 
void insert(char* key, char* val){ 
    int idx, i; 
    i = 0; 
    do{ 
        idx = h_probe(keyToValue(key), i);  
        if(T[idx].key == NULL){ 
            T[idx].key = key; 
            T[idx].val = val; 
            return; 
        }   
        else{ 
            i++; 
        } 
    }while(i != idx); 
    fprintf(stderr, "hash table overflow!"); 
} 

int search(char* key){ 
    int idx, i; 
    i = 0; 
    do{ 
        idx = h_probe(keyToValue(key), i);  
        if(!strcmp(T[idx].key, key)){  
            return idx; 
        } 
        else{ 
            i++; 
        } 
    }while(i != idx && T[idx].key != NULL);  
    return -1; 
}

void print(){ 
    int i; 
    for(i=0; i<SIZE; i++){ 
        printf("%s:%s\n", T[i].key, T[i].val);  
    } 
} 
int main(){ 
    init(); 
    insert("ab","red"); 
    insert("bc","black"); 
    insert("cd","white"); 
    insert("12","night"); 
    insert("xyz","kids"); 
    // print(); 
    int idx = search("qpq"); 
    if(idx != -1){
        printf("\n%s:%s\n", T[idx].key, T[idx].val); 
    } 
    else{ 
        printf("Data is not found\n"); 
    } 
    return 0; 
} 
