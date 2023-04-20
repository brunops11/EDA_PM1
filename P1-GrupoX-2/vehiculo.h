#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#include <string.h>

typedef struct {
    char patente[8];
    char marcamod[60];
    int anio;
    char nom[50];
    char tel[15];
    char serv[70];
    float importe;
    char fecha[11];
}vhlo;

void estvhlo(char *p,char *mm,int a,char *n,char *t,char *s,float i,char *f,vhlo *v){
    strcpy((*v).patente,p);
    (*v).anio = a;
    strcpy((*v).marcamod,mm);
    strcpy((*v).nom,n);
    strcpy((*v).tel,t);
    strcpy((*v).serv,s);
    (*v).importe = i;
    strcpy((*v).fecha,f);
}

void MostrarVhlo(vhlo v){
    printf("Patente: %s\n\n",v.patente);
    printf("Marca y modelo: %s\n\n",v.marcamod);
    printf("A%co de fabricacion: %d\n\n",165,v.anio);
    printf("Nombre del due%co: %s\n\n",165,v.nom);
    printf("Telefono: %s\n\n",v.tel);
    printf("Servicio efectuado: %s\n\n",v.serv);
    printf("Importe: %.2f\n\n",v.importe);
    printf("Fecha: %s\n\n",v.fecha);
    fflush(stdin);
}
#endif // VEHICULO_H_INCLUDED
