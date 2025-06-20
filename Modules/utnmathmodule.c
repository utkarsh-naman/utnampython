#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* utnmath_is_even(PyObject* self, PyObject* args) {
    long num;
    if (!PyArg_ParseTuple(args, "l", &num)) {
        return NULL;
    }
    return PyBool_FromLong(!(num & 1));  // Returns True if even, False if odd
}

static PyObject* utnmath_is_odd(PyObject* self, PyObject* args) {
    long num;
    if (!PyArg_ParseTuple(args, "l", &num)) {
        return NULL;
    }
    return PyBool_FromLong(num & 1);  // Returns True if odd, False if even
}

static PyMethodDef UtnMathMethods[] = {
    {"is_even", utnmath_is_even, METH_VARARGS, "Check if a number is even using bitwise & operation"},
    {"is_odd", utnmath_is_odd, METH_VARARGS, "Check if a number is odd using bitwise & operation."},
    {NULL, NULL, 0, NULL}  // Sentinel
};

static struct PyModuleDef utnmathmodule = {
    PyModuleDef_HEAD_INIT,
    "utnmath",  // Module name
    "Custom math functions",  // Module docstring
    -1,
    UtnMathMethods
};

PyMODINIT_FUNC PyInit_utnmath(void) {
    return PyModule_Create(&utnmathmodule);
}
