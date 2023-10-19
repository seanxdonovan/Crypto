#include "precomp.h"

namespace crypto
{
	namespace base64
	{
		namespace internal
		{
			const char output_table[] = {
				'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
				'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
				'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
				'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
				'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
				'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
				'w', 'x', 'y', 'z', '0', '1', '2', '3',
				'4', '5', '6', '7', '8', '9', '+', '/'
			};

			const bool valid_input_table [] = {
	false, 		// '\0' -- 0
	false, 		// '\1' -- 1
	false, 		// '\2' -- 2
	false, 		// '\3' -- 3
	false, 		// '' -- 4
	false, 		// '' -- 5
	false, 		// '' -- 6
	false, 		// '' -- 7
	false, 		// '' -- 8
	false, 		// '\t' -- 9
	false, 		// LF -- 10
	false, 		// '' -- 11
	false, 		// '' -- 12
	false, 		// CR -- 13
	false, 		// '' -- 14
	false, 		// '' -- 15
	false, 		// '' -- 16
	false, 		// '' -- 17
	false, 		// '' -- 18
	false, 		// '' -- 19
	false, 		// '' -- 20
	false, 		// '' -- 21
	false, 		// '' -- 22
	false, 		// '' -- 23
	false, 		// '' -- 24
	false, 		// '' -- 25
	false, 		// '' -- 26
	false, 		// '' -- 27
	false, 		// '' -- 28
	false, 		// '' -- 29
	false, 		// '' -- 30
	false, 		// '' -- 31
	false, 		// ' ' -- 32
	false, 		// '!' -- 33
	false, 		// '"' -- 34
	false, 		// '#' -- 35
	false, 		// '$' -- 36
	false, 		// '%' -- 37
	false, 		// '&' -- 38
	false, 		// ''' -- 39
	false, 		// '(' -- 40
	false, 		// ')' -- 41
	false, 		// '*' -- 42
	true, 		// '+' -- 43
	false, 		// ',' -- 44
	false, 		// '-' -- 45
	false, 		// '.' -- 46
	true, 		// '/' -- 47
	true, 		// '0' -- 48
	true, 		// '1' -- 49
	true, 		// '2' -- 50
	true, 		// '3' -- 51
	true, 		// '4' -- 52
	true, 		// '5' -- 53
	true, 		// '6' -- 54
	true, 		// '7' -- 55
	true, 		// '8' -- 56
	true, 		// '9' -- 57
	false, 		// ':' -- 58
	false, 		// ';' -- 59
	false, 		// '<' -- 60
	true, 		// '=' -- 61
	false, 		// '>' -- 62
	false, 		// '?' -- 63
	false, 		// '@' -- 64
	true, 		// 'A' -- 65
	true, 		// 'B' -- 66
	true, 		// 'C' -- 67
	true, 		// 'D' -- 68
	true, 		// 'E' -- 69
	true, 		// 'F' -- 70
	true, 		// 'G' -- 71
	true, 		// 'H' -- 72
	true, 		// 'I' -- 73
	true, 		// 'J' -- 74
	true, 		// 'K' -- 75
	true, 		// 'L' -- 76
	true, 		// 'M' -- 77
	true, 		// 'N' -- 78
	true, 		// 'O' -- 79
	true, 		// 'P' -- 80
	true, 		// 'Q' -- 81
	true, 		// 'R' -- 82
	true, 		// 'S' -- 83
	true, 		// 'T' -- 84
	true, 		// 'U' -- 85
	true, 		// 'V' -- 86
	true, 		// 'W' -- 87
	true, 		// 'X' -- 88
	true, 		// 'Y' -- 89
	true, 		// 'Z' -- 90
	false, 		// '[' -- 91
	false, 		// '\' -- 92
	false, 		// ']' -- 93
	false, 		// '^' -- 94
	false, 		// '_' -- 95
	false, 		// '`' -- 96
	true, 		// 'a' -- 97
	true, 		// 'b' -- 98
	true, 		// 'c' -- 99
	true, 		// 'd' -- 100
	true, 		// 'e' -- 101
	true, 		// 'f' -- 102
	true, 		// 'g' -- 103
	true, 		// 'h' -- 104
	true,		// 'i' -- 105
	true, 		// 'j' -- 106
	true, 		// 'k' -- 107
	true, 		// 'l' -- 108
	true, 		// 'm' -- 109
	true, 		// 'n' -- 110
	true, 		// 'o' -- 111
	true, 		// 'p' -- 112
	true, 		// 'q' -- 113
	true, 		// 'r' -- 114
	true, 		// 's' -- 115
	true, 		// 't' -- 116
	true, 		// 'u' -- 117
	true, 		// 'v' -- 118
	true, 		// 'w' -- 119
	true, 		// 'x' -- 120
	true, 		// 'y' -- 121
	true, 		// 'z' -- 122
	false, 		// '{' -- 123
	false, 		// '|' -- 124
	false, 		// '}' -- 125
	false, 		// '~' -- 126
	false, 		// '' -- 127
	false, 		// '' -- 128
	false, 		// '' -- 129
	false, 		// '' -- 130
	false, 		// '' -- 131
	false, 		// '' -- 132
	false, 		// '' -- 133
	false, 		// '' -- 134
	false, 		// '' -- 135
	false, 		// '' -- 136
	false, 		// '' -- 137
	false, 		// '' -- 138
	false, 		// '' -- 139
	false, 		// '' -- 140
	false, 		// '' -- 141
	false, 		// '' -- 142
	false, 		// '' -- 143
	false, 		// '' -- 144
	false, 		// '' -- 145
	false, 		// '' -- 146
	false, 		// '' -- 147
	false, 		// '' -- 148
	false, 		// '' -- 149
	false, 		// '' -- 150
	false, 		// '' -- 151
	false, 		// '' -- 152
	false, 		// '' -- 153
	false, 		// '' -- 154
	false, 		// '' -- 155
	false, 		// '' -- 156
	false, 		// '' -- 157
	false, 		// '' -- 158
	false, 		// '' -- 159
	false, 		// '' -- 160
	false, 		// '' -- 161
	false, 		// '' -- 162
	false, 		// '' -- 163
	false, 		// '' -- 164
	false, 		// '' -- 165
	false, 		// '' -- 166
	false, 		// '' -- 167
	false, 		// '' -- 168
	false, 		// '' -- 169
	false, 		// '' -- 170
	false, 		// '' -- 171
	false, 		// '' -- 172
	false, 		// '' -- 173
	false, 		// '' -- 174
	false, 		// '' -- 175
	false, 		// '' -- 176
	false, 		// '' -- 177
	false, 		// '' -- 178
	false, 		// '' -- 179
	false, 		// '' -- 180
	false, 		// '' -- 181
	false, 		// '' -- 182
	false, 		// '' -- 183
	false, 		// '' -- 184
	false, 		// '' -- 185
	false, 		// '' -- 186
	false, 		// '' -- 187
	false, 		// '' -- 188
	false, 		// '' -- 189
	false, 		// '' -- 190
	false, 		// '' -- 191
	false, 		// '' -- 192
	false, 		// '' -- 193
	false, 		// '' -- 194
	false, 		// '' -- 195
	false, 		// '' -- 196
	false, 		// '' -- 197
	false, 		// '' -- 198
	false, 		// '' -- 199
	false, 		// '' -- 200
	false, 		// '' -- 201
	false, 		// '' -- 202
	false, 		// '' -- 203
	false, 		// '' -- 204
	false, 		// '' -- 205
	false, 		// '' -- 206
	false, 		// '' -- 207
	false, 		// '' -- 208
	false, 		// '' -- 209
	false, 		// '' -- 210
	false, 		// '' -- 211
	false, 		// '' -- 212
	false, 		// '' -- 213
	false, 		// '' -- 214
	false, 		// '' -- 215
	false, 		// '' -- 216
	false, 		// '' -- 217
	false, 		// '' -- 218
	false, 		// '' -- 219
	false, 		// '' -- 220
	false, 		// '' -- 221
	false, 		// '' -- 222
	false, 		// '' -- 223
	false, 		// '' -- 224
	false, 		// '' -- 225
	false, 		// '' -- 226
	false, 		// '' -- 227
	false, 		// '' -- 228
	false, 		// '' -- 229
	false, 		// '' -- 230
	false, 		// '' -- 231
	false, 		// '' -- 232
	false, 		// '' -- 233
	false, 		// '' -- 234
	false, 		// '' -- 235
	false, 		// '' -- 236
	false, 		// '' -- 237
	false, 		// '' -- 238
	false, 		// '' -- 239
	false, 		// '' -- 240
	false, 		// '' -- 241
	false, 		// '' -- 242
	false, 		// '' -- 243
	false, 		// '' -- 244
	false, 		// '' -- 245
	false, 		// '' -- 246
	false, 		// '' -- 247
	false, 		// '' -- 248
	false, 		// '' -- 249
	false, 		// '' -- 250
	false, 		// '' -- 251
	false, 		// '' -- 252
	false, 		// '' -- 253
	false, 		// '' -- 254
	false, 		// '' -- 255
			};

