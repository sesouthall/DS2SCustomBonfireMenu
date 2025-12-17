#include <windows.h>
#include <thread>
#include <iostream>
#include <functional>
#include "SP/memory/injection/asm/x64.h"
#include "SP/memory/aob_scan.h"
#include "sp/memory/pointer.h"
#include "GameData.h"
#include "HookManager.inl"
using namespace std;

HINSTANCE hinst_dll = 0;
std::thread begin_thread;

extern "C" UINT_PTR directinput_create_proc = 0;
extern "C" __declspec(dllexport) HRESULT __cdecl DirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID * ppvOut, LPUNKNOWN punkOuter);
static decltype(&DirectInput8Create) original_dinput8_create;

typedef signed long long undefined8;
typedef signed int undefined4;

#pragma pack(push, 1)
class LocalizedString
{
public:
    int32_t LocTable;
    int32_t StringId;
};

class MapObjBonfireComponent
{
};

class DemoCharacterCtrl
{
public:
    undefined8 field_0x0;
    byte padding1[0x8];
    undefined8 field_0x10;
    undefined8 field_0x18;
    undefined8* field_0x20;
    byte field_0x28;
    byte padding2[0x7];
    undefined8 field_0x30;
    undefined8* field_0x38;
    byte padding3[0x8];
    undefined4 field_0x48;
    undefined4 field_0x4C;
    undefined8 field_0x50;
    byte padding4[0x900];
};

class UnknownClassProperty
{
public:
    byte padding[0x30];
    int64_t field_0x30;
};

class FeOperatorTestBonfirePropertyOfProperty
{
public:
    byte padding1[0x3a];
    byte field_0x3a;
    byte padding2[0xcd];
    UnknownClassProperty* field_0x108;
    byte padding3[0x1b0];
    undefined8 field_0x2c0;
    byte padding4[0x2c98];
    undefined4 field_0x2f60;
    undefined4 field_0x2f64;
};

class EventBonfireManager
{
public:
    void* mapObjectBonfireComponentVtable;
    MapObjBonfireComponent* MapObjBonfireComponent;
    uint64_t field_0x10;
    int64_t field_0x18;
    FeOperatorTestBonfirePropertyOfProperty* field_0x20;
};

class EventManager
{
public:
    byte padding1[0x58];
    EventBonfireManager* EventBonfireManager;
};

class PlayerData
{
public:
    byte padding[0x68];
    int32_t field_0x68;
};

class GameDataManager
{
public:
    byte padding1[0x68];
    int64_t field_0x68;
    byte padding[0x50];
    PlayerData* player_data;
};

class GameManagerImp
{
public:
    byte padding1[0x70];
    EventManager* EventManager;
    byte padding2[0x30];
    GameDataManager* GameDataManager;
    byte padding3[0x21e0];
    int64_t* field1124_0x22f0;
} *gameManagerImp;
#pragma pack(pop)

typedef GameDataManager*(voidFuncReturnsGameDataManager)(void);
voidFuncReturnsGameDataManager* FUN_140040420;

typedef void(gameDataManagerUndefined8FuncReturnsVoid)(GameDataManager*, undefined8);
gameDataManagerUndefined8FuncReturnsVoid* FUN_1401abee0;

typedef undefined8(eventBonfireManagerIntFuncReturnsUndefined8)(EventBonfireManager*, int);
eventBonfireManagerIntFuncReturnsUndefined8* FUN_14017e370;

typedef undefined8* (undefined8FuncReturnsUndefined8)(undefined8*);
undefined8FuncReturnsUndefined8* FUN_14024f090;

typedef bool (undefined8Undefined4FuncReturnsBool)(undefined8*, undefined4);
undefined8Undefined4FuncReturnsBool* FUN_14024f2a0;

typedef bool (feOperatorTestBonfirePropertyOfPropertyFuncReturnsBool)(FeOperatorTestBonfirePropertyOfProperty*);
feOperatorTestBonfirePropertyOfPropertyFuncReturnsBool* FUN_140513600;

