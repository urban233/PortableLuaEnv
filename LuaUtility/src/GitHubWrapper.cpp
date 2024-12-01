#include "GitHubWrapper.h"
#include <iostream>

GitHubWrapper::GitHubWrapper()
{
	std::cout << "GitHubWrapper created" << std::endl;
}

bool GitHubWrapper::clone_repo(const std::string& repo_url, const std::string& clone_path)
{
	std::string command = "git clone " + repo_url + " " + clone_path;
	int result = std::system(command.c_str());
	if (result == 0) {
		return true;
	}
	else {
		return false;
	}
}
