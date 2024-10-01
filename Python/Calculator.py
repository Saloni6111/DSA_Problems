# Define functions for basic operations

def add(x, y):
    # This function adds two numbers
    return x + y

def subtract(x, y):
    # This function subtracts one number from another
    return x - y

def multiply(x, y):
    # This function multiplies two numbers
    return x * y

def divide(x, y):
    # This function divides one number by another and handles division by zero
    if y != 0:
        return x / y
    else:
        return "Cannot divide by zero!"

# Display available operations to the user
print("Select operation:")
print("1. Add")
print("2. Subtract")
print("3. Multiply")
print("4. Divide")

# Take input from the user for the operation
choice = input("Enter choice(1/2/3/4): ")

# Input two numbers for the chosen operation
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))

# Perform the corresponding operation based on user choice
if choice == '1':
    # Calls the add function
    print(f"{num1} + {num2} = {add(num1, num2)}")

if choice == '2':
    # Calls the subtract function
    print(f"{num1} - {num2} = {subtract(num1, num2)}")

if choice == '3':
    # Calls the multiply function
    print(f"{num1} * {num2} = {multiply(num1, num2)}")

if choice == '4':
    # Calls the divide function
    print(f"{num1} / {num2} = {divide(num1, num2)}")

# If an invalid choice is entered, no operation is performed
if choice not in ['1', '2', '3', '4']:
    print("Invalid Input")



"""
How it works:
1-Functions: There are four functions—add, subtract, multiply, and divide—each performing the respective arithmetic operation.
2-User Input: The user is prompted to select an operation by entering a number (1, 2, 3, or 4) corresponding to the desired arithmetic operation.
3-Execution: Based on the user's choice, the appropriate function is called using if statements, and the result is printed.
4-Division by Zero Handling: The divide function checks if the second number is zero and returns a message to avoid division by zero.
5-Invalid Input: If the user enters anything other than 1, 2, 3, or 4, an "Invalid Input" message is displayed.
"""