typedef byte(eventBonfireManagerUndefined4FuncReturnsByte)(EventBonfireManager*, undefined4);
eventBonfireManagerUndefined4FuncReturnsByte* FUN_14017e830;

typedef int64_t* (voidFuncReturnsInt64)(void);
voidFuncReturnsInt64* FUN_140046bd0;

typedef void* (intIntVtablePointerFuncReturnsPointer)(int, int, int64_t*);
intIntVtablePointerFuncReturnsPointer* heapAllocator;

typedef void (mapObjBonfireComponentFuncReturnsVoid)(MapObjBonfireComponent**);
mapObjBonfireComponentFuncReturnsVoid* FUN_140833650;

typedef LocalizedString* (LocalizedStringInitializer)(LocalizedString*, int32_t, int32_t);
LocalizedStringInitializer* FUN_14003d870;

typedef DemoCharacterCtrl* (localizedStringDemoCharacterCtrlUndefined4FuncReturnsDemoCharacterCtrl)(LocalizedString*, DemoCharacterCtrl*, int32_t);
localizedStringDemoCharacterCtrlUndefined4FuncReturnsDemoCharacterCtrl* FUN_14003d880;

typedef undefined8* (DemoCharacterCtrlDemoCharacterCtrlUInt64UInt64FuncReturnsUndefined8)(DemoCharacterCtrl*, DemoCharacterCtrl*, uint64_t, uint64_t);
DemoCharacterCtrlDemoCharacterCtrlUInt64UInt64FuncReturnsUndefined8* FUN_14001dce0;

typedef byte(FeOperatorTestBonfirePropertyOfPropertyFuncReturnsByte)(FeOperatorTestBonfirePropertyOfProperty*);
FeOperatorTestBonfirePropertyOfPropertyFuncReturnsByte* FUN_1400d81e0;

typedef char* (RetrieveLocalizedString)(int32_t, int32_t);
RetrieveLocalizedString* FUN_140503620;

typedef undefined8 (undefined8Undefined8Undefined8FuncReturnsUndefined8)(undefined8**, int64_t*, undefined4*);
undefined8Undefined8Undefined8FuncReturnsUndefined8* FUN_14002aad0;

typedef undefined8(undefined8StringFuncReturnsUndefined8)(undefined8, char*);
undefined8StringFuncReturnsUndefined8* FUN_14002c580;

typedef undefined8(BonfireMenuFuncReturnsBonfireMenu)(undefined8);
BonfireMenuFuncReturnsBonfireMenu* FUN_14002b170;

typedef undefined8(addOptionToBonfireMenu)(undefined8, char*, EventBonfireManager**);
addOptionToBonfireMenu* FUN_14002b240;

typedef undefined8(undefined8ByteFuncReturnsUndefined8)(undefined8, char);
undefined8ByteFuncReturnsUndefined8* FUN_14002c680;

typedef undefined8(undefined8DemoCharacterCtrlEventBonfireManagerFuncReturnsUndefined8)(undefined8, DemoCharacterCtrl*, EventBonfireManager**);
undefined8DemoCharacterCtrlEventBonfireManagerFuncReturnsUndefined8* FUN_14002b3e0;

typedef undefined8(undefined8Undefined8FuncReturnsUndefined8)(undefined8, undefined8*);
undefined8Undefined8FuncReturnsUndefined8* FUN_14002b670;

typedef undefined8(undefined8CharFuncReturnsUndefined8)(undefined8*, char*);
undefined8CharFuncReturnsUndefined8* FUN_1400268c0;

typedef void(undefined8Undefined8Undefined8FuncReturnsVoid)(undefined8, undefined8, undefined8);
undefined8Undefined8Undefined8FuncReturnsVoid* FUN_140028bb0;

typedef void(undefined4FuncReturnsVoid)(undefined4*);
undefined4FuncReturnsVoid* FUN_14002aed0;

typedef void(undefined8Undefined8FuncReturnsVoid)(undefined8*, undefined8);

typedef void(undefined8FuncReturnsVoid)(undefined8);
undefined8FuncReturnsVoid* thunk_FUN_141b6b19f;

