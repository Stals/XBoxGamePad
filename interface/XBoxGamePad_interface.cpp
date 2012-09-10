/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "XBoxGamePad.h"

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef  s3eResult(*XBoxPadInit_t)();
typedef  s3eResult(*XBoxPadUpdate_t)();
typedef       bool(*XBoxPadIsConnected_t)(int controller);
typedef       bool(*XBoxPadVibrate_t)(int controller, int leftVal, int rightVal);
typedef     double(*XBoxPadXAxisL_t)(int controller);
typedef     double(*XBoxPadYAxisL_t)(int controller);
typedef     double(*XBoxPadXAxisR_t)(int controller);
typedef     double(*XBoxPadYAxisR_t)(int controller);
typedef     double(*XBoxPadXDPad_t)(int controller);
typedef     double(*XBoxPadYDPad_t)(int controller);
typedef       bool(*XBoxPadLeftThumb_t)(int controller);
typedef       bool(*XBoxPadRightThumb_t)(int controller);
typedef       bool(*XBoxPadAButton_t)(int controller);
typedef       bool(*XBoxPadBButton_t)(int controller);
typedef       bool(*XBoxPadXButton_t)(int controller);
typedef       bool(*XBoxPadYButton_t)(int controller);
typedef       bool(*XBoxPadLeftShoulder_t)(int controller);
typedef       bool(*XBoxPadRightShoulder_t)(int controller);
typedef       bool(*XBoxPadStartButton_t)(int controller);
typedef       bool(*XBoxPadBackButton_t)(int controller);
typedef     double(*XBoxPadLeftTrigger_t)(int controller);
typedef     double(*XBoxPadRightTrigger_t)(int controller);

/**
 * struct that gets filled in by XBoxGamePadRegister
 */
typedef struct XBoxGamePadFuncs
{
    XBoxPadInit_t m_XBoxPadInit;
    XBoxPadUpdate_t m_XBoxPadUpdate;
    XBoxPadIsConnected_t m_XBoxPadIsConnected;
    XBoxPadVibrate_t m_XBoxPadVibrate;
    XBoxPadXAxisL_t m_XBoxPadXAxisL;
    XBoxPadYAxisL_t m_XBoxPadYAxisL;
    XBoxPadXAxisR_t m_XBoxPadXAxisR;
    XBoxPadYAxisR_t m_XBoxPadYAxisR;
    XBoxPadXDPad_t m_XBoxPadXDPad;
    XBoxPadYDPad_t m_XBoxPadYDPad;
    XBoxPadLeftThumb_t m_XBoxPadLeftThumb;
    XBoxPadRightThumb_t m_XBoxPadRightThumb;
    XBoxPadAButton_t m_XBoxPadAButton;
    XBoxPadBButton_t m_XBoxPadBButton;
    XBoxPadXButton_t m_XBoxPadXButton;
    XBoxPadYButton_t m_XBoxPadYButton;
    XBoxPadLeftShoulder_t m_XBoxPadLeftShoulder;
    XBoxPadRightShoulder_t m_XBoxPadRightShoulder;
    XBoxPadStartButton_t m_XBoxPadStartButton;
    XBoxPadBackButton_t m_XBoxPadBackButton;
    XBoxPadLeftTrigger_t m_XBoxPadLeftTrigger;
    XBoxPadRightTrigger_t m_XBoxPadRightTrigger;
} XBoxGamePadFuncs;

static XBoxGamePadFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x1e9ba715, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: XBoxGamePad");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x1e9ba715, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool XBoxGamePadAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult XBoxPadInit()
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[0] func: XBoxPadInit"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_XBoxPadInit();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult XBoxPadUpdate()
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[1] func: XBoxPadUpdate"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_XBoxPadUpdate();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadIsConnected(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[2] func: XBoxPadIsConnected"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadIsConnected(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadVibrate(int controller, int leftVal, int rightVal)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[3] func: XBoxPadVibrate"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadVibrate(controller, leftVal, rightVal);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

double XBoxPadXAxisL(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[4] func: XBoxPadXAxisL"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    double ret = g_Ext.m_XBoxPadXAxisL(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

double XBoxPadYAxisL(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[5] func: XBoxPadYAxisL"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    double ret = g_Ext.m_XBoxPadYAxisL(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

double XBoxPadXAxisR(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[6] func: XBoxPadXAxisR"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    double ret = g_Ext.m_XBoxPadXAxisR(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

double XBoxPadYAxisR(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[7] func: XBoxPadYAxisR"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    double ret = g_Ext.m_XBoxPadYAxisR(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

double XBoxPadXDPad(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[8] func: XBoxPadXDPad"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    double ret = g_Ext.m_XBoxPadXDPad(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

double XBoxPadYDPad(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[9] func: XBoxPadYDPad"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    double ret = g_Ext.m_XBoxPadYDPad(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadLeftThumb(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[10] func: XBoxPadLeftThumb"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadLeftThumb(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadRightThumb(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[11] func: XBoxPadRightThumb"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadRightThumb(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadAButton(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[12] func: XBoxPadAButton"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadAButton(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadBButton(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[13] func: XBoxPadBButton"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadBButton(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadXButton(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[14] func: XBoxPadXButton"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadXButton(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadYButton(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[15] func: XBoxPadYButton"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadYButton(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadLeftShoulder(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[16] func: XBoxPadLeftShoulder"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadLeftShoulder(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadRightShoulder(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[17] func: XBoxPadRightShoulder"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadRightShoulder(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadStartButton(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[18] func: XBoxPadStartButton"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadStartButton(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool XBoxPadBackButton(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[19] func: XBoxPadBackButton"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_XBoxPadBackButton(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

double XBoxPadLeftTrigger(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[20] func: XBoxPadLeftTrigger"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    double ret = g_Ext.m_XBoxPadLeftTrigger(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

double XBoxPadRightTrigger(int controller)
{
    IwTrace(XBOXGAMEPAD_VERBOSE, ("calling XBoxGamePad[21] func: XBoxPadRightTrigger"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    double ret = g_Ext.m_XBoxPadRightTrigger(controller);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}