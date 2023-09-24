from random import *;
import numpy as np;

def encontreKQ(N):
    q = N - 1;
    k = 0;
    while q % 2 == 0:
        q = q//2;
        k=k+1;
    return (q,k);

def MillerRabin(N):
    
    if(N == 1):# 1 é invalidoif
        return 'Composto';
    if(N == 2):# 1 é invalidoif
        return 'ProvavelPrimo';
    
    if(N % 2 == 0):
        return 'Composto';
    
    (q,k) = encontreKQ(N);
    
    a = randint(2,N-1);
    #a = 2071;
    
    # TESTE 1
    resultNumTest1 = pow(a,q,N); # (a**q) mod N
    if(resultNumTest1 == 1 or resultNumTest1 == N-1):
        #caso VERDADEIRO finalize o algoritmo - PROVAVEL PRIMO
        return 'ProvavelPrimo';
    else:
        #caso FALSO continue o algoritmo
        1+1
        
    # TESTE 2
    x = resultNumTest1;
    for i in range(k):
        print(i,"/",k)
        resultNumTest2 = pow(x,2,N);
        if(resultNumTest2 == N-1):
            #caso VERDADEIRO finalize o algoritmo - PROVAVEL PRIMO
            return 'ProvavelPrimo';
        else:
            #caso FALSO continue o algoritmo
            1+1
        x = resultNumTest2;
    
    #Caso chegou aqui, nenhum teste deu verdadeiro - COMPOSTO
    return 'Composto';

import time;   

n = 44497 #237316ms =~ 4min

t0 = time.perf_counter_ns();

print(MillerRabin((2**n)-1));

t1 = time.perf_counter_ns();

t = int((t1 - t0)/1000000);

print("Tempo(ms)=",t)