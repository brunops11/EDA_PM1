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
int cantlvo = 0,cclvo=0,mplvoA=0,mplvoB=0;

void Localizar1(char p[],int *exito,nodoV **pos){
    *pos = NULL;
    if(lvo.ac==NULL){
        cclvo++;
        *exito = 0;
    }
    lvo.ap = lvo.ac;
    antLVO = lvo.ac;
    while((lvo.ap!=NULL) && (strcmpi((*lvo.ap).dato.patente,p) > 0)){
        antLVO = lvo.ap;
        lvo.ap = (*lvo.ap).sig;
        *pos = lvo.ap;
        cclvo++;
    }
    if(lvo.ap==NULL){
        cclvo++;
        *exito = 0;
    }
    if(strcmpi((*lvo.ap).dato.patente,p)==0){
        cclvo++;
        *pos = lvo.ap;
        *exito = 1;
    }
}

int Pertenece1(char p[]){
    int exitoL;
    nodoV *pos=NULL;
    Localizar1(p,&exitoL,&pos);
    return exitoL;
}

void Alta1(vhlo v,int *exito){
    int exitoL;
    nodoV *pos = NULL;
    Localizar1(v.patente,&exitoL,&pos);
    if(!exitoL){
        nodoV *n=(nodoV*)malloc(sizeof(nodoV));
        if(n == NULL)
            *exito = -1;
        (*n).dato = v;
        if(pos==NULL){
            (*n).sig = lvo.ac;
            lvo.ac = n;
        }else{
            (*n).sig = (*pos).sig;
            (*pos).sig = n;
        }
        *exito = 1;
        cantlvo++;
    }else
        *exito = 0;
}

void Baja1(char *p,vhlo v,int *exito,int cod){
    int exitoL;
    nodoV *pos=NULL;
    char vrf;
    vhlo vL;
    Localizar1(p,&exitoL,&pos);
    if(exitoL){
        lvo.ap = pos;
        vL=(*lvo.ap).dato;
        if(cod==1){
            MostrarVhlo(vL);
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
                    mplvoB = mplvoB + 2;
                }else{
                      (*antLVO).sig = lvo.ap;
                      mplvoB = mplvoB + 2;
                }
                cantlvo--;
                *exito = 1;
            }else
                *exito = 2;
    }else
        *exito = 0;
}

void Evocar1(char p[],vhlo *aux,int *exito){
    int exitoL;
    nodoV *pos=NULL;
    Localizar1(p,&exitoL,&pos);
    if(exitoL){
        *aux= (*lvo.ap).dato;
        *exito = 1;
    }else
        *exito=0;
}

#endif // LVO_H_INCLUDED
