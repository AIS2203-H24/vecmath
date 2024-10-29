import os
import subprocess
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

WINDOWS = (os.name == 'nt')

buildFolder = "build"


def version():
    return "0.1.0"


class CMakeExtension(Extension):

    def __init__(self):
        super().__init__(
            name="pyvecmath",
            sources=[

            ],
            library_dirs=["build/bin"],
            libraries=["vecmathc"])


class CMakeBuild(build_ext):

    def run(self):
        for ext in self.extensions:
            self.build_extension(ext)
        super().run()

    def build_extension(self, ext):

        build_type = 'Release'
        # configure
        cmake_args = [
            'cmake',
            '..',
            '-B',
            buildFolder,
            '-DCMAKE_BUILD_TYPE={}'.format(build_type),
        ]
        if WINDOWS:
            cmake_args.extend(['-A', 'x64'])

        subprocess.check_call(cmake_args)
        cmake_args_build = [
            'cmake',
            '--build',
            buildFolder
        ]
        if WINDOWS:
            cmake_args_build.extend(['--config', 'Release'])
        subprocess.check_call(cmake_args_build)


def binary_suffix():
    return ".exe" if WINDOWS else ""


setup(name="pyvecmath",
      version=version(),
      description="A linear algebra library",
      url="",
      author="Lars Ivar Hatledal",
      license="MIT",
      include_package_data=True,
      packages=['pyvecmath'],
      package_dir={'pyvecmath': '.'},
      data_files=[],
      ext_modules=[CMakeExtension()],
      cmdclass=dict(build_ext=CMakeBuild),
      )
