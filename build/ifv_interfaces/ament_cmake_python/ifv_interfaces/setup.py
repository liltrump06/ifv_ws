from setuptools import find_packages
from setuptools import setup

setup(
    name='ifv_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('ifv_interfaces', 'ifv_interfaces.*')),
)
