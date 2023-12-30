#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-explorer1632.mk)" "nbproject/Makefile-local-explorer1632.mk"
include nbproject/Makefile-local-explorer1632.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=explorer1632
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Example4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Example4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../src/system_config/explorer1632/framework/driver/adc/src/drv_adc_static.c ../src/system_config/explorer1632/framework/system/clk/src/sys_clk_static.c ../src/system_config/explorer1632/framework/system/ports/src/sys_ports_static.c ../src/system_config/explorer1632/system_init.c ../src/system_config/explorer1632/system_interrupt.c ../src/system_config/explorer1632/system_exceptions.c ../src/system_config/explorer1632/system_tasks.c ../src/app.c ../src/main.c ../../../../bsp/pic32mx470_pim+e16/bsp_sys_init.c ../../../../framework/system/devcon/src/sys_devcon.c ../../../../framework/system/devcon/src/sys_devcon_pic32mx.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/392146732/drv_adc_static.o ${OBJECTDIR}/_ext/1609116509/sys_clk_static.o ${OBJECTDIR}/_ext/1319843635/sys_ports_static.o ${OBJECTDIR}/_ext/760193242/system_init.o ${OBJECTDIR}/_ext/760193242/system_interrupt.o ${OBJECTDIR}/_ext/760193242/system_exceptions.o ${OBJECTDIR}/_ext/760193242/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o ${OBJECTDIR}/_ext/1271179505/sys_devcon.o ${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/392146732/drv_adc_static.o.d ${OBJECTDIR}/_ext/1609116509/sys_clk_static.o.d ${OBJECTDIR}/_ext/1319843635/sys_ports_static.o.d ${OBJECTDIR}/_ext/760193242/system_init.o.d ${OBJECTDIR}/_ext/760193242/system_interrupt.o.d ${OBJECTDIR}/_ext/760193242/system_exceptions.o.d ${OBJECTDIR}/_ext/760193242/system_tasks.o.d ${OBJECTDIR}/_ext/1360937237/app.o.d ${OBJECTDIR}/_ext/1360937237/main.o.d ${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o.d ${OBJECTDIR}/_ext/1271179505/sys_devcon.o.d ${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/392146732/drv_adc_static.o ${OBJECTDIR}/_ext/1609116509/sys_clk_static.o ${OBJECTDIR}/_ext/1319843635/sys_ports_static.o ${OBJECTDIR}/_ext/760193242/system_init.o ${OBJECTDIR}/_ext/760193242/system_interrupt.o ${OBJECTDIR}/_ext/760193242/system_exceptions.o ${OBJECTDIR}/_ext/760193242/system_tasks.o ${OBJECTDIR}/_ext/1360937237/app.o ${OBJECTDIR}/_ext/1360937237/main.o ${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o ${OBJECTDIR}/_ext/1271179505/sys_devcon.o ${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o

# Source Files
SOURCEFILES=../src/system_config/explorer1632/framework/driver/adc/src/drv_adc_static.c ../src/system_config/explorer1632/framework/system/clk/src/sys_clk_static.c ../src/system_config/explorer1632/framework/system/ports/src/sys_ports_static.c ../src/system_config/explorer1632/system_init.c ../src/system_config/explorer1632/system_interrupt.c ../src/system_config/explorer1632/system_exceptions.c ../src/system_config/explorer1632/system_tasks.c ../src/app.c ../src/main.c ../../../../bsp/pic32mx470_pim+e16/bsp_sys_init.c ../../../../framework/system/devcon/src/sys_devcon.c ../../../../framework/system/devcon/src/sys_devcon_pic32mx.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-explorer1632.mk dist/${CND_CONF}/${IMAGE_TYPE}/Example4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX470F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/392146732/drv_adc_static.o: ../src/system_config/explorer1632/framework/driver/adc/src/drv_adc_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/392146732" 
	@${RM} ${OBJECTDIR}/_ext/392146732/drv_adc_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/392146732/drv_adc_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/392146732/drv_adc_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/392146732/drv_adc_static.o.d" -o ${OBJECTDIR}/_ext/392146732/drv_adc_static.o ../src/system_config/explorer1632/framework/driver/adc/src/drv_adc_static.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1609116509/sys_clk_static.o: ../src/system_config/explorer1632/framework/system/clk/src/sys_clk_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1609116509" 
	@${RM} ${OBJECTDIR}/_ext/1609116509/sys_clk_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1609116509/sys_clk_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1609116509/sys_clk_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1609116509/sys_clk_static.o.d" -o ${OBJECTDIR}/_ext/1609116509/sys_clk_static.o ../src/system_config/explorer1632/framework/system/clk/src/sys_clk_static.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1319843635/sys_ports_static.o: ../src/system_config/explorer1632/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1319843635" 
	@${RM} ${OBJECTDIR}/_ext/1319843635/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1319843635/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1319843635/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1319843635/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/1319843635/sys_ports_static.o ../src/system_config/explorer1632/framework/system/ports/src/sys_ports_static.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/760193242/system_init.o: ../src/system_config/explorer1632/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760193242" 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760193242/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/760193242/system_init.o.d" -o ${OBJECTDIR}/_ext/760193242/system_init.o ../src/system_config/explorer1632/system_init.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/760193242/system_interrupt.o: ../src/system_config/explorer1632/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760193242" 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760193242/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/760193242/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/760193242/system_interrupt.o ../src/system_config/explorer1632/system_interrupt.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/760193242/system_exceptions.o: ../src/system_config/explorer1632/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760193242" 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760193242/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/760193242/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/760193242/system_exceptions.o ../src/system_config/explorer1632/system_exceptions.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/760193242/system_tasks.o: ../src/system_config/explorer1632/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760193242" 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760193242/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/760193242/system_tasks.o.d" -o ${OBJECTDIR}/_ext/760193242/system_tasks.o ../src/system_config/explorer1632/system_tasks.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o: ../../../../bsp/pic32mx470_pim+e16/bsp_sys_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1367982173" 
	@${RM} ${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o.d" -o ${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o ../../../../bsp/pic32mx470_pim+e16/bsp_sys_init.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1271179505/sys_devcon.o: ../../../../framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1271179505" 
	@${RM} ${OBJECTDIR}/_ext/1271179505/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/1271179505/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1271179505/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1271179505/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/1271179505/sys_devcon.o ../../../../framework/system/devcon/src/sys_devcon.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o: ../../../../framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1271179505" 
	@${RM} ${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_REAL_ICE=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o ../../../../framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/_ext/392146732/drv_adc_static.o: ../src/system_config/explorer1632/framework/driver/adc/src/drv_adc_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/392146732" 
	@${RM} ${OBJECTDIR}/_ext/392146732/drv_adc_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/392146732/drv_adc_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/392146732/drv_adc_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/392146732/drv_adc_static.o.d" -o ${OBJECTDIR}/_ext/392146732/drv_adc_static.o ../src/system_config/explorer1632/framework/driver/adc/src/drv_adc_static.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1609116509/sys_clk_static.o: ../src/system_config/explorer1632/framework/system/clk/src/sys_clk_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1609116509" 
	@${RM} ${OBJECTDIR}/_ext/1609116509/sys_clk_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1609116509/sys_clk_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1609116509/sys_clk_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1609116509/sys_clk_static.o.d" -o ${OBJECTDIR}/_ext/1609116509/sys_clk_static.o ../src/system_config/explorer1632/framework/system/clk/src/sys_clk_static.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1319843635/sys_ports_static.o: ../src/system_config/explorer1632/framework/system/ports/src/sys_ports_static.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1319843635" 
	@${RM} ${OBJECTDIR}/_ext/1319843635/sys_ports_static.o.d 
	@${RM} ${OBJECTDIR}/_ext/1319843635/sys_ports_static.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1319843635/sys_ports_static.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1319843635/sys_ports_static.o.d" -o ${OBJECTDIR}/_ext/1319843635/sys_ports_static.o ../src/system_config/explorer1632/framework/system/ports/src/sys_ports_static.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/760193242/system_init.o: ../src/system_config/explorer1632/system_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760193242" 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760193242/system_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/760193242/system_init.o.d" -o ${OBJECTDIR}/_ext/760193242/system_init.o ../src/system_config/explorer1632/system_init.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/760193242/system_interrupt.o: ../src/system_config/explorer1632/system_interrupt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760193242" 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_interrupt.o.d 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_interrupt.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760193242/system_interrupt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/760193242/system_interrupt.o.d" -o ${OBJECTDIR}/_ext/760193242/system_interrupt.o ../src/system_config/explorer1632/system_interrupt.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/760193242/system_exceptions.o: ../src/system_config/explorer1632/system_exceptions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760193242" 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_exceptions.o.d 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_exceptions.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760193242/system_exceptions.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/760193242/system_exceptions.o.d" -o ${OBJECTDIR}/_ext/760193242/system_exceptions.o ../src/system_config/explorer1632/system_exceptions.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/760193242/system_tasks.o: ../src/system_config/explorer1632/system_tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760193242" 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_tasks.o.d 
	@${RM} ${OBJECTDIR}/_ext/760193242/system_tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/760193242/system_tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/760193242/system_tasks.o.d" -o ${OBJECTDIR}/_ext/760193242/system_tasks.o ../src/system_config/explorer1632/system_tasks.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/app.o: ../src/app.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/app.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/app.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1360937237/app.o.d" -o ${OBJECTDIR}/_ext/1360937237/app.o ../src/app.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1360937237/main.o: ../src/main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1360937237" 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1360937237/main.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1360937237/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1360937237/main.o.d" -o ${OBJECTDIR}/_ext/1360937237/main.o ../src/main.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o: ../../../../bsp/pic32mx470_pim+e16/bsp_sys_init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1367982173" 
	@${RM} ${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o.d 
	@${RM} ${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o.d" -o ${OBJECTDIR}/_ext/1367982173/bsp_sys_init.o ../../../../bsp/pic32mx470_pim+e16/bsp_sys_init.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1271179505/sys_devcon.o: ../../../../framework/system/devcon/src/sys_devcon.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1271179505" 
	@${RM} ${OBJECTDIR}/_ext/1271179505/sys_devcon.o.d 
	@${RM} ${OBJECTDIR}/_ext/1271179505/sys_devcon.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1271179505/sys_devcon.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1271179505/sys_devcon.o.d" -o ${OBJECTDIR}/_ext/1271179505/sys_devcon.o ../../../../framework/system/devcon/src/sys_devcon.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o: ../../../../framework/system/devcon/src/sys_devcon_pic32mx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1271179505" 
	@${RM} ${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o.d 
	@${RM} ${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -ffunction-sections -O1 -I"../src" -I"../src/system_config/explorer1632" -I"../src/explorer1632" -I"../../../../framework" -I"../src/system_config/explorer1632/framework" -I"../../../../bsp/pic32mx470_pim+e16" -MMD -MF "${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o.d" -o ${OBJECTDIR}/_ext/1271179505/sys_devcon_pic32mx.o ../../../../framework/system/devcon/src/sys_devcon_pic32mx.c    -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Example4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../bin/framework/peripheral/PIC32MX470F512L_peripherals.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_REAL_ICE=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Example4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\bin\framework\peripheral\PIC32MX470F512L_peripherals.a      -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC0275F  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_REAL_ICE=1,--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/Example4.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  ../../../../bin/framework/peripheral/PIC32MX470F512L_peripherals.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Example4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    ..\..\..\..\bin\framework\peripheral\PIC32MX470F512L_peripherals.a      -DXPRJ_explorer1632=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=0,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Example4.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/explorer1632
	${RM} -r dist/explorer1632

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
