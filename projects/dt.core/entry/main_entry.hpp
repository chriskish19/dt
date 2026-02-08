/**********************************************************/
//
// File: main_entry.hpp
//
// Purpose: main classes for running dt
//
// Project: dt.core
//
/**********************************************************/

#pragma once
#include CORE_NAMES_INCLUDE
#include CORE_STL_INCLUDE_PATH
#include CORE_ARGS_INCLUDE_PATH
#include CORE_API_INCLUDE_PATH
#include CORE_PROCESSOR_INCLUDE_PATH
#include CORE_LOGGER_INCLUDE_PATH
#include CORE_SIM_INCLUDE_PATH
#include CORE_SIM_API_INCLUDE_PATH
#include CORE_WINDOW_INCLUDE_PATH
#include CORE_UI_INCLUDE_PATH
#include CORE_DEFINES_INCLUDE_PATH
#include CORE_TOUT_INCLUDE_PATH
#include CORE_SYSINIT_INCLUDE_PATH
#include CORE_DRAWING_INCLUDE_PATH


namespace core {
	namespace main {

		/************************************************/
		/*			Win32 GUI build objects				*/
		/************************************************/
		class backend : public core::backend::process {
		public:
			backend(const std::vector<arg_entry>& v);
			core::codes run();
		protected:
		};

		class frontend : public core::window::dt_window {
		public:
		protected:
		};

		class gui_with_terminal_entry {
		public:
			gui_with_terminal_entry();
			gui_with_terminal_entry(const std::vector<core::arg_entry>& v);
			void go();
		protected:
			void exit();
			void process_commands(std::shared_ptr<core::backend::commands_info> ci);
			void backend_messages();
			std::atomic<bool> m_run_backend_messages = true;
			std::unique_ptr<backend> m_be = nullptr;
			std::unique_ptr<frontend> m_fe = nullptr;
		};

		class gui_entry {
		public:
			gui_entry();
			gui_entry(const std::vector<core::arg_entry>& v);
			void go();
		protected:
			void exit();
			void gui_process_commands(std::shared_ptr<core::backend::commands_info> ci);
			void backend_messages();
			std::atomic<bool> m_run_backend_messages = true;
			std::unique_ptr<backend> m_be = nullptr;
			std::unique_ptr<frontend> m_fe = nullptr;
		};

		/************************************************/
		/*			Terminal build objects				*/
		/************************************************/

		/*
			for processing log messages and information
		*/
		void terminal_process_commands(std::shared_ptr<core::backend::commands_info> ci);

		/*
			main object for running the terminal build
		*/
		class terminal_entry {
		public:
			terminal_entry(int argc, char* argv[])
				:m_argc(argc), m_argv(argv) {}
			codes init();
			void go();
		protected:
			std::unique_ptr<backend> m_be = nullptr;
			int m_argc = 0;
			char** m_argv = nullptr;
			std::vector<arg_entry> m_v;
		};

		/*
			tests the terminal build
		*/
		class test_terminal_entry : public entry_sim {
		public:
			test_terminal_entry()
				: entry_sim(TEST_FOLDER) {
			}
			void go();
		protected:
		};
	}
}