			const char input_table[] = {
				0, 		// '\0' -- 0
				0, 		// '\1' -- 1
				0, 		// '\2' -- 2
				0, 		// '\3' -- 3
				0, 		// '.' -- 4
				0, 		// '.' -- 5
				0, 		// '.' -- 6
				0, 		// '.' -- 7
				0, 		// '.' -- 8
				0, 		// '\t' -- 9
				0, 		// LF -- 10
				0, 		// '.' -- 11
				0, 		// '.' -- 12
				0, 		// CR -- 13
				0, 		// '.' -- 14
				0, 		// '.' -- 15
				0, 		// '.' -- 16
				0, 		// '.' -- 17
				0, 		// '.' -- 18
				0, 		// '.' -- 19
				0, 		// '.' -- 20
				0, 		// '.' -- 21
				0, 		// '.' -- 22
				0, 		// '.' -- 23
				0, 		// '.' -- 24
				0, 		// '.' -- 25
				0, 		// '.' -- 26
				0, 		// '.' -- 27
				0, 		// '' -- 28
				0, 		// '' -- 29
				0, 		// '' -- 30
				0, 		// '' -- 31
				0, 		// ' ' -- 32
				0, 		// '!' -- 33
				0, 		// '"' -- 34
				0, 		// '#' -- 35
				0, 		// '$' -- 36
				0, 		// '%' -- 37
				0, 		// '&' -- 38
				0, 		// ''' -- 39
				0, 		// '(' -- 40
				0, 		// ')' -- 41
				0, 		// '*' -- 42
				62, 		// '+' -- 43
				0, 		// ',' -- 44
				0, 		// '-' -- 45
				0, 		// '.' -- 46
				63, 		// '/' -- 47
				52, 		// '0' -- 48
				53, 		// '1' -- 49
				54, 		// '2' -- 50
				55, 		// '3' -- 51
				56, 		// '4' -- 52
				57, 		// '5' -- 53
				58, 		// '6' -- 54
				59, 		// '7' -- 55
				60, 		// '8' -- 56
				61, 		// '9' -- 57
				0, 		// ':' -- 58
				0, 		// ';' -- 59
				0, 		// '<' -- 60
				0, 		// '=' -- 61
				0, 		// '>' -- 62
				0, 		// '?' -- 63
				0, 		// '@' -- 64
				0, 		// 'A' -- 65
				1, 		// 'B' -- 66
				2, 		// 'C' -- 67
				3, 		// 'D' -- 68
				4, 		// 'E' -- 69
				5, 		// 'F' -- 70
				6, 		// 'G' -- 71
				7, 		// 'H' -- 72
				8, 		// 'I' -- 73
				9, 		// 'J' -- 74
				10, 		// 'K' -- 75
				11, 		// 'L' -- 76
				12, 		// 'M' -- 77
				13, 		// 'N' -- 78
				14, 		// 'O' -- 79
				15, 		// 'P' -- 80
				16, 		// 'Q' -- 81
				17, 		// 'R' -- 82
				18, 		// 'S' -- 83
				19, 		// 'T' -- 84
				20, 		// 'U' -- 85
				21, 		// 'V' -- 86
				22, 		// 'W' -- 87
				23, 		// 'X' -- 88
				24, 		// 'Y' -- 89
				25, 		// 'Z' -- 90
				0, 		// '[' -- 91
				0, 		// '\' -- 92
				0, 		// ']' -- 93
				0, 		// '^' -- 94
				0, 		// '_' -- 95
				0, 		// '`' -- 96
				26, 		// 'a' -- 97
				27, 		// 'b' -- 98
				28, 		// 'c' -- 99
				29, 		// 'd' -- 100
				30, 		// 'e' -- 101
				31, 		// 'f' -- 102
				32, 		// 'g' -- 103
				33, 		// 'h' -- 104
				34, 		// 'i' -- 105
				35, 		// 'j' -- 106
				36, 		// 'k' -- 107
				37, 		// 'l' -- 108
				38, 		// 'm' -- 109
				39, 		// 'n' -- 110
				40, 		// 'o' -- 111
				41, 		// 'p' -- 112
				42, 		// 'q' -- 113
				43, 		// 'r' -- 114
				44, 		// 's' -- 115
				45, 		// 't' -- 116
				46, 		// 'u' -- 117
				47, 		// 'v' -- 118
				48, 		// 'w' -- 119
				49, 		// 'x' -- 120
				50, 		// 'y' -- 121
				51, 		// 'z' -- 122
				0, 		// '{' -- 123
				0, 		// '|' -- 124
				0, 		// '}' -- 125
				0, 		// '~' -- 126
				0, 		// '.' -- 127
				0, 		// '.' -- 128
				0,		// '.' -- 129
				0, 		// '.' -- 130
				0, 		// '.' -- 131
				0, 		// '.' -- 132
				0, 		// '.' -- 133
				0, 		// '.' -- 134
				0, 		// '.' -- 135
				0, 		// '.' -- 136
				0, 		// '.' -- 137
				0, 		// '.' -- 138
				0, 		// '.' -- 139
				0, 		// '.' -- 140
				0, 		// '.' -- 141
				0, 		// '.' -- 142
				0, 		// '.' -- 143
				0, 		// '.' -- 144
				0, 		// '.' -- 145
				0, 		// '.' -- 146
				0, 		// '.' -- 147
				0, 		// '.' -- 148
				0, 		// '.' -- 149
				0, 		// '.' -- 150
				0, 		// '.' -- 151
				0, 		// '.' -- 152
				0, 		// '.' -- 153
				0, 		// '.' -- 154
				0, 		// '.' -- 155
				0, 		// '.' -- 156
				0, 		// '.' -- 157
				0, 		// '.' -- 158
				0, 		// '.' -- 159
				0, 		// '.' -- 160
				0, 		// '.' -- 161
				0, 		// '.' -- 162
				0, 		// '.' -- 163
				0, 		// '.' -- 164
				0, 		// '.' -- 165
				0, 		// '.' -- 166
				0, 		// '.' -- 167
				0, 		// '.' -- 168
				0, 		// '.' -- 169
				0, 		// '.' -- 170
				0, 		// '.' -- 171
				0, 		// '.' -- 172
				0, 		// '.' -- 173
				0, 		// '.' -- 174
				0, 		// '.' -- 175
				0, 		// '.' -- 176
				0, 		// '.' -- 177
				0, 		// '.' -- 178
				0, 		// '.' -- 179
				0, 		// '.' -- 180
				0, 		// '.' -- 181
				0, 		// '.' -- 182
				0, 		// '.' -- 183
				0, 		// '.' -- 184
				0, 		// '.' -- 185
				0, 		// '.' -- 186
				0, 		// '.' -- 187
				0, 		// '.' -- 188
				0, 		// '.' -- 189
				0, 		// '.' -- 190
				0, 		// '.' -- 191
				0, 		// '.' -- 192
				0, 		// '.' -- 193
				0, 		// '.' -- 194
				0, 		// '.' -- 195
				0, 		// '.' -- 196
				0, 		// '.' -- 197
				0, 		// '.' -- 198
				0, 		// '.' -- 199
				0, 		// '.' -- 200
				0, 		// '.' -- 201
				0, 		// '.' -- 202
				0, 		// '.' -- 203
				0, 		// '.' -- 204
				0, 		// '.' -- 205
				0, 		// '.' -- 206
				0, 		// '.' -- 207
				0, 		// '.' -- 208
				0, 		// '.' -- 209
				0, 		// '.' -- 210
				0, 		// '.' -- 211
				0, 		// '.' -- 212
				0, 		// '.' -- 213
				0, 		// '.' -- 214
				0, 		// '.' -- 215
				0, 		// '.' -- 216
				0, 		// '.' -- 217
				0, 		// '.' -- 218
				0, 		// '.' -- 219
				0, 		// '.' -- 220
				0, 		// '.' -- 221
				0, 		// '.' -- 222
				0, 		// '.' -- 223
				0, 		// '.' -- 224
				0, 		// '.' -- 225
				0, 		// '.' -- 226
				0, 		// '.' -- 227
				0, 		// '.' -- 228
				0, 		// '.' -- 229
				0, 		// '.' -- 230
				0, 		// '.' -- 231
				0, 		// '.' -- 232
				0, 		// '.' -- 233
				0, 		// '.' -- 234
				0, 		// '.' -- 235
				0, 		// '.' -- 236
				0, 		// '.' -- 237
				0, 		// '.' -- 238
				0, 		// '.' -- 239
				0, 		// '.' -- 240
				0, 		// '.' -- 241
				0, 		// '.' -- 242
				0, 		// '.' -- 243
				0, 		// '.' -- 244
				0, 		// '.' -- 245
				0, 		// '.' -- 246
				0, 		// '.' -- 247
				0, 		// '.' -- 248
				0, 		// '.' -- 249
				0, 		// '.' -- 250
				0, 		// '.' -- 251
				0, 		// '.' -- 252
				0, 		// '.' -- 253
				0, 		// '.' -- 254
				0, 		// '.' -- 255
			};

