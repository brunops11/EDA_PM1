#ifndef LVO_H_INCLUDED
#define LVO_H_INCLUDED

typedef struct Nodo{
    vhlo dato;
    struct Nodo *sig;
}nodoV;

typedef struct{
    nodoV *ac;
    nodoV *ap;
}listaVO;

listaVO lvo;
nodoV *antLVO;
int cantlvo = 0;

void Localizar1(char p[],int *exito,nodoV **pos,float *cclvo){
    *pos = lvo.ac;
    if(lvo.ac==NULL){
        *cclvo = *cclvo + 1;
        *exito = 0;
    }
    lvo.ap = lvo.ac;
    antLVO = lvo.ac;
    while((lvo.ap!=NULL) && (strcmpi((*lvo.ap).dato.patente,p) < 0)){
        antLVO = lvo.ap;
        lvo.ap = (*lvo.ap).sig;
        *pos = lvo.ap;
        *cclvo = *cclvo + 1;
    }
    if(lvo.ap==NULL && lvo.ac!=NULL){
        *cclvo = *cclvo + 1;
        *exito = 0;
    }
    if(strcmpi((*lvo.ap).dato.patente,p)==0){
        *cclvo = *cclvo + 1;
        *pos = lvo.ap;
        *exito = 1;
    }
}

int Pertenece1(char p[]){
    int exitoL;
    float c=0;
    nodoV *pos=NULL;
    Localizar1(p,&exitoL,&pos,&c);
    return exitoL;
}

void Alta1(vhlo v,int *exito,float *mplvoA){
    int exitoL;
    float c;
    nodoV *pos = NULL;
    Localizar1(v.patente,&exitoL,&pos,&c);
    if(!exitoL){
        nodoV *n = (nodoV*)malloc(sizeof(nodoV));
        if(n==NULL)
            *exito = -1;
        (*n).dato = v;
        (*n).sig = NULL;
        if(lvo.ac==NULL){
            lvo.ac = n;
            lvo.ap = n;
            *mplvoA = *mplvoA + 2;
        }else if(pos==lvo.ac){
            (*n).sig = lvo.ac;
            lvo.ac = n;
            lvo.ap = n;
            *mplvoA = *mplvoA + 3;
        }else if(antLVO!=NULL && pos!=NULL){
            (*n).sig = lvo.ap;
            (*antLVO).sig = n;
            *mplvoA = *mplvoA + 2;
        }else{
            (*antLVO).sig = n;
            *mplvoA = *mplvoA + 1;
        }
        *exito = 1;
        cantlvo++;
    }else
        *exito = 0;
}

void Baja1(char *p,vhlo v,int *exito,int cod,float *mplvoB){
    int exitoL;
    nodoV *pos=NULL;
    char vrf;
    float c;
    vhlo vL;
    Localizar1(p,&exitoL,&pos,&c);
    if(exitoL){
        lvo.ap = pos;
        vL=(*lvo.ap).dato;
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
                vrf = 'S';
            else
                vrf = 'N';
        }
        if(vrf=='S'||vrf=='s'){
                if(lvo.ap == lvo.ac){
                    lvo.ac = (*lvo.ap).sig;
                    *mplvoB = *mplvoB + 2;
                }else{
                      (*antLVO).sig = lvo.ap;
                      *mplvoB = *mplvoB + 2;
                }
                cantlvo--;
                *exito = 1;
            }else
                *exito = 2;
    }else
        *exito = 0;
}

void Evocar1(char p[],vhlo *aux,int *exito,float *cclvo){
    int exitoL;
    nodoV *pos=NULL;
    Localizar1(p,&exitoL,&pos,cclvo);
    if(exitoL){
        *aux= (*lvo.ap).dato;
        *exito = 1;
    }else
        *exito=0;
}

#endif // LVO_H_INCLUDED
