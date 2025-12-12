#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct Entry {
    int key;
    int value;
    struct Entry* sig;
} Entry;

typedef struct {
    Entry* buckets[TAM];
} HashTable;


int hash(int key) {
    if (key < 0) key = -key;
    return key % TAM;
}

void ht_init(HashTable* ht) {
    for (int i = 0; i < TAM; i++) ht->buckets[i] = NULL;
}

Entry* crear_entry(int key, int value) {
    Entry* e = (Entry*)malloc(sizeof(Entry));
    if (!e) return NULL;
    e->key = key;
    e->value = value;
    e->sig = NULL;
    return e;
}

void ht_put(HashTable* ht, int key, int value) {
    int idx = hash(key);
    Entry* p = ht->buckets[idx];
    while (p) {
        if (p->key == key) {
            p->value = value; // actualizar//
            return;
        }
        p = p->sig;
    }

    Entry* e = crear_entry(key, value);
    if (!e) {
        printf("Error: no hay memoria.\n");
        return;

    }
    e->sig = ht->buckets[idx];
    ht->buckets[idx] = e;
}

int ht_get(HashTable* ht, int key, int* out_value) {
    int idx = hash(key);
    Entry* p = ht->buckets[idx];
    while (p) {
        if (p->key == key) {
            *out_value = p->value;
            return 1;
        }
        p = p->sig;
    }
    return 0;
}

int ht_remove(HashTable* ht, int key) {
    int idx = hash(key);
    Entry* p = ht->buckets[idx];
    Entry* ant = NULL;

    while (p && p->key != key) {
        ant = p;
        p = p->sig;
    }
    if (!p) return 0;

    if (!ant) ht->buckets[idx] = p->sig;
    else ant->sig = p->sig;

    free(p);
    return 1;
}

void ht_print(HashTable* ht) {
    for (int i = 0; i < TAM; i++) {
        printf("[%d]: ", i);
        Entry* p = ht->buckets[i];
        while (p) {
            printf("(k=%d,v=%d) -> ", p->key, p->value);
            p = p->sig;
        }
        printf("NULL\n");
    }
}

void ht_free(HashTable* ht) {
    for (int i = 0; i < TAM; i++) {
        Entry* p = ht->buckets[i];
        while (p) {
            Entry* tmp = p;
            p = p->sig;
            free(tmp);
        }
        ht->buckets[i] = NULL;
    }
}

int main(void) {
    HashTable ht;
    ht_init(&ht);

    ht_put(&ht, 15, 100);
    ht_put(&ht, 25, 200); // colision con 15 si TAM=10//
    ht_put(&ht, 7,  700);

    printf("Tabla hash:\n");
    ht_print(&ht);

    int val;
    printf("Get key=25: %s\n", ht_get(&ht, 25, &val) ? "OK" : "NO");
    if (ht_get(&ht, 25, &val)) printf("Valor: %d\n", val);

    printf("Remove key=15: %s\n", ht_remove(&ht, 15) ? "OK" : "NO");
    ht_print(&ht);

    ht_free(&ht);
    return 0;
}

