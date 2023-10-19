#include "precomp.h"
#include "../fs.lib/fs.lib.h"

#include "Tokenizer.h"

namespace tools
{
	Tokenizer::Tokenizer()
	{
	}

	Tokenizer::~Tokenizer()
	{
	}

	bool delimiter[] =
	{
		true, 		// '^@' -- 0
		true, 		// '^A' -- 1
		true, 		// '^B' -- 2
		true, 		// '^C' -- 3
		true, 		// '^D' -- 4
		true, 		// '^E' -- 5
		true, 		// '^F' -- 6
		true, 		// '^G' -- 7
		true, 		// '^H' -- 8
		true, 		// '^I' -- 9
		true, 		// '^J' -- 10
		true, 		// '^K' -- 11
		true, 		// '^L' -- 12
		true, 		// '^M' -- 13
		true, 		// '^N' -- 14
		true, 		// '^O' -- 15
		true, 		// '^P' -- 16
		true, 		// '^Q' -- 17
		true, 		// '^R' -- 18
		true, 		// '^S' -- 19
		true, 		// '^T' -- 20
		true, 		// '^U' -- 21
		true, 		// '^V' -- 22
		true, 		// '^W' -- 23
		true, 		// '^X' -- 24
		true, 		// '^Y' -- 25
		true, 		// '^Z' -- 26
		true, 		// '^[' -- 27
		true, 		// '^\' -- 28
		true, 		// '^]' -- 29
		true, 		// '^^' -- 30
		true, 		// '^_' -- 31
		true, 		// ' ' -- 32
		true, 		// '!' -- 33
		true, 		// '"' -- 34
		true, 		// '#' -- 35
		true, 		// '$' -- 36
		true, 		// '%' -- 37
		false, 		// '&' -- 38
		true, 		// ''' -- 39
		true, 		// '(' -- 40
		true, 		// ')' -- 41
		true, 		// '*' -- 42
		true, 		// '+' -- 43
		true, 		// ',' -- 44
		true, 		// '-' -- 45
		true, 		// '.' -- 46
		true, 		// '/' -- 47
		false, 		// '0' -- 48
		false, 		// '1' -- 49
		false, 		// '2' -- 50
		false, 		// '3' -- 51
		false, 		// '4' -- 52
		false, 		// '5' -- 53
		false, 		// '6' -- 54
		false, 		// '7' -- 55
		false, 		// '8' -- 56
		false, 		// '9' -- 57
		true, 		// ':' -- 58
		true, 		// ';' -- 59
		true, 		// '<' -- 60
		true, 		// '=' -- 61
		true, 		// '>' -- 62
		true, 		// '?' -- 63
		true, 		// '@' -- 64
		false, 		// 'A' -- 65
		false, 		// 'B' -- 66
		false, 		// 'C' -- 67
		false, 		// 'D' -- 68
		false, 		// 'E' -- 69
		false, 		// 'F' -- 70
		false, 		// 'G' -- 71
		false, 		// 'H' -- 72
		false, 		// 'I' -- 73
		false, 		// 'J' -- 74
		false, 		// 'K' -- 75
		false, 		// 'L' -- 76
		false, 		// 'M' -- 77
		false, 		// 'N' -- 78
		false, 		// 'O' -- 79
		false, 		// 'P' -- 80
		false, 		// 'Q' -- 81
		false, 		// 'R' -- 82
		false, 		// 'S' -- 83
		false, 		// 'T' -- 84
		false, 		// 'U' -- 85
		false, 		// 'V' -- 86
		false, 		// 'W' -- 87
		false, 		// 'X' -- 88
		false, 		// 'Y' -- 89
		false, 		// 'Z' -- 90
		true, 		// '[' -- 91
		true, 		// '\' -- 92
		true, 		// ']' -- 93
		true, 		// '^' -- 94
		false, 		// '_' -- 95
		true, 		// '`' -- 96
		false, 		// 'a' -- 97
		false, 		// 'b' -- 98
		false, 		// 'c' -- 99
		false, 		// 'd' -- 100
		false, 		// 'e' -- 101
		false, 		// 'f' -- 102
		false, 		// 'g' -- 103
		false, 		// 'h' -- 104
		false, 		// 'i' -- 105
		false, 		// 'j' -- 106
		false, 		// 'k' -- 107
		false, 		// 'l' -- 108
		false, 		// 'm' -- 109
		false, 		// 'n' -- 110
		false, 		// 'o' -- 111
		false, 		// 'p' -- 112
		false, 		// 'q' -- 113
		false, 		// 'r' -- 114
		false, 		// 's' -- 115
		false, 		// 't' -- 116
		false, 		// 'u' -- 117
		false, 		// 'v' -- 118
		false, 		// 'w' -- 119
		false, 		// 'x' -- 120
		false, 		// 'y' -- 121
		false, 		// 'z' -- 122
		true, 		// '{' -- 123
		true, 		// '|' -- 124
		true, 		// '}' -- 125
		true, 		// '~' -- 126
		true, 		// '' -- 127
		true, 		// '�' -- 128
		true, 		// '�' -- 129
		true, 		// '�' -- 130
		true, 		// '�' -- 131
		true, 		// '�' -- 132
		true, 		// '�' -- 133
		true, 		// '�' -- 134
		true, 		// '�' -- 135
		true, 		// '�' -- 136
		true, 		// '�' -- 137
		true, 		// '�' -- 138
		true, 		// '�' -- 139
		true, 		// '�' -- 140
		true, 		// '�' -- 141
		true, 		// '�' -- 142
		true, 		// '�' -- 143
		true, 		// '�' -- 144
		true, 		// '�' -- 145
		true, 		// '�' -- 146
		true, 		// '�' -- 147
		true, 		// '�' -- 148
		true, 		// '�' -- 149
		true, 		// '�' -- 150
		true, 		// '�' -- 151
		true, 		// '�' -- 152
		true, 		// '�' -- 153
		true, 		// '�' -- 154
		true, 		// '�' -- 155
		true, 		// '�' -- 156
		true, 		// '�' -- 157
		true, 		// '�' -- 158
		true, 		// '�' -- 159
		true, 		// '�' -- 160
		true, 		// '�' -- 161
		true, 		// '�' -- 162
		true, 		// '�' -- 163
		true, 		// '�' -- 164
		true, 		// '�' -- 165
		true, 		// '�' -- 166
		true, 		// '�' -- 167
		true, 		// '�' -- 168
		true, 		// '�' -- 169
		true, 		// '�' -- 170
		true, 		// '�' -- 171
		true, 		// '�' -- 172
		true, 		// '�' -- 173
		true, 		// '�' -- 174
		true, 		// '�' -- 175
		true, 		// '�' -- 176
		true, 		// '�' -- 177
		true, 		// '�' -- 178
		true, 		// '�' -- 179
		true, 		// '�' -- 180
		true, 		// '�' -- 181
		true, 		// '�' -- 182
		true, 		// '�' -- 183
		true, 		// '�' -- 184
		true, 		// '�' -- 185
		true, 		// '�' -- 186
		true, 		// '�' -- 187
		true, 		// '�' -- 188
		true, 		// '�' -- 189
		true, 		// '�' -- 190
		true, 		// '�' -- 191
		true, 		// '�' -- 192
		true, 		// '�' -- 193
		true, 		// '�' -- 194
		true, 		// '�' -- 195
		true, 		// '�' -- 196
		true, 		// '�' -- 197
		true, 		// '�' -- 198
		true, 		// '�' -- 199
		true, 		// '�' -- 200
		true, 		// '�' -- 201
		true, 		// '�' -- 202
		true, 		// '�' -- 203
		true, 		// '�' -- 204
		true, 		// '�' -- 205
		true, 		// '�' -- 206
		true, 		// '�' -- 207
		true, 		// '�' -- 208
		true, 		// '�' -- 209
		true, 		// '�' -- 210
		true, 		// '�' -- 211
		true, 		// '�' -- 212
		true, 		// '�' -- 213
		true, 		// '�' -- 214
		true, 		// '�' -- 215
		true, 		// '�' -- 216
		true, 		// '�' -- 217
		true, 		// '�' -- 218
		true, 		// '�' -- 219
		true, 		// '�' -- 220
		true, 		// '�' -- 221
		true, 		// '�' -- 222
		true, 		// '�' -- 223
		true, 		// '�' -- 224
		true, 		// '�' -- 225
		true, 		// '�' -- 226
		true, 		// '�' -- 227
		true, 		// '�' -- 228
		true, 		// '�' -- 229
		true, 		// '�' -- 230
		true, 		// '�' -- 231
		true, 		// '�' -- 232
		true, 		// '�' -- 233
		true, 		// '�' -- 234
		true, 		// '�' -- 235
		true, 		// '�' -- 236
		true, 		// '�' -- 237
		true, 		// '�' -- 238
		true, 		// '�' -- 239
		true, 		// '�' -- 240
		true, 		// '�' -- 241
		true, 		// '�' -- 242
		true, 		// '�' -- 243
		true, 		// '�' -- 244
		true, 		// '�' -- 245
		true, 		// '�' -- 246
		true, 		// '�' -- 247
		true, 		// '�' -- 248
		true, 		// '�' -- 249
		true, 		// '�' -- 250
		true, 		// '�' -- 251
		true, 		// '�' -- 252
		true, 		// '�' -- 253
		true, 		// '�' -- 254
		true, 		// '�' -- 255
	};


	void Tokenizer::Tokens(const std::string& p_string, std::vector<std::string> *p_pTokens)
	{
		std::string::const_iterator it = p_string.begin();

		bool inToken = false;
		std::string currentToken;
		while (it != p_string.end())
		{
			const char ch = *it;

			if (inToken)
			{
				if (delimiter[ch])
				{
					p_pTokens->push_back(currentToken);
					currentToken = "";
					inToken = false;
				}
				else
				{
					currentToken += ch;
				}
			}
			else
			{
				if (!delimiter[ch])
				{
					currentToken += ch;
					inToken = true;
				}
			}

			++it;
		}

		if (!currentToken.empty())
		{
			p_pTokens->push_back(currentToken);
		}
	}
}
