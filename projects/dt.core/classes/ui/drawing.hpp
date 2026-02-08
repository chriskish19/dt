/**********************************************************/
//
// File: drawing.hpp
//
// Purpose: simple drawing to windows
//
// Project: dt
//
/**********************************************************/

#pragma once
#include CORE_NAMES_INCLUDE
#include CORE_STL_INCLUDE_PATH
#include CORE_WIN32_INCLUDE_PATH
#include CORE_DEFINES_INCLUDE_PATH


namespace core {
	namespace main {
		/*
			draws a loading bar in the terminal
		*/
		class loading_bar {
		public:
			void draw();
		protected:
			int frame_index = 0;
			const int num_frames = 8;
			const char8_t frames[25] = u8"⣾⣽⣻⢿⡿⣟⣯⣷";
			const int bytes_per_frame = 3;
		};

		/*
			draws a loading bar on a window title
		*/
		class window_loading_bar {
		public:
			window_loading_bar(HWND handle, const std::wstring& message)
				:m_handle(handle), m_message(message) {}
			void draw();
		protected:
			int frame_index = 0;
			const int num_frames = 8;
			HWND m_handle;
			std::wstring m_message;
			const std::wstring m_frames = L"⣾⣽⣻⢿⡿⣟⣯⣷";
		};
	}
}