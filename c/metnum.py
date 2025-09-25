# Given data points
x_values = [1.8, 1.9, 2.0, 2.1, 2.2]
f_values = [1.96, 2.26, 3.30, 4.23, 4.67]

# Step size
h = 0.1

# Applying the second-order forward difference formula
f_prime_2 = (-3 * f_values[2] + 4 * f_values[3] - f_values[4]) / (2 * h)

# Print the result
print(f"Approximate derivative at x = 2: {f_prime_2}")

import math

# Function definition
def f(x):
    return x * math.exp(x)

# Limits of integration
a, b = 0.2, 2.2

# Trapezoidal Rule with one segment
integral = (b - a) / 2 * (f(a) + f(b))

# Print the result
print(f"Approximate integral value: {integral}")

# Function definition
def f(x):
    return x * math.exp(x)

# Limits of integration
a, b = 0.2, 2.2
n = 3  # Number of segments
h = (b - a) / n  # Step size

# Trapezoidal Rule with 3 segments
x_values = [a + i * h for i in range(n + 1)]
f_values = [f(x) for x in x_values]

integral = (h / 2) * (f_values[0] + 2 * sum(f_values[1:n]) + f_values[n])

# Print the result
print(f"Approximate integral value: {integral}")