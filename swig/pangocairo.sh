uname=`uname`
extra_pc=
if [ "$uname" = "Darwin" ]; then
        swig=swig
        extra_pc=lua5.3
elif [ "$uname" = "NetBSD" ]; then
        swig=swig3.0
else
        swig=swig3.0
fi
$swig -lua `pkg-config --cflags-only-I pangocairo` swig_pangocairo.i
gcc -fPIC `pkg-config --cflags pangocairo $extra_pc` -c swig_pangocairo_wrap.c -o swig_pangocairo_wrap.o
gcc -shared `pkg-config --cflags --libs pangocairo $extra_pc` swig_pangocairo_wrap.o -o swig_pangocairo.so
