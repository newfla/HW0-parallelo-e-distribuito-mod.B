//
// Created by bizzi on 14/03/18.
//

void mat_mat_ijk(int n, int m, int p, int lda, int ldb, int ldc, double A[][lda], double B[][ldb], double C[][ldc]){
    for(int i=0; i<n; i++){
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

void mat_mat_jik(int n, int m, int p, int lda, int ldb, int ldc, double A[][lda], double B[][ldb], double C[][ldc]){
    for(int j=0; j<m; j++){
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < p; k++) {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

//Migliore
void mat_mat_ikj(int n, int m, int p, int lda, int ldb, int ldc, double A[][lda], double B[][ldb], double C[][ldc]){
    for(int i=0; i<n; i++){
        for (int k = 0; k < p; k++) {
            for (int j = 0; j < m; j++) {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

//Peggiore
void mat_mat_jki(int n, int m, int p, int lda, int ldb, int ldc, double A[][lda], double B[][ldb], double C[][ldc]){
    for(int j=0; j<m; j++){
        for (int k = 0; k < p; k++) {
            for (int i = 0; i < n; i++) {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

void mat_mat_kij(int n, int m, int p, int lda, int ldb, int ldc, double A[][lda], double B[][ldb], double C[][ldc]){
    for(int k=0; k<p; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}

void mat_mat_kji(int n, int m, int p, int lda, int ldb, int ldc, double A[][lda], double B[][ldb], double C[][ldc]){
    for(int k=0; k<p; k++){
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}
