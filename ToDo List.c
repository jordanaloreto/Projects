#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct agenda
{
	int id_tarefa,status;
	char data[10],conteudo[100];
	struct lista *proximo;
	struct lista *anterior;
};
typedef struct agenda Lista;

Lista *lst_criar()
{
	return NULL;
}

Lista *lst_inserir(Lista *lst,int id_tarefa,char *data,char *conteudo)
{
	Lista *p;
	p=lst_buscar(lst,id_tarefa);
	if(p==NULL)
	{
        Lista *novo = (Lista *)malloc(sizeof(Lista));
    	novo->id_tarefa=id_tarefa;
    	novo->status=0;
    	strcpy(novo->conteudo,conteudo);
    	strcpy(novo->data,data);
    	
    	novo->proximo=lst;
    
    	
    	return novo;
    }
    printf("Esse id ja existe!\n");
    return lst;
}

void lst_imprimir(Lista *lst)
{
	Lista *aux_lst;
	for(aux_lst=lst;aux_lst!=NULL;aux_lst=aux_lst->proximo)
	{
		if(aux_lst==NULL)
		  printf("Nulo\n");
		
	   printf("%d\n",aux_lst->id_tarefa);
	   printf("%d\n",aux_lst->status);
	   printf("%s\n",aux_lst->data);
	   printf("%s\n",aux_lst->conteudo);
		
		
	}
}

int lst_vazia(Lista *lst)
{
	if(lst==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Lista *lst_buscar(Lista *lst,int id_tarefa)
{
    Lista *p;
    for(p=lst;p!=NULL;p=p->proximo)
    {
        if(p->id_tarefa==id_tarefa)
        {
            return p;
        }
    }
    return NULL;
}

Lista *lst_remover(Lista *lst, int id_tarefa)
{
	Lista *p = lst;
	Lista *ant = NULL;
	
	while(p != NULL && p->id_tarefa != id_tarefa)
	{
		ant = p;
		p = p->proximo;
	}
	
	if(p == NULL)
	{
		return lst;
	}
	
	if(ant == NULL)
	{
		lst = p->proximo;
	}
	else
	{
		ant->proximo = p->proximo;
	}
	
	free(p);
	return lst;
	
}

Lista *lst_liberar(Lista *lst)
{
	Lista *p = lst;

	while(p != NULL)
	{
		Lista *aux=p->proximo;
		free(p);
		p=aux;
	}
	return p;

}

void Lista *lst_alterar(Lista *lst,int id_tarefa,char *data,char *conteudo)
{
	Lista *p;
	for(p=lst;p!=NULL;p=p->proximo)
	{
		if(p->id_tarefa==id_tarefa)
		{
			strcpy(p->data,data);
			strcpy(p->conteudo,conteudo);
			printf("Modificacoes realizadas com sucesso!");
        }
	}

}
int Lista *lst_status(Lista *lst,int id_tarefa)
{
	Lista *tarefa = lst_buscar(lst, id_tarefa);
	
	if(tarefa->status==0)
	{
		tarefa->status=1;
		printf("Tarefa concluida\n");
	}
}

void menu()
{
    Lista *lst1=lst_criar();
    int funcao;
    
    printf("1 - Inserir tarefa\n");
    printf("2 - Editar tarefa\n");
    printf("3 - Remover tarefa\n");
    printf("4 - Concluir tarefa\n");
    
    printf("Digite a funcao desejada [1-4]: ");
    scanf("%d", &funcao);
    system("cls");
    
    switch(funcao)
    {
        case 1:
            printf("Digite a data da terefa: ");
            scanf("%s", &data);
            printf("Digite o conteudo da terefa: ");
            scanf("%s", &conteudo);
            lst_inserir(lst1,data,conteudo);
            break;
        case 2:
            printf("Digite o ID da tarefa a ser editada: ");
            scanf("%d", &id_tarefa);
            //lst_buscar(lst,int id_tarefa);
            printf("Digite a nova data da tarefa: ");
            scanf("%s",&data);
            printf("Digite o novo conteudo da tarefa: ");
            scanf("%s",&conteudo);
            lst_alterar(lst,id_tarefa,data,conteudo);
            break;
        case 3:
            printf("Digite o ID da tarefa a ser removida: ");
            scanf("%d",&id);
            lst_remover(lst,id_tarefa);
            break;
        case 4:
            printf("Digite o ID da tarefa a ser mudado o status: ");
            scanf("%d", &id_tarefa);
            //lst_buscar(lst,int id_tarefa);
            int resposta;
			printf("Deseja mudar o status da tarefa de pendente para concluida:\n 1-Sim\n 0-Nao");
            scanf("%d",&resposta)
			if(respota = 1)
			{
				lst_status(lst, id_tarefa);
			}
    }
}
            
int main()
{
	menu();
    Lista *lst1 = lst_criar();
	if(lst1==NULL)
	{
		printf("Nulo\n");
	}
	lst1=lst_inserir(lst1,01,"12/03/22","tarefa");
	lst_imprimir(lst1);
	
	return 0;
	
}
