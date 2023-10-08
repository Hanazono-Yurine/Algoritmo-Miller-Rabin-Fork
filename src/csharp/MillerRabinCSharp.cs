using System;
using System.Numerics;

namespace Primos
{
    class MillerRabinCSharp
    {

        public static string millerRabin(BigInteger N)
        {

            //Assumindo que a entrada é um numero maior que 2

            if(BigInteger.Remainder(N,2) == 0)
            {
                return "Composto";
            }

            BigInteger q = N - 1;
            BigInteger k = 0;

            while (q % 2 == 0)
            {
                q = q / 2;
                k++;
            }

            //quebra galho para gerar um numero aleatorio entre 2 e N-1
            Random random = new Random((int)DateTimeOffset.Now.ToUnixTimeMilliseconds());
            BigInteger a;
            if (N <= Int32.MaxValue)
            {
                a = random.Next(2, Int32.Parse(N.ToString())); 
            }
            else
            {
                a = random.Next(2, Int32.MaxValue);
            }
           
            Console.WriteLine("a = " + a);

            // TESTE 1
            BigInteger resultTest1 = BigInteger.ModPow(a, q, N);
            if (resultTest1 == 1 || resultTest1 == N - 1)
            {
                //Console.WriteLine("TESTE 1 - VERDADEIRO");
                return "ProvavelPrimo";
            }

            //TESTE2
            BigInteger x = resultTest1;
            BigInteger resultTest2;
            for (BigInteger i = 0; i < k; i++)
            {
                resultTest2 = BigInteger.ModPow(x, 2, N);

                //Console.WriteLine("resultTest2 =" + resultTest2);
                if(resultTest2 == N - 1)
                {
                    return "ProvavelPrimo";
                }

                x = resultTest2;

            }

            return "Composto";

        }

    }
}
