CC	  = gcc #Compiler

CFLAGS    = -I tools/include/SOIL/src#
CFLAGS   += -I tools/include#
CFLAGS   += -I headers#
CFLAGS   += -Wall#
CFLAGS   += -Werror#
CFLAGS   += -Wextra#
CFLAGS   += -w#
CFLAGS   += -c#
CFLAGS   += -std=c++11#
CFLAGS   += -fpermissive#

LDFLAGS   =  -I tools/include/SOIL/src#
LDFLAGS  += tools/src/libglfw3.a#
LDFLAGS	 += -rdynamic#
LDFLAGS  += -lSOIL#
LDFLAGS  += -lGLEW#
LDFLAGS  += -lrt#
LDFLAGS  += -lm#
LDFLAGS  += -lX11#
LDFLAGS  += -lpthread#
LDFLAGS  += -lXrandr#
LDFLAGS  += -lXinerama#
LDFLAGS  += -lXi#
LDFLAGS  += -lXxf86vm#
LDFLAGS  += -lXcursor#
LDFLAGS  += -lGL#
LDFLAGS  += -ldl#

# Main
SOURCES   = sources/main.cpp#

# Functions
SOURCES  += sources/keyCallback.cpp#
SOURCES  += sources/GL.cpp#
SOURCES  += sources/GLEW.cpp#
SOURCES  += sources/GLFW.cpp#

# Classes
SOURCES  += sources/AI.cpp#
SOURCES  += sources/AIMap.cpp#
# SOURCES  += sources/Ball.cpp#
SOURCES  += sources/Cam.cpp#
SOURCES  += sources/Game.cpp#
SOURCES  += sources/GameState.cpp#
SOURCES  += sources/Ghost.cpp#
SOURCES  += sources/Graphics.cpp#
SOURCES  += sources/Map.cpp#
SOURCES  += sources/Object.cpp#
SOURCES  += sources/Player.cpp#
SOURCES  += sources/Settings.cpp#
SOURCES  += sources/Shader.cpp#
SOURCES  += sources/Texture.cpp#
SOURCES  += sources/Window.cpp#

OOBJECTS  = $(SOURCES:.cpp=.o)#Object files
OBJECTS = $(OOBJECTS:sources/=objects/)

EXECUTEABLE= a.out #Output name

all: $(SOURCES) $(EXECUTEABLE)

$(EXECUTEABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $(EXECUTEABLE)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:  ; rm $(OBJECTS) $(EXECUTEABLE)

run:	; ./$(EXECUTEABLE)
