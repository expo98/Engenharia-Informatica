import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from scipy.optimize import curve_fit
from sklearn.metrics import r2_score

# Read the CSV file into a DataFrame
df = pd.read_csv("tempos.csv", header=None, delimiter=' ')

# Initialize an empty list to store arrays
arrays = []

# Iterate through each row of the DataFrame values
for row in df.values:
    # Split the string by comma and convert each substring to a float
    numbers = [float(x) for x in row[0].split(',')]
    # Append the list of numbers to the arrays list
    arrays.append(numbers)

y_quicksort_ascending = np.array(arrays[0])
y_quicksort_descending = np.array(arrays[1])
y_quicksort_random = np.array(arrays[2])

y_heapsort_ascending = np.array(arrays[3])
y_heapsort_descending = np.array(arrays[4])
y_heapsort_random = np.array(arrays[5])

y_insertionsort_ascending = np.array(arrays[6])
y_insertionsort_descending = np.array(arrays[7])
y_insertionsort_random = np.array(arrays[8])

x_items = np.array([10000,20000,30000,40000,50000,60000,70000,80000,90000,100000])

# Define the quadratic function (x^2)
def quadratic_func(x, a, b, c):
    return a * x**2 + b * x + c

# Define the O(nlogn) function
def nlogn_func(x, a, b):
    return a * x * np.log(x) + b

# Define O(n) function for insertion sort on ascending data
def linear_func(x, a, b):
    return a * x + b

# Fit the quadratic regression model to the data for quicksort ascending
popt_quicksort_asc, _ = curve_fit(quadratic_func, x_items, y_quicksort_ascending)
a_quicksort_asc, b_quicksort_asc, c_quicksort_asc = popt_quicksort_asc

# Fit the O(nlogn) regression model to the data for quicksort descending
popt_quicksort_desc, _ = curve_fit(nlogn_func, x_items, y_quicksort_descending)

# Fit the O(nlogn) regression model to the data for quicksort random
popt_quicksort_random, _ = curve_fit(nlogn_func, x_items, y_quicksort_random)

# Calculate R^2 for each regression line
r_squared_asc_qs = r2_score(y_quicksort_ascending, quadratic_func(x_items, *popt_quicksort_asc))
r_squared_desc_qs = r2_score(y_quicksort_descending, nlogn_func(x_items, *popt_quicksort_desc))
r_squared_random_qs = r2_score(y_quicksort_random, nlogn_func(x_items, *popt_quicksort_random))

# Fit the O(nlogn) regression model to the data for heapsort ascending
popt_heapsort_asc, _ = curve_fit(nlogn_func, x_items, y_heapsort_ascending)

# Fit the O(nlogn) regression model to the data for heapsort descending
popt_heapsort_desc, _ = curve_fit(nlogn_func, x_items, y_heapsort_descending)

# Fit the O(nlogn) regression model to the data for heapsort random
popt_heapsort_random, _ = curve_fit(nlogn_func, x_items, y_heapsort_random)

# Calculate R^2 for each regression line
r_squared_asc_hs = r2_score(y_heapsort_ascending, nlogn_func(x_items, *popt_heapsort_asc))
r_squared_desc_hs = r2_score(y_heapsort_descending, nlogn_func(x_items, *popt_heapsort_desc))
r_squared_random_hs = r2_score(y_heapsort_random, nlogn_func(x_items, *popt_heapsort_random))

# Fit the linear regression model to the data for insertionsort ascending
popt_insertionsort_asc, _ = curve_fit(linear_func, x_items, y_insertionsort_ascending)
a_insertionsort_asc, b_insertionsort_asc = popt_insertionsort_asc

# Fit the O(n^2) regression model to the data for insertionsort descending and random
popt_insertionsort_desc, _ = curve_fit(quadratic_func, x_items, y_insertionsort_descending)
popt_insertionsort_random, _ = curve_fit(quadratic_func, x_items, y_insertionsort_random)

# Calculate R^2 for each regression line
r_squared_asc_is = r2_score(y_insertionsort_ascending, linear_func(x_items, *popt_insertionsort_asc))
r_squared_desc_is = r2_score(y_insertionsort_descending, quadratic_func(x_items, *popt_insertionsort_desc))
r_squared_random_is = r2_score(y_insertionsort_random, quadratic_func(x_items, *popt_insertionsort_random))

# Plotting Quicksort
plt.figure(1)
plt.plot(x_items, y_quicksort_ascending, 'o', label='Ascending Data')
plt.plot(x_items, y_quicksort_descending, 'o', label='Descending Data')
plt.plot(x_items, y_quicksort_random, 'o', label='Random Data')
plt.plot(x_items, quadratic_func(x_items, *popt_quicksort_asc), color='blue', linestyle='--', label=f'O(n^2) Regression (R^2={r_squared_asc_qs})')
plt.plot(x_items, nlogn_func(x_items, *popt_quicksort_desc), color='orange', linestyle='--', label=f'O(nlogn) Regression (R^2={r_squared_desc_qs})')
plt.plot(x_items, nlogn_func(x_items, *popt_quicksort_random), color='green', linestyle='--', label=f'O(nlogn) Regression (R^2={r_squared_random_qs})')
plt.title('Quicksort')
plt.xlabel('Número de elementos')
plt.ylabel('Tempo (s)')
plt.legend()

