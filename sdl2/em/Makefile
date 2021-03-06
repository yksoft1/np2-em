# makefile for emscripten
#   gcc version 4

CC		=	emcc
RM		=	rm -f

ifeq ($(EMSCRIPTEN_ROOT),)
#Set it yourself if EMSCRIPTEN_ROOT not there
	EMSCRIPTEN_ROOT=c:/emsdk/emscripten/1.38.12
endif

#WebAssembly seemed to be a bit faster than asm.js
WASM=1

#Set maximum RAM that Emscripten use (in bytes).
EMSCRIPTEN_TOTAL_MEMORY=67108864

SDL_CONFIG ?= $(EMSCRIPTEN_ROOT)/system/bin/sdl2-config 
SDL_CFLAGS := $(shell $(SDL_CONFIG) --cflags) 
SDL_LIBS := $(shell $(SDL_CONFIG) --libs)

NP2_PATH	= ../..

CFLAGS	=	-O3 -Wstrict-overflow=0 -Wstrict-aliasing=0 -I. -I.. \
			-I$(NP2_PATH) \
			-I$(NP2_PATH)/cbus \
			-I$(NP2_PATH)/common \
			-I$(NP2_PATH)/embed \
			-I$(NP2_PATH)/embed/menu \
			-I$(NP2_PATH)/embed/menubase \
			-I$(NP2_PATH)/generic \
			-I$(NP2_PATH)/i286c \
			-I$(NP2_PATH)/io \
			-I$(NP2_PATH)/mem \
			-I$(NP2_PATH)/sound \
			-I$(NP2_PATH)/vram \
			-I$(NP2_PATH)/zlib 

CFLAGS	+=	$(SDL_CFLAGS)
LFLAGS	= 	 

TARGET	=	np2.bc

CPPSRCS	=	./main.c \
			$(NP2_PATH)/calendar.c \
			$(NP2_PATH)/debugsub.c \
			$(NP2_PATH)/keystat.c \
			$(NP2_PATH)/nevent.c \
			$(NP2_PATH)/pccore.c \
			$(NP2_PATH)/statsave.c \
			$(NP2_PATH)/timing.c \
			$(wildcard $(NP2_PATH)/bios/*.c) \
			$(wildcard $(NP2_PATH)/cbus/*.c) \
			$(wildcard $(NP2_PATH)/codecnv/*.c) \
			$(wildcard $(NP2_PATH)/common/*.c) \
			$(wildcard $(NP2_PATH)/embed/*.c) \
			$(wildcard $(NP2_PATH)/embed/menu/*.c) \
			$(wildcard $(NP2_PATH)/embed/menubase/*.c) \
			$(wildcard $(NP2_PATH)/fdd/*.c) \
			$(wildcard $(NP2_PATH)/font/*.c) \
			$(wildcard $(NP2_PATH)/generic/*.c) \
			$(wildcard $(NP2_PATH)/i286c/*.c) \
			$(wildcard $(NP2_PATH)/io/*.c) \
			$(wildcard $(NP2_PATH)/lio/*.c) \
			$(wildcard $(NP2_PATH)/mem/*.c) \
			$(wildcard $(NP2_PATH)/sdl2/*.c) \
			$(wildcard $(NP2_PATH)/sdl2/*.cpp) \
			$(wildcard $(NP2_PATH)/sound/*.c) \
			$(wildcard $(NP2_PATH)/sound/getsnd/*.c) \
			$(wildcard $(NP2_PATH)/sound/vermouth/*.c) \
			$(wildcard $(NP2_PATH)/vram/*.c) \
			$(wildcard $(NP2_PATH)/zlib/*.c)
			
OBJS = $(addsuffix .o,$(basename $(CPPSRCS)))
LIBS = -lm  $(SDL_LIBS) 

.SUFFIXES: .c.o
.SUFFIXES: .cpp.o

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) $(LFLAGS) -g -o $@ $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

.cpp.o:
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJS)

html: $(TARGET)
ifeq ($(PRELOAD), 1)
	$(CC) -O3 -s USE_SDL=2 -s WASM=$(WASM) -s TOTAL_MEMORY=$(EMSCRIPTEN_TOTAL_MEMORY)  -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1 \
	-s EMTERPRETIFY_WHITELIST=@em.txt $(TARGET) \
	--preload-file $(PREFILE) -o $(basename $(TARGET)).html 
else
	$(CC) -O3 -s USE_SDL=2 -s WASM=$(WASM) -s TOTAL_MEMORY=$(EMSCRIPTEN_TOTAL_MEMORY)  -s EMTERPRETIFY=1 -s EMTERPRETIFY_ASYNC=1 \
	-s EMTERPRETIFY_WHITELIST=@em.txt $(TARGET) -o $(basename $(TARGET)).html 
endif
