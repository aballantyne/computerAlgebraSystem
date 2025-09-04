# ----------------------------
# Makefile Options
# ----------------------------

NAME = COMPALGE
ICON = icon.png
DESCRIPTION = "Computer Algebra System"
COMPRESSED = NO

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------
SRC = main.cpp
include $(shell cedev-config --makefile)