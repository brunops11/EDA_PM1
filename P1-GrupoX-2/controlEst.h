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
float mLVO[4],mLSD[4],mLSO[4],mLSOBB[4];

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
        cclvo = 0;
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
        mplvoB = 0;
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
                    if(exitoL){
                        costoLSO[0].costoAcumulado = costoLSO[0].costoAcumulado + dlsoA;
                        costoLSO[0].cant++;
                        if(dlsoA>costoLSO[0].costoMax)
                            costoLSO[0].costoMax = dlsoA;
                    }
                    Alta1(aux,&exitoL);
                    if(exitoL){
                        costoLVO[0].costoAcumulado = costoLVO[0].costoAcumulado + mplvoA;
                        costoLVO[0].cant++;
                        if(mplvoA>costoLVO[0].costoMax)
                            costoLVO[0].costoMax = mplvoA;
                    }
                    Alta2(aux,&exitoL);
                    if(exitoL){
                        costoLSD[0].costoAcumulado = costoLSD[0].costoAcumulado + dlsdA;
                        costoLSD[0].cant++;
                        if(dlsdA>costoLSD[0].costoMax)
                            costoLSD[0].costoMax = dlsdA;
                    }
                    Alta3(aux,&exitoL);
                    if(exitoL){
                        costoLSOBB[0].costoAcumulado = costoLSOBB[0].costoAcumulado + dlsobbA;
                        costoLSOBB[0].cant++;
                        if(dlsobbA>costoLSOBB[0].costoMax)
                            costoLSOBB[0].costoMax = dlsobbA;
                    }
                }else{
                    Baja(aux.patente,aux,&exitoL,2);
                    if(exitoL){
                    costoLSO[1].costoAcumulado = costoLSO[1].costoAcumulado + dlsoB;
                    costoLSO[1].cant++;
                    if(dlsoB > costoLSO[1].costoMax)
                        costoLSO[1].costoMax = dlsoB;
                }
                    Baja1(aux.patente,aux,&exitoL,2);
                    if(exitoL){
                    costoLVO[1].costoAcumulado = costoLVO[1].costoAcumulado + mplvoB;
                    costoLVO[1].cant++;
                    if(mplvoB > costoLVO[1].costoMax)
                        costoLVO[1].costoMax = mplvoB;
                }
                    Baja2(aux.patente,aux,&exitoL,2);
                    if(exitoL){
                    costoLSD[1].costoAcumulado = costoLSD[1].costoAcumulado + dlsdB;
                    costoLSD[1].cant++;
                    if(dlsdB > costoLSD[1].costoMax)
                        costoLSD[1].costoMax = dlsdB;
                }
                    Baja3(aux.patente,aux,&exitoL,2);
                    if(exitoL){
                    costoLSOBB[1].costoAcumulado = costoLSOBB[1].costoAcumulado + dlsobbB;
                    costoLSOBB[1].cant++;
                    if(dlsobbB > costoLSOBB[1].costoMax)
                        costoLSOBB[1].costoMax = dlsobbB;
                }
                }
            }else{
                if(codOp==3){
                    fgets(aux.patente,8,fp);
                    fgetc(fp);
                    vhlo aux1;
                    Evocar(aux.patente,&aux1,&exitoL);
                    if(exitoL){
                        costoLSO[2].costoAcumulado = costoLSO[2].costoAcumulado + cclso;
                        costoLSO[2].cant++;
                        if(cclso > costoLSO[2].costoMax)
                            costoLSO[2].costoMax = cclso;
                    }
                    Evocar1(aux.patente,&aux1,&exitoL);
                    if(exitoL){
                        costoLVO[2].costoAcumulado = costoLVO[2].costoAcumulado + cclvo;
                        costoLVO[2].cant++;
                        if(cclvo > costoLVO[2].costoMax)
                            costoLVO[2].costoMax = cclvo;
                    }
                    Evocar2(aux.patente,&aux1,&exitoL);
                    if(exitoL){
                        costoLSD[2].costoAcumulado = costoLSD[2].costoAcumulado + cclsd;
                        costoLSD[2].cant++;
                        if(cclsd > costoLSD[2].costoMax)
                            costoLSD[2].costoMax = cclsd;
                    }
                    Evocar3(aux.patente,&aux1,&exitoL);
                    if(exitoL){
                        costoLSOBB[2].costoAcumulado = costoLSOBB[2].costoAcumulado + cclsobb;
                        costoLSOBB[2].cant++;
                        if(cclsobb > costoLSOBB[2].costoMax)
                            costoLSOBB[2].costoMax = cclsobb;
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
    printf("COSTOS\t\tLVO\tLSD\tLSO\tLSOBB\n");
    printf("_____________________________________________________\n");
    printf("MAX.ALTA\t%.2f\t%.2f\t%.2f\t%.2f\t\n", costoLVO[0].costoMax, costoLSD[0].costoMax, costoLSO[0].costoMax, costoLSOBB[0].costoMax);
    printf("MED.ALTA\t%.2f\t%.2f\t%.2f\t%.2f\t\n", mLVO[0], mLSD[0], mLSO[0], mLSOBB[0]);
    printf("_____________________________________________________\n");
    printf("MAX.BAJA\t%.2f\t%.2f\t%.2f\t%.2f\t\n", costoLVO[1].costoMax, costoLSD[1].costoMax, costoLSO[1].costoMax, costoLSOBB[1].costoMax);
    printf("MED.BAJA\t%.2f\t%.2f\t%.2f\t%.2f\t\n", mLVO[1], mLSD[1], mLSO[1], mLSOBB[1]);
    printf("_____________________________________________________\n");
    printf("MAX.EVOEX\t%.2f\t%.2f\t%.2f\t%.2f\t\n", costoLVO[2].costoMax, costoLSD[2].costoMax, costoLSO[2].costoMax, costoLSOBB[2].costoMax);
    printf("MED.EVOEX\t%.2f\t%.2f\t%.2f\t%.2f\t\n", mLVO[2], mLSD[2], mLSO[2], mLSOBB[2]);
    printf("_____________________________________________________\n");
    printf("MAX.EVONOEX\t%.2f\t%.2f\t%.2f\t%.2f\t\n", costoLVO[3].costoMax, costoLSD[3].costoMax, costoLSO[3].costoMax, costoLSOBB[3].costoMax);
    printf("MED.EVONOEX\t%.2f\t%.2f\t%.2f\t%.2f\t\n\n", mLVO[3], mLSD[3], mLSO[3], mLSOBB[3]);
    system("PAUSE");
    system("cls");
}



#endif // CONTROLEST_H_INCLUDED
