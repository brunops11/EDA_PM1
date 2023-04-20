#ifndef LSD_H_INCLUDED
#define LSD_H_INCLUDED
#include <string.h>

vhlo lsd[m];
int cantlsd = 0,cclsd=0,dlsdB=0;

void Localizar2(char *p,int *exito,int *pos){
    int i=0;
    while(strcmpi(lsd[i].patente,p)!=0 && i<cantlsd){
            i++;
            cclsd++;
    }
    *pos = i;
    *exito = i<cantlsd;
}

int Pertenece2(char *p){
    int exitoL,pos;
    Localizar2(p,&exitoL,&pos);
    return exitoL;
}

void Alta2(vhlo v,int *exito){
    int exitoL,pos;
    Localizar2(v.patente,&exitoL,&pos);
    if(!exitoL){
        lsd[pos] = v;
        cantlsd++;
        *exito = 1;
    }else
        *exito = 0;
}

void Baja2(char *p,vhlo v,int *exito,int cod){
    int exitoL = 0,pos = 0,i;
    char vrf;
    vhlo vL;
    Localizar2(p,&exitoL,&pos);
    if(exitoL){
        vL=lsd[pos];
        if(cod==1){
            printf("Patente: %s\n\n",vL.patente);
            printf("Marca y modelo: %s\n\n",vL.marcamod);
            printf("A%co de fabricacion: %d\n\n",164,vL.anio);
            printf("Nombre: %s\n\n",vL.nom);
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
                vrf='S';
            else
                vrf='N';
        }
        if(vrf=='S'||vrf=='s'){
            if(pos!=cantlsd-1){
                for(i=pos;i<cantlsd-1;i++){
                    lsd[i]=lsd[i+1];
                    dlsdB=dlsdB+1.5;
                }
            }
                cantlsd--;
                *exito = 1;
            }else
                *exito = 2;
    }else
        *exito = 0;
}

void Evocar2(char *p,vhlo *aux,int *exito){
    int exitoL,pos;
    Localizar2(p,&exitoL,&pos);
    if(exitoL){
        *aux = lsd[pos];
        *exito =1;
    }else
        *exito = 0;
}


#endif // LSD_H_INCLUDED
