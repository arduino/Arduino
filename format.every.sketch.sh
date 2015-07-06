# you need to have astyle installed before running this
find -name '*.ino' -exec /home/federico/materiale/works_Arduino/astyle/astyle-code/AStyle/build/gcc/bin/astyle --options=examples_formatter.conf {} \;
