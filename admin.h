#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void cadastroAdmin();
void loginAdmin();
int checaCadastroAdmin(char usuario[10]);
int checaLoginAdmin(char login[10], char senha[10]);
void menuAdmin(char login[10]);

#endif // ADMIN_H_INCLUDED
