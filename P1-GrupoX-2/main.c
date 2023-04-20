#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiculo.h"
#include "lvo.h"
#include "lso.h"
#include "lsd.h"
#include "lsobbb.h"

#ifdef _WIN32
    #include<windows.h>
#endif // _WIN32

void limpiar(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void MostrarLVO();
void MostrarLSO(vhlo[]);
void MostrarLSD(vhlo[]);
void MostrarLSOBB(vhlo[]);
void CargarVehiculo(vhlo*);
int Lectura_operaciones();

int main()
{
    int opctipo,opcestructura,opc,exito,res;
    vhlo nuevo;
    char pCE[7];
    lvo.ac=NULL;
    lvo.ap=NULL;
    do{
    printf("Elija una opcion:\n<1>Administracion de estructuras.\n<2>Comparacion de estructuras.\n<3>Salir\n");
    scanf("%d",&opctipo);
    switch(opctipo){
        case 1:do{
                printf("Elija una estructura:\n<1>Lista vinculada ordenada.\n<2>Lista secuencial desordenada.\n<3>Lista secuencial ordenada.\n<4>Lista secuencial ordenada (Busqueda binaria).\n<5>Salir\n");
                scanf("%d",&opcestructura);
                switch(opcestructura){
                    case 1: do{
                            printf("Elija la opcion a realizar:\n<1>Ingresar vehiculo.\n<2>Eliminar vehiculo.\n<3>Servicio realizado a un vehiculo.\n<4>Consultar informacion completa.\n<5>Mostrar estructura.\n<6>Salir.\n");
                            scanf("%d",&opc);
                            switch(opc){
                                case 1:if(cantlvo==250)
                                            printf("Lista llena.\n");
                                        else{
                                            CargarVehiculo(&nuevo);
                                            Alta1(nuevo,&exito);
                                            if(exito)
                                                printf("\nVehiculo ingresado.\n");
                                            else
                                                printf("El vehiculo ya se encuentra en la lista.\n");
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 2: if(cantlvo==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a eliminar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Baja1(pCE,nuevo,&exito,opctipo);
                                            if(exito==1)
                                                printf("Vehiculo eliminado.\n");
                                            else{
                                                if(exito==2)
                                                    printf("Elimincacion del vehiculo cancelada.\n");
                                                else
                                                    printf("No fue posible eliminar el vehiculo.\n");
                                            }
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 3: //determinar
                                break;
                                case 4: if(cantlvo==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar1(pCE,&nuevo,&exito);
                                            if(exito){
                                                printf("Resultado de la consulta:\n");
                                                MostrarVhlo(nuevo);
                                            }else
                                                printf("No fue posible consultar ese vehiculo.\n");
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 5: if(cantlvo==0){
                                            printf("Lista vacia. Ingrese vehiculos.\n");
                                            fflush(stdin);
                                            getchar();
                                            limpiar();

                                        }else
                                            MostrarLVO();
                                        limpiar();

                                break;
                                case 6: printf("Saliendo de la estructura...\n");
                                break;
                            }
                           }while(opc!=6);
                    break;
                    case 2:do{
                            printf("Elija la opcion a realizar:\n<1>Ingresar vehiculo.\n<2>Eliminar vehiculo.\n<3>Servicio realizado a un vehiculo.\n<4>Consultar informacion completa.\n<5>Mostrar estructura.\n<6>Salir.\n");
                            scanf("%d",&opc);
                            switch(opc){
                                case 1:if(cantlsd==250)
                                            printf("Lista llena.\n");
                                        else{
                                            CargarVehiculo(&nuevo);
                                            Alta2(nuevo,&exito);
                                            if(exito)
                                                printf("\nVehiculo ingresado.\n");
                                            else
                                                printf("El vehiculo ya se encuentra en la lista.\n");
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 2: if(cantlsd==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a eliminar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Baja2(pCE,nuevo,&exito,opctipo);
                                            if(exito==1)
                                                printf("Vehiculo eliminado.\n");
                                            else{
                                                if(exito==2)
                                                    printf("Elimincacion del vehiculo cancelada.\n");
                                                else
                                                    printf("No fue posible eliminar el vehiculo.\n");
                                            }
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 3: //determinar
                                break;
                                case 4: if(cantlsd==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar.\n");
                                            scanf("%7[^\n]",pCE);
                                            Evocar2(pCE,&nuevo,&exito);
                                            if(exito){
                                                printf("Resultado de la consulta:\n");
                                                MostrarVhlo(nuevo);
                                            }else
                                                printf("No fue posible consultar ese vehiculo.\n");
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 5: if(cantlsd==0){
                                            printf("Lista vacia. Ingrese vehiculos.\n");
                                            fflush(stdin);
                                            getchar();
                                            limpiar();

                                        }else
                                            MostrarLSD(l);
                                        limpiar();

                                break;
                                case 6: printf("Saliendo de la estructura...\n");
                                break;
                            }
                           }while(opc!=6);
                    break;
                    case 3:do{
                            printf("Elija la opcion a realizar:\n<1>Ingresar vehiculo.\n<2>Eliminar vehiculo.\n<3>Servicio realizado a un vehiculo.\n<4>Consultar informacion completa.\n<5>Mostrar estructura.\n<6>Salir.\n");
                            scanf("%d",&opc);
                            switch(opc){
                                case 1:if(cantlso==250)
                                            printf("Lista llena.\n");
                                        else{
                                            CargarVehiculo(&nuevo);
                                            Alta(nuevo,&exito);
                                            if(exito)
                                            printf("\nVehiculo ingresado.\n");
                                        else
                                            printf("El vehiculo ya se encuentra en la lista.\n");
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 2:if(cantlso==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a eliminar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Baja(pCE,nuevo,&exito,opctipo);
                                            if(exito==1)
                                                printf("Vehiculo eliminado.\n");
                                            else{
                                                if(exito==2)
                                                    printf("Elimincacion del vehiculo cancelada.\n");
                                                else
                                                    printf("No fue posible eliminar el vehiculo.\n");
                                            }
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 3://determinar
                                break;
                                case 4:if(cantlso==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar(pCE,&nuevo,&exito);
                                            if(exito){
                                                printf("Resultado de la consulta:\n");
                                                MostrarVhlo(nuevo);
                                            }else
                                                printf("No fue posible consultar ese vehiculo.\n");
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 5: if(cantlso==0){
                                            printf("Lista vacia. Ingrese vehiculos.\n");
                                            getchar();
                                        }else
                                            MostrarLSO(l);
                                        limpiar();
                                break;
                                case 6: printf("Saliendo de la estructura...\n");
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                            }
                           }while(opc!=6);
                    break;
                    case 4: do{
                            printf("Elija la opcion a realizar:\n<1>Ingresar vehiculo.\n<2>Eliminar vehiculo.\n<3>Servicio realizado a un vehiculo.\n<4>Consultar informacion completa.\n<5>Mostrar estructura.\n<6>Salir.\n");
                            scanf("%d",&opc);
                            switch(opc){
                                case 1:if(cantlsobb==250)
                                            printf("Lista llena.\n");
                                        else{
                                            CargarVehiculo(&nuevo);
                                            Alta3(nuevo,&exito);
                                            if(exito)
                                            printf("\nVehiculo ingresado.\n");
                                        else
                                            printf("El vehiculo ya se encuentra en la lista.\n");
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 2:if(cantlsobb==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a eliminar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Baja3(pCE,nuevo,&exito,opctipo);
                                            if(exito==1)
                                                printf("Vehiculo eliminado.\n");
                                            else{
                                                if(exito==2)
                                                    printf("Elimincacion del vehiculo cancelada.\n");
                                                else
                                                    printf("No fue posible eliminar el vehiculo.\n");
                                            }
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 3://determinar
                                break;
                                case 4:if(cantlsobb==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar3(pCE,&nuevo,&exito);
                                            if(exito){
                                                printf("\nResultado de la consulta:\n\n");
                                                MostrarVhlo(nuevo);
                                            }else
                                                printf("No fue posible consultar ese vehiculo.\n");
                                        }
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                                case 5: if(cantlsobb==0){
                                            printf("Lista vacia. Ingrese vehiculos.\n");
                                            getchar();
                                        }else
                                            MostrarLSOBB(lsobb);
                                        limpiar();
                                break;
                                case 6: printf("Saliendo de la estructura...\n");
                                        fflush(stdin);
                                        getchar();
                                        limpiar();
                                break;
                            }
                           }while(opc!=6);
                    break;
                    case 5: printf("\nSaliendo del programa...\n");
                    break;
                }
                }while(opcestructura!=5);
    break;
    case 2: printf("Cargando datos...\n");
            res = Lectura_operaciones();
            if(res){
                printf("Lectura exitosa.\n");
            }else
                printf("Error: Carga de datos no exitosa.\n");


    }
    }while(opcestructura!=3);
    return 0;
}

void MostrarLVO(){
    int i=1;
    vhlo aux;
    nodoV *n;
    printf("Mostrando...\n");
    for(n=lvo.ac;n!=NULL;n=(*n).sig){
        aux = (*n).dato;
        printf("\n----------[%d]----------\n",i);
        MostrarVhlo(aux);
        i++;
    }
    getchar();
}
void MostrarLSO (vhlo a[]){
    int i;
    vhlo aux;
    printf("Mostrando\n");
    for(i=0;i<cantlso;i++){
        aux=l[i];
        printf("\n----------[%d]----------\n",i+1);
        MostrarVhlo(aux);
    }
    getchar();
}

void MostrarLSD (vhlo a[]){
    int i;
    vhlo aux;
    printf("Mostrando\n");
    for(i=0;i<cantlsd;i++){
        aux=lsd[i];
        printf("\n----------[%d]----------\n",i+1);
        MostrarVhlo(aux);
    }
    getchar();
}

void MostrarLSOBB(vhlo a[]){
    int i;
    vhlo aux;
    printf("Mostrando...\n");
    for(i=0;i<cantlsobb;i++){
        aux = lsobb[i];
        printf("\n----------[%d]----------\n",i+1);
        MostrarVhlo(aux);
    }
    getchar();
}

void CargarVehiculo(vhlo *v){
    int nanio;
    float nImporte;
    char nPatente[8],nMM[60],nNombre[50],nTel[15],nServ[70],nFecha[11];
    printf("\nIngrese los siguentes datos del nuevo vehiculo:\n");
    printf("\nPatente: ");
    fflush(stdin);
    scanf("%8[^\n]",nPatente);
    printf("\nMarca y modelo: ");
    fflush(stdin);
    scanf("%60[^\n]",nMM);
    printf("\nA%co de fabricacion: ",165);
    fflush(stdin);
    scanf("%d",&nanio);
    printf("\nNombre del due%co: ",165);
    fflush(stdin);
    scanf("%50[^\n]",nNombre);
    printf("\nTelefono: ");
    fflush(stdin);
    scanf("%15[^\n]",nTel);
    printf("\nServicio realizado: ");
    fflush(stdin);
    scanf("%70[^\n]",nServ);
    printf("\nImporte: ");
    fflush(stdin);
    scanf("%f",&nImporte);
    printf("\nFecha: ");
    fflush(stdin);
    scanf("%11[^\n]",nFecha);
    estvhlo(nPatente,nMM,nanio,nNombre,nTel,nServ,nImporte,nFecha,v);
}

int Lectura_operaciones(){
    FILE *fp;
    int codOp,exitoL;
    if((fp=fopen("Operaciones.txt","r"))==NULL)
        return 0;
    else{
        while(!(feof(fp))){
            vhlo aux;
            fscanf(fp,"%d",&codOp);
            fgetc(fp);
            if(codOp==1||codOp==2){
                fgets(aux.patente,8,fp);
                fgetc(fp);
                fgets(aux.marcamod,60,fp);
                fscanf(fp,"%d",&aux.anio);
                fgetc(fp);
                fgets(aux.nom,50,fp);

                fgets(aux.tel,15,fp);

                fgets(aux.serv,70,fp);
                fscanf(fp,"%f",&aux.importe);
                fgetc(fp);
                fgets(aux.fecha,11,fp);
                fgetc(fp);
                if(codOp==1){
                    Alta(aux,&exitoL);
                    Alta1(aux,&exitoL);
                    Alta2(aux,&exitoL);
                    Alta3(aux,&exitoL);
                }else{
                    Baja(aux.patente,aux,&exitoL,2);
                    Baja1(aux.patente,aux,&exitoL,2);
                    Baja2(aux.patente,aux,&exitoL,2);
                    Baja3(aux.patente,aux,&exitoL,2);
                }
            }else{
                if(codOp==3){
                    fgets(aux.patente,8,fp);
                    fgetc(fp);
                    vhlo aux1;
                    Evocar(aux.patente,&aux1,&exitoL);
                    Evocar1(aux.patente,&aux1,&exitoL);
                    Evocar2(aux.patente,&aux1,&exitoL);
                    Evocar3(aux.patente,&aux1,&exitoL);
                }else
                    printf("Error: Codigo de operador desconocido.\n");
            }
        }
        return 1;
    }
    fclose(fp);
}
