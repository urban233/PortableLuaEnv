#include "FilesystemManager.h"
#include <iostream>

FilesystemManager::FilesystemManager() {
	std::cout << "FilesystemManager created" << std::endl;
}

bool FilesystemManager::create_directory(const std::string& path) {
	try {
		return fs::create_directory(path);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}
}

bool FilesystemManager::exists(const std::string& path) {
	return fs::exists(path);
}

std::uintmax_t FilesystemManager::file_size(const std::string& path) {
	try {
		return fs::file_size(path);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return static_cast<std::uintmax_t>(-1);
	}
}

bool FilesystemManager::remove(const std::string& path) {
	try {
		return fs::remove(path);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return false;
	}
}

std::vector<std::string> FilesystemManager::list_directory(const std::string& path) {
	std::vector<std::string> entries;
	try {
		for (const auto& entry : fs::directory_iterator(path)) {
			entries.push_back(entry.path().string());
		}
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return entries;
}
