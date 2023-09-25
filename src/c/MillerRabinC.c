#include <stdio.h>
#include <gmp.h>
#include <time.h>

int MillerRabin(mpz_t *N, mpz_t *res, mpz_t *q, mpz_t *k, mpz_t *a, gmp_randstate_t *randstate, mpz_t *Nminus1, mpz_t *i){
    // return 0 = composto
    // return 1 = provavelPrimo

    if(mpz_cmp_si(*N,1) == 0){
        printf("Entrada 1 não é valido\n");
        return 0;
    }
    if(mpz_cmp_si(*N,2) == 0){
        printf("2 é primo\n");
        return 1;
    }

    mpz_mod_ui(*res,*N,2);
    //gmp_pri*Ntf("%Zd\*N",*res);

    if (mpz_cmp_si(*res,0) == 0)
    {
        printf("Par\n");
        printf("Composto\n");
        return 0;
    }else
    {
        printf("impar\n");
    }

    mpz_set(*q,*Nminus1);
    mpz_set_si(*k,0);

    mpz_mod_ui(*res,*q,2);
    while (mpz_cmp_si(*res,0) == 0)
    {
        mpz_cdiv_q_ui(*q,*q,2);
        mpz_add_ui(*k,*k,1);
        //gmp_printf("q=%Zd \nk=%Zd \n",*q,*k);

        mpz_mod_ui(*res,*q,2);
    }
    
    //gmp_printf("q=%Zd \nk=%Zd \n",*q,*k);

    mpz_urandomm(*a,*randstate,*N); // ger*a um *Num r*a*Ndom e*Ntre 0 e *N-1
    //verific*ar se fu*Ncio*N*a
    if (mpz_cmp_si(*a,2) < 0) // SE a < 2
    {
        mpz_set_si(*a,2); // a = 2
    }
    //gmp_printf("a=%Zd \n",*a);

    //TESTE 1

    mpz_powm(*res,*a,*q,*N);

    if ((mpz_cmp_si(*res,1) == 0) || (mpz_cmp(*res,*Nminus1) == 0))
    {
        printf("Provavel primo\n");
        return 1;
    }

    //TESTE 2

    for (mpz_set_si(*i,0); mpz_cmp(*i,*k) < 0; mpz_add_ui(*i,*i,1))
    {
        mpz_powm_ui(*res,*res,2,*N);
        if (mpz_cmp(*res,*Nminus1) == 0)
        {
            printf("Provavel primo\n");
            return 1;
        }
        
    }
    
    
    printf("Composto\n");
    return 0;
}

int chamaMillerRabin(){

    mpz_t N;
    mpz_init_set_si(N,2);
    unsigned long int exp = 44497; //5s
    mpz_pow_ui(N,N,exp);
    mpz_sub_ui(N,N,1);
    //gmp_printf("N=%Zd \n",N);

    mpz_t res;
    mpz_init(res);

    mpz_t q;
    mpz_init(q);

    mpz_t k;
    mpz_init(k);

    mpz_t a;
    mpz_init(a);

    gmp_randstate_t randstate;
    gmp_randinit_default(randstate);
    gmp_randseed_ui(randstate,(unsigned long int) clock());

    mpz_t Nminus1;
    mpz_init(Nminus1);
    mpz_sub_ui(Nminus1,N,1);

    mpz_t i;
    mpz_init(i);


    MillerRabin(&N,&res,&q,&k,&a,&randstate,&Nminus1,&i);    


    mpz_clear(N);
    mpz_clear(res);
    mpz_clear(q);
    mpz_clear(k);
    mpz_clear(a);
    gmp_randclear(randstate);
    mpz_clear(Nminus1);
    mpz_clear(i);
}

int main(int *argc, char *argv[]){
    /*
    mpz_t N;
    mpz_init_set_si(N,2);
    unsigned long int num = 2;
    mpz_pow_ui(N,N,num);
    mpz_sub_ui(N,N,1);
    */
    clock_t start ,end;
    double intevalo;

    start = clock();
    chamaMillerRabin();
    end = clock();

    intevalo = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("tempo(s)=%f\n",intevalo);
    
    //mpz_clear(N);

    return 0;
}

//Comando para compilar:
//gcc MillerRabinC.c -o mr -lgmp
