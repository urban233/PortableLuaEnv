#pragma once
#include <string>

class GitHubWrapper
{
public:
	GitHubWrapper();
	bool clone_repo(const std::string& repo_url, const std::string& clone_path);
};

