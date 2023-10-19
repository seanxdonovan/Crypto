namespace ss
{
	bool Exists(const Filename& p_fn);
	bool FileExists(const TCHAR *p_filename);
	bool IsDirectory(const TCHAR *p_filename);
	bool IsDirectory(const Filename& p_filename);

	void MakeDirectory(const TCHAR *p_filename);
	void Delete(const TCHAR *p_filename);

	void MakeDirectory(const Filename& p_fn);
	void Delete(const Filename& p_fn);
	void Create(const Filename& p_fn);
	void Move(const Filename& p_fnFrom, const Filename& p_fnTo);

	void CurrentWorkingDirectory(Filename *p_pCurrentWorkingDirectory);

	void ParsePath(const std::string p_path, std::vector<Filename> *p_pPaths, const char p_delimiter = ';');
	bool FindInPath(const std::string& p_filename, const std::vector<Filename>& p_path, Filename *p_pResolvedFilename);

	void GenerateLogFilename(const Filename& p_inDirectory, const std::string& p_sBaseName, const std::string& p_sExtension, Filename *p_pLogFilename);

	std::string format(fs::Time p_time);
	std::string format(fs::Date p_date);
	std::string format(fs::DateTime p_datetime);

	std::string FormatForFilename(fs::DateTime p_datetime);

	void ReadText(::fs::PT<Filename>::T p_fn, ::std::vector<::std::string> *p_pv);
}

/* End Of File: utility.h */

