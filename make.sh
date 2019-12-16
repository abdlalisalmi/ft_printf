#!/bin/sh
make
rm -rf *.o
cp libftprintf.a ../
cp libftprintf.a ../tester/
cp ft_printf.h ../tester/
cp libftprintf.a ../Thala/


