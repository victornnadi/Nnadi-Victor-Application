// Developed by Nnadi Victor 
//The following program uses the Proth theorem to test real numbers below 97 for primality.
//The program is divided into two parts: the first part checks if the number is proth 
//if that condition is satisfied, the second part uses Proth theorem to test for primality
//The output is a list of statements: if at least one of the statement says "Number is a proth prime" it is a proth prime.
//The other statements shows "Number is not proth prime" because the proth theorem is a Las Vegas algorithm. But it is still useful because it can return a 
//false negative, but can never return a false positive.
//If number is not proth, it doesn't test for primality, and informs user that number is not proth.
//Logic: The proth theorem expression is  a^p-1/2 + 1 = mod p; 
//if an integer a exists such that the expression is a multiple of p, p is a proth prime.
//The program is limited to real numbers below 96 because as the numbers get bigger, the exponent 
//becomes too big for the power function to precisely store its result in c++ datatypes int, double or long double.
//Beyond 96, this program is not guaranteed to work correctly. More details on how i tried to circumvent the limits
//after the code  
#include <bits/stdc++.h> 
using namespace std; 

// Utility function to check power of two 
bool isPowerOfTwo(int n) 
{ 
	return (n && !(n & (n - 1))); 
} 

// Function to check if the 
// Given number is Proth number or not 
bool isProthNumber(int n) 
{ 

	int k = 1; 
	while (k < (n / k)) { 

		// check if k divides n or not 
		if (n % k == 0) { 

			// Check if n/k is power of 2 or not 
			if (isPowerOfTwo(n / k)) 
				return true; 
		} 

		// update k to next odd number 
		k = k + 2; 
	} 

	// If we reach here means 
	// there exists no value of K 
	// Such that k is odd number 
	// and n/k is a power of 2 greater than k 
	return false; 
} 

 
int main() 
{ 

	// Get n
	 int n;
 cout << "Type a number below 97(limited memory allocated to c++ int datatype makes this program limited to proth numbers up to 96): "; // Type a number and press enter
 cin >> n; // Get user input from the keyboard
	 

	// Check n for Proth Number 
	if (isProthNumber(n - 1)) 
	
	{ //execute the code if number is proth  
			int p = n * 1;
		
		int a;
 double x;     
 double y;
 
 x = p-1; 
 y = x/2;     //proth theorem exponent

for (a = 1; a < 10; ++a)   //iterates integral values of a from 1 to 10 in the proth theorem formula a^p-1/2 = -1 mod p
      
	  {
		 
		double d = pow(a,y);        //proth theorem computation begins here
		double e = d + 1;
		double f = fmod(e , p);     //number is a proth prime if the remainder is zero
		
		if (f == 0)
            printf("%d is a proth prime number\n", p);  //if this statement is executed at least once in the 10 iterations, number is a proth prime.
            
            
        else
        	printf("%d is not a proth prime number\n", p);
      }
      
}

else
		cout << "Number is not proth";  //Primality test is not done if proth test is not passed.


 return 0;
}
	
//This was a very interesting project to work on. I learnt a lot from it and i am thankful for that opportunity. 
//I am glad i was able to build a program that performed the task the question required using the proth theorem logic.
//However, i still wanted to circumvent c++ limit, i tried to learn about the GNP library for arithmetic precision. I tried methods for installing it in my
//machine, but my limited skill in the use of the command line, limited amounts of documentation for the library and a not so 
//beginner friendly manual, made my learning pace too slow to meet up with the submission deadline. At the last moments, i learnt about
//a little about golang	to see that its numerical datatypes were more accomodating. However, i was not able to learn all that i needed
//about the new language to build this particular program on it before the deadline. I am happy i learnt this and i think i like the golang route
//better than the GNP and will surely investigate both methods further to see which leads me to a more accomodating program. Thanks again
//for the opportunity. 	- Nnadi.
