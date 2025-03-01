#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* is_prime(PyObject* self, PyObject* args) {
    int n, i;
    if (!PyArg_ParseTuple(args, "i", &n))
        return NULL;

    if (n < 2)
        Py_RETURN_FALSE;
    else if (n <= 3)
        Py_RETURN_TRUE;
    else if (n % 2 == 0 || n % 3 == 0)
        Py_RETURN_FALSE;
    for (i = 5; i * i <= n; i+=6) {
        if (n % i == 0 || n % (i+2) == 0 )
            Py_RETURN_FALSE;
    }

    Py_RETURN_TRUE;
}

// Method definitions
static PyMethodDef UtnAlgoMethods[] = {
    {"is_prime", is_prime, METH_VARARGS, "Check if a number is prime"},
    {NULL, NULL, 0, NULL}  // Sentinel
};

// Module definition
static struct PyModuleDef utnalgocmodule = {
    PyModuleDef_HEAD_INIT,
    "utnalgo",  // Module name
    "C extension for utnalgo",
    -1,
    UtnAlgoMethods
};

// Module initialization function
PyMODINIT_FUNC PyInit_utnalgo_c(void) {
    return PyModule_Create(&utnalgocmodule);
}
