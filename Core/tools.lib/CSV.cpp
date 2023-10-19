#include "precomp.h"
#include "Core/fs.lib/fs.lib.h"
#include "declarations.h"

namespace tools
{
	void WriteCSVLine(FILE *p_foutLog, const std::vector<std::string>& p_values)
	{
		sPrecondition(0 != p_foutLog);

		for (size_t ix = 0; ix < p_values.size(); ++ix)
		{
			if (0 != ix)
			{
				fputc(',', p_foutLog);
			}
			fputc('\"', p_foutLog);
			const std::string& value = p_values[ix];
			for (size_t jx = 0; jx < value.length(); ++jx)
			{
				if (value[jx] == '\"')
				{
					fputc(value[jx], p_foutLog);
				}
				fputc(value[jx], p_foutLog);
			}
			fputc('\"', p_foutLog);
		}
		fputc('\n', p_foutLog);
	}


	void WriteCSVLine(fs::Stream& p_out, const std::vector<std::string>& p_values)
	{
		std::string s;
		
		for (size_t ix = 0; ix < p_values.size(); ++ix)
		{
			if (0 != ix)
			{
				s += ',';
			}
			s += '\"';

			const std::string& value = p_values[ix];
			for (size_t jx = 0; jx < value.length(); ++jx)
			{
				if (value[jx] == '\"')
				{
					s += value[jx];
				}
				s += value[jx];
			}
			s += '\"';
		}

		WriteLn(p_out, s);
	}
}

/* End Of File: CSV.cpp */
