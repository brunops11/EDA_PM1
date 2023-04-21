#ifndef CONTROLEST_H_INCLUDED
#define CONTROLEST_H_INCLUDED
#include "lso.h"
#include "lsd.h"
#include "lsobbb.h"
#include "lvo.h"
#include "vehiculo.h"

typedef struct{
    float costoAcumulado;
    float costoMax;
    int cant;
}bloque;

bloque costoLVO[4];
bloque costoLSD[4];
bloque costoLSO[4];
bloque costoLSOBB[4];

void initC(bloque *);
void initM(float *);

vhlo dat;
vhlo exitoE;
vhlo exitoEv;
int exito = 0,opc = 0;
char patAux[8];
float mLVO[4],mLSD[4],mLSO[4],mLSOBB[4],costo;

int Lectura_operaciones(){
    FILE *fp;
    int codOp,exitoL;
    if((fp=fopen("Operaciones.txt","r"))==NULL)
        return 0;
    else{
        nodoV *aux = lvo.ac;
        while(lvo.ac!=NULL){
            free(aux);
            aux = lvo.ac;
        }
        cantlvo = 0;
        cantlso = 0;
        cantlsd = 0;
        cantlsobb = 0;
        /*cclvo = 0;
        cclso = 0;
        cclsd = 0;
        cclsobb = 0;
        dlsoA = 0;
        dlsoB = 0;
        dlsdA = 0;
        dlsdB = 0;
        dlsobbA = 0;
        dlsobbB = 0;
        mplvoA = 0;
        mplvoB = 0;*/
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
                    if(cantlso<250){
                        costo = 0;
                        Alta(aux,&exitoL,&costo);
                        if(exitoL){
                            costoLSO[0].costoAcumulado = costoLSO[0].costoAcumulado + costo;
                            costoLSO[0].cant++;
                            if(costo>costoLSO[0].costoMax)
                                costoLSO[0].costoMax = costo;
                        }
                    }
                    if(cantlvo<250){
                    costo = 0;
                    Alta1(aux,&exitoL,&costo);
                        if(exitoL){
                            costoLVO[0].costoAcumulado = costoLVO[0].costoAcumulado + costo;
                            costoLVO[0].cant++;
                            if(costo>costoLVO[0].costoMax)
                                costoLVO[0].costoMax = costo;
                        }
                    }
                    if(cantlsd<250){
                        costo = 0;
                        Alta2(aux,&exitoL,&costo);
                        if(exitoL){
                            costoLSD[0].costoAcumulado = costoLSD[0].costoAcumulado + costo;
                            costoLSD[0].cant++;
                            if(costo>costoLSD[0].costoMax)
                                costoLSD[0].costoMax = costo;
                        }
                    }
                    if(cantlsobb<250){
                        costo = 0;
                        Alta3(aux,&exitoL,&costo);
                        if(exitoL){
                            costoLSOBB[0].costoAcumulado = costoLSOBB[0].costoAcumulado + costo;
                            costoLSOBB[0].cant++;
                            if(costo>costoLSOBB[0].costoMax)
                                costoLSOBB[0].costoMax = costo;
                        }
                    }
                }else{
                    if(cantlso>0){
                        costo = 0;
                        Baja(aux.patente,aux,&exitoL,2,&costo);
                        if(exitoL){
                        costoLSO[1].costoAcumulado = costoLSO[1].costoAcumulado + costo;
                        costoLSO[1].cant++;
                        if(costo > costoLSO[1].costoMax)
                            costoLSO[1].costoMax = costo;
                        }
                    }
                    if(cantlvo>0){
                        costo = 0;
                        Baja1(aux.patente,aux,&exitoL,2,&costo);
                        if(exitoL){
                        costoLVO[1].costoAcumulado = costoLVO[1].costoAcumulado + costo;
                        costoLVO[1].cant++;
                        if(costo > costoLVO[1].costoMax)
                            costoLVO[1].costoMax = costo;
                        }
                    }
                    if(cantlsd>0){
                        costo = 0;
                        Baja2(aux.patente,aux,&exitoL,2,&costo);
                        if(exitoL){
                        costoLSD[1].costoAcumulado = costoLSD[1].costoAcumulado + costo;
                        costoLSD[1].cant++;
                        if(costo > costoLSD[1].costoMax)
                            costoLSD[1].costoMax = costo;
                        }
                    }
                    if(cantlsobb>0){
                        costo = 0;
                        Baja3(aux.patente,aux,&exitoL,2,&costo);
                        if(exitoL){
                        costoLSOBB[1].costoAcumulado = costoLSOBB[1].costoAcumulado + costo;
                        costoLSOBB[1].cant++;
                        if(costo > costoLSOBB[1].costoMax)
                            costoLSOBB[1].costoMax = costo;
                        }
                    }
                }
            }else{
                if(codOp==3){
                    fgets(aux.patente,8,fp);
                    fgetc(fp);
                    vhlo aux1;
                    costo = 0;
                    Evocar(aux.patente,&aux1,&exitoL,&costo);
                    if(exitoL){
                        costoLSO[2].costoAcumulado = costoLSO[2].costoAcumulado + costo;
                        costoLSO[2].cant++;
                        if(costo > costoLSO[2].costoMax)
                            costoLSO[2].costoMax = costo;
                    }
                    costo = 0;
                    Evocar1(aux.patente,&aux1,&exitoL,&costo);
                    if(exitoL){
                        costoLVO[2].costoAcumulado = costoLVO[2].costoAcumulado + costo;
                        costoLVO[2].cant++;
                        if(costo > costoLVO[2].costoMax)
                            costoLVO[2].costoMax = costo;
                    }
                    costo = 0;
                    Evocar2(aux.patente,&aux1,&exitoL,&costo);
                    if(exitoL){
                        costoLSD[2].costoAcumulado = costoLSD[2].costoAcumulado + costo;
                        costoLSD[2].cant++;
                        if(costo > costoLSD[2].costoMax)
                            costoLSD[2].costoMax = costo;
                    }
                    costo = 0;
                    Evocar3(aux.patente,&aux1,&exitoL,&costo);
                    if(exitoL){
                        costoLSOBB[2].costoAcumulado = costoLSOBB[2].costoAcumulado + costo;
                        costoLSOBB[2].cant++;
                        if(costo > costoLSOBB[2].costoMax)
                            costoLSOBB[2].costoMax = costo;
                    }
                }else
                    printf("Error: Codigo de operador desconocido.\n");
            }
        }
        fclose(fp);
        if(costoLVO[0].cant != 0)
            mLVO[0] = costoLVO[0].costoAcumulado * (1.0/costoLVO[0].cant);
        if(costoLVO[1].cant != 0)
            mLVO[1] = costoLVO[1].costoAcumulado * (1.0/costoLVO[1].cant);
        if(costoLVO[2].cant != 0)
            mLVO[2] = costoLVO[2].costoAcumulado * (1.0/costoLVO[2].cant);
        if(costoLVO[3].cant != 0)
            mLVO[3] = costoLVO[3].costoAcumulado * (1.0/costoLVO[3].cant);

        if(costoLSD[0].cant != 0)
            mLSD[0] = costoLSD[0].costoAcumulado * (1.0/costoLSD[0].cant);
        if(costoLSD[1].cant != 0)
            mLSD[1] = costoLSD[1].costoAcumulado * (1.0/costoLSD[1].cant);
        if(costoLSD[2].cant != 0)
            mLSD[2] = costoLSD[2].costoAcumulado * (1.0/costoLSD[2].cant);
        if(costoLSD[3].cant != 0)
            mLSD[3] = costoLSD[3].costoAcumulado * (1.0/costoLSD[3].cant);
        //LSO
        if(costoLSO[0].cant != 0)
            mLSO[0] = costoLSO[0].costoAcumulado * (1.0/costoLSO[0].cant);
        if(costoLSO[1].cant != 0)
            mLSO[1] = costoLSO[1].costoAcumulado * (1.0/costoLSO[1].cant);
        if(costoLSO[2].cant != 0)
            mLSO[2] = costoLSO[2].costoAcumulado * (1.0/costoLSO[2].cant);
        if(costoLSO[3].cant != 0)
            mLSO[3] = costoLSO[3].costoAcumulado * (1.0/costoLSO[3].cant);
        //LSOBB
        if(costoLSOBB[0].cant != 0)
            mLSOBB[0] = costoLSOBB[0].costoAcumulado * (1.0/costoLSOBB[0].cant);
        if(costoLSOBB[1].cant != 0)
            mLSOBB[1] = costoLSOBB[1].costoAcumulado * (1.0/costoLSOBB[1].cant);
        if(costoLSOBB[2].cant != 0)
            mLSOBB[2] = costoLSOBB[2].costoAcumulado * (1.0/costoLSOBB[2].cant);
        if(costoLSOBB[3].cant != 0)
            mLSOBB[3] = costoLSOBB[3].costoAcumulado * (1.0/costoLSOBB[3].cant);

        return 1;
    }

}

