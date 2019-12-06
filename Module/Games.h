#include "stdafx.h"
#pragma once

class Games {
public:
	static HMODULE DashboardHandle;

	class TitlePatch {
	public:
		static BOOL DashLoaded;
		static VOID InitializeTitlePatching(PLDR_DATA_TABLE_ENTRY ModuleHandle);
	};

	typedef enum TitleIds : DWORD {
		DASHBOARD = 0xFFFE07D1,
		FREESTYLEDASH = 0xF5D20000,
		GTA_V = 0x545408A7,
		COD_4 = 0x415607E6,
		COD_WAW = 0x4156081C,
		COD_BO1 = 0x41560855,
		COD_BO2 = 0x415608C3,
		COD_MW2 = 0x41560817,
		COD_MW3 = 0x415608CB,
		COD_GHOSTS = 0x415608fC,
		COD_AW = 0x41560914,
		COD_BO3 = 0x4156091D,
		XEX_MENU = 0xFFFF0055,
		XEX_MENUALT = 0xC0DE9999,
		XEX_MENU2 = 0x00000170,
		XSHELLXDK = 0xFFFE07FF,
		DashLaunch = 0xFFFF011D,
		NETFLIX = 0x584807D5,
	} TitleIds;

	class AW {
	public:
		struct AWBypassData_s {
			DWORD Seed;
			DWORD SeedAnswer;
		};
		static AWBypassData_s AwBypassData;
		static DWORD WINAPI AwBypass();
	};

	class BO2 {
	public:
		static	DWORD WINAPI BO2Bypass();
	};

	class Ghosts {
	public:
		static DWORD WINAPI GhostBypass();
	};
};

