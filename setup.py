from setuptools import setup, Extension

dt_module = Extension("dt",
                      sources=["dtmodule.c"],
                      )
setup(
    name="dt",
    platforms=["win-amd64", 'win32'],
    license="GNU GPLv3",
    ext_modules=[dt_module],
)
