//
// Created by bizzi on 14/03/18.
//

#ifndef HW0_MAT_MAT_H
#define HW0_MAT_MAT_H

#endif //HW0_MAT_MAT_

void mat_mat_ijk(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C);

void mat_mat_jik(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C);

//Migliore
void mat_mat_ikj(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C);

//Peggiore
void mat_mat_jki(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C);

void mat_mat_kij(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C);

void mat_mat_kji(int n, int m, int p, int lda, int ldb, int ldc, double* A, double* B, double* C);




