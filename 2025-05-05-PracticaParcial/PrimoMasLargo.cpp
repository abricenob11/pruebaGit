long largest_prime_factor (long n){

    long variacion = n;
    long largestPrimeFactor = 0;
    int contador=0;
    do{
        while (variacion % 2 == 0) {
            largestPrimeFactor = 2;
            variacion /= 2;
        }
        
        for (long x = 3; x <= sqrt(variacion); x += 2) {
            while (variacion % x == 0) { 
                largestPrimeFactor = x;
                variacion /= x;
            }
        }
        contador++;
    }while(contador<2);

    if (variacion > 1 && isprime(variacion)) {
            largestPrimeFactor = variacion;
    }

    return largestPrimeFactor; 
}