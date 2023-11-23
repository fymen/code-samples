/* The C programming language, Exercise 6-2
   Write a program that read a C source file and prints in alphabetical order
   each group names of variables that are identical in the first 6
   characters, but different somewhere thereafter.
   Don't count words within strings and comments. Make 6 the parameter that
   can be set.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tree_node{
  int num;
  char *word;
  struct tree_node *parent;
  struct tree_node *left;
  struct tree_node *right;
} tnode;

tnode *talloc(void)
{
  tnode *node = (tnode *)malloc(sizeof(tnode));
  memset(node, 0, sizeof(tnode));

  return node;  
}

char* strdup(const char* s)
{
  char* tmp = (char*)malloc(strlen(s)+1);
  memset(tmp, 0, strlen(s)+1);
  strcpy(tmp, s);

  return tmp;
}

tnode *add_tree(tnode *tree, tnode *parent, const char* s)
{
  int cond = 0;

  if (!s) {
    return NULL;
  }

  if (!tree) {
    tree = talloc();
    if (!tree){
      return NULL;
    } 

    tree->word = strdup(s);
    if(!tree->word) {
      return NULL;
    }
    tree->num = 1;
    tree->parent = parent;
    tree->left = tree->right = NULL;
    printf("debug: %d, %s\n", tree->num, tree->word);
  }
  else {
    cond = strcmp(tree->word, s);
    if (cond == 0) {
      tree->num++;
    }
    else if (cond > 0) {
      tree->left = add_tree((tree->left), tree, s);  
    }
    else {
      tree->right = add_tree((tree->right), tree, s);  
    }
  }
  return tree;
}

void delete_tree(tnode *tree)
{
  if (tree) {
    if (tree->left) {
      delete_tree(tree->left);
    }
    if (tree->right) {
      delete_tree(tree->right);
    }
    if (tree->word) {
      free(tree->word);
    }
    if (tree) {
      free(tree); 
    }
    tree = NULL;
  }
}
void print_node(tnode *tree) {
  printf("node: %d %s\n", tree->num, tree->word);
}
void print_tree(tnode *tree, int first_num)
{
  if (tree) {
    print_tree(tree->left, first_num);

    if(!tree->left && !tree->right) {
      if (tree->parent) {
        if (!strncmp(tree->word, tree->parent->word, first_num))
          print_node(tree);
      }
    }
    else if (tree->left && tree->right) {
      if (!strncmp(tree->word, tree->right->word, first_num) || !strncmp(tree->word, tree->left->word, first_num))
        print_node(tree);

    }
    else if (tree->left) {
      if (!strncmp(tree->word, tree->left->word, first_num))
        print_node(tree);
      else {
        if (tree->parent) {
          if (!strncmp(tree->word, tree->parent->word, first_num))
            print_node(tree);
        }
      }
    }
    else {
      if (!strncmp(tree->word, tree->right->word, first_num))
        print_node(tree);
      else {
        if (tree->parent) {
          if (!strncmp(tree->word, tree->parent->word, first_num))
            print_node(tree);
        }
      }
    }
    
    print_tree(tree->right, first_num);

  }
}

static char stmp[100] = {0};
char* get_word(FILE *fp)
{
  
  if(!fp)
    return NULL;
  char c;
  FILE* tfp = fp;
  int i = 0;
  int mark_apostrophy = 0;
  int mark_quotation = 0;
  int mark_backslash = 0;


  
  static char last_char = 0;

  while ((c = fgetc(tfp)) != EOF) {

    if (mark_backslash) {
      mark_backslash = 0;
      continue;
    }
    if (c == '\\') {
      mark_backslash = 1;
      continue;
    }

    if ((c == '\'')) {
      mark_apostrophy = ~mark_apostrophy;
      continue;
    }
    
    if (mark_apostrophy)
      continue;

    if ((c == '"')) {
      mark_quotation = ~mark_quotation;
      continue;
    }
    if (mark_quotation)
      continue;

    if ((c == ' ') || (c == '\n') || (c == '\t') || (c == '(')
        || (c == ')') || (c == '%') || (c == '{') || (c == '}')
        || (c == ';') || (c == '=') || (c == '[') || (c == ']')
        || (c == '#') || (c == '<') || (c == '>') || (c == '-')
        || (c == '/') || (c == '|') || (c == '+') 

        || (c == ',') || (c == '*') || (c == '!')) {
      if(i == 0)
        continue;
      
      break;
    }
    
    
    stmp[i] = c;
    i++;

  }
  if (!i)
    return NULL;
  
  stmp[i] = '\0';
  return stmp;
}

int main(int argc, char** argv)
{
  tnode *test_tree = NULL;
  int ret = 0;

  FILE *fp = NULL;

  fp = fopen(argv[1], "r");
  if (!fp) {
    printf("open file %s failed\n", argv[1]);
    return -1;
  }
  char *tmpc = NULL;
  while (tmpc = get_word(fp))
    test_tree = add_tree(test_tree, NULL, tmpc);
  printf("........%p...............................\n", test_tree);

  print_tree(test_tree, 6);
  
  delete_tree(test_tree);

  return 0;
}
