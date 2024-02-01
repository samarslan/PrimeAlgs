#include <stdio.h>
#include <stdbool.h>

int main() {
	long long int number;
	bool isPrime=true;
  

	//scanf("%d", &number);
  number=11120933330250889;
	if (number <= 1) {
		isPrime = false;
	} else if (number == 2) {
		isPrime = true;
	} else {
		for (int i = 3; i < number; i++) {
			if (number % i == 0) {
				isPrime = false;
				break;
			}
		}
	}

  if(isPrime){
    printf("\n%lld is prime\n", number);
  }
  else{
    printf("\n%lld is not prime\n", number);
  }
}