/**********************************************************/
//
// File:
//
// Purpose:
//
// Project:
//
/**********************************************************/


#include CORE_NAMES_INCLUDE
#include CORE_MESSAGES_INCLUDE_PATH

core::main::messages::messages(build type)
{
	switch (type) {
	case build::gui:
		m_frontend = std::make_unique<core::frontend::gui>();
		break;
	case build::gui_with_terminal:
		m_frontend = std::make_unique<core::frontend::gui_with_terminal>();
		break;
	case build::terminal:
		m_frontend = std::make_unique<core::frontend::terminal>();
		break;
	default:
		break;
	}

	m_backend = std::make_unique<core::backend::Cbackend>();
}

void core::main::messages::process()
{
	while (m_run_messages.load() == true) {
		// timer here, seconds to wait time
		std::this_thread::sleep_for(std::chrono::milliseconds(GUI_SYNC_INTERVAL));
		
		auto q = m_backend->get_current_queue();
		while (q.empty() == false && m_run_messages.load() == true) {
			auto& command = q.front();
			m_frontend->process_commands(command);
			q.pop();
		}

		m_frontend->draw_progress();
	}
}
