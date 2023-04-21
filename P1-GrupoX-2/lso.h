#ifndef LSO_H_INCLUDED
#define LSO_H_INCLUDED
#include <string.h>
#define m 250

vhlo l[m];
int cantlso = 0,cclso=0;
float dlsoA=0,dlsoB=0;

void Localizar(char *p, int *exito, int *pos){
    int i = 0;
    while(i<cantlso && strcmpi(l[i].patente,p) < 0){
        i++;
        cclso++;
    }
        *pos = i;
        *exito = strcmpi(l[i].patente,p)==0;
}

int Pertenece(char *p){
    int exito=0,pos=-1;
    Localizar(p,&exito,&pos);
    return exito;
}

void Evocar(char *p,vhlo *aux,int *exito){
    int exitoL=0, pos=0;
    Localizar(p,&exitoL,&pos);
    if (exitoL){
        *aux = l[pos];
        *exito = 1;
    }else
        *exito = 0;
}

void Alta(vhlo v,int *exito){
    int exitoL,pos,i;
    Localizar((v).patente,&exitoL,&pos);
    if(exitoL){
        *exito = 0;
    }else{
        for(i=cantlso-1;i>=pos;i--){
            l[i+1]=l[i];
            dlsoA=dlsoA+1.5;
        }
        l[pos]=v;
        *exito=1;
        cantlso++;
    }
}

/*void Baja(char *p,int *exito,int cod){
    int exitoL = 0,pos = 0,i;
    char vrf;
    vhlo v;
    Localizar(p,&exitoL,&pos);
    if(exitoL){
        if(cod==1){
            v=l[pos];
            MostrarVhlo(v);
            do{
                printf("¿Esta seguro que desea eliminar el vehiculo? S/N\n");
                scanf(" %c",&vrf);
            }while(vrf!='S'||vrf!='s'||vrf!='N'||vrf!='n');
            if(vrf=='S'||vrf=='s'){
                for(i=pos;i<cantlso-1;i++)
                    l[i]=l[i+1];
                cantlso--;
                *exito = 1;
            }else
                *exito = 2;
        }else{
            for(i=pos;i<cantlso-1;i++)
                l[i]=l[i+1];
            cantlso--;
            *exito = 1;
        }
    }else
        *exito = 0;
}*/

void Baja(char *p,vhlo v,int *exito,int cod){
    int exitoL = 0,pos = 0,i;
    char vrf;
    vhlo vL;
    Localizar(p,&exitoL,&pos);
    if(exitoL){
        vL=l[pos];
        if(cod==1){
            printf("Patente: %s\n\n",vL.patente);
            printf("Marca y modelo: %s\n\n",vL.marcamod);
            printf("A%co de fabricacion: %d\n\n",164,vL.anio);
            printf("Nombre del due%co: %s\n\n",164,vL.nom);
            printf("Telefono: %s\n\n",vL.tel);
            printf("Servicio efectuado: %s\n\n",vL.serv);
            printf("Importe: %.2f\n\n",vL.importe);
            printf("Fecha: %s\n\n",vL.fecha);
            do{
                printf("Esta seguro que desea eliminar el vehiculo? S/N\n");
                fflush(stdin);
                scanf(" %c",&vrf);
            }while((vrf!='S'&&vrf!='s')&&(vrf!='N'&&vrf!='n'));
        }else{
            if((strcmpi(v.patente,vL.patente)==0) && (strcmpi(v.marcamod,vL.marcamod)==0) && (v.anio==vL.anio) && (strcmpi(v.nom,vL.nom)==0) && (strcmpi(v.tel,vL.tel)==0) && (strcmpi(v.serv,vL.serv)==0) && (v.importe==vL.importe) && (strcmpi(v.fecha,vL.fecha)==0))
                vrf= 'S';
            else
                vrf = 'N';
        }
        if(vrf=='S'||vrf=='s'){
                for(i=pos;i<cantlso-1;i++){
                    l[i]=l[i+1];
                    dlsoB=dlsoB+1.5;
                }
                cantlso--;
                *exito = 1; //eliminado
            }else
                *exito = 2; //cancelado
    }else
        *exito = 0; //no encontrado
}



#endif // LSO_H_INCLUDED
