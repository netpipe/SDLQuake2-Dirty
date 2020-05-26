CC:=gcc
CFLAGS:=-O3 -g -Wall $(shell sdl-config --cflags) -lm -lSDL -lSDL_sound -fPIC

GAMES:=baseq2

TARGETS:=quake2 q2ded ref_sdlgl.so $(foreach game, $(GAMES), $(game)/game.so)

.PHONY: default all clean distclean

default: all

all: $(TARGETS)

quake2_SRC:=cl_ents.c cl_fx.c cl_input.c cl_inv.c cl_main.c cl_newfx.c\
	    cl_parse.c cl_pred.c cl_scrn.c cl_tent.c cl_view.c cmd.c cmodel.c\
	    common.c console.c crc.c cvar.c files.c glob.c keys.c le_physics.c\
	    le_util.c md4.c menu.c m_flash.c mersennetwister.c net_chan.c\
	    net_udp.c pmove.c qmenu.c q_shared.c q_shlinux.c redblack.c\
	    snd_dma.c snd_mem.c snd_mix.c snd_openal.c snd_sdl.c sv_ccmds.c\
	    sv_ents.c sv_game.c sv_init.c sv_main.c sv_send.c sv_user.c\
	    sv_world.c sys_linux.c vid_menu.c vid_so.c
quake2_OBJ:=$(quake2_SRC:.c=.o)


sdlgl_SRC:=gl_draw.c gl_image.c gl_light.c gl_mesh.c gl_model.c gl_rmain.c\
	   gl_rmisc.c gl_rsurf.c gl_sdl.c gl_warp.c glob.c q_shared.c\
	   q_shlinux.c qgl_linux.c
sdlgl_OBJ:=$(sdlgl_SRC:.c=.sh.o)

q2ded_SRC:=cmd.c cmodel.c common.c crc.c cvar.c files.c md4.c net_chan.c\
	   mersennetwister.c redblack.c sv_ccmds.c sv_ents.c sv_game.c\
	   sv_init.c sv_main.c sv_send.c sv_user.c sv_world.c q_shlinux.c\
	   sys_linux.c glob.c net_udp.c q_shared.c pmove.c q2ded.c
q2ded_OBJ:=$(q2ded_SRC:.c=.o)

%.sh.o: %.c
	$(CC) -c -MF .depends/$*.sh.d -MMD -fPIC $(CFLAGS) -o $@ $<
	@sed "s@^\(.*\)\.o:@$(dir $*)\1.sh.o:@" < .depends/$*.sh.d > .depends/$*.sh.d.new
	@mv .depends/$*.sh.d.new .depends/$*.sh.d

%.o: %.c
	$(CC) -c -MF .depends/$*.d -MMD $(CFLAGS) -o $@ $<
	@sed "s@^\(.*\)\.o:@$(dir $*)\1.o:@" < .depends/$*.d > .depends/$*.d.new
	@mv .depends/$*.d.new .depends/$*.d


quake2: $(quake2_OBJ)
	$(CC) -g -o $@ $(shell sdl-config --libs) -lz -lm -ldl -lSDL $^

q2ded: $(q2ded_OBJ)
	$(CC) -g -o $@ $^ -lz -ldl -lm -lSDL

ref_sdlgl.so: $(sdlgl_OBJ)
	$(CC) -shared -g -o $@ $(shell sdl-config --libs) -lGL -ljpeg -lpng12 $^

ALLOBJ:=$(quake2_OBJ) $(sdlgl_OBJ)

include $(foreach game, $(GAMES), $(game)/module.mk)
DEPENDS:=$(foreach file, $(ALLOBJ:.o=.d), .depends/$(file))

clean:
	-rm -rf *.o $(TARGETS) $(foreach game, $(GAMES), $(game)/*.o)

distclean: clean
	-rm -rf $(DEPENDS)

-include $(DEPENDS)