# Plotting Heapsort
plt.figure(2)
plt.plot(x_items, y_heapsort_ascending, 'o', label='Ascending Data')
plt.plot(x_items, y_heapsort_descending, 'o', label='Descending Data')
plt.plot(x_items, y_heapsort_random, 'o', label='Random Data')
plt.plot(x_items, nlogn_func(x_items, *popt_heapsort_asc), color='blue', linestyle='--', label=f'O(nlogn) Regression (R^2={r_squared_asc_hs})')
plt.plot(x_items, nlogn_func(x_items, *popt_heapsort_desc), color='orange', linestyle='--', label=f'O(nlogn) Regression (R^2={r_squared_desc_hs})')
plt.plot(x_items, nlogn_func(x_items, *popt_heapsort_random), color='green', linestyle='--', label=f'O(nlogn) Regression (R^2={r_squared_random_hs})')
plt.title('Heapsort')
plt.xlabel('Número de elementos')
plt.ylabel('Tempo (s)')
plt.legend()

# Plotting Insertion Sort
plt.figure(3)
plt.plot(x_items, y_insertionsort_ascending, 'o', label='Ascending Data')
plt.plot(x_items, y_insertionsort_descending, 'o', label='Descending Data')
plt.plot(x_items, y_insertionsort_random, 'o', label='Random Data')
plt.plot(x_items, linear_func(x_items, *popt_insertionsort_asc), color='blue', linestyle='--', label=f'O(n) Regression (R^2={r_squared_asc_is})')
plt.plot(x_items, quadratic_func(x_items, *popt_insertionsort_desc), color='orange', linestyle='--', label=f'O(n^2) Regression (R^2={r_squared_desc_is})')
plt.plot(x_items, quadratic_func(x_items, *popt_insertionsort_random), color='green', linestyle='--', label=f'O(n^2) Regression (R^2={r_squared_random_is})')
plt.title('Insertion Sort')
plt.xlabel('Número de elementos')
plt.ylabel('Tempo (s)')
plt.legend()

# Plotting Ascending Items
plt.figure(4)
plt.plot(x_items, y_insertionsort_ascending, 'o', label='Insertion Sort')
plt.plot(x_items, y_quicksort_ascending, 'o', label='Quicksort')
plt.plot(x_items, y_heapsort_ascending, 'o', label='Heapsort Data')
plt.plot(x_items, linear_func(x_items, *popt_insertionsort_asc), color='blue', linestyle="--", label=f'O(n) Regression (R^2={r_squared_asc_is})')
plt.plot(x_items, nlogn_func(x_items, *popt_heapsort_asc), color='green',linestyle="--", label=f'O(nlogn) Regression (R^2={r_squared_asc_hs})')
plt.plot(x_items, quadratic_func(x_items, *popt_quicksort_asc), color='orange',linestyle="--", label=f'O(n^2) Regression (R^2={r_squared_asc_qs})')
plt.title('Ascending Data')
plt.xlabel('Número de elementos')
plt.ylabel('Tempo (s)')
plt.legend()


# Plotting Descending Items
plt.figure(5)
plt.plot(x_items, y_insertionsort_descending, 'o', label='Insertion Sort')
plt.plot(x_items, y_quicksort_descending, 'o', label='Quicksort')
plt.plot(x_items, y_heapsort_descending, 'o', label='Heapsort Data')
plt.plot(x_items, quadratic_func(x_items, *popt_insertionsort_desc), color='blue', linestyle='--', label=f'O(n^2) Regression (R^2={r_squared_desc_is})')
plt.plot(x_items, nlogn_func(x_items, *popt_heapsort_desc), color='green', linestyle='--', label=f'O(nlogn) Regression (R^2={r_squared_desc_hs})')
plt.plot(x_items, nlogn_func(x_items, *popt_quicksort_desc), color='orange', linestyle='--', label=f'O(nlogn) Regression (R^2={r_squared_desc_qs})')
plt.title('Descending Data')
plt.xlabel('Número de elementos')
plt.ylabel('Tempo (s)')
plt.legend()

# Plotting Random Items
plt.figure(6)
plt.plot(x_items, y_insertionsort_random, 'o', label='Insertion Sort')
plt.plot(x_items, y_quicksort_random, 'o', label='Quicksort')
plt.plot(x_items, y_heapsort_random, 'o', label='Heapsort Data')
plt.plot(x_items, nlogn_func(x_items, *popt_quicksort_random), color='orange', linestyle='--', label=f'O(nlogn) Regression (R^2={r_squared_random_qs})')
plt.plot(x_items, quadratic_func(x_items, *popt_insertionsort_random), color='blue', linestyle='--', label=f'O(n^2) Regression (R^2={r_squared_random_is})')
plt.plot(x_items, nlogn_func(x_items, *popt_heapsort_random), color='green', linestyle='--', label=f'O(nlogn) Regression (R^2={r_squared_random_hs})')
plt.title('Random Data')
plt.xlabel('Número de elementos')
plt.ylabel('Tempo (s)')
plt.legend()

plt.show()
