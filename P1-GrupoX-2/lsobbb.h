#ifndef LSOBBB_H_INCLUDED
#define LSOBBB_H_INCLUDED

vhlo lsobb[m];
int cantlsobb = 0;

void Localizar3(char p[],int *exito,int *pos,float *cclsobb){
    int li=0,ls=cantlsobb,t=0,vm[m];
    while(li<ls && strcmpi(lsobb[t].patente,p)!=0){
        if(li==ls-1){
            t=li;
        }else
            t=((li+ls)/2)-1;
        if(strcmpi(lsobb[t].patente,p)!=0){
            if(strcmpi(lsobb[t].patente,p)<0)
                li=t+1;
            else
                ls=t;
            *cclsobb = *cclsobb + 1;
            vm[t]=1;
        }
    }
    *pos = t;
    if(vm[li]!=1)
        *cclsobb = *cclsobb + 1;
    *exito = li<ls;
}

int Pertenece3(char p[]){
    int exitoL,pos;
    float c=0;
    Localizar3(p,&exitoL,&pos,&c);
    return exitoL;
}

void Alta3(vhlo v,int *exito,float *dlsobbA){
    int exitoL,pos,i;
    float c;
    Localizar3(v.patente,&exitoL,&pos,&c);
    if(!exitoL){
        for(i=cantlsobb-1;i>=pos;i--){
            lsobb[i+1] = lsobb[i];
            *dlsobbA = *dlsobbA + 1.5;
        }
        lsobb[pos] = v;
        cantlsobb++;
        *exito=1;
    }else
        *exito = 0;
}

void Baja3(char p[],vhlo v,int *exito,int cod,float *dlsobbB){
    int exitoL,pos,i;
    char vrf;
    float c;
    vhlo vL;
    Localizar3(p,&exitoL,&pos,&c);
    if(exitoL){
        vL=lsobb[pos];
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
                for(i=pos;i<cantlsobb-1;i++){
                    lsobb[i] = lsobb[i+1];
                    *dlsobbB = *dlsobbB+1.5;
                }
                cantlsobb--;
                *exito = 1;
            }else
                *exito = 2;
    }else
        *exito = 0;
    }

void Evocar3(char p[],vhlo *aux,int *exito,float *cclsobb){
    int exitoL,pos;
    Localizar3(p,&exitoL,&pos,cclsobb);
    if(exitoL){
        *aux = lsobb[pos];
        *exito = 1;
    }else
        *exito=0;
}



#endif // LSOBBB_H_INCLUDED
