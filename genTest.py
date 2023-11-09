import random
import sys

def generate_polynomial(degree):
    coefficients = [random.randint(-10, 10) for _ in range(degree + 1)]
    return coefficients

def format_polynomial(coefficients):
    formatted_poly = ""
    for i, coeff in enumerate(coefficients):
        if coeff != 0:
            if i == 0:
                term = f"{coeff}"
            elif i == 1:
                term = f"{coeff} * X"
            else:
                term = f"{coeff} * X^{i}"
            formatted_poly += term + " + "
    return formatted_poly.rstrip(" + ")

def main(num_polynomials):
    with open("tester.txt", "w") as file:
        for _ in range(num_polynomials):
            degree = random.randint(1, 2)  # Random degree between 1 and 3
            coefficients = generate_polynomial(degree)
            formatted_poly = format_polynomial(coefficients)
            file.write(formatted_poly + "= X^" + str(degree) + "\n")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python script.py <number_of_polynomials>")
    else:
        num_polynomials = int(sys.argv[1])
        main(num_polynomials)

