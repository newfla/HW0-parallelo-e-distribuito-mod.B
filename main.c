#include <stdio.h>
#include <stdlib.h>
#include <Timer/c_timer.h>
#include <Varie/varie.h>
#include <Mat_Mat/mat_mat.h>
#include <Mat_Vet/mat_vet.h>
#include <memory.h>
#include <math.h>

#define MAXITER 200

int main() {
    char* fileName="../Test.csv",
        *firstLine="Strategy;Dimension;Performance",
        result[50];
    double *A, *B, *C, *x, *y;

    double btime, etime, span;

    //Inizializzazione variabili
    A=(double*)calloc(MAXITER*MAXITER, sizeof(double));
    B=(double*)calloc(MAXITER*MAXITER, sizeof(double));
    C=(double*)calloc(MAXITER*MAXITER, sizeof(double));
    x=(double*)calloc(MAXITER*MAXITER, sizeof(double));
    y=(double*)calloc(MAXITER, sizeof(double));

    fill_vector(A,MAXITER*MAXITER);
    fill_vector(B,MAXITER*MAXITER);
    fill_vector(x,MAXITER);


    //Creazione file .CSV con indicazione righe;
    clean_file(fileName);
    append_to_file(fileName,firstLine);

    //Ciclo su tutte i metodi da testare
    for (int i = 5; i <= MAXITER; i+=5) {

        //Strategia IJK
        btime = get_cur_time(); //inizio blocco da monitorare
        mat_mat_ijk(i,i,i,i,i,i,(double (*)[])A,(double (*)[])B,(double (*)[])C);
        etime = get_cur_time();  //fine blocco da monitorare
        span=etime-btime;
        span=(2*(pow(i,3)))/span;
        span/=pow(10,9);
        if (!isfinite(span))
            span=0.01;
        sprintf(result,"ijk;%d;%.2f",i,span);
        append_to_file(fileName,result);

        memset(C, 0, sizeof(double)*(MAXITER*MAXITER));

        //Strategia JIK
        btime = get_cur_time(); //inizio blocco da monitorare
        mat_mat_jik(i,i,i,i,i,i,(double (*)[])A,(double (*)[])B,(double (*)[])C);
        etime = get_cur_time();  //fine blocco da monitorare
        span=etime-btime;
        span=(2*(pow(i,3)))/span;
        span/=pow(10,9);
        if (!isfinite(span))
            span=0.01;
        sprintf(result,"jik;%d;%.2f",i,span);
        append_to_file(fileName,result);

        memset(C, 0, sizeof(double)*(MAXITER*MAXITER));

        //Strategia IKJ
        btime = get_cur_time(); //inizio blocco da monitorare
        mat_mat_ikj(i,i,i,i,i,i,(double (*)[])A,(double (*)[])B,(double (*)[])C);
        etime = get_cur_time();  //fine blocco da monitorare
        span=etime-btime;
        span=(2*(pow(i,3)))/span;
        span/=pow(10,9);
        if (!isfinite(span))
            span=0.01;
        sprintf(result,"ikj;%d;%.2f",i,span);
        append_to_file(fileName,result);

        memset(C, 0, sizeof(double)*(MAXITER*MAXITER));

        //Strategia JKI
        btime = get_cur_time(); //inizio blocco da monitorare
        mat_mat_jki(i,i,i,i,i,i,(double (*)[])A,(double (*)[])B,(double (*)[])C);
        etime = get_cur_time();  //fine blocco da monitorare
        span=etime-btime;
        span=(2*(pow(i,3)))/span;
        span/=pow(10,9);
        if (!isfinite(span))
            span=0.01;
        sprintf(result,"jki;%d;%.2f",i,span);
        append_to_file(fileName,result);

        memset(C, 0, sizeof(double)*(MAXITER*MAXITER));

        //Strategia KIJ
        btime = get_cur_time(); //inizio blocco da monitorare
        mat_mat_kij(i,i,i,i,i,i,(double (*)[])A,(double (*)[])B,(double (*)[])C);
        etime = get_cur_time();  //fine blocco da monitorare
        span=etime-btime;
        span=(2*(pow(i,3)))/span;
        span/=pow(10,9);
        if (!isfinite(span))
            span=0.01;
        sprintf(result,"kij;%d;%.2f",i,span);
        append_to_file(fileName,result);

        memset(C, 0, sizeof(double)*(MAXITER*MAXITER));

        //Strategia KJI
        btime = get_cur_time(); //inizio blocco da monitorare
        mat_mat_kji(i,i,i,i,i,i,(double (*)[])A,(double (*)[])B,(double (*)[])C);
        etime = get_cur_time();  //fine blocco da monitorare
        span=etime-btime;
        span=(2*(pow(i,3)))/span;
        span/=pow(10,9);
        if (!isfinite(span))
            span=0.01;
        sprintf(result,"kji;%d;%.2f",i,span);
        append_to_file(fileName,result);

        memset(C, 0, sizeof(double)*(MAXITER*MAXITER));

        //Strategia IJ
        btime = get_cur_time(); //inizio blocco da monitorare
        mat_vet_ij(i,i,(double (*)[])A,x,y);
        etime = get_cur_time();  //fine blocco da monitorare
        span=etime-btime;
        span=(pow(i,2))/span;
        span/=pow(10,9);
        if (!isfinite(span))
            span=0;
        sprintf(result,"ij;%d;%.2f",i,span);
        append_to_file(fileName,result);

        memset(y, 0, sizeof(double)*(MAXITER));

        //Strategia JI
        btime = get_cur_time(); //inizio blocco da monitorare
        mat_vet_ji(i,i,(double (*)[])A,x,y);
        etime = get_cur_time();  //fine blocco da monitorare
        span=etime-btime;
        span=(pow(i,2))/span;
        span/=pow(10,9);
        if (!isfinite(span))
            span=0.01;
        sprintf(result,"ji;%d;%.2f",i,span);
        append_to_file(fileName,result);

        memset(y, 0, sizeof(double)*(MAXITER));
    }
    free(A);
    free(B);
    free(C);
    free(x);
    free(y);
    return 0;
}