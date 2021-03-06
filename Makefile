#############################################################################
# Makefile for building: HelloWorld
# Generated by qmake (2.01a) (Qt 4.8.1) on: Tue Dec 9 15:36:43 2014
# Project:  HelloWorld.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile HelloWorld.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Ilib -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = addresswindow.cpp \
		ccnumwindow.cpp \
		chargewindow.cpp \
		errorwindow.cpp \
		functions.cpp \
		loginwindow.cpp \
		main.cpp \
		md5.cpp \
		modratewindow.cpp \
		movie.cpp \
		movieinfo.cpp \
		netflix.cpp \
		newuserwindow.cpp \
		passwordwindow.cpp \
		ratewindow.cpp \
		searchresults.cpp \
		searchwindow.cpp \
		settingswindow.cpp \
		user.cpp \
		viewratingswindow.cpp \
		lib/emptyqueue.cpp \
		lib/nosuch.cpp moc_addresswindow.cpp \
		moc_ccnumwindow.cpp \
		moc_chargewindow.cpp \
		moc_errorwindow.cpp \
		moc_loginwindow.cpp \
		moc_modratewindow.cpp \
		moc_movieinfo.cpp \
		moc_newuserwindow.cpp \
		moc_passwordwindow.cpp \
		moc_ratewindow.cpp \
		moc_searchresults.cpp \
		moc_searchwindow.cpp \
		moc_settingswindow.cpp \
		moc_viewratingswindow.cpp
OBJECTS       = addresswindow.o \
		ccnumwindow.o \
		chargewindow.o \
		errorwindow.o \
		functions.o \
		loginwindow.o \
		main.o \
		md5.o \
		modratewindow.o \
		movie.o \
		movieinfo.o \
		netflix.o \
		newuserwindow.o \
		passwordwindow.o \
		ratewindow.o \
		searchresults.o \
		searchwindow.o \
		settingswindow.o \
		user.o \
		viewratingswindow.o \
		emptyqueue.o \
		nosuch.o \
		moc_addresswindow.o \
		moc_ccnumwindow.o \
		moc_chargewindow.o \
		moc_errorwindow.o \
		moc_loginwindow.o \
		moc_modratewindow.o \
		moc_movieinfo.o \
		moc_newuserwindow.o \
		moc_passwordwindow.o \
		moc_ratewindow.o \
		moc_searchresults.o \
		moc_searchwindow.o \
		moc_settingswindow.o \
		moc_viewratingswindow.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		HelloWorld.pro
QMAKE_TARGET  = HelloWorld
DESTDIR       = 
TARGET        = HelloWorld

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: HelloWorld.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile HelloWorld.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile HelloWorld.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/HelloWorld1.0.0 || $(MKDIR) .tmp/HelloWorld1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/HelloWorld1.0.0/ && $(COPY_FILE) --parents addresswindow.h ccnumwindow.h chargewindow.h errorwindow.h loginwindow.h md5.h modratewindow.h movie.h movieImpl.h movieinfo.h netflix.h newuserwindow.h passwordwindow.h queue.h queueImpl.h ratewindow.h searchresults.h searchwindow.h settingswindow.h user.h viewratingswindow.h lib/emptyqueue.h lib/mergesort.h lib/nosuch.h lib/projmap.h lib/projmapImpl.h lib/projset.h lib/projsetImpl.h lib/queue.h lib/queueImpl.h .tmp/HelloWorld1.0.0/ && $(COPY_FILE) --parents addresswindow.cpp ccnumwindow.cpp chargewindow.cpp errorwindow.cpp functions.cpp loginwindow.cpp main.cpp md5.cpp modratewindow.cpp movie.cpp movieinfo.cpp netflix.cpp newuserwindow.cpp passwordwindow.cpp ratewindow.cpp searchresults.cpp searchwindow.cpp settingswindow.cpp user.cpp viewratingswindow.cpp lib/emptyqueue.cpp lib/nosuch.cpp .tmp/HelloWorld1.0.0/ && (cd `dirname .tmp/HelloWorld1.0.0` && $(TAR) HelloWorld1.0.0.tar HelloWorld1.0.0 && $(COMPRESS) HelloWorld1.0.0.tar) && $(MOVE) `dirname .tmp/HelloWorld1.0.0`/HelloWorld1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/HelloWorld1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_addresswindow.cpp moc_ccnumwindow.cpp moc_chargewindow.cpp moc_errorwindow.cpp moc_loginwindow.cpp moc_modratewindow.cpp moc_movieinfo.cpp moc_newuserwindow.cpp moc_passwordwindow.cpp moc_ratewindow.cpp moc_searchresults.cpp moc_searchwindow.cpp moc_settingswindow.cpp moc_viewratingswindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_addresswindow.cpp moc_ccnumwindow.cpp moc_chargewindow.cpp moc_errorwindow.cpp moc_loginwindow.cpp moc_modratewindow.cpp moc_movieinfo.cpp moc_newuserwindow.cpp moc_passwordwindow.cpp moc_ratewindow.cpp moc_searchresults.cpp moc_searchwindow.cpp moc_settingswindow.cpp moc_viewratingswindow.cpp
moc_addresswindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		addresswindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) addresswindow.h -o moc_addresswindow.cpp