void Comparacion(){
    printf("\t COMPARACION DE ESTRUCTURAS\n\n");
    printf("CANTIDAD\tLVO\tLSD\tLSO\tLSOBB\n");
    printf("\t\t%d\t%d\t%d\t%d\t\n\n",cantlvo,cantlsd,cantlso,cantlsobb);
    printf("COSTOS\t\tLVO\t\tLSD\t\tLSO\t\tLSOBB\n");
    printf("____________________________________________________________________\n");
    printf("MAX.ALTA\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n", costoLVO[0].costoMax, costoLSD[0].costoMax, costoLSO[0].costoMax, costoLSOBB[0].costoMax);
    printf("MED.ALTA\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n", mLVO[0], mLSD[0], mLSO[0], mLSOBB[0]);
    printf("____________________________________________________________________\n");
    printf("MAX.BAJA\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n", costoLVO[1].costoMax, costoLSD[1].costoMax, costoLSO[1].costoMax, costoLSOBB[1].costoMax);
    printf("MED.BAJA\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n", mLVO[1], mLSD[1], mLSO[1], mLSOBB[1]);
    printf("____________________________________________________________________\n");
    printf("MAX.EVOEX\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n", costoLVO[2].costoMax, costoLSD[2].costoMax, costoLSO[2].costoMax, costoLSOBB[2].costoMax);
    printf("MED.EVOEX\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n", mLVO[2], mLSD[2], mLSO[2], mLSOBB[2]);
    printf("____________________________________________________________________\n");
    printf("MAX.EVONOEX\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n", costoLVO[3].costoMax, costoLSD[3].costoMax, costoLSO[3].costoMax, costoLSOBB[3].costoMax);
    printf("MED.EVONOEX\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t\n\n", mLVO[3], mLSD[3], mLSO[3], mLSOBB[3]);
    system("PAUSE");
    system("cls");
}



#endif // CONTROLEST_H_INCLUDED
