//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiculo.h"
#include "lvo.h"
#include "lso.h"
#include "lsd.h"
#include "lsobbb.h"
#include "controlEst.h"

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
void MostrarLSO();
void MostrarLSD();
void MostrarLSOBB();
void CargarVehiculo(vhlo*);


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
                                            Alta1(nuevo,&exito,&costo);
                                            if(exito)
                                                printf("\nVehiculo ingresado.\n");
                                            else
                                                printf("El vehiculo ya se encuentra en la lista.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 2: if(cantlvo==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a eliminar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Baja1(pCE,nuevo,&exito,opctipo,&costo);
                                            if(exito==1)
                                                printf("Vehiculo eliminado.\n");
                                            else{
                                                if(exito==2)
                                                    printf("Elimincacion del vehiculo cancelada.\n");
                                                else
                                                    printf("No fue posible eliminar el vehiculo.\n");
                                            }
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 3: if(cantlvo==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar por servicio.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar1(pCE,&nuevo,&exito,&costo);
                                            if(exito){
                                                if(strlen(nuevo.serv)==0)
                                                    printf("NO se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                                else
                                                    printf("SI se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                            }else
                                                printf("No fue posible consultar por el vehiculo.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 4: if(cantlvo==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar1(pCE,&nuevo,&exito,&costo);
                                            if(exito){
                                                printf("\nResultado de la consulta:\n\n");
                                                printf("Patente: %s\n\n",nuevo.patente);
                                                printf("Marca y modelo: %s\n\n",nuevo.marcamod);
                                                printf("A%co de fabricacion: %d\n\n",164,nuevo.anio);
                                                printf("Nombre del due%co: %s\n\n",164,nuevo.nom);
                                                printf("Telefono: %s\n\n",nuevo.tel);
                                                printf("Servicio efectuado: %s\n\n",nuevo.serv);
                                                printf("Importe: %.2f\n\n",nuevo.importe);
                                                printf("Fecha: %s\n\n",nuevo.fecha);
                                            }else
                                                printf("No fue posible consultar por el vehiculo.\n");
                                        }
                                        fflush(stdin);
                                        system("pause");
                                        limpiar();
                                break;
                                case 5: if(cantlvo==0){
                                            printf("Lista vacia. Ingrese vehiculos.\n");
                                            system("pause");
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
                                            Alta2(nuevo,&exito,&costo);
                                            if(exito)
                                                printf("\nVehiculo ingresado.\n");
                                            else
                                                printf("El vehiculo ya se encuentra en la lista.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 2: if(cantlsd==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a eliminar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Baja2(pCE,nuevo,&exito,opctipo,&costo);
                                            if(exito==1)
                                                printf("Vehiculo eliminado.\n");
                                            else{
                                                if(exito==2)
                                                    printf("Elimincacion del vehiculo cancelada.\n");
                                                else
                                                    printf("No fue posible eliminar el vehiculo.\n");
                                            }
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 3: if(cantlsd==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar por servicio.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar2(pCE,&nuevo,&exito,&costo);
                                            if(exito){
                                                if(strlen(nuevo.serv)==0)
                                                    printf("NO se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                                else
                                                    printf("SI se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                            }else
                                                printf("No fue posible consultar por el vehiculo.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 4: if(cantlsd==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar.\n");
                                            scanf("%7[^\n]",pCE);
                                            Evocar2(pCE,&nuevo,&exito,&costo);
                                            if(exito){
                                                printf("\nResultado de la consulta:\n\n");
                                                printf("Patente: %s\n\n",nuevo.patente);
                                                printf("Marca y modelo: %s\n\n",nuevo.marcamod);
                                                printf("A%co de fabricacion: %d\n\n",164,nuevo.anio);
                                                printf("Nombre del due%co: %s\n\n",164,nuevo.nom);
                                                printf("Telefono: %s\n\n",nuevo.tel);
                                                printf("Servicio efectuado: %s\n\n",nuevo.serv);
                                                printf("Importe: %.2f\n\n",nuevo.importe);
                                                printf("Fecha: %s\n\n",nuevo.fecha);
                                            }else
                                                printf("No fue posible consultar ese vehiculo.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 5: if(cantlsd==0){
                                            printf("Lista vacia. Ingrese vehiculos.\n");
                                            system("pause");
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
                                            Alta(nuevo,&exito,&costo);
                                            if(exito)
                                            printf("\nVehiculo ingresado.\n");
                                        else
                                            printf("El vehiculo ya se encuentra en la lista.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 2:if(cantlso==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a eliminar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Baja(pCE,nuevo,&exito,opctipo,&costo);
                                            if(exito==1)
                                                printf("Vehiculo eliminado.\n");
                                            else{
                                                if(exito==2)
                                                    printf("Elimincacion del vehiculo cancelada.\n");
                                                else
                                                    printf("No fue posible eliminar el vehiculo.\n");
                                            }
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 3:if(cantlso==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar por servicio.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar(pCE,&nuevo,&exito,&costo);
                                            if(exito){
                                                if(strlen(nuevo.serv)==0)
                                                    printf("NO se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                                else
                                                    printf("SI se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                            }else
                                                printf("No fue posible consultar por el vehiculo.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 4:if(cantlso==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar(pCE,&nuevo,&exito,&costo);
                                            if(exito){
                                                printf("\nResultado de la consulta:\n\n");
                                                printf("Patente: %s\n\n",nuevo.patente);
                                                printf("Marca y modelo: %s\n\n",nuevo.marcamod);
                                                printf("A%co de fabricacion: %d\n\n",164,nuevo.anio);
                                                printf("Nombre del due%co: %s\n\n",164,nuevo.nom);
                                                printf("Telefono: %s\n\n",nuevo.tel);
                                                printf("Servicio efectuado: %s\n\n",nuevo.serv);
                                                printf("Importe: %.2f\n\n",nuevo.importe);
                                                printf("Fecha: %s\n\n",nuevo.fecha);
                                            }else
                                                printf("No fue posible consultar ese vehiculo.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 5: if(cantlso==0){
                                            printf("Lista vacia. Ingrese vehiculos.\n");
                                            system("pause");
                                        }else
                                            MostrarLSO(l);
                                        limpiar();
                                break;
                                case 6: printf("Saliendo de la estructura...\n");
                                        system("pause");
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
                                            Alta3(nuevo,&exito,&costo);
                                            if(exito)
                                            printf("\nVehiculo ingresado.\n");
                                        else
                                            printf("El vehiculo ya se encuentra en la lista.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 2:if(cantlsobb==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a eliminar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Baja3(pCE,nuevo,&exito,opctipo,&costo);
                                            if(exito==1)
                                                printf("Vehiculo eliminado.\n");
                                            else{
                                                if(exito==2)
                                                    printf("Elimincacion del vehiculo cancelada.\n");
                                                else
                                                    printf("No fue posible eliminar el vehiculo.\n");
                                            }
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 3:if(cantlsobb==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar por servicio.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar3(pCE,&nuevo,&exito,&costo);
                                            if(exito){
                                                if(strlen(nuevo.serv)==0)
                                                    printf("NO se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                                else
                                                    printf("SI se le ha realizado servicio mecanico al vehiculo con patente %s.\n",pCE);
                                            }else
                                                printf("No fue posible consultar por el vehiculo.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 4:if(cantlsobb==0)
                                            printf("Lista vacia.\n");
                                        else{
                                            printf("Ingrese patente del vehiculo a consultar.\n");
                                            fflush(stdin);
                                            scanf("%7[^\n]",pCE);
                                            Evocar3(pCE,&nuevo,&exito,&costo);
                                            if(exito){
                                                printf("\nResultado de la consulta:\n\n");
                                                printf("Patente: %s\n\n",nuevo.patente);
                                                printf("Marca y modelo: %s\n\n",nuevo.marcamod);
                                                printf("A%co de fabricacion: %d\n\n",164,nuevo.anio);
                                                printf("Nombre del due%co: %s\n\n",164,nuevo.nom);
                                                printf("Telefono: %s\n\n",nuevo.tel);
                                                printf("Servicio efectuado: %s\n\n",nuevo.serv);
                                                printf("Importe: %.2f\n\n",nuevo.importe);
                                                printf("Fecha: %s\n\n",nuevo.fecha);
                                            }else
                                                printf("No fue posible consultar ese vehiculo.\n");
                                        }
                                        system("pause");
                                        limpiar();
                                break;
                                case 5: if(cantlsobb==0){
                                            printf("Lista vacia. Ingrese vehiculos.\n");
                                            system("pause");
                                        }else
                                            MostrarLSOBB(lsobb);
                                        limpiar();
                                break;
                                case 6: printf("Saliendo de la estructura...\n");
                                        system("pause");
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
                Comparacion();
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
        printf("Patente: %s\n\n",aux.patente);
        printf("Marca y modelo: %s\n\n",aux.marcamod);
        printf("A%co de fabricacion: %d\n\n",165,aux.anio);
        printf("Nombre del due%co: %s\n\n",165,aux.nom);
        printf("Telefono: %s\n\n",aux.tel);
        printf("Servicio efectuado: %s\n\n",aux.serv);
        printf("Importe: %.2f\n\n",aux.importe);
        printf("Fecha: %s\n\n",aux.fecha);
        i++;
    }
    system("pause");
}
void MostrarLSO (){
    int i;
    vhlo aux;
    printf("Mostrando\n");
    for(i=0;i<cantlso;i++){
        aux=l[i];
        printf("\n----------[%d]----------\n",i+1);
        printf("Patente: %s\n\n",aux.patente);
        printf("Marca y modelo: %s\n\n",aux.marcamod);
        printf("A%co de fabricacion: %d\n\n",165,aux.anio);
        printf("Nombre del due%co: %s\n\n",165,aux.nom);
        printf("Telefono: %s\n\n",aux.tel);
        printf("Servicio efectuado: %s\n\n",aux.serv);
        printf("Importe: %.2f\n\n",aux.importe);
        printf("Fecha: %s\n\n",aux.fecha);
    }
    system("pause");
}

void MostrarLSD (){
    int i;
    vhlo aux;
    printf("Mostrando\n");
    for(i=0;i<cantlsd;i++){
        aux=lsd[i];
        printf("\n----------[%d]----------\n",i+1);
        printf("Patente: %s\n\n",aux.patente);
        printf("Marca y modelo: %s\n\n",aux.marcamod);
        printf("A%co de fabricacion: %d\n\n",165,aux.anio);
        printf("Nombre del due%co: %s\n\n",165,aux.nom);
        printf("Telefono: %s\n\n",aux.tel);
        printf("Servicio efectuado: %s\n\n",aux.serv);
        printf("Importe: %.2f\n\n",aux.importe);
        printf("Fecha: %s\n\n",aux.fecha);
    }
    system("pause");
}

void MostrarLSOBB(){
    int i;
    vhlo aux;
    printf("Mostrando...\n");
    for(i=0;i<cantlsobb;i++){
        aux = lsobb[i];
        printf("\n----------[%d]----------\n",i+1);
        printf("Patente: %s\n\n",aux.patente);
        printf("Marca y modelo: %s\n\n",aux.marcamod);
        printf("A%co de fabricacion: %d\n\n",165,aux.anio);
        printf("Nombre del due%co: %s\n\n",165,aux.nom);
        printf("Telefono: %s\n\n",aux.tel);
        printf("Servicio efectuado: %s\n\n",aux.serv);
        printf("Importe: %.2f\n\n",aux.importe);
        printf("Fecha: %s\n\n",aux.fecha);
    }
    system("pause");
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
    printf("\nA%co de fabricacion: ",164);
    fflush(stdin);
    scanf("%d",&nanio);
    printf("\nNombre del due%co: ",164);
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

