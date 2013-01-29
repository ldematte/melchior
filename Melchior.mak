# Microsoft Developer Studio Generated NMAKE File, Based on Melchior.dsp
!IF "$(CFG)" == ""
CFG=Melchior - Win32 Debug
!MESSAGE No configuration specified. Defaulting to Melchior - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Melchior - Win32 Release" && "$(CFG)" != "Melchior - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Melchior.mak" CFG="Melchior - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Melchior - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Melchior - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Melchior - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\Melchior.exe"


CLEAN :
	-@erase "$(INTDIR)\Icmp.obj"
	-@erase "$(INTDIR)\IcmpPacket.obj"
	-@erase "$(INTDIR)\IPPacket.obj"
	-@erase "$(INTDIR)\melchior.obj"
	-@erase "$(INTDIR)\melchior.res"
	-@erase "$(INTDIR)\Reactor.obj"
	-@erase "$(INTDIR)\Scheduler.obj"
	-@erase "$(INTDIR)\TCP.obj"
	-@erase "$(INTDIR)\TCPPacket.obj"
	-@erase "$(INTDIR)\UDP.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\Melchior.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /ML /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\Melchior.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x410 /fo"$(INTDIR)\melchior.res" /d "NDEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Melchior.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\Melchior.pdb" /machine:I386 /out:"$(OUTDIR)\Melchior.exe" 
LINK32_OBJS= \
	"$(INTDIR)\Icmp.obj" \
	"$(INTDIR)\IcmpPacket.obj" \
	"$(INTDIR)\IPPacket.obj" \
	"$(INTDIR)\melchior.obj" \
	"$(INTDIR)\Reactor.obj" \
	"$(INTDIR)\TCP.obj" \
	"$(INTDIR)\TCPPacket.obj" \
	"$(INTDIR)\UDP.obj" \
	"$(INTDIR)\melchior.res" \
	"$(INTDIR)\Scheduler.obj"

"$(OUTDIR)\Melchior.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\Melchior.exe" "$(OUTDIR)\Melchior.bsc"


CLEAN :
	-@erase "$(INTDIR)\Icmp.obj"
	-@erase "$(INTDIR)\Icmp.sbr"
	-@erase "$(INTDIR)\IcmpPacket.obj"
	-@erase "$(INTDIR)\IcmpPacket.sbr"
	-@erase "$(INTDIR)\IPPacket.obj"
	-@erase "$(INTDIR)\IPPacket.sbr"
	-@erase "$(INTDIR)\melchior.obj"
	-@erase "$(INTDIR)\melchior.res"
	-@erase "$(INTDIR)\melchior.sbr"
	-@erase "$(INTDIR)\Reactor.obj"
	-@erase "$(INTDIR)\Reactor.sbr"
	-@erase "$(INTDIR)\Scheduler.obj"
	-@erase "$(INTDIR)\Scheduler.sbr"
	-@erase "$(INTDIR)\TCP.obj"
	-@erase "$(INTDIR)\TCP.sbr"
	-@erase "$(INTDIR)\TCPPacket.obj"
	-@erase "$(INTDIR)\TCPPacket.sbr"
	-@erase "$(INTDIR)\UDP.obj"
	-@erase "$(INTDIR)\UDP.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vc60.pdb"
	-@erase "$(OUTDIR)\Melchior.bsc"
	-@erase "$(OUTDIR)\Melchior.exe"
	-@erase "$(OUTDIR)\Melchior.ilk"
	-@erase "$(OUTDIR)\Melchior.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MLd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\Melchior.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /GZ /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC_PROJ=/l 0x410 /fo"$(INTDIR)\melchior.res" /d "_DEBUG" 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\Melchior.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\Icmp.sbr" \
	"$(INTDIR)\IcmpPacket.sbr" \
	"$(INTDIR)\IPPacket.sbr" \
	"$(INTDIR)\melchior.sbr" \
	"$(INTDIR)\Reactor.sbr" \
	"$(INTDIR)\TCP.sbr" \
	"$(INTDIR)\TCPPacket.sbr" \
	"$(INTDIR)\UDP.sbr" \
	"$(INTDIR)\Scheduler.sbr"

"$(OUTDIR)\Melchior.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ws2_32.lib BugsLayerutil.lib /nologo /subsystem:windows /incremental:yes /pdb:"$(OUTDIR)\Melchior.pdb" /debug /machine:I386 /out:"$(OUTDIR)\Melchior.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\Icmp.obj" \
	"$(INTDIR)\IcmpPacket.obj" \
	"$(INTDIR)\IPPacket.obj" \
	"$(INTDIR)\melchior.obj" \
	"$(INTDIR)\Reactor.obj" \
	"$(INTDIR)\TCP.obj" \
	"$(INTDIR)\TCPPacket.obj" \
	"$(INTDIR)\UDP.obj" \
	"$(INTDIR)\melchior.res" \
	"$(INTDIR)\Scheduler.obj"

"$(OUTDIR)\Melchior.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("Melchior.dep")
!INCLUDE "Melchior.dep"
!ELSE 
!MESSAGE Warning: cannot find "Melchior.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "Melchior - Win32 Release" || "$(CFG)" == "Melchior - Win32 Debug"
SOURCE=.\Icmp.cpp

!IF  "$(CFG)" == "Melchior - Win32 Release"


"$(INTDIR)\Icmp.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"


"$(INTDIR)\Icmp.obj"	"$(INTDIR)\Icmp.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\IcmpPacket.cpp

!IF  "$(CFG)" == "Melchior - Win32 Release"


"$(INTDIR)\IcmpPacket.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"


"$(INTDIR)\IcmpPacket.obj"	"$(INTDIR)\IcmpPacket.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\IPPacket.cpp

!IF  "$(CFG)" == "Melchior - Win32 Release"


"$(INTDIR)\IPPacket.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"


"$(INTDIR)\IPPacket.obj"	"$(INTDIR)\IPPacket.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\melchior.cpp

!IF  "$(CFG)" == "Melchior - Win32 Release"


"$(INTDIR)\melchior.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"


"$(INTDIR)\melchior.obj"	"$(INTDIR)\melchior.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\Reactor.cpp

!IF  "$(CFG)" == "Melchior - Win32 Release"


"$(INTDIR)\Reactor.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"


"$(INTDIR)\Reactor.obj"	"$(INTDIR)\Reactor.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\Scheduler.cpp

!IF  "$(CFG)" == "Melchior - Win32 Release"


"$(INTDIR)\Scheduler.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"


"$(INTDIR)\Scheduler.obj"	"$(INTDIR)\Scheduler.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\TCP.cpp

!IF  "$(CFG)" == "Melchior - Win32 Release"


"$(INTDIR)\TCP.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"


"$(INTDIR)\TCP.obj"	"$(INTDIR)\TCP.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\TCPPacket.cpp

!IF  "$(CFG)" == "Melchior - Win32 Release"


"$(INTDIR)\TCPPacket.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"


"$(INTDIR)\TCPPacket.obj"	"$(INTDIR)\TCPPacket.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\UDP.cpp

!IF  "$(CFG)" == "Melchior - Win32 Release"


"$(INTDIR)\UDP.obj" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "Melchior - Win32 Debug"


"$(INTDIR)\UDP.obj"	"$(INTDIR)\UDP.sbr" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\melchior.rc

"$(INTDIR)\melchior.res" : $(SOURCE) "$(INTDIR)"
	$(RSC) $(RSC_PROJ) $(SOURCE)



!ENDIF 