moc_ccnumwindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		ccnumwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ccnumwindow.h -o moc_ccnumwindow.cpp

moc_chargewindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		modratewindow.h \
		searchwindow.h \
		ratewindow.h \
		searchresults.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		newuserwindow.h \
		errorwindow.h \
		chargewindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) chargewindow.h -o moc_chargewindow.cpp

moc_errorwindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		errorwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) errorwindow.h -o moc_errorwindow.cpp

moc_loginwindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		loginwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) loginwindow.h -o moc_loginwindow.cpp

moc_modratewindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		modratewindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) modratewindow.h -o moc_modratewindow.cpp

moc_movieinfo.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		movieinfo.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) movieinfo.h -o moc_movieinfo.cpp

moc_newuserwindow.cpp: user.h \
		movie.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/nosuch.h \
		lib/projsetImpl.h \
		searchwindow.h \
		netflix.h \
		md5.h \
		modratewindow.h \
		newuserwindow.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		newuserwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) newuserwindow.h -o moc_newuserwindow.cpp

moc_passwordwindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		passwordwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) passwordwindow.h -o moc_passwordwindow.cpp

moc_ratewindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		ratewindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) ratewindow.h -o moc_ratewindow.cpp

moc_searchresults.cpp: user.h \
		movie.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/nosuch.h \
		lib/projsetImpl.h \
		searchwindow.h \
		netflix.h \
		md5.h \
		modratewindow.h \
		newuserwindow.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		searchresults.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) searchresults.h -o moc_searchresults.cpp

moc_searchwindow.cpp: movie.h \
		user.h \
		netflix.h \
		lib/nosuch.h \
		md5.h \
		modratewindow.h \
		searchwindow.h \
		ratewindow.h \
		searchresults.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		newuserwindow.h \
		errorwindow.h \
		searchwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) searchwindow.h -o moc_searchwindow.cpp

moc_settingswindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		addresswindow.h \
		ccnumwindow.h \
		passwordwindow.h \
		settingswindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) settingswindow.h -o moc_settingswindow.cpp

moc_viewratingswindow.cpp: netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		modratewindow.h \
		searchwindow.h \
		ratewindow.h \
		searchresults.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		newuserwindow.h \
		errorwindow.h \
		viewratingswindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) viewratingswindow.h -o moc_viewratingswindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

addresswindow.o: addresswindow.cpp addresswindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o addresswindow.o addresswindow.cpp

ccnumwindow.o: ccnumwindow.cpp ccnumwindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ccnumwindow.o ccnumwindow.cpp

chargewindow.o: chargewindow.cpp chargewindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		modratewindow.h \
		searchwindow.h \
		ratewindow.h \
		searchresults.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		movieinfo.h \
		viewratingswindow.h \
		newuserwindow.h \
		errorwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o chargewindow.o chargewindow.cpp

errorwindow.o: errorwindow.cpp errorwindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o errorwindow.o errorwindow.cpp

functions.o: functions.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o functions.o functions.cpp

loginwindow.o: loginwindow.cpp loginwindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o loginwindow.o loginwindow.cpp

main.o: main.cpp netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		loginwindow.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

md5.o: md5.cpp md5.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o md5.o md5.cpp

modratewindow.o: modratewindow.cpp modratewindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		ratewindow.h \
		searchresults.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		newuserwindow.h \
		errorwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o modratewindow.o modratewindow.cpp

