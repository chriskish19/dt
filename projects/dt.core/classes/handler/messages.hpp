/**********************************************************/
//
// File:
//
// Purpose:
//
// Project:
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
#include CORE_FRONTEND_INCLUDE_PATH
#include CORE_BACKEND_INCLUDE_PATH


namespace core{
	namespace main {
		enum class build {
			gui,
			gui_with_terminal,
			terminal
		};


		class messages {
		public:
			messages(build type);

			void process();
		protected:
			std::atomic<bool> m_run_messages = true;
			std::unique_ptr<core::backend::Cbackend> m_backend = nullptr;
			std::unique_ptr<core::frontend::Cfrontend> m_frontend = nullptr;
		};
	}
}