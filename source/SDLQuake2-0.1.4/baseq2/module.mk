baseq2_SRC:=$(wildcard baseq2/*.c) m_flash.c q_shared.c
baseq2_OBJ:=$(baseq2_SRC:.c=.sh.o)

baseq2/game.so: CFLAGS+=-I.

baseq2/game.so: $(baseq2_OBJ)
	$(CC) -shared -g -o $@ $^

ALLOBJ+=$(baseq2_OBJ)