typedef undefined8 (FeOperatorTestBonfirePropertyOfPropertyUndefined8Undefined4FuncReturnsVoid)(FeOperatorTestBonfirePropertyOfProperty*, undefined8, undefined4);
FeOperatorTestBonfirePropertyOfPropertyUndefined8Undefined4FuncReturnsVoid* OriginalCreateBonfireMenu;

static undefined8 CustomMenuFunction(undefined8 param_1, undefined8 param_2)
{
    printf_s("param_1 is %x\n", param_1);
    printf_s("param_2 is %x\n", param_2);
    return param_2;
}

static undefined8 Override_CreateBonfireMenu(FeOperatorTestBonfirePropertyOfProperty* param_1, undefined8 param_2, undefined4 param_3)
{
    bool uVar2;
    int iVar3;
    GameDataManager* lVar4;
    int64_t lVar5;
    int64_t* plVar6;
    EventBonfireManager* pEVar7;
    DemoCharacterCtrl* pDVar8;
    EventBonfireManager* pEVar9;
    char* pcVar10;
    char* pcVar11;
    char* pcVar12;
    char* pcVar13;
    char* pcVar14;
    char* pcVar15;
    char* pcVar16;
    undefined8 uVar16;
    undefined8 uVar17;
    int iVar18;
    char local_a88;
    int64_t* local_a78;
    undefined4 local_a70;
    undefined4 local_a6c;
    uint32_t local_a68;
    uint32_t uStack_a64;
    EventBonfireManager* local_a60;
    FeOperatorTestBonfirePropertyOfProperty* local_a58;
    LocalizedString local_a48;
    EventBonfireManager* local_a40;
    LocalizedString local_a38;
    LocalizedString LStack_a30;
    undefined8 local_a28;
    EventBonfireManager* local_a20;
    EventBonfireManager* local_a18;
    EventBonfireManager* local_a10;
    LocalizedString local_a08;
    EventBonfireManager* local_a00;
    EventBonfireManager* CustomMenuOption;
    LocalizedString local_9f8;
    LocalizedString local_9f0;
    LocalizedString local_9e8;
    DemoCharacterCtrl auStack_9e0;
    char local_958[16];
    DemoCharacterCtrl local_940;

    printf_s("Started menu creation\n");
    param_1->field_0x2f60 = param_3;
    local_a58 = param_1;
    lVar4 = (GameDataManager*)FUN_140040420();
    if (lVar4 != (GameDataManager*)0x0) {
        FUN_1401abee0(lVar4, 0x304b480);
        FUN_1401abee0(lVar4, 0x304db90);
    }
    pEVar9 = (EventBonfireManager*)0x0;
    local_a78 = 0;
    pEVar7 = (EventBonfireManager*)0x0;
    if (gameManagerImp->EventManager != (EventManager*)0x0) {
        pEVar7 = gameManagerImp->EventManager->EventBonfireManager;
    }
    iVar18 = 0;
    iVar3 = 0;
    if (lVar5 = FUN_14017e370(pEVar7, param_3), lVar5 != 0)
    {
        iVar3 = *(int*)(lVar5 + 0x1c);
    }
    *(int*)(param_1 + 0x2f64) = iVar3;
    FUN_14024f090(&local_a28);
    if (FUN_14024f2a0(&local_a28, param_1->field_0x2f64) && gameManagerImp->field1124_0x22f0 &&
        FUN_140513600(param_1) && FUN_14017e830(gameManagerImp->EventManager->EventBonfireManager, param_1->field_0x2f60)) {
        local_a88 = 1;
    }
    else
    {
        local_a88 = 0;
    }
    local_a68 = 0;
    auStack_9e0.field_0x48 = 0;

    printf_s("Ready to construct 1st EventBonfireManager\n");

    plVar6 = (int64_t*)FUN_140046bd0();
    pEVar7 = (EventBonfireManager*)heapAllocator(0x28, 8, plVar6);
    local_a18 = (EventBonfireManager*)0x0;
    if (pEVar7 != (EventBonfireManager*)0x0) {
        pEVar7->field_0x10 = Game::ds2_base + 0xd9a10;
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10add70);
        pEVar7->field_0x18 = 0;
        pEVar7->field_0x20 = param_1;
        *(undefined4*)&pEVar7->MapObjBonfireComponent = 0;
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10bad98);
        local_a18 = pEVar7;
    }
    if (local_a18 != (EventBonfireManager*)0x0) {
        FUN_140833650(&local_a18->MapObjBonfireComponent);
    }
    pEVar7 = (EventBonfireManager*)0x0;
    if (gameManagerImp->GameDataManager != (GameDataManager*)0x0) {
        pEVar7 = (EventBonfireManager*)gameManagerImp->GameDataManager->player_data;
    }
    if (pEVar7 != (EventBonfireManager*)0x0) {
        iVar18 = (gameManagerImp->GameDataManager->player_data->field_0x68) + 1;
    }
    FUN_14003d870(&LStack_a30, 0xb, 0x277d);
    pDVar8 = FUN_14003d880(&LStack_a30, &local_940, iVar18);
    auStack_9e0.field_0x20 = pDVar8->field_0x20;
    auStack_9e0.field_0x18 = 7;
    auStack_9e0.field_0x10 = 0;
    auStack_9e0.field_0x0 = auStack_9e0.field_0x0 & 0xffffff00;
    auStack_9e0.field_0x38 = auStack_9e0.field_0x20;
    FUN_14001dce0(&auStack_9e0, pDVar8, 0, 0xffffffffffffffff);
    auStack_9e0.field_0x28 = pDVar8->field_0x28;
    auStack_9e0.field_0x30 = 0x5f5c5b200000067;

    printf_s("Ready to construct 2nd EventBonfireManager\n");

    plVar6 = FUN_140046bd0();
    pEVar7 = (EventBonfireManager*)heapAllocator(0x28, 8, plVar6);
    local_a60 = (EventBonfireManager*)0x0;
    if (pEVar7 != (EventBonfireManager*)0x0) {
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10add70);
        *(undefined4*)&pEVar7->MapObjBonfireComponent = 0;
        pEVar7->field_0x10 = Game::ds2_base + 0xd90b0;
        *(undefined8*)&pEVar7->field_0x18 = 0;
        pEVar7->field_0x20 = param_1;
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10bad98);
        local_a60 = pEVar7;
    }
    if (local_a60 != (EventBonfireManager*)0x0) {
        FUN_140833650(&local_a60->MapObjBonfireComponent);
    }

    printf_s("Ready to construct 3rd EventBonfireManager\n");

    FUN_14003d870(&local_a08, 0xb, 0x2777);
    plVar6 = (int64_t*)FUN_140046bd0();
    pEVar7 = (EventBonfireManager*)heapAllocator(0x28, 8, plVar6);
    local_a40 = (EventBonfireManager*)0x0;
    if (pEVar7 != (EventBonfireManager*)0x0) {
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10add70);
        *(undefined4*)&pEVar7->MapObjBonfireComponent = 0;
        pEVar7->field_0x10 = Game::ds2_base + 0xd93b0;
        *(uint64_t*)&pEVar7->field_0x18 = 0;
        pEVar7->field_0x20 = param_1;
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10bad98);
        local_a40 = pEVar7;
    }
    if (local_a40 != (EventBonfireManager*)0x0) {
        FUN_140833650(&local_a40->MapObjBonfireComponent);
    }

    printf_s("Ready to construct 4th EventBonfireManager\n");

    FUN_14003d870(&local_a48, 0xb, 0x277e);
    plVar6 = (int64_t*)FUN_140046bd0();
    pEVar7 = (EventBonfireManager*)heapAllocator(0x28, 8, plVar6);
    local_a10 = (EventBonfireManager*)0x0;
    if (pEVar7 != (EventBonfireManager*)0x0) {
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10add70);
        *(undefined4*)&pEVar7->MapObjBonfireComponent = 0;
        pEVar7->field_0x10 = Game::ds2_base + 0xd8870;
        *(uint64_t*)&pEVar7->field_0x18 = 0;
        pEVar7->field_0x20 = param_1;
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10bad98);
        local_a10 = pEVar7;
    }
    if (local_a10 != (EventBonfireManager*)0x0) {
        FUN_140833650(&local_a10->MapObjBonfireComponent);
    }

    printf_s("Ready to construct 5th EventBonfireManager\n");

    FUN_14003d870(&local_9f8, 0xb, 0x2778);
    plVar6 = (int64_t*)FUN_140046bd0();
    pEVar7 = (EventBonfireManager*)heapAllocator(0x28, 8, plVar6);
    local_a00 = (EventBonfireManager*)0x0;
    if (pEVar7 != (EventBonfireManager*)0x0) {
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10add70);
        *(undefined4*)&pEVar7->MapObjBonfireComponent = 0;
        pEVar7->field_0x10 = Game::ds2_base + 0xd9c90;
        *(undefined8*)&pEVar7->field_0x18 = 0;
        pEVar7->field_0x20 = param_1;
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10bad98);
        local_a00 = pEVar7;
    }
    if (local_a00 != (EventBonfireManager*)0x0) {
        FUN_140833650(&local_a00->MapObjBonfireComponent);
    }

    printf_s("Ready to construct 6th EventBonfireManager\n");

    FUN_14003d870(&local_9e8, 0xb, 0x2775);
    plVar6 = (int64_t*)FUN_140046bd0();
    pEVar7 = (EventBonfireManager*)heapAllocator(0x28, 8, plVar6);
    if (pEVar7 != (EventBonfireManager*)0x0) {
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10add70);
        *(undefined4*)&pEVar7->MapObjBonfireComponent = 0;
        pEVar7->field_0x10 = Game::ds2_base + 0xd9dd0;
        *(uint64_t*)&pEVar7->field_0x18 = 0;
        pEVar7->field_0x20 = param_1;
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10bad98);
        pEVar9 = pEVar7;
    }
    local_a20 = pEVar9;
    if (pEVar9 != (EventBonfireManager*)0x0) {
        FUN_140833650(&pEVar9->MapObjBonfireComponent);
    }

    printf_s("Ready to construct 7th EventBonfireManager\n");

    plVar6 = (int64_t*)FUN_140046bd0();
    pEVar7 = (EventBonfireManager*)heapAllocator(0x28, 8, plVar6);
    if (pEVar7 != (EventBonfireManager*)0x0) {
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10add70);
        *(undefined4*)&pEVar7->MapObjBonfireComponent = 0;
        pEVar7->field_0x10 = (uint64_t)CustomMenuFunction;
        *(uint64_t*)&pEVar7->field_0x18 = 0;
        pEVar7->field_0x20 = param_1;
        pEVar7->mapObjectBonfireComponentVtable = (void*)(Game::ds2_base + 0x10bad98);
        pEVar9 = pEVar7;
    }
    CustomMenuOption = pEVar9;
    if (pEVar9 != (EventBonfireManager*)0x0) {
        FUN_140833650(&pEVar9->MapObjBonfireComponent);
    }

    printf_s("Ready to write bonfire menu options\n");

    FUN_14003d870(&local_a38, 0xb, 0x2776);
    FUN_14003d870(&local_9f0, 0x12, param_3);
    local_a70 = 0;
    local_a6c = 0x14;
    local_a68 = local_a68 & 0xffffff00;
    if (param_1->field_0x108 != 0) {
        local_a78 = &param_1->field_0x108->field_0x30;
    }
    uVar2 = FUN_1400d81e0(param_1);
    printf_s("Getting localized strings");
    pcVar10 = FUN_140503620(local_a08.LocTable, local_a08.StringId);
    pcVar11 = FUN_140503620(local_a48.LocTable, local_a48.StringId);
    pcVar12 = FUN_140503620(local_9f8.LocTable, local_9f8.StringId);
    pcVar13 = FUN_140503620(local_9e8.LocTable, local_9e8.StringId);
    pcVar14 = FUN_140503620(local_a38.LocTable, local_a38.StringId);
    pcVar15 = FUN_140503620(local_9f0.LocTable, local_9f0.StringId);
    pcVar16 = FUN_140503620(0xb, 0x277F);
    uVar16 = FUN_14002aad0(&local_940.field_0x38, local_a78, &local_a70);
    printf_s("Writing into menu object");
    uVar16 = FUN_14002c580(uVar16, pcVar15);
    uVar16 = FUN_14002b170(uVar16);
    uVar16 = FUN_14002b240(uVar16, pcVar14, &local_a20);
    uVar16 = FUN_14002b240(uVar16, pcVar13, &local_a00);
    uVar16 = FUN_14002b240(uVar16, pcVar12, &local_a10);
    uVar16 = FUN_14002b240(uVar16, pcVar16, &CustomMenuOption);
    uVar16 = FUN_14002b240(uVar16, pcVar11, &local_a40);
    uVar16 = FUN_14002c680(uVar16, local_a88);
    uVar16 = FUN_14002b240(uVar16, pcVar10, &local_a60);
    uVar16 = FUN_14002b3e0(uVar16, &auStack_9e0, &local_a18);
    uVar16 = FUN_14002c680(uVar16, uVar2);
    uVar16 = FUN_14002b670(uVar16, &auStack_9e0.field_0x50);
    printf_s("Finizing stuff?");
    uVar17 = FUN_1400268c0(&param_1->field_0x2c0, local_958);
    FUN_140028bb0(param_2, uVar17, uVar16);
    FUN_14002aed0(&local_940.field_0x48);
    if (7 < (uint64_t)local_940.field_0x18) {
        (*(undefined8Undefined8FuncReturnsVoid**)((*local_940.field_0x20) + 0x68))
            (local_940.field_0x20, local_940.field_0x0);
    }

    printf_s("Done\n");

    return param_2;
}

