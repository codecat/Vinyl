#pragma once

#include "Common.h"

VINYL_NS_BEGIN;

class Folder;

class FolderIndex
{
	friend class Folder;

public:
	FolderIndex(const char* path, bool recursive);
	~FolderIndex();

	const char* GetPath();

	int GetFileCount();
	const char* GetFilePath(int i);

	int GetDirCount();
	const char* GetDirPath(int i);

private:
	void ReadDir(void* impl, const char* dirname, bool recursive);

	s::String m_path;
	s::StackArray<s::String> m_files;
	s::StackArray<s::String> m_dirs;
};

class Folder
{
public:
	Folder(const char* path);
	~Folder();

	const char* GetPath();

	FolderIndex GetIndex(bool recursive = false);

private:
	s::String m_path;
};

VINYL_NS_END;