//
// Created by bizzi on 14/03/18.
//

void mat_mat_ijk(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C){
    for(int i=0; i<n; i++){
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                C[(ldc*i)+j]+=A[(lda*i)+k]*B[(ldb*k)+j];
            }
        }
    }
}

void mat_mat_jik(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C){
    for(int j=0; j<m; j++){
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < p; k++) {
                C[(ldc*i)+j]+=A[(lda*i)+k]*B[(ldb*k)+j];
            }
        }
    }
}

//Migliore
void mat_mat_ikj(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C){
    for(int i=0; i<n; i++){
        for (int k = 0; k < p; k++) {
            for (int j = 0; j < m; j++) {
                C[(ldc*i)+j]+=A[(lda*i)+k]*B[(ldb*k)+j];
            }
        }
    }
}

//Peggiore
void mat_mat_jki(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C){
    for(int j=0; j<m; j++){
        for (int k = 0; k < p; k++) {
            for (int i = 0; i < n; i++) {
                C[(ldc*i)+j]+=A[(lda*i)+k]*B[(ldb*k)+j];
            }
        }
    }
}

void mat_mat_kij(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C){
    for(int k=0; k<p; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                C[(ldc*i)+j]+=A[(lda*i)+k]*B[(ldb*k)+j];
            }
        }
    }
}

void mat_mat_kji(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C){
    for(int k=0; k<p; k++){
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                C[(ldc*i)+j]+=A[(lda*i)+k]*B[(ldb*k)+j];
            }
        }
    }
}
