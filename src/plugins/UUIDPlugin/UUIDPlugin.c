/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.1699 uuid: 186ebd51-28ef-4e7f-8411-96b61577b777
   from
	UUIDPlugin VMMaker.oscog-eem.1699 uuid: 186ebd51-28ef-4e7f-8411-96b61577b777
 */
static char __buildInfo[] = "UUIDPlugin VMMaker.oscog-eem.1699 uuid: 186ebd51-28ef-4e7f-8411-96b61577b777 " __DATE__ ;



#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
#endif

#include "UUIDPlugin.h"
#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveMakeUUID(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine*anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*isBytes)(sqInt oop);
static sqInt (*methodArgumentCount)(void);
static sqInt (*primitiveFail)(void);
static sqInt (*stackObjectValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt byteSizeOf(sqInt oop);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt isBytes(sqInt oop);
extern sqInt methodArgumentCount(void);
extern sqInt primitiveFail(void);
extern sqInt stackObjectValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"UUIDPlugin VMMaker.oscog-eem.1699 (i)"
#else
	"UUIDPlugin VMMaker.oscog-eem.1699 (e)"
#endif
;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* UUIDPlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return sqUUIDInit();
}

	/* UUIDPlugin>>#primitiveMakeUUID */
EXPORT(sqInt)
primitiveMakeUUID(void)
{
	char*location;
	sqInt oop;

	oop = stackObjectValue(0);
	if ((failed())
	 || (((methodArgumentCount()) != 0)
	 || ((!(isBytes(oop)))
	 || ((byteSizeOf(oop)) != 16)))) {
		return primitiveFail();
	}
	location = firstIndexableField(oop);
	MakeUUID(location);
	return oop;
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine*anInterpreter)
{
	sqInt ok;

	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		byteSizeOf = interpreterProxy->byteSizeOf;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		isBytes = interpreterProxy->isBytes;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		primitiveFail = interpreterProxy->primitiveFail;
		stackObjectValue = interpreterProxy->stackObjectValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* UUIDPlugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return sqUUIDShutdown();
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "UUIDPlugin";
void* UUIDPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "primitiveMakeUUID\000\001", (void*)primitiveMakeUUID},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{(void*)_m, "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveMakeUUIDAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
