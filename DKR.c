#include <stdio.h>
#include <stdlib.h>

#define Txt_IN "txt_in.txt"

void task_1();
void task_2();
void task_3();
int** create_matrix_for_3();

int main(){

 int var_of_task;
 srand( time(NULL) );
 printf(" Choose the task number");

 while( var_of_task < 1 || var_of_task > 3 ){
    printf("\n >");
    scanf("%d", &var_of_task);
 }

 system("cls");

 switch(var_of_task){

    case 1:
        task_1();
        break;

    case 2:
        task_2();
        break;

    case 3:
        task_3();
     break;
 }

 return 0;
}


void task_1(){

 int N;
 double a, sum = 0;

 printf(" Enter a:");
 scanf("%lf", &a);
 printf("\n Enter number of terms (N >= 0):");
 scanf("%d", &N);

 if ( N < 0 ){
    printf(" N cannot be a negative number");
    printf(" Enter an acceptable value >");
    scanf("%d", &N);
 }

 for( int n = 0; n<=N; n++ ){

    double factorial = 1;
    double power = 1;

    for( int i = 1;  i <= 2*n; i++ ){
        power *=a;
        factorial *=i;
    }

    power = power / factorial;
    sum += power;

 }

 printf("\n The sum of the calculated series: %lf\n", sum);

}


void task_2(){

 int** A;
 int N, r, column, sum = 0;


 printf("\n Enter the dimension of matrix");
 while( N < 2 || N > 15 ){
    printf("\n >");
    scanf("%d", &N);
 }

 A=(int**)calloc(N, sizeof(int*));
 for( int j=0; j<N; j++ ){

    A[j]=(int*) calloc(N, sizeof(int));
    if(A[j]==NULL){
        printf("\nMemory has not been allocated");
        exit(0);
    }

 }

 r = 5 + rand()%6;

 for( int i=0; i<N; i++ ){

    for( int j=0; j<N; j++ ){

        A[i][j] = rand()%(2*r+1)-r;

    }

 }

 for( int j=0; j<N; j++ ){

    int temp =0;
    for ( int i=0; i<N; i++ ){

        int pos = A [i][j];
        temp += pos;

    }

    if ( temp < sum ){
        sum = temp;
        column = j+1;
    }

 }

 system("cls");
 printf("\n Created matrix:\n\n");

 for ( int i=0; i<N; i++ ){

    for ( int j=0; j<N; j++ ){

        printf("%3d ", A[i][j]);

    }

    printf("\n");
}

 printf("\n The smallest amount = %d", sum);
 printf("\n Column: %d\n", column);

 for ( int i=0; i<N; i++ ){
        free(A[i]);
 }

 free(A);

}


void task_3(){

 FILE * f_in;
 int count = 0, length;
 int **cnt_arr = create_matrix_for_3();

 for( int i = 0; i < 10; i++ ){
   cnt_arr[i][0] = i;
 }

 f_in = fopen(Txt_IN, "r");
 if ( f_in == NULL ){
    printf("\nCannot open an input file!");
    printf("Press any key to exit...");
    getch();
    exit (1);
 }

 fseek( f_in, 0, SEEK_END );
 length = ftell( f_in );
 fseek( f_in, 0, SEEK_SET );

 for( int i=0; i<length; i++ ){

    char ch;
    ch = fgetc( f_in );

    switch ( ch ){

        case '0':
            cnt_arr[0][1]++;
            break;

        case '1':
            cnt_arr[1][1]++;
            break;

        case '2':
            cnt_arr[2][1]++;
            break;

        case '3':
            cnt_arr[3][1]++;
            break;

        case '4':
            cnt_arr[4][1]++;
            break;

        case '5':
            cnt_arr[5][1]++;
            break;

        case '6':
            cnt_arr[6][1]++;
            break;

        case '7':
            cnt_arr[7][1]++;
            break;

        case '8':
            cnt_arr[8][1]++;
            break;

        case '9':
            cnt_arr[9][1]++;
            break;

    }

 }

 fclose( f_in );

 for( int i=0 ; i<9; i++ ){

    for( int j = 0; j < 9 - i; j++ ){

        if(cnt_arr[j][1] < cnt_arr[j+1][1]) {

            int tmp_count = cnt_arr[j][1];
            int tmp_num= cnt_arr[j][0];
            cnt_arr[j][1] = cnt_arr[j+1][1];
            cnt_arr[j][0] = cnt_arr[j+1][0];
            cnt_arr[j+1][1] = tmp_count;
            cnt_arr[j+1][0] = tmp_num;

        }
    }
 }

 printf("\n The most common numeric characters in the file:\n\n");

 for ( int i=0;i<4;i++ ){

    printf(" Numeric character %d encountered %d times in the file;", cnt_arr[i][0], cnt_arr[i][1]);
    printf("\n");

    }

 for( int i=0; i<10; i++ )
    free(cnt_arr[i]);

 free( cnt_arr );
}

int** create_matrix_for_3(){

 int ** cnt_arr =(int**) calloc(10,  sizeof(int*));
     for( int i=0;i<10;i++ ){
         cnt_arr[i]=(int*) calloc(2, sizeof(int));

         if( cnt_arr[i] == NULL ){
             printf("Memory has not been allocated");
             exit(0);
         }
     }

 return cnt_arr;
}
