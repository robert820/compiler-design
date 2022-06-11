#ifndef SYMTAB_H
#define SYMTAB_H

#define NAME_MAX_LENGTH 256
#define LINKEDLIST_MAX_SIZE 32

typedef enum identifier_type
{
    function_i,
    variable_i,
    constant_i
} identifier_type;

typedef enum ValueType
{
    void_v,
    bool_v,
    int_v,
    real_v,
    string_v,
    unknown_v
} ValueType;

typedef struct LinkedList
{
    char name[NAME_MAX_LENGTH];
    struct LinkedList *next;
    int index;
    identifier_type type;
    ValueType valueType;
} LinkedList;

typedef struct Hash
{
    struct LinkedList *entries[LINKEDLIST_MAX_SIZE];
    int size;
} Hash;

Hash *create();
LinkedList *insert(Hash *, char *name);
LinkedList *lookup(Hash *, char *name);

char *dump(Hash *);

#endif