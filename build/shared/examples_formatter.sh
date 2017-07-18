# you need to have astyle installed before running this
find examples -name '*.ino' -exec astyle --options=examples_formatter.conf {} \;
