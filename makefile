# ----------------------------
# Makefile Options
# ----------------------------

NAME = CASYS
ICON = icon.png
DESCRIPTION = "Computer Algebra System"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz
HAS_PRINTF = NO
# ----------------------------
SRC = main.cpp
include $(shell cedev-config --makefile)