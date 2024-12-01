#pragma once
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

class FilesystemManager {
public:
	/**
	 * Constructor
	 */
	FilesystemManager();
	/**
	 * Creates a single directory for the given path without creating parent directories.
	 * 
	 * @param A path of the directory to create
	 * @return True if the operation was successful, Otherwise: false
	 */
	bool create_directory(const std::string& path);
	/**
	 * Checks if a given path exists
	 * 
	 * @param Path to check
	 * @return True if the path exists, Otherwise: false
	 */
	bool exists(const std::string& path);
	/**
	 * Gets the size of a given file
	 * 
	 * @param A path to get the size of
	 * @return The size of the file
	 */
	std::uintmax_t file_size(const std::string& path);
	/**
	 * Removes a given path
	 * 
	 * @param A path that should be removed
	 * @return True if the operation was successful, Otherwise: false
	 */
	bool remove(const std::string& path);
	/**
	 * Creates a list of the directory content of the given path
	 * 
	 * @param The path to list the items of
	 * @return A list with the contents of the given path
	 */
	std::vector<std::string> list_directory(const std::string& path);
};
