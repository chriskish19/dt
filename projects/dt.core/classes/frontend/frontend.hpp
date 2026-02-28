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
#include CORE_WINDOW_INCLUDE_PATH
#include CORE_DRAWING_INCLUDE_PATH
#include CORE_LOGGER_INCLUDE_PATH
#include CORE_SYSINIT_INCLUDE_PATH


namespace core {
	namespace frontend {
		class Cfrontend : public core::window::dt_window {
		public:
			virtual ~Cfrontend() = default;
			virtual void draw_progress() = 0;
			virtual void process_commands(std::shared_ptr<core::backend::commands_info> ci) = 0;
		protected:


		};

		class gui_with_terminal : public Cfrontend{
		public:

			void draw_progress() override;
			void process_commands(std::shared_ptr<core::backend::commands_info> ci) override;
		protected:
			core::main::loading_bar progress;

		};

		class gui : public Cfrontend {
		public:
			~gui();
			void draw_progress() override;
			void process_commands(std::shared_ptr<core::backend::commands_info> ci) override;
		protected:
			core::main::window_loading_bar* progress = new core::main::window_loading_bar(core::logger::glb_sl->get_window_handle(), L"Processing...");

		};

		class terminal : public Cfrontend {
		public:
			void draw_progress() override;
			void process_commands(std::shared_ptr<core::backend::commands_info> ci) override;
		protected:
			core::main::loading_bar progress;
		};


	}
	
}