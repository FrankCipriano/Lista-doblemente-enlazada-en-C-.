#include <iostream>
#define Ascendente 1
#define Descendente 0

using namespace std;
//********************NODO****************
typedef struct nodo{
	int info;
	struct nodo *sig;
	struct nodo *ant;
}TNodo;
//*******************LISTA***************
typedef struct LE{
    TNodo *inicio;
}TLE;
//*******************CREAR NODO*********
TNodo *crearNodo(int x){
    TNodo *nodo=(TNodo*)malloc(sizeof(TNodo));
    nodo->info=x;
    nodo->sig=NULL;
    nodo->ant=NULL;
    return nodo;
}
//******************CREAR LISTA*********
TLE *crearLista(){
    TLE *lista=(TLE*)malloc(sizeof(TLE));
    lista->inicio=NULL;
    return lista;
}
//*****************INSERTAR************
void insertar(TLE *lista,int x){
    TNodo *nodo=crearNodo(x);
    TNodo *p=NULL;
    if(lista->inicio==NULL){
        lista->inicio=nodo;
        nodo->ant=NULL;
    }else{
        p=lista->inicio;
        while(p->sig != NULL)
        p=p->sig;
        p->sig=nodo;
        nodo->ant=p;
    }
}
//****************ELIMINAR*************
void Eliminar(TLE *lista,int dato){
    int encontrado;
    TNodo *p=lista->inicio;
    TNodo *ant=NULL;{
    if(p->info==dato)
    encontrado=1;
    else{
        ant=p;
        p=p->sig;
    }
    }
    if(p!=NULL){
        if(ant==NULL)
        lista->inicio=(lista->inicio)->sig;
        else{
            ant->sig=p->sig;
            p->sig->ant=ant;
        }
        free(p);
    }
}
//******************BORRAR**************
void Borrar(TLE *lista){
    TNodo *p=NULL;
    while(lista->inicio != NULL){
        p=lista->inicio;
        lista->inicio=p->sig;
        p->sig->ant=NULL;
        free(p);
    }
}
//****************REPORTAR**************
void Reportar(TLE *lista,int orden){
    TNodo *p=lista->inicio;
    if(orden==Ascendente){
        cout<<" Lista-> ";
        while(p!=NULL){
            cout<<p->info<<"<->";
            p=p->sig;
        }
        cout<<"NULL";
    }else{
        cout<<"NULL";
        while(p->sig != NULL)
        p=p->sig;
        while(p != NULL){
            cout<<"<->"<<p->info;
            p=p->ant;
        }
        cout<<"<-Lista";
    }
    cout<<"\n"<<"\n";
}
//**************ESTA VACIA?***************
void Vacia(TLE *lista){
    if(lista->inicio==NULL)
    cout<<"\n -La Lista esta vacia!!\n";
    else
    cout<<"\n -La Lista no esta vacia!\n\n";
}
//******************************************
int main(){
    TLE *L=crearLista();
    int N,E,i=0;
    int op;
    cout<<"\n------------------------------";
    cout<<"\n  LISTA DOBLEMENTE ENLAZADA   ";
    cout<<"\n------------------------------";
    cout<<"\n\n          MENU              ";
    while(1){
        cout<<"\n----------------------------";
        cout<<"\n 1. Insertar";
        cout<<"\n 2. Eliminar Elemento";
        cout<<"\n 3. Borrar lista";
        cout<<"\n 4. Mostrar Lista Ascendente";
        cout<<"\n 5. Mostrar Lista Descendente";
        cout<<"\n 6. Lista esta vacia?";
        cout<<"\n 7. Salir";
        cout<<"\n----------------------------";
        do{
            cout<<"\n\n->Ingrese opcion\n";
            cin>>op;
        }while(op<1||op>7);
        switch(op){
            case 1:
            i++;
            cout<<"\n -Ingrese["<<i<<"] elemento:";
            cin>>N;
            insertar(L,N);
            break;
            case 2:
            cout<<"\n -Ingrese elemento a eliminar: ";
            cin>>E;
            Eliminar(L,E);
            break;
            case 3:
            Borrar(L);
            cout<<"\n\n -Se elimino la Lista correctamente...";
            break;
            case 4:
            cout<<"\n";
            Reportar(L,Ascendente);
            break;
            case 5:
            cout<<"\n";
            Reportar(L,Descendente);
            break;
            case 6:
            Vacia(L);
            break;
            case 7:
            exit(1);
            default:
            cout<<"\n\nOpcion no valida!";
        }
    }
    return EXIT_SUCCESS;
}