package Primos;

import java.math.BigInteger;
import java.util.Random;

public class MillerRabinJava {

    public static String MillerRabin(BigInteger N){

        final BigInteger DOIS = new BigInteger("2");

        if (N.compareTo(DOIS) < 0) {
            return "Composto";
        } else if (N.compareTo(DOIS) == 0) {
            return "ProvavelPrimo";
        }

        if(N.mod(DOIS).equals(BigInteger.ZERO)){
            return "Composto";
        }

        BigInteger q = N.subtract(BigInteger.ONE);
        BigInteger k = BigInteger.ZERO;
        while (q.mod(DOIS).equals(BigInteger.ZERO)){
            q = q.divide(DOIS);
            k = k.add(BigInteger.ONE);
        }

        BigInteger a = new BigInteger(N.bitLength()-1,new Random(System.currentTimeMillis()));
        if (a.compareTo(DOIS) < 0) {
            a = DOIS;
        }
        //BigInteger(n,random) gera um numero aleatorio entre 0 e (2^n)-1
        //Preciso de um numero aleatorio entre 2 e N-1
        //Se eu usar BigInteger(N.bitLength(),random); ele vai gerar um numero com a mesma quant. de bits que N, isso pode gerar um numero maior que N
        //Para evitar isso, vou gerar um numero aleatoria com 1 bit a menos que N BigInteger(N.bitLength-1,random);


        //TESTE 1
        BigInteger resultNumTest1 = a.modPow(q,N);
        if(resultNumTest1.equals(BigInteger.ONE) || resultNumTest1.equals(N.subtract(BigInteger.ONE))){
            return "ProvavelPrimo";
        }

        //TESTE 2
        BigInteger x = resultNumTest1;

        for (BigInteger i = BigInteger.ZERO; i.compareTo(k) < 0; i = i.add(BigInteger.ONE)) {
            BigInteger resultNumTest2 = x.modPow(DOIS,N);
            if(resultNumTest2.equals(N.subtract(BigInteger.ONE))){
                return "ProvavelPrimo";
            }
            x = resultNumTest2;
            System.out.println(i.toString() +" de "+ k.toString());
        }

        return "Composto";
    }

}
