#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
extern char **environ;
#define MAX_ARGS 6

char *_strdup(char *str);
char *get_path();
/* excutable functions*/
int exec_cmd(char *command, char *path);
int exit_cmd_check(char *command);
int env_cmd_check(char *command);
void copy_tokenized_cmd(char **args, char **tokenized_command);
int executable_check(char *path);
void exec_executable(char **args);
void path_ret_error(void);
void reset_path_entry(char *path_entry, int *path_entry_len);
char *append_path_entry(char *path_entry, char path_character, int *path_entry_len);
void err_cmd_not_found(char *command);
void exec_cleanup(char **args);
char *prepare_path_entry(char *path_entry, int path_entry_len, char *command);
int exec_path_ent(char *path_entry, char **args);
void exec_cmds_path(char **args, char *path);
void exec_cmd_fork(char *command);

/* interactive and non-interacive*/
void exec_interactive_shell(void);
void exec_noninteractive_cmds(char *input_file);
/*main function */
int main(int ac, char **argv);
/* strings functions */
int _putchar(char c);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
size_t _strcspn(const char *str, const char *ch);
char *_strncat(char *dest, char *src, int n);
void *_realloc(void *ptr, size_t size);
/*void* _realloc(void *ptr, unsigned int old_size, unsigned int new_size);*/
char *_strtok(char *s, const char *deli);
/*char* _strtok(char* str, const char* delims);*/
int is_deli(char ch, const char *deli);
int _strncmp(const char *str1, const char *str2, size_t n);
typedef struct Node
{
char *directory;
struct Node *next;
} Node;

void print_directories(char *path);
Node *build_directory_ls(char *path);

char **tokenize_cmd(char *command);
char *_getenv(char *varname);
void print_env(void);
size_t my_getline(char **lineptr, size_t *size, FILE *stream);
char *mystrtok(char *s, char d);

void set_exit_status(int status);
int get_exit_status();

#endif
