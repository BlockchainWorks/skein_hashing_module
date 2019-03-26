from distutils.core import setup, Extension

skein_hash_module = Extension('skein_hash',
                             sources=['skeinmodule.c',
                                      'skein.c',
                                      'sph/skein.c'],
                             include_dirs=['.', './sph'])

setup(name='skein_hash',
      version='1.0',
      description='Bindings for skein hashing algorithm',
      author='os',
      author_email='osnwt@github.com',
      url='https://github.com/BlockchainWorks/skein_hashing_module',
      ext_modules=[skein_hash_module])
