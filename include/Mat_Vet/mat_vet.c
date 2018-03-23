//
// Created by bizzi on 14/03/18.
//


void mat_vet_ij(int n,int lda, double A[][lda], double* x, double* y){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            y[i]+=A[i][j]*x[j];
        }
    }

}

void mat_vet_ji(int n, int lda, double A[][lda],double* x, double* y){
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            y[i] += A[i][j] * x[j];
        }
    }
}
