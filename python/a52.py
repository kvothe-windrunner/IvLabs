"""
5.2 Write a program that repeatedly prompts a user for integer numbers until the user enters 'done'. Once 'done' is entered, print out the largest and smallest of the numbers. If the user enters anything other than a valid number catch it with a try/except and put out an appropriate message and ignore the number. Enter 7, 2, bob, 10, and 4 and match the output below.
"""

largest = 0
num = (input("Enter a number: "))
smallest = 9999999
while True:
    num = (input("Enter a number: "))
    try:
        n=int(num)
        if largest < n : largest = n
        if smallest > n : smallest = n
    except:
        if num == "done":
            break
        else:
            print("Invalid input")
            
print("Maximum is",largest)
print("Minimum is",smallest)