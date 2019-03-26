// Skein module

#include <Python.h>

#include "skein.h"

static PyObject *skein_hash_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    char *input;
    unsigned int len;
    PyObject *value;

    if (!PyArg_ParseTuple(args, "y#", &input, &len))
        return NULL;
    output = PyMem_Malloc(32);

    skein_hash(input, output, len);

#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif

    PyMem_Free(output);
    return value;
}

static PyMethodDef SkeinMethods[] = {
    { "getPoWHash", skein_hash_getpowhash, METH_VARARGS, "Returns the proof of work hash using skein hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef SkeinModule = {
    PyModuleDef_HEAD_INIT,
    "skein_hash",
    "...",
    -1,
    SkeinMethods
};

PyMODINIT_FUNC PyInit_skein_hash(void) {
    return PyModule_Create(&SkeinModule);
}

#else

PyMODINIT_FUNC initskein_hash(void) {
    (void) Py_InitModule("skein_hash", SkeinMethods);
}
#endif
