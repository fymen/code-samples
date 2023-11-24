/* The C programming language Exercise 6-5. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

typedef struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
} hnlist;

static hnlist* hash_tab[HASHSIZE] = {0};

char* strdup(const char* s)
{
     char* tmp = (char*)malloc(strlen(s)+1);
     memset(tmp, 0, strlen(s)+1);
     strcpy(tmp, s);

     return tmp;
}

unsigned int hash(const char *s)
{
  if (!s)
    return 0;

  unsigned int hash_val = 0;

  for(hash_val=0; *s != '\0'; s++) {
    hash_val = *s + 31 * hash_val;
  }
  return hash_val % HASHSIZE;
}

hnlist* lookup(char* name)
{
  hnlist *sp;
  for (sp = hash_tab[hash(name)]; sp != NULL; sp = sp->next) {
    if (!strcmp(sp->name, name)) {
      return sp;
    }
  }
  
  return NULL;
}

hnlist* install(char* name, char* defn)
{
  hnlist *np;

  if (!name || !defn) {
    return NULL;
  }

  if (!(np = lookup(name))) {
    np = (hnlist*)malloc(sizeof(hnlist));
    if (!np)
      return NULL;
    
    if (!(np->name = strdup(name)))
         return NULL;
    
    np->next = hash_tab[hash(name)];
    hash_tab[hash(name)] = np;
  }
  else {
    free(np->defn);
  }
  
  if (!(np->defn = strdup(defn)))
       return NULL;
  
  return np;
}

void uninstall(char* name)
{
     hnlist *sp;
     static hnlist* parent;

     int hash_val = hash(name);
     
     printf("uninstall %s\n", name);
     
     for (parent = sp = hash_tab[hash_val]; sp != NULL; sp = sp->next) {
          if (!strcmp(sp->name, name)) {
               if (parent == sp) {
                    hash_tab[hash_val] = sp->next;
               }
               else {
                    parent->next = sp->next;
               }
               free(sp->name);
               free(sp->defn);
               free(sp);
               sp = NULL;
               
               break;
          }
          parent = sp;
     }
}

void delete_htab(void)
{
     hnlist *np, *tmp;
     
     for (int i = 0; i < HASHSIZE; i++) {
          for (np = hash_tab[i]; np != NULL; np = tmp) {
               tmp = np->next;
               free(np->name);
               free(np->defn);
               free(np);
          }
          hash_tab[i] = NULL;
     }
     
}

void print_hash_tab(void)
{
     hnlist *np;
     printf("print hash tab...................\n");
     for (int i = 0; i < HASHSIZE; i++) {
          for (np = hash_tab[i]; np != NULL; np = np->next)
               printf("%d,%s,%s;", i, np->name, np->defn);
          if (hash_tab[i])
               printf("\n");
     }
}
int main(int argc, char **argv)
{

     print_hash_tab();

  install("MAX", "10000");
  install("NAME", "Robert is a big mouth");
  install("MAX_NUM", "100");
  install("MAX_DUMP", "aaaaaaaaaaa");
  install("MAX_name", "one hundred");


  print_hash_tab();
  uninstall("MAX");
  uninstall("NAME");
  uninstall("MAX_name");

  print_hash_tab();

  delete_htab();
  print_hash_tab();

  
  return 0;
}

