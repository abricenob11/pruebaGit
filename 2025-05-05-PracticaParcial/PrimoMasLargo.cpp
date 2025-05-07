long largest_prime_factor (long n){

    long variacion = n;
    long largestPrimeFactor = 0;

    // Dividir por 2 mientras se pueda
    while (variacion % 2 == 0) {
        largestPrimeFactor = 2;
        variacion /= 2;
    }

    // Iterar sobre impares a partir de 3 para no usar todos los números
    for (long x = 3; x <= sqrt(variacion); x += 2) {
        while (variacion % x == 0) { //Dividir por x mientras se pueda
            largestPrimeFactor = x;
            variacion /= x;
        }
    }

    // Si lo que queda de variacion es mayor que 1 y es primo, ese sería el factor primo más grande
    if (variacion > 1 && isprime(variacion)) {
            largestPrimeFactor = variacion;
        }
     
    return largestPrimeFactor; // Ahora la función devuelve el resultado
}