movie.o: movie.cpp movie.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o movie.o movie.cpp

movieinfo.o: movieinfo.cpp movie.h \
		movieinfo.h \
		netflix.h \
		user.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		viewratingswindow.h \
		chargewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o movieinfo.o movieinfo.cpp

netflix.o: netflix.cpp netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o netflix.o netflix.cpp

newuserwindow.o: newuserwindow.cpp newuserwindow.h \
		user.h \
		movie.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/nosuch.h \
		lib/projsetImpl.h \
		searchwindow.h \
		netflix.h \
		md5.h \
		modratewindow.h \
		ratewindow.h \
		errorwindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o newuserwindow.o newuserwindow.cpp

passwordwindow.o: passwordwindow.cpp passwordwindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o passwordwindow.o passwordwindow.cpp

ratewindow.o: ratewindow.cpp ratewindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ratewindow.o ratewindow.cpp

searchresults.o: searchresults.cpp searchresults.h \
		user.h \
		movie.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/nosuch.h \
		lib/projsetImpl.h \
		searchwindow.h \
		netflix.h \
		md5.h \
		modratewindow.h \
		newuserwindow.h \
		errorwindow.h \
		ratewindow.h \
		viewratingswindow.h \
		chargewindow.h \
		movieinfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o searchresults.o searchresults.cpp

searchwindow.o: searchwindow.cpp searchwindow.h \
		movie.h \
		user.h \
		netflix.h \
		lib/nosuch.h \
		md5.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o searchwindow.o searchwindow.cpp

settingswindow.o: settingswindow.cpp settingswindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		searchwindow.h \
		modratewindow.h \
		newuserwindow.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		errorwindow.h \
		ratewindow.h \
		searchresults.h \
		movieinfo.h \
		viewratingswindow.h \
		chargewindow.h \
		addresswindow.h \
		ccnumwindow.h \
		passwordwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settingswindow.o settingswindow.cpp

user.o: user.cpp user.h \
		movie.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o user.o user.cpp

viewratingswindow.o: viewratingswindow.cpp viewratingswindow.h \
		netflix.h \
		user.h \
		movie.h \
		lib/nosuch.h \
		md5.h \
		modratewindow.h \
		searchwindow.h \
		ratewindow.h \
		searchresults.h \
		lib/projset.h \
		lib/projmap.h \
		lib/projmapImpl.h \
		lib/projsetImpl.h \
		movieinfo.h \
		chargewindow.h \
		newuserwindow.h \
		errorwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o viewratingswindow.o viewratingswindow.cpp

emptyqueue.o: lib/emptyqueue.cpp lib/emptyqueue.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o emptyqueue.o lib/emptyqueue.cpp

nosuch.o: lib/nosuch.cpp lib/nosuch.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o nosuch.o lib/nosuch.cpp

moc_addresswindow.o: moc_addresswindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_addresswindow.o moc_addresswindow.cpp

moc_ccnumwindow.o: moc_ccnumwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ccnumwindow.o moc_ccnumwindow.cpp

moc_chargewindow.o: moc_chargewindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_chargewindow.o moc_chargewindow.cpp

moc_errorwindow.o: moc_errorwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_errorwindow.o moc_errorwindow.cpp

moc_loginwindow.o: moc_loginwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_loginwindow.o moc_loginwindow.cpp

moc_modratewindow.o: moc_modratewindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_modratewindow.o moc_modratewindow.cpp

moc_movieinfo.o: moc_movieinfo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_movieinfo.o moc_movieinfo.cpp

moc_newuserwindow.o: moc_newuserwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_newuserwindow.o moc_newuserwindow.cpp

moc_passwordwindow.o: moc_passwordwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_passwordwindow.o moc_passwordwindow.cpp

moc_ratewindow.o: moc_ratewindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ratewindow.o moc_ratewindow.cpp

moc_searchresults.o: moc_searchresults.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_searchresults.o moc_searchresults.cpp

moc_searchwindow.o: moc_searchwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_searchwindow.o moc_searchwindow.cpp

moc_settingswindow.o: moc_settingswindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_settingswindow.o moc_settingswindow.cpp

moc_viewratingswindow.o: moc_viewratingswindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_viewratingswindow.o moc_viewratingswindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

