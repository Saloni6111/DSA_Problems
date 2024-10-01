# Define functions for basic and advanced operations
def add(x, y):
    return x + y  # Adds two numbers

def subtract(x, y):
    return x - y  # Subtracts second number from the first

def multiply(x, y):
    return x * y  # Multiplies two numbers

def divide(x, y):
    if y == 0:
        return "Error! Division by zero."  # Avoids dividing by zero
    return x / y  # Divides first number by second

def modulus(x, y):
    if y == 0:
        return "Error! Division by zero."  # Avoids dividing by zero
    return x % y  # Returns the remainder of division

def exponentiate(x, y):
    return x ** y  # Raises first number to the power of second

def floor_divide(x, y):
    if y == 0:
        return "Error! Division by zero."  # Avoids dividing by zero
    return x // y  # Returns the integer quotient of division

# Dictionary to map operation symbols to corresponding functions
operations = {
    '+': add,          # Addition
    '-': subtract,     # Subtraction
    '*': multiply,     # Multiplication
    '/': divide,       # Division
    '%': modulus,      # Modulus (remainder)
    '**': exponentiate,  # Exponentiation (power)
    '//': floor_divide  # Floor division (integer division)
}

# Function to perform the calculation
def calculator():
    while True:
        try:
            # Get the first number from the user
            num1 = float(input("Enter the first number (or 'q' to quit): "))
            
            # Get the operation from the user
            op = input("Enter operation (+, -, *, /, %, **, //): ")
            
            # Get the second number from the user
            num2 = float(input("Enter the second number: "))

            # Check if the entered operation exists in the operations dictionary
            if op in operations:
                # Call the corresponding function for the operation
                result = operations[op](num1, num2)
                # Display the result
                print(f"Result: {result}")
            else:
                # Handle invalid operation input
                print("Invalid operation. Please choose a valid operator.")

        except ValueError:
            # Handle invalid input for numbers
            print("Error! Please enter valid numbers.")
        
        # Ask user if they want to perform another calculation
        another_calculation = input("Do you want to perform another calculation? (yes/no): ").strip().lower()
        if another_calculation != 'yes':
            print("Thank you for using the calculator!")
            break

# Run the calculator
calculator()