bool Begin(uint64_t qModuleHandle) {

    char dllpath[MAX_PATH];
    GetSystemDirectoryA(dllpath, MAX_PATH);
    strcat_s(dllpath, "\\dinput8.dll");
    hinst_dll = LoadLibraryA(dllpath);

    if (!hinst_dll) {
        MessageBoxA(NULL, "Failed to load original DLL", "Error", MB_ICONERROR);
        return false;
    };

    original_dinput8_create = (decltype(&DirectInput8Create))GetProcAddress(hinst_dll, "DirectInput8Create");
    if (!original_dinput8_create) {
        MessageBoxA(NULL, "Failed to load original DLL", "Error", MB_ICONERROR);
        return false;
    }

    // Do whatever here, entry point to the entire mod
    AllocConsole();
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
    printf_s("Working fine so far\n");
    //MessageBoxA(NULL, "", "", MB_ICONERROR);

    Game::init();

    void* gameManagerImp_sp = sp::mem::aob_scan("48 8B 05 xx xx xx xx 48 8B 58 38 48 85 DB 74 xx F6");
    gameManagerImp = (GameManagerImp *) sp::mem::pointer<uint8_t>((void*)((uint64_t)gameManagerImp_sp + *(uint32_t*)((uint64_t)gameManagerImp_sp + 3) + 7), {0x0}).resolve();

    Hook::HookManager* pHookManager = Hook::HookManager::GetInstance();
    pHookManager->Initialize();

    pHookManager->CreateHook<FeOperatorTestBonfirePropertyOfPropertyUndefined8Undefined4FuncReturnsVoid*>(Game::ds2_base + 0xd6dc0, &OriginalCreateBonfireMenu, &Override_CreateBonfireMenu, NULL, "CreateBonfireMenu"); // Normal hook example

    //pHookManager->Hookless<FeOperatorTestBonfirePropertyOfProperty::FUN_140513600Type*>(DebugManager::GetVTableAddr(), 1, (FeOperatorTestBonfirePropertyOfProperty::FUN_140513600Type*)(Game::ds2_base+0x513600), &FeOperatorTestBonfirePropertyOfProperty::FUN_140513600, "PointBackToFUN140513600"); //VTable injection example

    FUN_140040420 = (voidFuncReturnsGameDataManager*)(Game::ds2_base + 0x40420);
    FUN_1401abee0 = (gameDataManagerUndefined8FuncReturnsVoid*)(Game::ds2_base + 0x1abee0);
    FUN_14017e370 = (eventBonfireManagerIntFuncReturnsUndefined8*)(Game::ds2_base + 0x17e370);
    FUN_14024f090 = (undefined8FuncReturnsUndefined8*)(Game::ds2_base + 0x24f090);
    FUN_14024f2a0 = (undefined8Undefined4FuncReturnsBool*)(Game::ds2_base + 0x24f2a0);
    FUN_140513600 = (feOperatorTestBonfirePropertyOfPropertyFuncReturnsBool*)(Game::ds2_base + 0x513600);
    FUN_14017e830 = (eventBonfireManagerUndefined4FuncReturnsByte*)(Game::ds2_base + 0x14017e830);
    heapAllocator = (intIntVtablePointerFuncReturnsPointer*)(Game::ds2_base + 0x833320);
    FUN_140833650 = (mapObjBonfireComponentFuncReturnsVoid*)(Game::ds2_base + 0x833650);
    FUN_14003d870 = (LocalizedStringInitializer*)(Game::ds2_base + 0x3d870);
    FUN_14003d880 = (localizedStringDemoCharacterCtrlUndefined4FuncReturnsDemoCharacterCtrl*)(Game::ds2_base + 0x3d880);
    FUN_14001dce0 = (DemoCharacterCtrlDemoCharacterCtrlUInt64UInt64FuncReturnsUndefined8*)(Game::ds2_base + 0x1dce0);
    FUN_140046bd0 = (voidFuncReturnsInt64*)(Game::ds2_base + 0x46bd0);
    FUN_1400d81e0 = (FeOperatorTestBonfirePropertyOfPropertyFuncReturnsByte*)(Game::ds2_base + 0xd81e0);
    FUN_140503620 = (RetrieveLocalizedString*)(Game::ds2_base + 0x503620);
    FUN_14002aad0 = (undefined8Undefined8Undefined8FuncReturnsUndefined8*)(Game::ds2_base + 0x2aad0);
    FUN_14002c580 = (undefined8StringFuncReturnsUndefined8*)(Game::ds2_base + 0x2c580);
    FUN_14002b170 = (BonfireMenuFuncReturnsBonfireMenu*)(Game::ds2_base + 0x2b170);
    FUN_14002b240 = (addOptionToBonfireMenu*)(Game::ds2_base + 0x2b240);
    FUN_14002c680 = (undefined8ByteFuncReturnsUndefined8*)(Game::ds2_base + 0x2c680);
    FUN_14002b3e0 = (undefined8DemoCharacterCtrlEventBonfireManagerFuncReturnsUndefined8*)(Game::ds2_base + 0x2b3e0);
    FUN_14002b670 = (undefined8Undefined8FuncReturnsUndefined8*)(Game::ds2_base + 0x2b670);
    FUN_1400268c0 = (undefined8CharFuncReturnsUndefined8*)(Game::ds2_base + 0x268c0);
    FUN_140028bb0 = (undefined8Undefined8Undefined8FuncReturnsVoid*)(Game::ds2_base + 0x28bb0);
    FUN_14002aed0 = (undefined4FuncReturnsVoid*)(Game::ds2_base + 0x2aed0);
    thunk_FUN_141b6b19f = (undefined8FuncReturnsVoid*)(Game::ds2_base + 0xc2c9e0);

    return true;
};

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {

    switch (fdwReason) {
        case (DLL_PROCESS_ATTACH): {
            DisableThreadLibraryCalls(hinstDLL);
            begin_thread = std::thread(Begin, (uint64_t)hinstDLL);
            break;
        };
        case (DLL_PROCESS_DETACH): {
            begin_thread.detach();
            FreeLibrary(hinst_dll);
            break;
        };
    }
    return TRUE;
}

// Define original dll export and call the original function
extern "C" __declspec(dllexport) HRESULT __cdecl DirectInput8Create(
    HINSTANCE hinst,
    DWORD dwVersion,
    REFIID riidltf,
    LPVOID * ppvOut,
    LPUNKNOWN punkOuter)
{
    return original_dinput8_create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
}