			const char pad = '=';
		}

		void Encode(fs::Stream& p_from, fs::Stream& p_to, fs::Stream::Offset p_length)
		{
			const fs::Stream::Offset nWholeTriples = p_length / 3;

			fs::dword n = 0;

			fs::FixedBuffer<4> encoded;
			while (n < nWholeTriples)
			{
				fs::FixedBuffer<3> buffer;
				p_from.Read(buffer);
				fs::byte b1 = buffer[0];
				fs::byte b2 = buffer[1];
				fs::byte b3 = buffer[2];

				encoded[0] = internal::output_table[(b1 & 0xFC) >> 2];
				encoded[1] = internal::output_table[((b1 & 3) << 4) | ((b2 & 0xF0) >> 4)];
				encoded[2] = internal::output_table[((b2 & 0x0F) << 2) | ((b3 & 0xC0) >> 6)];
				encoded[3] = internal::output_table[(b3 & 0x3F)];

				p_to.Write(encoded);
				++n;
				if (0 == n % 19)
				{
					p_to.Write(fs::CR);
					p_to.Write(fs::LF);
				}
			}

			fs::Buffer::Offset nRemainder = p_length % 3;

			if (1 == nRemainder)
			{
				fs::FixedBuffer<1> buffer;
				p_from.Read(buffer);
				fs::byte b1 = buffer[0];

				encoded[0] = internal::output_table[(b1 & 0xFC) >> 2];
				encoded[1] = internal::output_table[((b1 & 3) << 4)];
				encoded[2] = internal::pad;
				encoded[3] = internal::pad;
				p_to.Write(encoded);
			}
			else if (2 == nRemainder)
			{
				fs::FixedBuffer<2> buffer;
				p_from.Read(buffer);
				fs::byte b1 = buffer[0];
				fs::byte b2 = buffer[1];

				encoded[0] = internal::output_table[(b1 & 0xFC) >> 2];
				encoded[1] = internal::output_table[((b1 & 3) << 4) | ((b2 & 0xF0) >> 4)];
				encoded[2] = internal::output_table[((b2 & 0x0F) << 2)];
				encoded[3] = internal::pad;
				p_to.Write(encoded);
			}
			p_to.Write(fs::CR);
			p_to.Write(fs::LF);
		}

