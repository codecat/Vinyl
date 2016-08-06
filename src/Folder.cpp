#include "Common.h"
#include "Folder.h"
#include "Mountpoint.h"

VINYL_NS_BEGIN;

FolderIndex::FolderIndex()
{
}

FolderIndex::FolderIndex(const char* path, bool recursive)
{
	m_path = path;
	Populate(recursive);
}

FolderIndex::~FolderIndex()
{
}

void FolderIndex::Populate(bool recursive)
{
	for (auto &point : Mount::Points) {
		point.FolderGetIndex(*this, m_path, recursive);
	}
}

const char* FolderIndex::GetPath()
{
	return m_path;
}

int FolderIndex::GetFileCount()
{
	return m_files.Count();
}

const char* FolderIndex::GetFilePath(int i)
{
	return m_files[i];
}

int FolderIndex::GetDirCount()
{
	return m_dirs.Count();
}

const char* FolderIndex::GetDirPath(int i)
{
	return m_dirs[i];
}

Folder::Folder(const char* path)
{
	m_path = path;
}

Folder::~Folder()
{
}

const char* Folder::GetPath()
{
	return m_path;
}

FolderIndex Folder::GetIndex(bool recursive)
{
	FolderIndex ret;
	s::String pathname = m_path;
	if (!pathname.EndsWith("/")) {
		pathname += "/";
	}
	ret.m_path = pathname;
	ret.Populate(recursive);
	return ret;
}

VINYL_NS_END;
