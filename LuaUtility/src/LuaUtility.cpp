// LuaUtility.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <filesystem>
#include <string>

// Define DLL export macro
#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

#define LUA_LIB
#include "LuaUtility.h"

// Function to create a new FilesystemManager instance in Lua
int filesystem_manager_new(lua_State* L) {
	// Create a new FilesystemManager object and push it to the stack as userdata
	FilesystemManager* manager = new FilesystemManager();
	*(FilesystemManager**)lua_newuserdata(L, sizeof(FilesystemManager*)) = manager;

	// Set the metatable for this userdata to enable method calls on it
	luaL_getmetatable(L, "FilesystemManager");
	lua_setmetatable(L, -2);

	return 1; // Return the new object
}

// Method to call create_directory on the FilesystemManager instance
int filesystem_manager_create_directory(lua_State* L) {
	FilesystemManager* manager = *(FilesystemManager**)luaL_checkudata(L, 1, "FilesystemManager");
	const char* path = luaL_checkstring(L, 2);
	bool result = manager->create_directory(path);
	lua_pushboolean(L, result);
	return 1;
}

// Method to call exists on the FilesystemManager instance
int filesystem_manager_exists(lua_State* L) {
	FilesystemManager* manager = *(FilesystemManager**)luaL_checkudata(L, 1, "FilesystemManager");
	const char* path = luaL_checkstring(L, 2);
	bool result = manager->exists(path);
	lua_pushboolean(L, result);
	return 1;
}

// Register the methods of FilesystemManager to Lua
void register_filesystem_manager(lua_State* L) {
	// Ensure the metatable is created for the first time
	if (luaL_newmetatable(L, "FilesystemManager")) {
		// Set up the metatable's __index to point to itself
		lua_pushvalue(L, -1);  // Duplicate metatable
		lua_setfield(L, -2, "__index");

		// Register the methods
		lua_pushcfunction(L, filesystem_manager_create_directory);
		lua_setfield(L, -2, "create_directory");

		lua_pushcfunction(L, filesystem_manager_exists);
		lua_setfield(L, -2, "exists");
	}

	// Pop the metatable off the stack
	lua_pop(L, 1);
}
//void register_filesystem_manager(lua_State* L) {
//	// Create a metatable for FilesystemManager
//	luaL_newmetatable(L, "FilesystemManager");
//
//	// Set up the metatable's __index to point to the methods of FilesystemManager
//	lua_pushvalue(L, -1);  // Duplicate metatable
//	lua_setfield(L, -2, "__index");
//
//	// Register the methods
//	lua_pushcfunction(L, filesystem_manager_create_directory);
//	lua_setfield(L, -2, "create_directory");
//
//	lua_pushcfunction(L, filesystem_manager_exists);
//	lua_setfield(L, -2, "exists");
//
//	// Other methods could be added here
//
//	// Pop the metatable off the stack
//	lua_pop(L, 1);
//}

int github_wrapper_new(lua_State* L) {
	// Create a new FilesystemManager object and push it to the stack as userdata
	GitHubWrapper* wrapper = new GitHubWrapper();
	*(GitHubWrapper**)lua_newuserdata(L, sizeof(GitHubWrapper*)) = wrapper;

	// Set the metatable for this userdata to enable method calls on it
	luaL_getmetatable(L, "GitHubWrapper");
	lua_setmetatable(L, -2);

	return 1; // Return the new object
}

int github_wrapper_clone_repo(lua_State* L) {
	GitHubWrapper* wrapper = *(GitHubWrapper**)luaL_checkudata(L, 1, "GitHubWrapper");
	const char* repo_url = luaL_checkstring(L, 2);
	const char* clone_path = luaL_checkstring(L, 3);
	bool result = wrapper->clone_repo(repo_url, clone_path);
	lua_pushboolean(L, result);
	return 1;
}

void register_github_wrapper(lua_State* L) {
	if (luaL_newmetatable(L, "GitHubWrapper")) {
		lua_pushvalue(L, -1);  // Duplicate metatable
		lua_setfield(L, -2, "__index");

		lua_pushcfunction(L, github_wrapper_clone_repo);
		lua_setfield(L, -2, "clone_repo");
	}

	lua_pop(L, 1);
}
//void register_github_wrapper(lua_State* L) {
//	luaL_newmetatable(L, "GitHubWrapper");
//
//	// Set up the metatable's __index to point to the methods of FilesystemManager
//	lua_pushvalue(L, -1);  // Duplicate metatable
//	lua_setfield(L, -2, "__index");
//
//	// Register the methods
//	lua_pushcfunction(L, github_wrapper_clone_repo);
//	lua_setfield(L, -2, "clone_repo");
//	// Pop the metatable off the stack
//	lua_pop(L, 1);
//}

// Lua function to open the library and bind the FilesystemManager
extern "C" DLL_EXPORT int luaopen_LuaUtility(lua_State* L) {
	// Register the FilesystemManager methods
	register_filesystem_manager(L);
	register_github_wrapper(L);

	// Create the library table
	lua_newtable(L);

	// Register the constructor as the "FilesystemManager" field of the table
	lua_pushcfunction(L, filesystem_manager_new);
	lua_setfield(L, -2, "FilesystemManager");
	lua_pushcfunction(L, github_wrapper_new);
	lua_setfield(L, -2, "GitHubWrapper");

	return 1; // Return the module table
}
