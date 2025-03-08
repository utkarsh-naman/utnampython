#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <math.h>

// Function to check if a number is a palindrome
static PyObject* numbers_is_palindrome(PyObject* self, PyObject* args) {
    long n, reversed = 0, original, remainder;
    if (!PyArg_ParseTuple(args, "l", &n))
        return NULL;

    original = n;
    while (n > 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (original == reversed)
        Py_RETURN_TRUE;
    else
        Py_RETURN_FALSE;
}

// Function to check if a number is an Armstrong number
static PyObject* numbers_is_armstrong(PyObject* self, PyObject* args) {
    long n;
    if (!PyArg_ParseTuple(args, "l", &n))
        return NULL;

    if (n < 0) {
        Py_RETURN_FALSE;  // Negative numbers cannot be Armstrong numbers
    }

    long original = n;
    int count = 0;
    long temp = original;
    unsigned long long sum = 0;

    // Count the number of digits
    while (temp != 0) {
        temp /= 10;
        count++;
    }

    temp = original;
    while (temp != 0) {
        int digit = temp % 10;
        sum += (unsigned long long)pow(digit, count);  // Compute digit^count directly
        temp /= 10;
    }

    if (sum == (unsigned long long)original) {
        Py_RETURN_TRUE;
    }
    else {
        Py_RETURN_FALSE;
    }
}

// Function to check if a number is a Perfect Number
static PyObject* numbers_is_perfect(PyObject* self, PyObject* args) {
    long n;
    if (!PyArg_ParseTuple(args, "l", &n)) {
        return NULL;
    }

    if (n < 2) {
        Py_RETURN_FALSE;  // 1 and negatives are not perfect numbers
    }

    long sum = 1;  // 1 is always a divisor
    long sqrt_n = sqrt(n);

    for (long i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {  // Avoid adding the square root twice
                sum += n / i;
            }
        }
    }

    if (sum == n) {
        Py_RETURN_TRUE;
    }
    else {
        Py_RETURN_FALSE;
    }
}



// Helper function to compute sum of proper divisors
long sum_of_divisors(long n) {
    if (n < 2) return 0;  // No amicable pairs exist for n < 2

    long sum = 1;  // 1 is always a divisor
    long sqrt_n = sqrt(n);

    for (long i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {  // Avoid adding square root twice
                sum += n / i;
            }
        }
    }
    return sum;
}

// Function to check if two numbers are amicable
static PyObject* numbers_is_amicable(PyObject* self, PyObject* args) {
    long a, b;
    if (!PyArg_ParseTuple(args, "ll", &a, &b)) {
        return NULL;
    }

    if (a <= 0 || b <= 0 || a == b) {
        Py_RETURN_FALSE;  // Amicable numbers must be distinct positive numbers
    }

    long sum_a = sum_of_divisors(a);
    long sum_b = sum_of_divisors(b);

    if (sum_a == b && sum_b == a) {
        Py_RETURN_TRUE;
    }
    else {
        Py_RETURN_FALSE;
    }
}


// Function to check if a number is a Harshad Number
static PyObject* numbers_is_harshad(PyObject* self, PyObject* args) {
    long n;
    if (!PyArg_ParseTuple(args, "l", &n))
        return NULL;

    if (n <= 0) {
        Py_RETURN_FALSE;  // Harshad numbers must be positive
    }

    long sum_digits = 0, temp = n;

    // Calculate the sum of digits
    while (temp > 0) {
        sum_digits += temp % 10;
        temp /= 10;
    }

    // Check divisibility
    if (n % sum_digits == 0) {
        Py_RETURN_TRUE;
    }
    else {
        Py_RETURN_FALSE;
    }
}


// Function to check if a number is an Evil Number
static PyObject* numbers_is_evil(PyObject* self, PyObject* args) {
    long n;
    if (!PyArg_ParseTuple(args, "l", &n))
        return NULL;

    if (n < 0) {
        Py_RETURN_FALSE;  // Negative numbers are not considered
    }

    int count = 0;
    long temp = n;

    // Count the number of 1s in the binary representation
    while (temp > 0) {
        count += (temp & 1);
        temp >>= 1;
    }

    // Check if the count is even
    if (count % 2 == 0) {
        Py_RETURN_TRUE;
    }
    else {
        Py_RETURN_FALSE;
    }
}

// Function to check if a number is an Automorphic Number
static PyObject* numbers_is_automorphic(PyObject* self, PyObject* args) {
    long n;
    if (!PyArg_ParseTuple(args, "l", &n))
        return NULL;

    if (n < 0) {
        Py_RETURN_FALSE;  // Negative numbers cannot be Automorphic
    }

    long square = n * n;
    long temp = n;

    // Check if the last digits of square match n
    while (temp > 0) {
        if (square % 10 != temp % 10) {
            Py_RETURN_FALSE;
        }
        square /= 10;
        temp /= 10;
    }

    Py_RETURN_TRUE;
}

// Method table for Numbers submodule
static PyMethodDef NumbersMethods[] = {
    {"is_palindrome", numbers_is_palindrome, METH_VARARGS, "Check if a number is a palindrome"},
    {"is_armstrong", numbers_is_armstrong, METH_VARARGS, "Check if a number is an Armstrong number"},
    {"is_perfect", numbers_is_perfect, METH_VARARGS, "Check if a number is an Perfect number"},
    {"is_amicable", numbers_is_amicable, METH_VARARGS, "Check if two numbers are Amicable Numbers"},
    {"is_harshad", numbers_is_harshad, METH_VARARGS, "Check if a number is a Harshad Number"},
    {"is_evil", numbers_is_evil, METH_VARARGS, "Check if a number is an Evil Number"},
    {"is_automorphic", numbers_is_automorphic, METH_VARARGS, "Check if a number is an Automorphic Number"},
    {NULL, NULL, 0, NULL} // Sentinel
};

// Define the Numbers submodule
static struct PyModuleDef numbersmodule = {
    PyModuleDef_HEAD_INIT,
    "Numbers",  // Submodule name
    "Submodule containing number-related functions",
    -1,
    NumbersMethods
};

// Initialization function for the submodule
PyMODINIT_FUNC PyInit_Numbers(void) {
    return PyModule_Create(&numbersmodule);
}
