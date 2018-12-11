## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = mygym

mygym_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	login.c login.h \
	admin.c admin.h \
	kine.c kine.h \
	rdv.c rdv.h \
	treeview_admin.c treeview_admin.h \
	treeview_login.c treeview_login.h \
	nutri.c nutri.h

mygym_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)