		void Encode(const fs::Buffer& p_buffer, std::string *p_encoded)
		{
			const fs::Buffer::Offset datasize = p_buffer.Size();
			const fs::Buffer::Offset nWholeTriples = datasize / 3;
			fs::Buffer::Offset stringSize = nWholeTriples * 4;
			if (0 != datasize % 3)
			{
				stringSize += 4;
			}
			p_encoded->resize(stringSize);

			fs::dword n = 0;

			while (n < nWholeTriples)
			{
				fs::byte b1 = p_buffer[n * 3 + 0];
				fs::byte b2 = p_buffer[n * 3 + 1];
				fs::byte b3 = p_buffer[n * 3 + 2];

				(*p_encoded)[4 * n + 0] = internal::output_table[(b1 & 0xFC) >> 2];
				(*p_encoded)[4 * n + 1] = internal::output_table[((b1 & 3) << 4) | ((b2 & 0xF0) >> 4)];
				(*p_encoded)[4 * n + 2] = internal::output_table[((b2 & 0x0F) << 2) | ((b3 & 0xC0) >> 6)];
				(*p_encoded)[4 * n + 3] = internal::output_table[(b3 & 0x3F)];

				++n;
			}

			fs::Buffer::Offset nRemainder = datasize % 3;

			if (1 == nRemainder)
			{
				fs::byte b1 = p_buffer[n * 3 + 0];

				(*p_encoded)[4 * n + 0] = internal::output_table[(b1 & 0xFC) >> 2];
				(*p_encoded)[4 * n + 1] = internal::output_table[((b1 & 3) << 4)];
				(*p_encoded)[4 * n + 2] = internal::pad;
				(*p_encoded)[4 * n + 3] = internal::pad;
			}
			else if (2 == nRemainder)
			{
				fs::byte b1 = p_buffer[n * 3 + 0];
				fs::byte b2 = p_buffer[n * 3 + 1];

				(*p_encoded)[4 * n + 0] = internal::output_table[(b1 & 0xFC) >> 2];
				(*p_encoded)[4 * n + 1] = internal::output_table[((b1 & 3) << 4) | ((b2 & 0xF0) >> 4)];
				(*p_encoded)[4 * n + 2] = internal::output_table[((b2 & 0x0F) << 2)];
				(*p_encoded)[4 * n + 3] = internal::pad;
			}
		}

