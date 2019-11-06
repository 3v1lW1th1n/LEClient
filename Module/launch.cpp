#include "stdafx.h"

std::string launchDevice;
std::string launchFile;
static PPLUGIN_LOAD_PATH dlaunchPluginPath = nullptr;

DWORD Launch::SetupFileSystem() {
	if ((dlaunchPluginPath = reinterpret_cast<PPLUGIN_LOAD_PATH>(Utilities::ResolveFunction("Launch.xex", DL_ORDINALS_PLUGINPATH))) == NULL) {
		return ERROR_INVALID_ORDINAL;
	}
	if (dlaunchPluginPath->magic == PLUGIN_LOAD_PATH_MAGIC && dlaunchPluginPath->devicePath != NULL && dlaunchPluginPath->iniPath != NULL) {

		launchDevice.assign(dlaunchPluginPath->devicePath);
		launchFile.assign(dlaunchPluginPath->iniPath);

		std::string link("\\System??\\" LAUNCH_MOUNT);
		std::string directory(launchDevice);
		directory.append(launchFile.substr(1, launchFile.find_last_of('\\')));

		if (FAILED(Utilities::MountPath(directory, link, TRUE))) {
#ifdef DEBUG
			DebugPrint("failed to mount drive");
#endif
			return E_FAIL;
		}

	}
	return ERROR_SUCCESS;
}
