#define PY_SSIZE_T_CLEAN  /* Make "s#" use Py_ssize_t rather than int. */
#include <Python.h>

//#include <datetime.h>
//PyDateTimeAPI = reinterpret_cast<PyDateTime_CAPI *>(PyCapsule_Import(PyDateTime_CAPSULE_NAME, 0));
//char* name_datetime_c_api = "datetime.datetime_CAPI";
PyCapsule_Import("datetime.datetime_CAPI", 0);


static PyObject *
dt_parse(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    if (sts < 0) {
        PyErr_SetString(PyExc_ValueError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

static PyMethodDef DtMethods[] = {
    {"parse",  dt_parse, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef dtmodule = {
    PyModuleDef_HEAD_INIT,
    "dt",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    DtMethods
};

PyMODINIT_FUNC
PyInit_dt(void)
{
    return PyModule_Create(&dtmodule);
}