		//
		// Evaluate the string to see if it is a valid base64 representation.
		//
		bool IsValid(const std::string& p_sTest)
		{
			if (0 != (p_sTest.size() % 4))
			{
				sTraceX(("The test string is not valid base 64, its size, ", p_sTest.size(), " is not a multiple of 4."));
				return false;
			}

			for (size_t ix = 0; ix < p_sTest.size(); ++ix)
			{
				if (!internal::valid_input_table[p_sTest[ix]])
				{
					sTraceX(("The character '", p_sTest[ix], "' at position ", ix, " is not a valid base64 character."));
					return false;
				}
			}

			return true;
		}

		void Decode(fs::Stream& p_from, fs::Stream& p_to, fs::Stream::Offset p_length)
		{
			sRaiseError(("Not implemetned."));
		}

		void Decode(const std::string& p_encodedText, fs::Buffer *p_pData)
		{
			sPrecondition(0 == (p_encodedText.size() % 4)); // malformed string.

			fs::Buffer::Offset nTriplets = p_encodedText.size() / 4;
			if (nTriplets > 0)
			{
				fs::byte b1 = 0;
				fs::byte b2 = 0;
				fs::byte b3 = 0;

				fs::dword ix = 0;
				for (; ix < nTriplets - 1; ++ ix)
				{
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 0]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 1]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 2]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 3]]);
					b1 = (internal::input_table[p_encodedText[ix * 4 + 0]] << 2)
						| (internal::input_table[p_encodedText[ix * 4 + 1]] >> 4);

					b2 = ((internal::input_table[p_encodedText[ix * 4 + 1]] & 0xF) << 4)
						| (internal::input_table[p_encodedText[ix * 4 + 2]] >> 2);

					b3 = ((internal::input_table[p_encodedText[ix * 4 + 2]] & 3) << 6)
						| (internal::input_table[p_encodedText[ix * 4 + 3]]);
					(*p_pData)[ix * 3 + 0] = b1;
					(*p_pData)[ix * 3 + 1] = b2;
					(*p_pData)[ix * 3 + 2] = b3;
				}

				sAssert(p_encodedText[ix * 4 + 0] != internal::pad);
				sAssert(p_encodedText[ix * 4 + 1] != internal::pad);

				if (p_encodedText[ix * 4 + 2] == internal::pad)
				{
					//
					// 1 byte to decode
					//
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 0]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 1]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 2]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 3]]);
					b1 = (internal::input_table[p_encodedText[ix * 4 + 0]] << 2)
						| (internal::input_table[p_encodedText[ix * 4 + 1]] >> 4);

					(*p_pData)[ix * 3 + 0] = b1;
				}
				else if (p_encodedText[ix * 4 + 3] == internal::pad)
				{
					//
					// 2 bytes to decode.
					//
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 0]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 1]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 2]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 3]]);
					b1 = (internal::input_table[p_encodedText[ix * 4 + 0]] << 2)
						| (internal::input_table[p_encodedText[ix * 4 + 1]] >> 4);

					b2 = ((internal::input_table[p_encodedText[ix * 4 + 1]] & 0xF) << 4)
						| (internal::input_table[p_encodedText[ix * 4 + 2]] >> 2);

					(*p_pData)[ix * 3 + 0] = b1;
					(*p_pData)[ix * 3 + 1] = b2;
				}
				else
				{
					//
					// Full triplet. would be nice if this could be folded into
					// the loop.
					//

					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 0]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 1]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 2]]);
					sAssert(internal::valid_input_table[p_encodedText[ix * 4 + 3]]);
					b1 = (internal::input_table[p_encodedText[ix * 4 + 0]] << 2)
						| (internal::input_table[p_encodedText[ix * 4 + 1]] >> 4);

					b2 = ((internal::input_table[p_encodedText[ix * 4 + 1]] & 0xF) << 4)
						| (internal::input_table[p_encodedText[ix * 4 + 2]] >> 2);

					b3 = ((internal::input_table[p_encodedText[ix * 4 + 2]] & 3) << 6)
						| (internal::input_table[p_encodedText[ix * 4 + 3]]);
					(*p_pData)[ix * 3 + 0] = b1;
					(*p_pData)[ix * 3 + 1] = b2;
					(*p_pData)[ix * 3 + 2] = b3;
				}
			}

		}


		size_t DecodedBufferSize(const std::string& p_encodedText)
		{
			size_t size = 0;
			
			if (p_encodedText.size() > 0)
			{
				size = (p_encodedText.size() / 4) * 3;

				if (p_encodedText[p_encodedText.size() - 1] == internal::pad)
				{
					--size;
				}
				if (p_encodedText[p_encodedText.size() - 2] == internal::pad)
				{
					--size;
				}

			}
			return size;
		}

	} /* base64 */

} /* crypto */

/* End Of File: base64.cpp */
