## Minha implementação do algoritmo de teste de primalidade probabilístico Miller-Rabin em linguagem diferentes
# ⚠️ ATENÇÃO: AS INFORMAÇÕES PRESENTES NESSE REPOSITÓRIO PODEM CONTER ERROS, NÃO UTILIZE COMO REFERÊNCIA ⚠️
### Linguagens:
- [C (usando biblioteca GMP)](https://github.com/RafaelHipolit/Minha-implementacao-Algoritmo-Miller-Rabin/blob/main/src/c/MillerRabinC.c)
- [Crystal](https://github.com/RafaelHipolit/Minha-implementacao-Algoritmo-Miller-Rabin/blob/main/src/crystal/miller_rabin.cr) By [Hanazono-Yurine](https://github.com/Hanazono-Yurine)
- [Python](https://github.com/RafaelHipolit/Minha-implementacao-Algoritmo-Miller-Rabin/blob/main/src/python/MillerRabinPy.py)
- [Java (usando classe BigInteger)](https://github.com/RafaelHipolit/Minha-implementacao-Algoritmo-Miller-Rabin/blob/main/src/java/MillerRabinJava.java)
- [C# (usando System.Numerics BigInteger)](https://github.com/RafaelHipolit/Minha-implementacao-Algoritmo-Miller-Rabin/blob/main/src/csharp/MillerRabinCSharp.cs)

### Para testar a primalidade do 27º Primo de Mersenne(2^44497-1):
- C demorou aproximadamente 10s
- Crystal demorou aproximadamente 35s
- Python demorou aproximadamente 4min
- Java demorou aproximadamente 4,2min

### Comentários:
Na implementação em C#, por dificuldade de gerar um BigInteger aleatório, o número gerado está sendo um int de 32bits. Quanto menor esse numero aleatório, mais rápido devera ser as operações aritmeticas realizadas no codigo. 
Contudo, a minha execução demorou 35min para testar a primalidade do 27º Primo de Mersenne(2^44497-1).
Possíveis causas:
- Erro na implementação do algoritmo
- A classe System.Numerics BigInteger(que já vem "nativa" com o C#) não é eficiente para realizar operações aritméticas.
- C# não é eficiente para realizar operações aritméticas com número grandes.

A fazer:
- Criar gráfico comparando o desempenho entre as linguagens.
- Melhorar a geração de números aleatórios na implementação em Java.
- Melhorar a geração de números aleatórios na implementação em C#.
- Entender a causa da demora na execução da implementação em C#.
- Entender a relação entre o número aleatório utilizado no algoritmo e o fator de probabilidade da resposta do algoritmo. Pois, se for possível utilizar um número aleatório pequeno sem influenciar na resposta, poderia-se diminuir o tempo de execução.
