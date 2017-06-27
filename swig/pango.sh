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
$swig -lua `pkg-config --cflags-only-I pango` swig_pango.i
gcc -fPIC `pkg-config --cflags pango $extra_pc` -c swig_pango_wrap.c -o swig_pango_wrap.o
gcc -shared `pkg-config --cflags --libs pango $extra_pc` swig_pango_wrap.o -o swig_pango.so
