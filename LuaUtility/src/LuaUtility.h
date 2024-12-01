#pragma once
#include <lua.hpp>
#include "FilesystemManager.h"
#include "GitHubWrapper.h"

// Do NOT declare the extern "C" DLL_EXPORT int luaopen_LuaUtility(lua_State* L) here!
// This will lead to an compiler error!

// Lua binding functions
int filesystem_manager_new(lua_State* L);
int filesystem_manager_create_directory(lua_State* L);
int filesystem_manager_exists(lua_State* L);
void register_filesystem_manager(lua_State* L);

int github_wrapper_new(lua_State* L);
int github_wrapper_clone_repo(lua_State* L);
void register_github_wrapper(lua_State* L);
